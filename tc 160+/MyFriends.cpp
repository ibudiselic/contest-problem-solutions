#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class MyFriends {
	public:
	string calcFriends(vector <int> F, int k) {
		int SF = 0;
        int n = F.size();
        for (int i=0; i<n; ++i) {
            SF += F[i];
        }

        if (SF % (n-2) != 0) {
            return "IMPOSSIBLE";
        }

        int S = SF / (n-2);

        vector<int> f(n, -1);
        for (int i=0; i<n; ++i) {
            int j = i;
            int val = 0;
            int sign = 1;
            do {
                val += sign * (S-F[j]);
                sign *= -1;
                j = (j+k) % n;
            } while (j != i);

            if (val<0 || val>2*(n-1)) {
                return "IMPOSSIBLE";
            }
            if (val & 1) {
                return "IMPOSSIBLE";
            }
            f[i] = val / 2;
        }

        for (int i=0; i<n; ++i) {
            if (S-F[i] != f[i] + f[(i+k) % n]) {
                return "IMPOSSIBLE";
            }
        }

        for (int i=0; i<n; ++i) {
            sort(f.begin(), f.end());
            int x = f.back();
            f.pop_back();
            if (x<0 || x>(int)f.size()) {
                return "IMPOSSIBLE";
            }
            for (int j=0; j<x; ++j) {
                --f[(int)f.size()-1-j];
            }
        }
        
        return "POSSIBLE";
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {8, 9, 8, 8, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "POSSIBLE"; verify_case(0, Arg2, calcFriends(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {7, 6, 5, 4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "IMPOSSIBLE"; verify_case(1, Arg2, calcFriends(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5, 6, 5, 4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arg2 = "POSSIBLE"; verify_case(2, Arg2, calcFriends(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arg2 = "IMPOSSIBLE"; verify_case(3, Arg2, calcFriends(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MyFriends ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
