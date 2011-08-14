#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int n;
class BinaryCode {
	public:
	inline int get(string &s, int i) {
		return (i>=n || i<0) ? 0:s[i]-'0';
	}
	vector <string> decode(string message) {
		n = (int)message.size();

		vector<string> sol(2, "");
		sol[0] += '0';
		sol[1] += '1';
		for (int t=0; t<2; ++t) {
			string &s = sol[t];
			for (int i=0; i<n-1; ++i)
				s += message[i]-get(s, i)-get(s, i-1);
			if (message[n-1] != s[n-1]+get(s, n-2)) {
				s = "NONE";
				continue;
			}
			for (int i=0; i<(int)s.size(); ++i)
				if (s[i]>'1' || s[i]<'0') {
					s = "NONE";
					break;
				}
		}
		return sol;
	}







// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "123210122"; string Arr1[] = { "011100011",  "NONE" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, decode(Arg0)); }
	void test_case_1() { string Arg0 = "11"; string Arr1[] = { "01",  "10" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, decode(Arg0)); }
	void test_case_2() { string Arg0 = "22111"; string Arr1[] = { "NONE",  "11001" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, decode(Arg0)); }
	void test_case_3() { string Arg0 = "123210120"; string Arr1[] = { "NONE",  "NONE" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, decode(Arg0)); }
	void test_case_4() { string Arg0 = "3"; string Arr1[] = { "NONE",  "NONE" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, decode(Arg0)); }
	void test_case_5() { string Arg0 = "12221112222221112221111111112221111"; string Arr1[] = { "01101001101101001101001001001101001",  "10110010110110010110010010010110010" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, decode(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BinaryCode ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
