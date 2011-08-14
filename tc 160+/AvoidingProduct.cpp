#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool X[1000000];
int my_abs(int x) {
    return x>0 ? x : -x;
}
class AvoidingProduct {
	public:
	vector <int> getTriple(vector <int> a, int n) {
		memset(X, 0, sizeof X);
        for (int i=0; i<(int)a.size(); ++i) {
            X[a[i]] = true;
        }

        int dist = 500000;
        vector<int> sol(3);
        for (int x=1; x<=n+dist; ++x) {
            if (X[x]) {
                continue;
            }
            cerr << x << '\n';
            for (int y=x; y<=(n+dist)/x; ++y) {
                if (X[y]) {
                    continue;
                }
                for (int z=y; z<=(n+dist)/(x*y); ++z) {
                    if (X[z]) {
                        continue;
                    }
                    if (my_abs(n-x*y*z) < dist) {
                        dist = my_abs(n-x*y*z);
                        sol[0] = x;
                        sol[1] = y;
                        sol[2] = z;
                    }
                }
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arr2[] = {1, 1, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getTriple(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arr2[] = {2, 2, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getTriple(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arr2[] = {3, 3, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getTriple(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arr2[] = {2, 2, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getTriple(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; int Arr2[] = {2, 2, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getTriple(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 90; int Arr2[] = {2, 5, 9 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, getTriple(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    AvoidingProduct ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
