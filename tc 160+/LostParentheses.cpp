#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

vector<int> num;
vector<bool> isPlus;
int minVal[50][50], maxVal[50][50];
class LostParentheses {
	public:
	int minResult(string e) {
		num.clear();
		isPlus.clear();

		bool inNum = 0;
		int val = 0;
		for (int i=0; i<(int)e.size(); ++i)
			if (inNum) {
				if (isdigit(e[i])) {
					val = val*10 + e[i]-'0';
				} else {
					inNum = false;
					num.push_back(val);
					val = 0;
					isPlus.push_back(e[i] == '+');
				}
			} else {
				if (isdigit(e[i])) {
					val = e[i]-'0';
					inNum = true;
				} else {
					assert(0);
				}
			}
		num.push_back(val);

		/*cerr << e << '\n';
		for (int i=0; i<(int)num.size(); ++i)
			cerr << num[i] << ' ';
		cerr << '\n';
		for (int i=0; i<(int)isPlus.size(); ++i)
			cerr << (isPlus[i] ? '+' : '-');
		cerr << '\n';*/

		int n = num.size();
		for (int i=0; i<n; ++i)
			minVal[i][i] = maxVal[i][i] = num[i];

		for (int l=1; l<n; ++l)
			for (int i=0; i+l<n; ++i) {
				minVal[i][i+l] = 1234567890;
				maxVal[i][i+l] = -1234567890;
				for (int k=0; k<l; ++k) {
					minVal[i][i+l] = min(minVal[i][i+l], isPlus[i+k] ? minVal[i][i+k]+minVal[i+k+1][i+l] : minVal[i][i+k]-maxVal[i+k+1][i+l]);
					maxVal[i][i+l] = max(maxVal[i][i+l], isPlus[i+k] ? maxVal[i][i+k]+maxVal[i+k+1][i+l] : maxVal[i][i+k]-minVal[i+k+1][i+l]);
				}
			}

		return minVal[0][n-1];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "55-50+40"; int Arg1 = -35; verify_case(0, Arg1, minResult(Arg0)); }
	void test_case_1() { string Arg0 = "10+20+30+40"; int Arg1 = 100; verify_case(1, Arg1, minResult(Arg0)); }
	void test_case_2() { string Arg0 = "00009-00009"; int Arg1 = 0; verify_case(2, Arg1, minResult(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LostParentheses ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
