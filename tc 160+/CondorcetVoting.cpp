#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> V;
bool cmp(int x, int y) {
	int a = 0;
	int b = 0;
	for (int i=0; i<(int)V.size(); ++i) {
		if (V[i][x] < V[i][y]) {
			++a;
		} else if (V[i][x] == V[i][y]) {
			++a;
			++b;
		} else {
			++b;
		}
	}
	if (a != b) {
		return a > b;
	}
	return x < y;
}
bool diff(int x, int y) {
	int a = 0;
	int b = 0;
	for (int i=0; i<(int)V.size(); ++i) {
		if (V[i][x] < V[i][y]) {
			++a;
		} else if (V[i][x] == V[i][y]) {
			++a;
			++b;
		} else {
			++b;
		}
	}
	return a != b;
}

class CondorcetVoting {
	public:
	int winner(vector <string> votes) {
		V = votes;

		vector<int> t;
		for (int i=0; i<(int)V[0].size(); ++i) {
			t.push_back(i);
		}
		if (t.size() == 1) {
			return 0;
		}

		sort(t.begin(), t.end(), cmp);
		for (int i=1; i<(int)t.size(); ++i) {
			if (!diff(t[i], t[0]) || cmp(t[i], t[0])) {
				return -1;
			}
		}
		return t[0];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"acbd",
 "bacd",
 "bdca"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, winner(Arg0)); }
	void test_case_1() { string Arr0[] = {"abc", 
 "bca", 
 "cab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, winner(Arg0)); }
	void test_case_2() { string Arr0[] = {"cezdqcw"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, winner(Arg0)); }
	void test_case_3() { string Arr0[] = {"abcd", "abcd", "abcd", "abcd", "abcd", "abcd",
 "cbad", "cbad", "cbad", "cbad", "cbad",
 "dbca", "cbda", "cbda"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, winner(Arg0)); }
	void test_case_4() { string Arr0[] = {"abbcbbbaaccaaccbbacbbbaacbccbccacaaacaacaaacbccaac",
 "accbabcaacacbcccbbccbbcaccccccbbcbbcbaccbcbcacbcbc",
 "acacaaabccaaaccabbaaaacabaaabacacbaacbcccbccbcbacb",
 "acbcbabaabbcaababaacbabcacbaccabbaaacccbcabbbcacba",
 "cbbbacbbacccbbabbbcbaabaaaacaacbcbccbaaccbcaaccbcb",
 "cbacbbcbbcbcaaabccabcabbcbacaaabccabbcbacbbacbbaca",
 "cacaabccbbbaaacccacbbcacababbcaaabccbbacbbbccacbaa",
 "bccbbabaaaababcbabbbbcbcacbcbcbacccacacacacacacaab",
 "bccabcaabcabbccaaccbcabaaabbbcaabaaabbbbabbbaabaac",
 "accccbabaaaabcbacabbcbbacaacaaaacccbbbcacaccccaaac",
 "cccbcaababbaacaaabbbaabbccccacaacbacaacbbbaacccbbb",
 "bccccaccbcbbaaaaaaaaccbababcabaaccacbbabbbcabbaaca",
 "cbacacaabbccacaabbbbbbccabcbbaccacbcacacacbccbcbcc",
 "baabcabccaaaaccbaacaaccacccbcbbaaacacaccbcaacbbbba",
 "bccaaaabcbbcbbbbbcaabaacccbccbbcbabacaaccbccaababb",
 "cacbbbbcabbcbaabbccbaccbaacbbcbbbbcabababccabbbcab",
 "bccbcacbccaacacccccaacabacbacbbbcaabacacccbbbccaac",
 "aaaccbbbacacbaaaacacaabbaacccbcccbcabbccbcacabbacb",
 "bcabcbbacbacacbbaaccabcabcbbaabacacccbbbcabbbcaacb",
 "bacbbbbaccbaabbbbbcaccbbcbcabbbccbcacccbabbbcaaacc",
 "bababcacbacacacccccbbcacccbbcbccaccaacbbcacabcabba",
 "aaabaccbbcacaacbabccccabbbcbcccccccbaacbccbaacbbbc",
 "abacbaaaaaccacbbbaccbbbabaacbcbccacccabaaaacbaabbb",
 "cbbcacbaccabbbcaacbcbabbcabcbaccabcbbbcabcbcbaacca",
 "babbacaaacbbcbbbabbaabcbabcbbaacaacbbbaaaabbcabcca",
 "cbabaacabcccaabbbacccaccbacabbaacaaabcbcccbcbcccaa",
 "aabbbcbacabbcabcbcccbccaccbcacbaacabbbccaabaabcbba",
 "caccabcccabbaacbabbaaaccccccccaaccbcaccacaabacccba",
 "bbbcabcababaabacaccacabcbccacccbbbbcbbbaccabcabaab",
 "bbbcaababbbbababababcbbbbaaabbacaabcacbbccbcaaaaaa",
 "bcbacccaaaabbcbcabbbcababbcacaabbbbcbbacbaabcbaccb",
 "bbcaccaaccacbbaaccaaaabccbbacbcbacaacbacbccaaccbba",
 "abaaacbccbbabbcaccbaccccbaaacaccccababcbccccbabcca",
 "acccaccababababacbbaccbcabcaccbabaabacbaacaaacabca",
 "aaabababccabccbcbabcabcacbbcacbcbbbabcabacbcaacacb",
 "ccacbaabbcbaccaccbbabbabbabaacccabcaaccacacccbbcab",
 "bbaabcbabbbaacacabaabcbaaabacbccccaccaaaacbacabbbc",
 "abaaaccaacbbcacacbcbccbaaacbbcbacabbbccabbbccaaaac",
 "bbacbabbcacbbacccaccbcbcabbcbaacabbbbabbaaabaacacb",
 "cacbacbccbcbabacccacabcacacabbcabbccaacacbaaacaacb",
 "bacbbacbccccabcbabcbbcbacacaaabcbaccccaabaabbacbcb",
 "abcaaccccabccaaaaccbabccacbcaaaacaccaccccccaaaabaa",
 "bacabcbccbacccbaaaabcbbaabbabaabcabacccbcabacccbcc",
 "babaccbbcbcbacccabccbcccbaaaaacccabcbccbbbbcbabcbc",
 "cccbbaccbabbbbcbcbcbaaacbbcacbcaacacacccbcabccbcaa",
 "caacbcacbccaaaaacaaababbcccacbabaaabcaacaaababacba",
 "cccccaccabcaacababbacbcbabbcaacbacbabbbccbabcbabbb",
 "ccbcababcabcbcccaccccacabcbaaacaabccbbaabaccbaccab",
 "abbbcacaccabcbccbacabbbccaccaaaacccabbcbacbbccabcb",
 "bacabccabcbbcaacbcacabcbccacbcccbcbcaaaabbaabccabb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(4, Arg1, winner(Arg0)); }
	void test_case_5() { string Arr0[] = {"h", "e", "l", "l", "o"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, winner(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CondorcetVoting ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
