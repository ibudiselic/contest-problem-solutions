#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

inline long long f(int x, int m) {
    return (x%m + m) % m; // handles negative x
}

inline long long calc(int x, int y, int m) {
    return f(x, m)*m + f(y, m);
}
class NCool {
	public:
	int nCoolPoints(vector <int> x, vector <int> y, int N) {
		vector<int> hull;
        int p = 0;
        int n = x.size();
        for (int i=1; i<n; ++i) {
            if (x[i]<x[p] || x[i]==x[p] && y[i]<y[p]) {
                p = i;
            }
        }

        hull.push_back(p);
        int q = p;
        do {
            int r = -1;
            int dxx = 0;
            int dyy = 0;
            for (int i=0; i<n; ++i) {
                int dx = x[i] - x[q];
                int dy = y[i] - y[q];
                if (dx==0 && dy==0) {
                    continue;
                }

                if (r==-1 || dx*dyy - dy*dxx > 0 || dx*dyy - dy*dxx == 0 && dx*dx + dy*dy > dxx*dxx + dyy*dyy) {
                    r = i;
                    dxx = dx;
                    dyy = dy;
                }
            }

            assert(r != -1);
            q = r;
            hull.push_back(q);
        } while (q != p);

        assert(hull[0] == hull.back());

        vector<double> X;
        vector<double> Y;
        for (int xx=0; xx<=10000; ++xx) {
            vector<double> ys;
            for (int i=1; i<(int)hull.size(); ++i) {
                int x1 = x[hull[i-1]];
                int x2 = x[hull[i]];
                int y1 = y[hull[i-1]];
                int y2 = y[hull[i]];


                if (!(min(x1, x2)<=xx && xx<=max(x1, x2))) {
                    continue;
                }

                if (x1 == x2) {
                    ys.push_back(y1);
                    ys.push_back(y2);
                } else {
                    ys.push_back(y1 + (y2-y1)*double(xx-x1)/(x2-x1));
                }
            }
            if (ys.size() == 0) {
                continue;
            }
            sort(ys.begin(), ys.end());
            int y1 = (int)ceil(ys[0] - 1e-9);
            int y2 = (int)floor(ys.back() + 1e-9);
            for (int yy=y1; yy<=y2; ++yy) {
                X.push_back(xx);
                Y.push_back(yy);
            }
        }

        map<long long, int> M;
        for (int i=0; i<(int)X.size(); ++i) {
            ++M[calc(int(X[i]+1e-9), int(Y[i]+1e-9), N-1)];
        }

        int sol = 0;
        for (map<long long, int>::const_iterator it=M.begin(); it!=M.end(); ++it) {
            if (it->second > 1) {
                sol += it->second;
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 1, 2, 7, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 1, 6, 1, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = 21; verify_case(0, Arg3, nCoolPoints(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0, 1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 3; verify_case(1, Arg3, nCoolPoints(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0, 0, 1, 2, 2, 1, 0, 0, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 2, 1, 0, 0, 0, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 6; verify_case(2, Arg3, nCoolPoints(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 2, 0, 2, 0, 2, 0, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 4; verify_case(3, Arg3, nCoolPoints(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 2, 0, 2, 0, 2, 0, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 10; verify_case(4, Arg3, nCoolPoints(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NCool ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
