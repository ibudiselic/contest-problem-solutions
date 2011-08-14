#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int mnth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string valid(const string &s) {
	if (s.size() != 10)
		return "NO";

	int yy, mm, dd, cs;
	sscanf(s.c_str(), "%2d%2d%2d%4d", &yy, &mm, &dd, &cs);

	if (mm<1 || (mm>12 && (mm<51 || mm>62)))
		return "NO";

	int leap = 0;
	if (yy < 7)
		yy += 2000;
	else
		yy += 1900;

	if (yy%400==0 || yy%100!=0 && yy%4==0)
		leap = 1;

	if (mm >= 51)
		mm -= 50;

	if (dd<1 || dd>mnth[mm]+(mm==2)*leap)
		return "NO";

	long long n;
	istringstream is(s);
	is >> n;

	if (n%11 != 0)
		return "NO";

	return "YES";
}
class BirthNumbersValidator {
	public:
	vector <string> validate(vector <string> test) {
		for (int i=0; i<(int)test.size(); ++i)
			test[i] = valid(test[i]);

		return test;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"8104121234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YES" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, validate(Arg0)); }
	void test_case_1() { string Arr0[] = {"8154121239"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YES" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, validate(Arg0)); }
	void test_case_2() { string Arr0[] = {"8134120005"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NO" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, validate(Arg0)); }
	void test_case_3() { string Arr0[] = {"8102310007","8104121235"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NO", "NO" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, validate(Arg0)); }
	void test_case_4() { string Arr0[] = {"0411131237"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YES" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, validate(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BirthNumbersValidator ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
