#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int d[] = {0, 1, 4, 9};
class SquareDigitNumbers {
	public:
	int getNumber(int n) {
		vector<int> num(1, 0);

        while (n--) {
            for (int i=0; i<(int)num.size(); ++i) {
                if (num[i] < 3) {
                    ++num[i];
                    break;
                } else {
                    num[i] = 0;
                }
            }
            if (num.back() == 0) {
                num.push_back(1);
            }
        }

        int sol = 0;
        while (num.size() > 0) {
            sol = sol*10 + d[num.back()];
            num.pop_back();
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 0; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 11; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { int Arg0 = 16; int Arg1 = 100; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { int Arg0 = 121; int Arg1 = 1941; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { int Arg0 = 123; int Arg1 = 1949; verify_case(4, Arg1, getNumber(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SquareDigitNumbers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
