#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string a[] = { "heck", "gosh", "dang", "shucks" , "fooey", "snafu", "fubar" };
string P, C;

void go(vector<string> &w, int x, string s) {
	if (x == (int)s.size()) {
		w.push_back(s);
		return;
	}
	go(w, x+1, s);
	for (int i=0; i<(int)P.size(); ++i)
		if (P[i] == s[x]) {
			s[x] = C[i];
			go(w, x+1, s);
			s[x] = P[i];
		}
}
class Foobar {
	public:
	string censor(string plain, string code, string text) {
		vector<int> orig;
		string s;
		P = plain;
		C = code;
		for (int i=0; i<(int)text.size(); ++i)
			if (text[i] != ' ') {
				s += text[i];
				orig.push_back(i);
			}

		vector<string> w;
		for (int i=0; i<7; ++i)
			go(w, 0, a[i]);

		sort(w.begin(), w.end());
		w.erase(unique(w.begin(), w.end()), w.end());

		string t = s;
		for (int i=0; i<(int)t.size(); ++i) {
			for (int j=0; j<(int)w.size(); ++j)
				if (i+w[j].size()<=t.size() && s.substr(i, w[j].size())==w[j])
					for (int k=0; k<(int)w[j].size(); ++k)
						t[i+k] = '*';
		}

		string sol(text.size(), ' ');
		for (int i=0; i<(int)orig.size(); ++i) {
			sol[orig[i]] = t[i];
			if (i<(int)orig.size() && t[i]=='*' && t[i+1]=='*')
				for (int j=orig[i]; j<orig[i+1]; ++j)
					sol[j] = '*';
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ogg"; string Arg1 = "08B"; string Arg2 = "I say f00ey on this dan8 problem and the danB set!"; string Arg3 = "I say ***** on this **** problem and the **** set!"; verify_case(0, Arg3, censor(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "eafk"; string Arg1 = "88$$"; string Arg2 = "What the h 8 c $ is this s  n  8  $  u?"; string Arg3 = "What the ******* is this *************?"; verify_case(1, Arg3, censor(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "au"; string Arg1 = "ui"; string Arg2 = "Dung? What the ding do you mean, dung?"; string Arg3 = "Dung? What the ding do you mean, ****?"; verify_case(2, Arg3, censor(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "YYYggggabcdefghijklmnopqrstuvwxyz"; string Arg1 = "XXXggggABCDEFGHIJKLMNOPQRSTUVWXYZ"; string Arg2 = "DANGitALLtoHECK"; string Arg3 = "****itALLto****"; verify_case(3, Arg3, censor(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "ddhhooggss<y}T?h:1+Wd~\\\'\""; string Arg1 = "D*HNO0G&S5Rfubar%f3k<:..."; string Arg2 = "Dangoshucks, I say, * a n & 0 5 H u c k 5."; string Arg3 = "***********, I say, *********************."; verify_case(4, Arg3, censor(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Foobar ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
