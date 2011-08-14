#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool test(const string &a) {
	if (a[0]=='0' && a.size()>1)
		return false;

	int x;
	sscanf(a.c_str(), "%d", &x);
	return x>=0 && x<256;
}
void update(const string &ip, int i, int j, int k, vector<string> &sol) {
	const string &a = ip.substr(0, i);
	const string &b = ip.substr(i, j-i);
	const string &c = ip.substr(j, k-j);
	const string &d = ip.substr(k);

	if (test(a) && test(b) && test(c) && test(d))
		sol.push_back(a + '.' + b + '.' + c + '.' + d);
}
class IPConverter {
	public:
	vector <string> possibleAddresses(string ip) {
		vector<string> sol;
		for (int i=1; i<(int)ip.size(); ++i)
			for (int j=i+1; j<(int)ip.size(); ++j)
				for (int k=j+1; k<(int)ip.size(); ++k)
					update(ip, i, j, k, sol);

		sort(sol.begin(), sol.end());
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "1902426"; string Arr1[] = { "1.90.24.26",  "1.90.242.6",  "19.0.24.26",  "19.0.242.6",  "190.2.4.26",  "190.2.42.6",  "190.24.2.6" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, possibleAddresses(Arg0)); }
	void test_case_1() { string Arg0 = "000"; string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, possibleAddresses(Arg0)); }
	void test_case_2() { string Arg0 = ""; string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, possibleAddresses(Arg0)); }
	void test_case_3() { string Arg0 = "0186290"; string Arr1[] = { "0.18.62.90",  "0.186.2.90",  "0.186.29.0" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, possibleAddresses(Arg0)); }
	void test_case_4() { string Arg0 = "11111111"; string Arr1[] = { "1.1.111.111",  "1.11.11.111",  "1.11.111.11",  "1.111.1.111",  "1.111.11.11",  "1.111.111.1",  "11.1.11.111",  "11.1.111.11",  "11.11.1.111",  "11.11.11.11",  "11.11.111.1",  "11.111.1.11",  "11.111.11.1",  "111.1.1.111",  "111.1.11.11",  "111.1.111.1",  "111.11.1.11",  "111.11.11.1",  "111.111.1.1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, possibleAddresses(Arg0)); }
	void test_case_5() { string Arg0 = "3082390871771742784899852251737850570843857369760"; string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, possibleAddresses(Arg0)); }
	void test_case_6() { string Arg0 = "256255255"; string Arr1[] = { "2.56.255.255",  "25.6.255.255",  "25.62.55.255" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(6, Arg1, possibleAddresses(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    IPConverter ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
