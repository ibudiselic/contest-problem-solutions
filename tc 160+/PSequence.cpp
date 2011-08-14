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

struct State {
    int prev_from;
    vector<int> rem;
};
bool operator<(const State &a, const State &b) {
    if (a.prev_from != b.prev_from) {
        return a.prev_from < b.prev_from;
    }
    return a.rem < b.rem;
}

const long long mod = 1234567891LL;
map<State, int> M;

int go(State s) {
    if (M.count(s)) {
        return M[s];
    }
    
    int &ret = M[s];
    if (s.rem.size() == 0) {
        return 1;
    }
    ret = 0;
    for (int i=0; i<(int)s.rem.size(); ++i) {
        if (i != s.prev_from) {
            State t = s;
            if (t.rem[i] == 1) {
                t.prev_from = -1;
                t.rem.erase(t.rem.begin() + i);
            } else {
                int v = --t.rem[i];
                sort(t.rem.begin(), t.rem.end());
                t.prev_from = find(t.rem.begin(), t.rem.end(), v) - t.rem.begin();
            }
            ret = (ret + (long long)s.rem[i] * go(t)) % mod;
        }
    }
    
    return ret;
}
class PSequence {
	public:
	int count(vector <int> S, int p) {
		M.clear();
        for (int i=0; i<(int)S.size(); ++i) {
            if (S[i] >= 0) {
                S[i] = S[i]%p;
            } else {
                int t = -S[i]/p;
                S[i] = (S[i]+(t+1)*p) % p;
            }
        }
        
        State s;
        s.prev_from = -1;
        sort(S.begin(), S.end());
        for (int i=0; i<(int)S.size(); ) {
            int j = i+1;
            while (j<(int)S.size() && S[j]==S[i]) {
                ++j;
            }
            s.rem.push_back(j - i);
            i = j;
        }
        sort(s.rem.begin(), s.rem.end());
        
        return go(s);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1,0,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 120; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {6,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 12; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {4,6,8,-3,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 12; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PSequence ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
