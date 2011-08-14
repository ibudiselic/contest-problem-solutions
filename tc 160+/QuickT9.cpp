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

int digs[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
class QuickT9 {
	public:
	int minimumPressings(vector <string> t9, string word) {
		vector<string> W;
        for (int i=0; i<(int)t9.size(); ++i) {
            istringstream is(t9[i]);
            string s;
            while (is >> s) {
                W.push_back(s);
            }
        }
        sort(W.begin(), W.end());
        W.resize(unique(W.begin(), W.end()) - W.begin());
        map< vector<int>, vector<int> > dig2cand;
        for (int i=0; i<(int)W.size(); ++i) {
            vector<int> v;
            v.reserve(W[i].size());
            for (int j=0; j<(int)W[i].size(); ++j) {
                v.push_back(digs[W[i][j]-'a']);
                bool add = (dig2cand.count(v)==0);
                if (!add) {
                    int x = dig2cand[v].back();
                    if (W[i].substr(0, j+1) != W[x].substr(0, j+1)) {
                        add = true;
                    }
                }
                if (add) {
                    dig2cand[v].push_back(i);
                }
            }
        }
        
        map<string, int> costToWrite;
        for (map< vector<int>, vector<int> >::const_iterator it=dig2cand.begin(); it!=dig2cand.end(); ++it) {
            const vector<int> &t = it->second;
            int len = it->first.size();
            for (int i=0; i<(int)t.size(); ++i) {
                for (int j=1; j<=len; ++j) {
                    int cost = len + i + max(1, len-j); // the 1 is the Right button (no deletes)
                    const string &s = W[t[i]].substr(0, j);
                    if (costToWrite.count(s)) {
                        costToWrite[s] = min(costToWrite[s], cost);
                    } else {
                        costToWrite[s] = cost;
                    }
                }
            }
        }
        
        int best[64];
        memset(best, 0x3f, sizeof best);
        int inf;
        memset(&inf, 0x3f, sizeof inf);
        best[0] = 0;
        for (int i=0; i<(int)word.size(); ++i) {
            if (best[i] == inf) {
                continue;
            }
            for (int sz=1; i+sz<=(int)word.size(); ++sz) {
                const string &s = word.substr(i, sz);
                if (costToWrite.count(s)) {
                    best[i+sz] = min(best[i+sz], best[i] + costToWrite[s]);
                }
            }
        }
        
        return best[word.size()]==inf ? -1 : best[word.size()];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"aae", "bab", "abad", "bdbd", "beta"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "babe"; int Arg2 = 9; verify_case(0, Arg2, minimumPressings(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"ann","ie"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "annie"; int Arg2 = 7; verify_case(1, Arg2, minimumPressings(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"ann","amm"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "annie"; int Arg2 = -1; verify_case(2, Arg2, minimumPressings(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"aaa aab","aac aba abb ccca"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aba"; int Arg2 = 6; verify_case(3, Arg2, minimumPressings(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"acac aba aaab","aab aa baa","bba bacade abb","baba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "abbaca"; int Arg2 = 10; verify_case(4, Arg2, minimumPressings(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"aaa aab aac","aba abb","ccca"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ccc"; int Arg2 = 5; verify_case(5, Arg2, minimumPressings(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    QuickT9 ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
