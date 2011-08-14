#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>
#include <map>

using namespace std;

string f(const string &s, const vector<string> &part) {
    string ret;
    for (int i=0; i<(int)s.size(); ++i) {
        int j = 0;
        while (part[j].find(s[i]) == string::npos) {
            ++j;
        }
        ret += char('1' + j);
    }
    return ret;
}

string g(const string &s, map<string, vector<string> > &M) {
    int j = 0;
    while (j<(int)s.size() && s[j]!='*' && s[j]!='#') {
        ++j;
    }
    assert(M.count(s.substr(0, j)));
    int sz = j;
    int i = 0;
    while (j < (int)s.size()) {
        i += (s[j]=='*')*5 + (s[j]=='#')*1;
        ++j;
    }
    return M[s.substr(0, sz)][i];
}
class T9 {
	public:
	string message(vector <string> part, vector <string> dict, vector <string> keystr) {
		string s = accumulate(keystr.begin(), keystr.end(), string());
        map<string, vector<string> > M;
        for (int i=0; i<(int)dict.size(); ++i) {
            M[f(dict[i], part)].push_back(dict[i]);
        }
        for (map<string, vector<string> >::iterator it=M.begin(); it!=M.end(); ++it) {
            sort(it->second.begin(), it->second.end());
        }
        s += '0';
        string sol;
        int i = 0;
        int j = 0;
        while (i < (int)s.size()) {
            j = i;
            while (j<(int)s.size() && s[j]!='0') {
                ++j;
            }
            if (i > 0) {
                sol += ' ';
            }
            if (j > i) {
                sol += g(s.substr(i, j-i), M);
            }
            i = j+1;
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"bad"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2230223"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "bad bad"; verify_case(0, Arg3, message(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"the", "tie"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0843#000843#000"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = " tie   tie   "; verify_case(1, Arg3, message(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"bad", "ace", "aad", "aae", "aaf", "acf", "acd", "the", "tie"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"223#02", "23*#00843#0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "aae bad  tie "; verify_case(2, Arg3, message(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"the", "tie", "bad", "ace", "aad", "aae", "aaf", "acf", "acd"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"84300223#02", "23#*"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "the  aae bad"; verify_case(3, Arg3, message(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"bad", "ace", "aad", "aae", "tie", "aaf", "acf", "acd", "the"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"223#02", "23######"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "aae bad"; verify_case(4, Arg3, message(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"", "rq", "lde", "yoauz", "cbfgn", "tjkpx", "wvs", "ih", "m"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"xktgmfmoqlmivm", 
 "hmthr", 
 "tpjgmnmaremiwm", 
 "tpjcmnmyrlmhvm", 
 "xkpnmgmzqdmhsm", 
 "wqopvvmiig", 
 "melbcbqeeg", 
 "jkxnmbmardmhwm", 
 "kpxnmcmyqlmism", 
 "wrztvsmhhf", 
 "srztssmiic", 
 "pxtgmfmyrdmhwm", 
 "vqoxswmiin", 
 "wryksvmihb", 
 "ptjfmbmoremhvm"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"00", 
 "7246779885##00000089682000007246779885##0000724677", 
 "9885#000089682000093355523350066659594239879###000"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "  wqopvvmiig      hmthr     wqopvvmiig    vqoxswmiin    hmthr    melbcbqeeg  pxtgmfmyrdmhwm   "; verify_case(5, Arg3, message(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    T9 ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
