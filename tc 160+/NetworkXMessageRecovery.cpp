#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int value(char c) {
    if (c <= 'Z') {
        return c - 'A';
    } else {
        return 26 + c - 'a';
    }
}
long long after[50][50];
class NetworkXMessageRecovery {
	public:
	string recover(vector <string> messages) {
        int n = messages.size();
        vector< vector<int> > V(n, vector<int>());
        for (int i=0; i<n; ++i) {
            for (int j=0; j<(int)messages[i].size(); ++j) {
                V[i].push_back(value(messages[i][j]));
            }
        }
        for (int i=0; i<n; ++i) {
            after[i][(int)V[i].size() - 1] = 0;
            for (int j=(int)V[i].size()-2; j>=0; --j) {
                after[i][j] = after[i][j+1] | (1ll<<V[i][j+1]);
            }
        }
        
        vector<int> ind(n, 0);
        string sol;
        while (1) {
            set<int> cand;
            long long mask = 0;
            for (int i=0; i<n; ++i) {
                if (ind[i] < (int)V[i].size()) {
                    cand.insert(V[i][ind[i]]);
                    mask |= after[i][ind[i]];
                }
            }
            if (cand.size() == 0) {
                break;
            }
            
            for (set<int>::const_iterator it=cand.begin(); it!=cand.end(); ++it) {
                if (!(mask & (1ll<<*it))) {
                    sol += char(*it<26 ? 'A'+*it : 'a'+*it-26);
                    for (int i=0; i<n; ++i) {
                        if (ind[i]<(int)V[i].size() && V[i][ind[i]]==*it) {
                            ++ind[i];
                        }
                    }
                    break;
                }
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"acd", "bce"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "abcde"; verify_case(0, Arg1, recover(Arg0)); }
	void test_case_1() { string Arr0[] = {"ed", "dc", "cb", "ba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "edcba"; verify_case(1, Arg1, recover(Arg0)); }
	void test_case_2() { string Arr0[] = {"Fox", "Ciel", "FoxCiel"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "FoxCiel"; verify_case(2, Arg1, recover(Arg0)); }
	void test_case_3() { string Arr0[] = {"a", "A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Aa"; verify_case(3, Arg1, recover(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NetworkXMessageRecovery ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
