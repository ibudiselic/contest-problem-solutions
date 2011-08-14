#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int X[10], Y[10];
int n_airport;
int n_plane;
int S[20], D[20], T[20], L[20];

double dist(double x1, double y1, double x2, double y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
bool bet(double a, int b, int c) {
    return b<=a+1e-9 && a<=c+1e-9;
}
bool ibet(int a, int b, int c) {
    return b<=a && a<=c;
}

double dx[20], dy[20];
inline double get_x(int i, double t) {
    return X[S[i]] + dx[i]*(t-T[i]);
}
inline double get_y(int i, double t) {
    return Y[S[i]] + dy[i]*(t-T[i]);
}

double eps[] = { 1e-12, 1e-10 };
inline void add_all(double t, vector<double> &v) {
    v.push_back(t);
    for (int i=0; i<2; ++i) {
        v.push_back(t - eps[i]);
        v.push_back(t + eps[i]);
    }
}
bool G[30][30];
bool can_do(double d) {
    d *= d;
    
    vector<double> crit;
    for (int i=0; i<n_plane; ++i) {
        crit.push_back(T[i]);
        crit.push_back(L[i]);
        for (int j=i+1; j<n_plane; ++j) {
            if (T[j] >= L[i]) {
                break;
            }

            double xx = X[S[i]] - dx[i]*T[i] - X[S[j]] + dx[j]*T[j];
            double dxx = dx[i] - dx[j];

            double yy = Y[S[i]] - dy[i]*T[i] - Y[S[j]] + dy[j]*T[j];
            double dyy = dy[i] - dy[j];

            double a = dxx*dxx + dyy*dyy;
            double b = 2*(xx*dxx + yy*dyy);
            double c = xx*xx + yy*yy - d;

            double denom = 2*a;
            if (fabs(denom) <= 1e-12) {
                continue;
            }

            double det = b*b - 4*a*c;
            if (det < -1e-12) {
                continue;
            }
            if (det <= 1e-12) {
                det = 0;
            } else {
                det = sqrt(det);
            }

            double t1 = (-b - det) / denom;
            double t2 = (-b + det) / denom;

            if (bet(t1, T[j], L[i])) {
                add_all(t1, crit);
            }
            
            if (bet(t2, T[j], L[i])) {
                add_all(t2, crit);
            }
        }

        for (int j=0; j<n_airport; ++j) {
            double xx = X[S[i]] - X[j] - dx[i]*T[i];
            double yy = Y[S[i]] - Y[j] - dy[i]*T[i];
            
            double a = dx[i]*dx[i] + dy[i]*dy[i];
            double b = 2*(xx*dx[i] + yy*dy[i]);
            double c = xx*xx + yy*yy - d;
            double denom = 2*a;
            if (fabs(denom) <= 1e-12) {
                continue;
            }

            double det = b*b - 4*a*c;
            if (det < -1e-12) {
                continue;
            }
            if (det <= 1e-12) {
                det = 0;
            } else {
                det = sqrt(det);
            }

            double t1 = (-b - det) / denom;
            double t2 = (-b + det) / denom;
            /*cerr << "@@@@@@@\n";
            cerr << "plane " << i << " airport " << j << '\n';
            cerr << a << ' ' << b << ' ' << c << '\n';
            cerr << t1 << ' ' << t2 << '\n';
            cerr << "@@@@@@@\n";*/

            if (bet(t1, T[i], L[i])) {
                add_all(t1, crit);
            }
            
            if (bet(t2, T[i], L[i])) {
                add_all(t2, crit);
            }
        }
    }

    sort(crit.begin(), crit.end());
    crit.erase(unique(crit.begin(), crit.end()), crit.end());

    for (int i=0; i<(int)crit.size(); ++i) {
        double t = crit[i];
        memset(G, 0, sizeof G);

        for (int u=0; u<n_airport; ++u) {
            G[u][u] = 1;
        }

        vector<int> active;
        vector<double> x, y;
        for (int u=0; u<n_plane; ++u) {
            if (bet(t, T[u], L[u])) {
                active.push_back(u);
                x.push_back(get_x(u, t));
                y.push_back(get_y(u, t));
            }
        }


        for (int j=0; j<(int)active.size(); ++j) {
            for (int k=0; k<n_airport; ++k) {
                if (dist(X[k], Y[k], x[j], y[j]) <= d+1e-12) {
                    G[k][n_airport + active[j]] = 1;
                    G[n_airport + active[j]][k] = 1;
                }
            }

            for (int k=j+1; k<(int)active.size(); ++k) {
                if (dist(x[j], y[j], x[k], y[k]) <= d+1e-12) {
                    G[n_airport+active[k]][n_airport+active[j]] = 1;
                    G[n_airport+active[j]][n_airport+active[k]] = 1;
                }
            }
        }

        int tot = n_plane + n_airport;
        /*cerr << "!!!!\n" << t << ' ' << n_airport << ' ' << tot << '\n';
        for (int r=0; r<tot; ++r) {
            for (int c=0; c<tot; ++c) {
                cerr << G[r][c] << ' ';
            }
            cerr << '\n';
        }*/
        for (int c=0; c<tot; ++c) {
            for (int a=0; a<tot; ++a) {
                if (G[a][c]) {
                    for (int b=0; b<tot; ++b) {
                        G[a][b] |= G[c][b];
                    }
                }
            }
        }

        int cnt_covered = 0;
        vector<bool> covered(n_plane, false);
        for (int u=0; u<n_airport; ++u) {
            for (int k=n_airport; k<tot; ++k) {
                if (G[u][k] && !covered[k-n_airport]) {
                    covered[k-n_airport] = 1;
                    ++cnt_covered;
                }
            }
        }

        assert(cnt_covered <= (int)active.size());
        if (cnt_covered < (int)active.size()) {
            return false;
        }
    }

    return true;
}

class AirlineInternet {
	public:
	double minimumRange(vector <string> loc, vector <string> flights) {
		n_airport = loc.size();
        for (int i=0; i<n_airport; ++i) {
            sscanf(loc[i].c_str(), "%d %d", (X+i), (Y+i));
        }

        n_plane = flights.size();
        for (int i=0; i<n_plane; ++i) {
            sscanf(flights[i].c_str(), "%d %d %d %d", S+i, D+i, T+i, L+i);
        }
        for (int i=0; i<n_plane; ++i) {
            for (int j=i+1; j<n_plane; ++j) {
                if (T[i] > T[j]) {
                    swap(T[i], T[j]);
                    swap(L[i], L[j]);
                    swap(S[i], S[j]);
                    swap(D[i], D[j]);
                }
            }
        }

        for (int i=0; i<n_plane; ++i) {
            dx[i] = double(X[D[i]] - X[S[i]]) / (L[i]-T[i]);
            dy[i] = double(Y[D[i]] - Y[S[i]]) / (L[i]-T[i]);
        }

        double lo = 0.0;
        double hi = 1e3;
        for (int t=0; t<60; ++t) {
            double m = lo + (hi-lo)/2;
            if (can_do(m)) {
                hi = m;
            } else {
                lo = m;
            }
        }

        return hi;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0 0","100 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1 0 100"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 50.0; verify_case(0, Arg2, minimumRange(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"0 0","100 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1 0 100","0 1 25 125","0 1 50 150","0 1 75 175"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 25.0; verify_case(1, Arg2, minimumRange(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"25 100","0 50","90 150","22 22","60 1","95 8","12 40"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1 0 500","2 5 10 300","2 0 100 200"
,"3 6 150 400","4 5 50 450","5 1 0 300"
,"2 6 10 100"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 64.28201130009927; verify_case(2, Arg2, minimumRange(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"0 0","50 0","100 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1 0 100"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 25.0; verify_case(3, Arg2, minimumRange(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"417 262","519 592","941 778"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1 376 534","0 2 603 763","1 0 137 431"
,"0 1 525 583","2 1 367 551","0 1 953 996"
,"0 1 668 886"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 246.618769031594; verify_case(4, Arg2, minimumRange(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"101 591","283 183","346 696","436 638","738 46"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3 0 855 890","2 0 260 698","3 4 229 743"
,"1 2 519 898","3 1 863 955","4 0 407 993"
,"2 4 872 969","0 3 320 663"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 298.18759041416865; verify_case(5, Arg2, minimumRange(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"152 998","656 487","75 999","913 535"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 0 347 530","0 3 75 819","3 1 893 935"
,"1 0 971 992","2 0 471 887","2 0 924 955"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 358.8652253980556; verify_case(6, Arg2, minimumRange(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    AirlineInternet ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
