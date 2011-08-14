#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> pass;
string sol;
string C;
char charVal(int x) {
	if (x == 0)
		return ' ';
	else
		return 'a' + (x-1);
}
int intVal(char c) {
	if (c == ' ')
		return 0;
	else
		return c-'a'+1;
}
string vowels = "aeiou";
bool hasVowel(const string &s) {
	for (int i=0; i<(int)s.size(); ++i)
		if (vowels.find(s[i]) != string::npos)
			return true;
	return false;
}
bool check(int last) {
	for (int i=1; i<last; ++i)
		if (sol[i]==' ' && sol[i-1]==' ')
			return false;

	string w;
	string t = sol.substr(0, last);
	if (last != (int)sol.size())
		t = t.substr(0, t.size()-1);

	istringstream is(t);
	while (is >> w)
		if (!(w.size()>=2 && w.size()<=8 && hasVowel(w)))
			return false;

	return true;
}
bool canMatch(int pos) {
	if (pos == (int)C.size())
		return check(C.size());

	if (pos>0 && sol[pos-1]==' ' && !check(pos))
		return false;
	for (int v=((pos==0 || pos==(int)sol.size()-1) ? 1: 0); v<27; ++v) {
		char t = charVal((v+pass[pos%3])%27);
		if (t == C[pos]) {
			sol[pos] = charVal(v);
			if (canMatch(pos+1))
				return true;
		}
	}
	return false;
}
bool go(int pos) {
	if (pos == 3)
		return canMatch(0);

	for (int i=1; i<27; ++i) {
		pass[pos] = i;
		if (go(pos+1))
			return true;
	}

	return false;
}
class SimpleRotationDecoder {
	public:
	string decode(string cipherText) {
		pass.assign(3, 0);
		C = cipherText;
		sol.assign(C.size(), ' ');

		go(0);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "mmbtvrbhhtgohaktklqegnrmlelojotyeyeiudvtil ey ffg"; string Arg1 = "the quick brown fox jumps over the lazy dog again"; verify_case(0, Arg1, decode(Arg0)); }
	void test_case_1() { string Arg0 = "ntgntgntgntofwlfwlfwlnookookook"; string Arg1 = "he he he heh he he heh he he he"; verify_case(1, Arg1, decode(Arg0)); }
	void test_case_2() { string Arg0 = "f sgnzslhzquq ydyuinmqiwfyrtdvn"; string Arg1 = "abkbprnn usmlbqz mdpelkoa jofni"; verify_case(2, Arg1, decode(Arg0)); }
	void test_case_3() { string Arg0 = "shxnaaeqjlofhhsuurbhpdgt z"; string Arg1 = "naeiui jrghnca pnzxaxz avs"; verify_case(3, Arg1, decode(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SimpleRotationDecoder ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
