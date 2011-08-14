#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool is_square[10001];
int win[10001], lose[10001];

string to_str(int x) {
	ostringstream os;
	os << x;
	return os.str();
}
class PowerGame {
	public:
	string winner(int size0, int size1) {
		for (int i=1; i*i<=10000; ++i) {
			is_square[i*i] = 1;
		}

		win[0] = 0;
		win[1] = 1;
		lose[0] = 0;
		lose[1] = 1234567890;
		for (int x=2; x<=10000; ++x) {
			if (is_square[x]) {
				win[x] = 1;
				lose[x] = 1234567890;
			} else {
				win[x] = 1234567890;
				lose[x] = 0;
				for (int t=1; t*t<x; ++t) {
					win[x] = min(win[x], lose[x-t*t]+1);
					lose[x] = max(lose[x], min(1234567890, win[x-t*t]+1));
				}
			}
		}
			
		if (win[size0]<1234567890 && win[size1]<1234567890) {
			return "Alan will win after " + to_str(min(win[size0], win[size1])) + " moves";
		} else if (win[size0] == 1234567890) {
			if (win[size1] < lose[size0]) {
				return "Alan will win after " + to_str(win[size1]) + " moves";
			} else {
				return "Bob will win after " + to_str(lose[size0]) + " moves";
			}
		} else {
			if (win[size0] < lose[size1]) {
				return "Alan will win after " + to_str(win[size0]) + " moves";
			} else {
				return "Bob will win after " + to_str(lose[size1]) + " moves";
			}
		}
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 9; string Arg2 = "Alan will win after 1 moves"; verify_case(0, Arg2, winner(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 3; string Arg2 = "Alan will win after 1 moves"; verify_case(1, Arg2, winner(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; string Arg2 = "Bob will win after 2 moves"; verify_case(2, Arg2, winner(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 13; string Arg2 = "Bob will win after 4 moves"; verify_case(3, Arg2, winner(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 2136; int Arg1 = 1244; string Arg2 = "Alan will win after 7 moves"; verify_case(4, Arg2, winner(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PowerGame ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
