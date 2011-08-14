#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool f(const string &a, const string &b) {
    char c[26];
    bool used[26] = {0};
    bool fixed[26] = {0};
    for (int i=0; i<26; ++i) {
        c[i] = i;
    }

    for (int i=0; i<(int)a.size(); ++i) {
        if (a[i] == b[i]) {
            if (c[a[i]-'a'] != a[i]-'a') {
                return false;
            }
            if (!fixed[a[i]-'a'] && used[a[i]-'a']) {
                return false;
            }
            fixed[a[i]-'a'] = 1;
            used[a[i]-'a'] = 1;
        } else {
            if (used[b[i]-'a'] && c[a[i]-'a']!=b[i]-'a' || fixed[a[i]-'a'] && c[a[i]-'a']!=b[i]-'a') {
                return false;
            }
            used[b[i]-'a'] = 1;
            fixed[a[i]-'a'] = 1;
            c[a[i]-'a'] = b[i]-'a';
        }
    }

    return true;
}

class IsomorphicWords {
	public:
	int countPairs(vector <string> words) {
		int sol = 0;
        for (int i=0; i<(int)words.size(); ++i) {
            for (int j=i+1; j<(int)words.size(); ++j) {
                sol += f(words[i], words[j]);
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"abca", "zbxz", "opqr"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, countPairs(Arg0)); }
	void test_case_1() { string Arr0[] = {"aa", "ab", "bb", "cc", "cd"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, countPairs(Arg0)); }
	void test_case_2() { string Arr0[] = { "cacccdaabc", "cdcccaddbc", "dcdddbccad", "bdbbbaddcb",
  "bdbcadbbdc", "abaadcbbda", "babcdabbac", "cacdbaccad",
  "dcddabccad", "cacccbaadb", "bbcdcbcbdd", "bcbadcbbca" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(2, Arg1, countPairs(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    IsomorphicWords ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
