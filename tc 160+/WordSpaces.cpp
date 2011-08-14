#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool same(const string &s, int start, int spacing, const string &w) {
	int i=0;

	while (i<(int)w.size()) {
		if (s[start] != w[i])
			return false;
		++i;
		start += spacing+1;
	}

	return true;
}
class WordSpaces {
	public:
	vector <int> find(string sentence, vector <string> words) {
		vector<int> sol(words.size(), -1);

		for (int i=0; i<(int)words.size(); ++i) {
			for (int start=0; start<(int)sentence.size(); ++start)
				if (words[i].size() == 1) {
					if (same(sentence, start, 0, words[i])) {
						sol[i] = start;
						goto next;
					}
				} else {
					for (int spacing=0; start + ((int)words[i].size()-1)*spacing + (int)words[i].size() <= (int)sentence.size(); ++spacing)
						if (same(sentence, start, spacing, words[i])) {
							sol[i] = start;
							goto next;
						}
				}
			next: ;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "at bah ate"; string Arr1[] = {"the","aa","hae"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1,  0,  5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "test this one out"; string Arr1[] = {"test","tst","hoe","not"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0,  0,  -1,  -1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "t ah mi as this"; string Arr1[] = {"this","mat","zebra","hh"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0,  5,  -1,  3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abcdefghijklmnoqrstuvwxyz zywvutsrponmlkjighfedcba"; string Arr1[] = {"foy","foz","fox","ace","rom"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 5,  -1,  -1,  0,  33 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, find(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "ridikulus ridiculous"; string Arr1[] = {"kuri","ks","cs","z","i","rsl"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 4,  4,  14,  -1,  1,  0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WordSpaces ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
