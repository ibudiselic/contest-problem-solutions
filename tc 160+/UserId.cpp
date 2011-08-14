#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <cassert>

using namespace std;

string method1(const string &first, const string &middle, const string &last) {
	string ret;
	ret += first[0];
	ret += last.substr(0, 7);
	return ret;
}
string method2(const string &first, const string &middle, const string &last) {
	if (middle.size()==0)
		return "InVaLiD";

	string ret;
	ret += first[0];
	ret += middle[0];
	ret += last.substr(0, 6);
	return ret;
}
string method3(const string &first, const string &middle, const string &last, const vector<string> &used) {
	string ret;
	ret += first[0];
	ret += last.substr(0, 5);
	char buff[3];
	for (int i=1; ; ++i) {
		sprintf(buff, "%02d", i);
		if (find(used.begin(), used.end(), ret+buff)==used.end())
			return ret+buff;
	}
	return "InVaLiD";
}

bool cnt_ok(const string &s) {
	int cnt=0;
	for (string::size_type i=0; i<s.size(); ++i)
		cnt += isalpha(s[i]);
	return cnt>1;
}
bool chars_ok(const string &s) {
	for (string::size_type i=0; i<s.size(); ++i)
		if (!(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z' || s[i]=='\'' || s[i]==' '))
			return false;
	return true;
}
string normalize(const string& s) {
	string ret;

	for (string::size_type i=0; i<s.size(); ++i)
		if (isalpha(s[i]))
			ret += tolower(s[i]);
	return ret;
}

class UserId {
	public:
	string id(vector <string> used, string first, string middle, string last) {
		if (!chars_ok(first) || !chars_ok(middle) || !chars_ok(last) || !cnt_ok(first) || !cnt_ok(last))
			return "BAD DATA";

		first = normalize(first);
		middle = normalize(middle);
		last = normalize(last);

		string sol = method1(first, middle, last);
		if (find(used.begin(), used.end(), sol)!=used.end()) {
			sol = method2(first, middle, last);
			if (sol == "InVaLiD" || find(used.begin(), used.end(), sol)!=used.end()) {
				sol = method3(first, middle, last, used);
				assert(find(used.begin(), used.end(), sol)==used.end());
			}
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"bjones","bjones03","bmjones","old34id"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bob"; string Arg2 = ""; string Arg3 = "Jones"; string Arg4 = "bjones01"; verify_case(0, Arg4, id(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"bjones","bjones03","bmjones","old34id"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 =  "Bob Mack"; string Arg2 = "Hertobise"; string Arg3 = "Jone's" ; string Arg4 = "bhjones"; verify_case(1, Arg4, id(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"bjonesto","bjones01","bjonesto","old34id"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BoB-Mack"; string Arg2 = "Mo"; string Arg3 = "Jonestone" ; string Arg4 = "BAD DATA"; verify_case(2, Arg4, id(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"momorris","mmmm","momorr01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "'m m"; string Arg2 = ""; string Arg3 = "O'Morrisy"; string Arg4 = "momorr02"; verify_case(3, Arg4, id(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "'m m"; string Arg2 = "J.J"; string Arg3 = "O'Morrisy"; string Arg4 = "BAD DATA"; verify_case(4, Arg4, id(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    UserId ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
