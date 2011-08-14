#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool can_do(int sz, const vector<string> &w, int W, int H) {
	int cw=0, ch=0;
	for (int i=0; i<(int)w.size(); ++i) {
		if (cw == 0) {
			ch += 2*sz;
			if (ch > H) {
				return false;
			}
			assert((sz+2)*w[i].size() <= W);
			cw = (sz+2)*w[i].size();
		} else {
			int add = (sz+2)*(w[i].size() + 1);
			if (cw + add > W) {
				cw = 0;
				--i;
				continue;
			}
			cw += add;
		}
	}
	return true;
}
class StringFragmentation {
	public:
	int largestFontSize(string text, int width, int height) {
		if (height < 16) {
			return -1;
		}
		vector<string> w;
		string s;
		istringstream is(text);
		int max_len = 0;
		while (is >> s) {
			w.push_back(s);
			max_len = max(max_len, (int)s.size());
		}

		int lo = 8;
		int hi = min(height/2, width/max_len - 2);
		if (hi<lo || !can_do(lo, w, width, height)) {
			return -1;
		}

		while (lo < hi) {
			int mid = lo + (hi-lo+1)/2;
			if (can_do(mid, w, width, height)) {
				lo = mid;
			} else {
				hi = mid-1;
			}
		}

		return lo;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ONE TWO THREE FOUR FIVE"; int Arg1 = 150; int Arg2 = 40; int Arg3 = 9; verify_case(0, Arg3, largestFontSize(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "ONE TWO THREE FOUR FIVE"; int Arg1 = 150; int Arg2 = 60; int Arg3 = 10; verify_case(1, Arg3, largestFontSize(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "ONE TWO THREE FOUR FIVE"; int Arg1 = 150; int Arg2 = 10000; int Arg3 = 28; verify_case(2, Arg3, largestFontSize(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "ONE TWO THREE FOUR FIVE"; int Arg1 = 10000; int Arg2 = 10000; int Arg3 = 1250; verify_case(3, Arg3, largestFontSize(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "ONE TWO THREE FOUR FIVE"; int Arg1 = 50; int Arg2 = 50; int Arg3 = -1; verify_case(4, Arg3, largestFontSize(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "A"; int Arg1 = 9; int Arg2 = 14; int Arg3 = -1; verify_case(5, Arg3, largestFontSize(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    StringFragmentation ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
