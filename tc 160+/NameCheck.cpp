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

bool name(const string &s) {
	for (int i=0; i<(int)s.size(); ++i)
		if (!isalpha(s[i]))
			return false;
	return s.size() > 1;
}
bool initial(const string &s) {
	if (s.size()!=2 || !isalpha(s[0]) || s[1]!='.') return false;
	return true;
}
bool well_formed(const string &s) {
	istringstream is(s);
	int cnt = 0;
	string t;
	while (is >> t) {
		if (!name(t) && !initial(t)) return false;
		++cnt;
	}
	if (cnt!=2 && cnt!=3) return false;
	if (s[0]==' ' || s[s.size()-1]==' ') return false;
	if (s[s.size()-1] == '.') return false;
	return true;
}

class NameCheck {
	public:
	vector <string> formatList(vector <string> namelist) {
		vector<string> sol;
		for (int i=0; i<(int)namelist.size(); ++i) {
			if (well_formed(namelist[i])) {
				string s, w;
				istringstream is(namelist[i]);
				while (is >> w) {
					w[0] = toupper(w[0]);
					for (int i=1; i<(int)w.size(); ++i)
						w[i] = tolower(w[i]);
					s += w + ' ';
				}
				sol.push_back(s.substr(0, s.size()-1));
			}
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"Doug#as good","bArneY R.", "bArneY   Rubble"," Bob Stone", "Bob B. J. Toms","J. Lo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Barney Rubble",  "J. Lo" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, formatList(Arg0)); }
	void test_case_1() { string Arr0[] = {"Doug G.","GG WALNUT DOUG", "AB. JONES", "A. BOB J.", "Gg DouG", "GG DOUG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Gg Walnut Doug",  "Gg Doug",  "Gg Doug" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, formatList(Arg0)); }
	void test_case_2() { string Arr0[] = {"A BIG Mess", "A. Big Mess.Mess", "ABig","M.MESS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, formatList(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    NameCheck ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
