#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class OnTheFarmDivTwo {
	public:
	vector <int> animals(int heads, int legs) {
		if (legs & 1) {
            return vector<int>();
        }
        for (int cows=0; 4*cows<=legs; ++cows) {
            int chicks = (legs-4*cows)/2;
            if (cows + chicks == heads) {
                int sol[] = {chicks, cows};
                return vector<int>(sol, sol+2);
            }
        }
        return vector<int>();
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 8; int Arr2[] = {2, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, animals(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 40; int Arr2[] = {0, 10 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, animals(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 42; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, animals(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 3; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, animals(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 0; int Arg1 = 0; int Arr2[] = {0, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, animals(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    OnTheFarmDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
