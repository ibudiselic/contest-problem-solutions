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

double D[50][50];
int n;

double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
struct S {
    int a, b;
    double l;
    S(int a_, int b_, double l_): a(a_), b(b_), l(l_) {}
};
class WalkingDistance {
	public:
	double getLongestShortest(vector <int> x, vector <int> y, vector <string> streets) {
		n = x.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                D[i][j] = 1e20;
            }
        }
        vector<S> v;
        for (int i=0; i<n; ++i) {
            D[i][i] = 0.0;
            for (int j=i+1; j<n; ++j) {
                if (streets[i][j] == 'Y') {
                    v.push_back(S(i, j, dist(x[i], y[i], x[j], y[j])));
                    D[i][j] = D[j][i] = v.back().l;
                }
            }
        }

        for (int k=0; k<n; ++k) {
            for (int i=0; i<n; ++i) {
                if (D[i][k] < 1e15) {
                    for (int j=0; j<n; ++j) {
                        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                    }
                }
            }
        }

        double sol = 0.0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                sol = max(sol, D[i][j]);
            }
        }
        for (int i=0; i<(int)v.size(); ++i) {
            const int a = v[i].a;
            const int b = v[i].b;
            for (int j=i+1; j<(int)v.size(); ++j) {
                const int c = v[j].a;
                const int d = v[j].b;
                sol = max(sol, min(v[i].l + D[a][c] + v[j].l + D[d][b], v[i].l + D[a][d] + v[j].l + D[c][b])/2);
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NY","YN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 1.4142135623730951; verify_case(0, Arg3, getLongestShortest(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,2,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NNYY","NNYY","YYNN","YYNN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 4.82842712474619; verify_case(1, Arg3, getLongestShortest(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NYY","YNY", "YYN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 1.7071067811865475; verify_case(2, Arg3, getLongestShortest(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NYY", "YNN", "YNN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 4.242640687119286; verify_case(3, Arg3, getLongestShortest(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    WalkingDistance ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
