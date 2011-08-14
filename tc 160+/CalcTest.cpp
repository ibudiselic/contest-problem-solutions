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

vector<string> cutUp(const string &s, const string &delim=" ") {
	int lastPos = 0, pos = 0;
	vector<string> ret;

	while (pos+delim.size() <= s.size()) {
		if (s.substr(pos, delim.size()) == delim) {
			ret.push_back(s.substr(lastPos, pos-lastPos));

			pos += (int)delim.size()-1;
			lastPos = pos+1;
		}
		++pos;
	}

	if (lastPos < (int)s.size())
		ret.push_back(s.substr(lastPos));

	return ret;
}
class CalcTest {
	public:
	vector <string> uniform(vector <string> numbers) {
		for (int i=0; i<(int)numbers.size(); ++i) {
			vector<string> t = cutUp(numbers[i]);
			numbers[i] = t[0];
			for (int j=1; j<(int)t.size(); ++j)
				numbers[i] += t[j];
		}
		for (int i=0; i<(int)numbers.size(); ++i)
			for (int j=0; j<(int)numbers[i].size(); ++j)
				if (!isdigit(numbers[i][j]))
					numbers[i][j] = '.';

		return numbers;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"1.5", "2$ 3", "12 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1.5", "2.3", "123" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, uniform(Arg0)); }
	void test_case_1() { string Arr0[] = {",5", "3,", ".5", "3.", "000,000", "000 000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".5", "3.", ".5", "3.", "000.000", "000000" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, uniform(Arg0)); }
	void test_case_2() { string Arr0[] = {"263C45233 ", " 2364A56", "B273664"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"263.45233", "2364.56", ".273664" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, uniform(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CalcTest ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
