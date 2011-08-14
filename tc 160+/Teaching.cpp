#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int init;
int ind[26];
vector<int> mask;

int bc(int x) {
    int ret = 0;
    while (x > 0) {
        ++ret;
        x &= x-1;
    }
    return ret;
}
class Teaching {
	public:
	int count(vector <string> words, int K) {
        if (K < 5) {
            return 0;
        }
	    int n = words.size();
        memset(ind, 0, sizeof ind);
        init = 0;
        const string str = "acint";
        int t = 25;
        for (int i=0; i<(int)str.size(); ++i) {
            ind[str[i]-'a'] = t--;
            init |= 1<<ind[str[i]-'a'];
        }
        for (int i=0; i<26; ++i) {
            if (ind[i] == 0) {
                ind[i] = t--;
            }
        }
        assert(t == -1);
        
        mask.assign(n, 0);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<(int)words[i].size(); ++j) {
                mask[i] |= (1<<ind[words[i][j]-'a']);
            }
        }
        
        K -= 5;
        int sol = 0;
        for (int m=0; m<(1<<21); ++m) {
            int t = bc(m);
            if (t != K) {
                continue;
            }
            int mm = m | init;
            int cnt = 0;
            for (int i=0; i<n; ++i) {
                cnt += ((mask[i]&mm) == mask[i]);
            }
            
            sol = max(sol, cnt);
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"antarctica","antahellotica","antacartica"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"antaxxxxxxxtica","antarctica"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"antabtica","antaxtica","antadtica","antaetica","antaftica",
 "antagtica","antahtica","antajtica","antaktica"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 3; verify_case(2, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Teaching ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
