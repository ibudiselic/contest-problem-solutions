#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long gcd(long long m, long long n) {
    return m==0 ? n : gcd(n%m, m);
}
long long lcm(long long a, long long b) {
    return a/gcd(a, b)*b;
}

long long T[10][10][2];
int N;
class IngredientProportions {
	public:
	vector <int> getMasses(vector <string> P) {
		memset(T, 0xff, sizeof T);
        N = P.size()+1;

        for (int i=0; i<(int)P.size(); ++i) {
            int a, b, x, y;
            sscanf(P[i].c_str(), "#%d and #%d as %d:%d", &a, &b, &x, &y);
            int d = gcd(x, y);
            x /= d;
            y /= d;
            T[a][b][0] = x;
            T[a][b][1] = y;
            T[b][a][0] = y;
            T[b][a][1] = x;
        }

        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                if (T[i][j][0] != -1) {
                    for (int k=0; k<N; ++k) {
                        if (T[j][k][0] != -1) {
                            long long u = T[i][j][0] * T[j][k][0];
                            long long v = T[i][j][1] * T[j][k][1];
                            long long d = gcd(u, v);
                            u /= d;
                            v /= d;
                            T[i][k][0] = u;
                            T[i][k][1] = v;
                        }
                    }
                }
            }
        }


        vector<long long> t(N, 1);
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                if (T[i][j][0] != -1) {
                    t[i] = lcm(t[i], T[i][j][0]);
                }
            }
        }

        while (1) {
            bool change = false;
            for (int i=0; i<N; ++i) {
                long long val = t[i];
                for (int j=0; j<N; ++j) {
                    if (T[i][j][0] != -1) {
                        val = max(val, T[i][j][0]*t[j]/T[i][j][1]);
                    }
                }
                if (val != t[i]) {
                    change = true;
                }
                t[i] = val;
            }
            if (!change) {
                break;
            }
        }

        return vector<int>(t.begin(), t.end()); 
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"#0 and #1 as 6:4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getMasses(Arg0)); }
	void test_case_1() { string Arr0[] = {"#0 and #1 as 9:8","#1 and #2 as 9:8"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {81, 72, 64 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getMasses(Arg0)); }
	void test_case_2() { string Arr0[] = {"#4 and #0 as 1:1", "#4 and #1 as 3:1", "#4 and #2 as 5:1", "#4 and #3 as 7:1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {105, 35, 21, 15, 105 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getMasses(Arg0)); }
	void test_case_3() { string Arr0[] = {"#2 and #3 as 6:8", "#0 and #1 as 9:3", "#3 and #0 as 7:5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {60, 20, 63, 84 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getMasses(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    IngredientProportions ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
