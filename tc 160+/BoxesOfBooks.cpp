#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class BoxesOfBooks {
	public:
	int boxes(vector <int> weight, int maxWeight) {
		reverse(weight.begin(), weight.end());

        int cur = 0;
        int sol = 0;
        while (weight.size() > 0) {
            if (cur + weight.back() > maxWeight) {
                cur = weight.back();
                ++sol;
            } else {
                cur += weight.back();
            }
            weight.pop_back();
        }

        return sol + (cur > 0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 5, 5, 5, 5, 5, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 3; verify_case(0, Arg2, boxes(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = { 51, 51, 51, 51, 51 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 5; verify_case(1, Arg2, boxes(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = { 1, 1, 1, 7, 7, 7 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 4; verify_case(2, Arg2, boxes(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = { 12, 1, 11, 2, 10, 3, 4, 5, 6, 6, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 6; verify_case(3, Arg2, boxes(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = { }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 0; verify_case(4, Arg2, boxes(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = { 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
  20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
  20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
  20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
  20, 20, 20, 20, 20, 20, 20, 20, 20, 20 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 1; verify_case(5, Arg2, boxes(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BoxesOfBooks ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
