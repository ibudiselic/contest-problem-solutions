#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

map<string, long long> M[1<<13][2];
vector<string> W;

bool is_palin(const string &s) {
    int i = 0;
    int j = (int)s.size()-1;
    while (i < j) {
        if (s[i++] != s[j--]) {
            return false;
        }
    }
    
    return true;
}
        
long long go(int avail, bool left, const string &rem) {
    if (M[avail][left].count(rem)) {
        return M[avail][left][rem];
    }
    long long &ret = M[avail][left][rem];
    
    ret = is_palin(rem);
    for (int i=0; i<(int)W.size(); ++i) {
        if ((avail>>i) & 1) {
            int k = 0;
            if (left) {
                while (k<(int)rem.size() && k<(int)W[i].size() && rem[k]==W[i][W[i].size()-1-k]) {
                    ++k;
                }
                if (k<(int)rem.size() && k<(int)W[i].size()) {
                    continue;
                }
                
                if (k == (int)rem.size()) {
                    ret += go(avail ^ (1<<i), 0, W[i].substr(0, W[i].size()-k));
                } else {
                    ret += go(avail ^ (1<<i), 1, rem.substr(k));
                }
            } else {
                while (k<(int)rem.size() && k<(int)W[i].size() && rem[rem.size()-1-k]==W[i][k]) {
                    ++k;
                }
                if (k<(int)rem.size() && k<(int)W[i].size()) {
                    continue;
                }

                if (k == (int)rem.size()) {
                    ret += go(avail ^ (1<<i), 1, W[i].substr(k));
                } else {
                    ret += go(avail ^ (1<<i), 0, rem.substr(0, rem.size()-k));
                }
            }
        } 
    }
    
    return ret;
}
class PalindromePhrases {
	public:
	long long getAmount(vector <string> words) {
        W = words;
        for (int i=0; i<(1<<13); ++i) {
            for (int j=0; j<2; ++j) {
                M[i][j].clear();
            }
        }
        
        return go((1<<W.size())-1, 0, "") - 1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"a","ba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(0, Arg1, getAmount(Arg0)); }
	void test_case_1() { string Arr0[] = {"ab","bcd","efg"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(1, Arg1, getAmount(Arg0)); }
	void test_case_2() { string Arr0[] = {"a", "bba", "abb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; verify_case(2, Arg1, getAmount(Arg0)); }
	void test_case_3() { string Arr0[] = {"aabccc", "ccbbca", "a", "acaabb", "aaa", "aab", "c", "babb", "aacaa", "b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 47LL; verify_case(3, Arg1, getAmount(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PalindromePhrases ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
