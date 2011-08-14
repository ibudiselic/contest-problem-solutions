#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int leftmost[26], rightmost[26];
bool valid(int c, int n) {
	return leftmost[c]>=0 && leftmost[c]<n;
}
vector<int> make_sol(int x, int y) {
	vector<int> ret;
	ret.push_back(x);
	ret.push_back(y);
	return ret;
}
class LetterInterchange {
	public:
	vector <int> interchangeWhich(vector <string> s1, vector <string> s2) {
		string s;
		for (int i=0; i<(int)s1.size(); ++i)
			s += s1[i];
		for (int i=0; i<(int)s2.size(); ++i)
			s += s2[i];

		memset(leftmost, 0x3f, sizeof leftmost);
		memset(rightmost, 0xff, sizeof rightmost);
		int n = s.size();
		for (int i=0; i<n; ++i) {
			leftmost[s[i]-'a'] = min(leftmost[s[i]-'a'], i);
			rightmost[s[i]-'a'] = max(rightmost[s[i]-'a'], i);
		}

		// try to make it better
		for (int i=0; i<26; ++i)
			if (valid(i, n)) {
				int left = 1234567890;
				for (int j=25; j>i; --j)
					if (valid(j, n))
						left = min(left, leftmost[j]);
				if (left < rightmost[i])
					return make_sol(left, rightmost[i]);
			}

		// can't make it better
		// don't make it any worse
		vector<bool> done(26, 0);
		for (int i=0; i+1<n; ++i)
			if (!done[s[i]-'a']) {
				done[s[i]-'a'] = true;
				string::size_type pos = s.substr(i+1).find(s[i]);
				if (pos != string::npos)
					return make_sol(i, (int)pos+i+1);
			}

		// must make it worse - it is definitely sorted and there are no repeating elements so just take the last two
		return make_sol(n-2, n-1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"a", "b", "a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"c", "a", "b", "a"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, interchangeWhich(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"aa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"bb"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, interchangeWhich(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"b", "c"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, interchangeWhich(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"a", "b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"cb"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, interchangeWhich(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
 "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
 "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
 "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
 "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
 "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
 "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
 "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbccccccc",
 "cccccccccccccccccccccccccccccccccccccccccccccccccc",
 "cccccccccccccccccccccccccccccccccccccccccccccccccc",
 "cccccccccccccccccccccccccccccccccccccccccccccccccc",
 "cccccccccccccccccccccccccccccccccccccccccccccccccc",
 "cccccccccccccccccccccccccccccccccccccccccccccccccc",
 "cccccccccccccccccccccccccccccccccccccccccccccccccc",
 "cccccccccccddddddddddddddddddddddddddddddddddddddd",
 "dddddddddddddddddddddddddddddddddddddddddddddddddd",
 "dddddddddddddddddddddddddddddddddddddddddddddddddd",
 "dddddddddddddddddddddddddddddddddddddddddddddddddd",
 "dddddddddddddddddddddddddddddddddddddddddddddddddd",
 "dddddddddddddddddddddddddddddddddddddddddddddddddd",
 "dddddddddddddddddddddddddddddddddddddddddddddddddd",
 "ddddddddddddddddddeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee",
 "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee",
 "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee",
 "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee",
 "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee",
 "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee",
 "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee",
 "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeffffff",
 "ffffffffffffffffffffffffffffffffffffffffffffffffff",
 "ffffffffffffffffffffffffffffffffffffffffffffffffff",
 "ffffffffffffffffffffffffffffffffffffffffffffffffff",
 "ffffffffffffffffffffffffffffffffffffffffffffffffff",
 "ffffffffffffffffffffffffffffffffffffffffffffffffff",
 "ffffffffffffffffffffffffffffffffffffffffffffffffff",
 "ffffffffffffffffffffffffffffffffffffffffffffffffff",
 "fffffffffffffffggggggggggggggggggggggggggggggggggg",
 "gggggggggggggggggggggggggggggggggggggggggggggggggg",
 "gggggggggggggggggggggggggggggggggggggggggggggggggg",
 "gggggggggggggggggggggggggggggggggggggggggggggggggg",
 "gggggggggggggggggggggggggggggggggggggggggggggggggg",
 "gggggggggggggggggggggggggggggggggggggggggggggggggg",
 "gggggggggggggggggggggggggggggggggggggggggggggggggg"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"gggggggggggggggggggggggggggggggggggggggggggggggggg",
 "ghhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh",
 "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh",
 "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh",
 "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh",
 "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh",
 "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh",
 "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhiiiiiiiiiiii",
 "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii",
 "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii",
 "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii",
 "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii",
 "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii",
 "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii",
 "iiiiiiiiiiiiiiiiiiiiiijjjjjjjjjjjjjjjjjjjjjjjjjjjj",
 "jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj",
 "jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj",
 "jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj",
 "jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj",
 "jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj",
 "jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj",
 "jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjkkkkk",
 "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk",
 "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk",
 "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk",
 "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk",
 "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk",
 "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk",
 "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkllll",
 "llllllllllllllllllllllllllllllllllllllllllllllllll",
 "llllllllllllllllllllllllllllllllllllllllllllllllll",
 "llllllllllllllllllllllllllllllllllllllllllllllllll",
 "llllllllllllllllllllllllllllllllllllllllllllllllll",
 "llllllllllllllllllllllllllllllllllllllllllllllllll",
 "llllllllllllllllllllllllllllllllllllllllllllllllll",
 "llllllllllllllllllllllllllllllllllllllllllllllllll",
 "lllllllllllllmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm",
 "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm",
 "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm",
 "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm",
 "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm",
 "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm",
 "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm",
 "mmmmmmmmmmmmmmmmmmmmmmnnnnnnnnnnnnnnnnnnnnnnnnnnnn",
 "nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn",
 "nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn",
 "nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn",
 "nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn",
 "nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn",
 "nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, interchangeWhich(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"aa"}	; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"b", "bcc"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, interchangeWhich(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LetterInterchange ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
