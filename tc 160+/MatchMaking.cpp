#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class MatchMaking {
	public:
	int cntMatches(const string &a, const string &b) {
		int ret =0;
		for (int i=0; i<(int)a.size(); ++i)
			ret += (a[i]==b[i]);
		return ret;
	}
	void sorter(vector<string> &a, vector<string> &b) {
		for (int i=0; i<(int)a.size(); ++i)
			for (int j=i+1; j<(int)b.size(); ++j)
				if (a[i] > a[j]) {
					swap(a[i], a[j]);
					swap(b[i], b[j]);
				}
	}
	string makeMatch(vector <string> namesWomen, vector <string> answersWomen, vector <string> namesMen, vector <string> answersMen, string queryWoman) {
		sorter(namesWomen, answersWomen);
		sorter(namesMen, answersMen);

		vector<bool> usedM(namesMen.size(), 0);

		for (int i=0; i<(int)namesWomen.size(); ++i) {
			int best = -1;
			int besti = 0;

			for (int j=0; j<(int)namesMen.size(); ++j)
				if (!usedM[j]) {
					const int t = cntMatches(answersWomen[i], answersMen[j]);
					if (t > best) {
						best = t;
						besti = j;
					}
				}

			usedM[besti] = 1;
			if (namesWomen[i] == queryWoman)
				return namesMen[besti];
		}

		return ":cry";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Constance", "Bertha", "Alice"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"aaba", "baab", "aaaa"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Chip", "Biff", "Abe"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"bbaa", "baaa", "aaab"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Bertha"; string Arg5 = "Biff"; verify_case(0, Arg5, makeMatch(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arr0[] = {"Constance", "Bertha", "Alice"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"aaba", "baab", "aaaa"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Chip", "Biff", "Abe"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"bbaa", "baaa", "aaab"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Constance"; string Arg5 = "Chip"; verify_case(1, Arg5, makeMatch(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arr0[] = {"Constance", "Alice", "Bertha", "Delilah", "Emily"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"baabaa", "ababab", "aaabbb", "bababa", "baabba"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Ed", "Duff", "Chip", "Abe", "Biff"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"aabaab", "babbab", "bbbaaa", "abbbba", "abaaba"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Constance"; string Arg5 = "Duff"; verify_case(2, Arg5, makeMatch(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { string Arr0[] = {"Constance", "Alice", "Bertha", "Delilah", "Emily"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"baabaa", "ababab", "aaabbb", "bababa", "baabba"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Ed", "Duff", "Chip", "Abe", "Biff"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"aabaab", "babbab", "bbbaaa", "abbbba", "abaaba"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Delilah"; string Arg5 = "Chip"; verify_case(3, Arg5, makeMatch(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { string Arr0[] = {"Constance", "Alice", "Bertha", "Delilah", "Emily"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"baabaa", "ababab", "aaabbb", "bababa", "baabba"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Ed", "Duff", "Chip", "Abe", "Biff"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"aabaab", "babbab", "bbbaaa", "abbbba", "abaaba"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Emily"; string Arg5 = "Ed"; verify_case(4, Arg5, makeMatch(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { string Arr0[] = {"anne", "Zoe"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a", "a"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"bob", "chuck"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"a", "a"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Zoe"; string Arg5 = "bob"; verify_case(5, Arg5, makeMatch(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_6() { string Arr0[] = {"F", "M", "S", "h", "q", "g", "r", "N", "U", "x", "H", "P",
 "o", "E", "R", "z", "L", "m", "e", "u", "K", "A", "w", "Q",
 "O", "v", "j", "a", "t", "p", "C", "G", "k", "c", "V", "B",
 "D", "s", "n", "i", "f", "T", "I", "l", "d", "J", "y", "b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"abaabbbb", "bbaabbbb", "aaabaaab", "aabbaaaa", "baabbaab",
 "aaababba", "bbabbbbb", "bbbabbba", "aaabbbba", "aabbbaaa",
 "abbabaaa", "babbabbb", "aaaaabba", "aaaabbaa", "abbbabaa",
 "babababa", "abbaaaaa", "bbababba", "baaaaaba", "baaaaabb",
 "bbbbabba", "ababbaaa", "abbbabab", "baabbbaa", "bbbaabbb",
 "aababbab", "ababbabb", "abbaabba", "baabbabb", "aaabaaab",
 "aabbbaba", "aabaaabb", "abababba", "aabbaaaa", "aabbabaa",
 "bababaaa", "aabaaaab", "bbbbaabb", "baaababb", "abaabbab",
 "aabbbaaa", "baabbaba", "bbabbbaa", "aabbbbaa", "abbbaaab",
 "abababbb", "ababaaba", "bababaaa"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"f", "C", "v", "g", "Q", "z", "n", "c", "B", "o", "M", "F",
 "u", "x", "I", "T", "K", "L", "E", "U", "w", "A", "d", "t",
 "e", "R", "D", "s", "p", "q", "m", "r", "H", "j", "J", "V",
 "l", "a", "k", "h", "G", "y", "i", "P", "O", "N", "b", "S"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"bbbaabab", "bbabaabb", "ababbbbb", "bbbababb", "baababaa",
 "bbaaabab", "abbabbaa", "bbbabbbb", "aabbabab", "abbababa",
 "aababbbb", "bababaab", "aaababbb", "baabbaba", "abaaaaab",
 "bbaababa", "babaabab", "abbabbba", "ababbbab", "baabbbab",
 "babbaaab", "abbbbaba", "bbabbbba", "baaabaab", "ababbabb",
 "abbbaabb", "bbbbaabb", "bbbaaabb", "baabbaba", "bbabaaab",
 "aabbbaab", "abbbbabb", "bbaaaaba", "bbbababa", "abbaabba",
 "bababbbb", "aabaaabb", "babbabab", "baaaabaa", "ababbaba",
 "aaabaabb", "bbaaabaa", "baaaaabb", "bbaabaab", "bbababab",
 "aabaaaab", "aaaaabab", "aabbaaba"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "U"; string Arg5 = "x"; verify_case(6, Arg5, makeMatch(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_7() { string Arr0[] = {"q", "M", "w", "y", "p", "N", "s", "r", "a", "H", "o", "n",
 "F", "m", "l", "b", "D", "j", "C", "u", "f", "I", "g", "L",
 "i", "x", "A", "G", "O", "k", "h", "d", "c", "E", "B", "v",
 "J", "z", "K", "e", "t"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"aabbaaabb", "baabababb", "bbaababba", "bbbaaaaaa", "abaaaabaa",
 "bababbbab", "abbaabbaa", "aabababbb", "bababaaaa", "abbababaa",
 "aabbbbbba", "bbabbabab", "babaabbba", "babbabbbb", "baaabbbbb",
 "baaabaaaa", "aaabbaaab", "abbaabbbb", "abbabbbab", "bbaaaabba",
 "babbaaabb", "aabbabbab", "baaababba", "ababaabab", "bbbaabbab",
 "aaaabbabb", "babaaaaaa", "abbbbaaab", "aabaaabba", "bbbaaaaba",
 "bbbbbbaab", "aabbaaabb", "aabaabbab", "aababaaba", "bbabbbbab",
 "abbabaaab", "babaaabbb", "bababbaaa", "aabbaabaa", "baaabbabb",
 "bbbbbbbbb"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"m", "k", "n", "q", "L", "E", "M", "l", "w", "x", "g", "e",
 "i", "z", "F", "r", "a", "h", "f", "D", "J", "K", "j", "v",
 "A", "t", "N", "y", "s", "c", "o", "p", "d", "b", "B", "G",
 "O", "I", "u", "C", "H"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"bbaaabbba", "bbaaaaaab", "abaaababb", "baaaabbbb", "abbbababa",
 "baaaaaaaa", "aabbbbbab", "aaaaabbba", "baabababb", "babaaabab",
 "baaababaa", "bbbbaabba", "bbaabbabb", "bbaaababb", "abbabbaba",
 "aababaaab", "abbbbbbaa", "aabbaabaa", "bbbaabbba", "abbabbaba",
 "aaabbbaaa", "bbaabaaaa", "aabababbb", "abbbbabab", "baaabbbba",
 "bababbbba", "aababbaab", "bbaabbaab", "bbbaaabbb", "babbbbabb",
 "ababababb", "babaaabab", "bbaaaaaba", "aaaaabaaa", "abbaaabbb",
 "bbbbababb", "baabababb", "bbaabaaaa", "aaababbbb", "abbbbbbba",
 "bbaabbaaa"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "o"; string Arg5 = "C"; verify_case(7, Arg5, makeMatch(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MatchMaking ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
