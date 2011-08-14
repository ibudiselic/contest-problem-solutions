#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <numeric>

using namespace std;

map<char, int> tag_ind;
map<string, int> color_ind;
string tag_chars = "bui";
string colors[] = { "black", "blue", "gray", "green", "red", "white", "yellow" };

struct Tag {
    int tag, color;
    int index;
    vector<int> children;
};
vector<Tag> tags;

int parse(int &start, const string &S) {
    assert(S[start] == '<');
    ++start;
    assert(tag_chars.find(S[start]) != string::npos);
    int tag = tag_ind[S[start]];
    int pos = start + 1 + S.substr(start+1).find("'color:") + 7;
    int col_end = pos + S.substr(pos).find('\'');
    int color = color_ind[S.substr(pos, col_end-pos)];
    start = col_end + 2;
    assert(S[start] == '<');
    
    int retval = tags.size();
    tags.push_back(Tag());
    tags[retval].tag = tag;
    tags[retval].color = color;
    tags[retval].index = retval;
    while (S[start+1] != '/') {
        tags[retval].children.push_back(parse(start, S));
    }
    start += 4;
    return retval;
}

int dp[128][8][8][8];
int go(int root, int b_col, int u_col, int i_col) {
    int &ret = dp[root][b_col][u_col][i_col];
    if (ret != -1) {
        return ret;
    }
    
    Tag &t = tags[root];
    if (t.tag == 0) {
        ret = (t.color != b_col);
    } else if (t.tag == 1) {
        ret = (t.color != u_col);
    } else {
        ret = (t.color != i_col);
    }
    
    if (t.children.size() > 0) {
        int best = 123456789;
        for (int v1=0; v1<8; ++v1) {
            for (int v2=0; v2<8; ++v2) {
                for (int v3=0; v3<8; ++v3) {
                    int cur = (v1>0) + (v2>0) + (v3>0);
                    for (int i=0; i<(int)t.children.size(); ++i) {
                        cur += go(t.children[i],
                                  v1==0 ? b_col : v1,
                                  v2==0 ? u_col : v2,
                                  v3==0 ? i_col : v3);
                    }
                    best = min(best, cur);
                }
            }
        }
        ret += best;
    }
    
    return ret;
}
class CssRules {
	public:
	int getMinimalCssRuleCount(vector <string> xthml) {
        for (int i=0; i<(int)tag_chars.size(); ++i) {
            tag_ind[tag_chars[i]] = i;
        }
        for (int i=0; i<7; ++i) {
            color_ind[colors[i]] = i+1;
        }
        
        string S = accumulate(xthml.begin(), xthml.end(), string());
        tags.clear();
        int start = 0;
        int sol = 0;
        memset(dp, 0xff, sizeof dp);
        while (start < (int)S.size()) {
            int root = parse(start, S);
            sol += go(root, 0, 0, 0);
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"<b id='x' style='color:red'></b>"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, getMinimalCssRuleCount(Arg0)); }
	void test_case_1() { string Arr0[] = {"<b id='x' style='color:red'>","<b id='y' style='color:red'>",
 "<b id='z' style='color:red'>","</b></b></b>"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, getMinimalCssRuleCount(Arg0)); }
	void test_case_2() { string Arr0[] = {"<b id='x' style='color:red'>",
"<b id='y' style='color:red'>",
"<b id='w' style='color:red'>",
"</b>",
"</b>",
"<u id='z' style='color:red'>",
"</u>",
"</b>"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, getMinimalCssRuleCount(Arg0)); }
	void test_case_3() { string Arr0[] = {"<b id='x' style='color:red'>",
"<i id='y' style='color:black'>",
"<u id='w' style='color:white'>",
"</u>",
"</i>",
"<u id='z' style='color:yellow'>",
"</u>",
"</b>"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, getMinimalCssRuleCount(Arg0)); }
	void test_case_4() { string Arr0[] = {"<b id='x' style='col", "or:red'></b>", "<b id=", "'xx' style='color", ":red'></b>"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, getMinimalCssRuleCount(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CssRules ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
