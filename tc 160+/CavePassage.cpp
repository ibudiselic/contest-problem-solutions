#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct S {
    bool map_left;
    int t, mask;
    S(bool map_left_, int t_, int mask_): map_left(map_left_), t(t_), mask(mask_) {}
};
bool operator<(const S &a, const S &b) {
    if (a.t != b.t) {
        return a.t > b.t;
    } else if (a.mask != b.mask) {
        return a.mask < b.mask;
    } else {
        return a.map_left < b.map_left;
    }
}

int best[1<<13][2];
int bc[1<<13];
bool nok[1<<13];
int TM[1<<13];
class CavePassage {
	public:
	int minimalTime(vector <int> W, vector <int> T, vector <string> T_, int B) {
		int n = W.size();
        bc[0] = 0;
        for (int i=1; i<(1<<n); ++i) {
            bc[i] = bc[i>>1] + (i&1);
        }
        vector<int> TR(n, 0);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (i!=j && T_[i][j]=='Y') {
                    TR[i] |= (1<<j);
                }
            }
        }
        memset(best, 0x3f, sizeof best);
        int inf = 0x3f3f3f3f;
        
        memset(nok, 0, sizeof nok);
        memset(TM, 0, sizeof TM);
        for (int m=0; m<(1<<n); ++m) {
            int w = 0;
            for (int i=0; i<n; ++i) {
                if (m & (1<<i)) {
                    w += W[i];
                    TM[m] = max(TM[m], T[i]);
                    if (w>B || (TR[i] & m)==0 && bc[m]>1) {
                        nok[m] = true;
                        break;
                    }
                }
            }
        }
        

        priority_queue<S> PQ;
        PQ.push(S(1, 0, (1<<n)-1));
        while (!PQ.empty()) {
            S state = PQ.top();
            PQ.pop();
            if (state.t > best[state.mask][state.map_left]) {
                continue;
            }
            if (state.mask == 0) {
                assert(!state.map_left);
                return state.t;
            }
            best[state.mask][state.map_left] = state.t;
            
            if (state.map_left) {
                for (int m=(~state.mask+1)&state.mask; m>0; m=(m+1+~state.mask)&state.mask) {
                    assert((m & state.mask) == m);
                    assert((m | state.mask) == state.mask);
                    if (!nok[m]) {
                        const int time = TM[m];
                        const int nmask = state.mask - m;
                        const int nt = state.t + time;
                        if (nt < best[nmask][false]) {
                            best[nmask][false] = nt;
                            PQ.push(S(false, nt, nmask));
                        }
                    }
                }
            } else {
                for (int m=(state.mask+1)&~state.mask; m<(1<<n); m=(m+1+state.mask)&~state.mask) {
                    assert((m & state.mask) == 0);
                    if (!nok[m]) {
                        const int time = TM[m];
                        const int nmask = state.mask + m;
                        const int nt = state.t + time;
                        if (nt < best[nmask][true]) {
                            best[nmask][true] = nt;
                            PQ.push(S(true, nt, nmask));
                        }
                    }
                }
            }
        }

        return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "YYY", "YYY", "YYY" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 9; verify_case(0, Arg4, minimalTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = { 1, 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "YYY", "YYY", "NYY" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 10; verify_case(1, Arg4, minimalTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = { 1, 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 7, 13, 19 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "YYN", "NYY", "YNY" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 19; verify_case(2, Arg4, minimalTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = { 43 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 23 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "Y" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 42; int Arg4 = -1; verify_case(3, Arg4, minimalTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CavePassage ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
