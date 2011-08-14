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

void process(deque<int> &d, int cnt) {
    cnt %= d.size();
    while (cnt--) {
        d.push_front(d.back());
        d.pop_back();
    }
}
int brute_force(int n, int left, int right) {
    vector<int> p;
    p.reserve(n);
    for (int i=0; i<n; ++i) {
        p.push_back(i);
    }
    
    vector<int> res;
    while (p.size() > 2) {
        deque<int> L, R;
        while (p.size() > 0) {
            L.push_back(p.back());
            p.pop_back();
            if (p.size() > 0) {
                R.push_back(p.back());
                p.pop_back();
            }
        }
        process(L, left);
        process(R, right);
        res.push_back(L.back());
        L.pop_back();
        res.push_back(R.back());
        R.pop_back();
        copy(L.rbegin(), L.rend(), back_inserter(p));
        copy(R.rbegin(), R.rend(), back_inserter(p));
    }
    
    return p.size() ? p[0] : res.back();
}

class TheCardShufflingDivOne {
	public:
	int shuffle(int n, int left, int right) {
        if (n == 1) {
            return 1;
        }
        
        int sz = 0;
        int szres = n;
        int at = 0;
        if (n & 1) {
            sz = 1;
            --szres;
        } else {
            sz = 2;
            szres -= 2;
        }
        
        while (sz < n) {
            int szl = (sz + 1)/2, szr = sz/2;
            int atl = -1, atr = -1;
            if (at < szl) {
                atl = szl-1-at;
            } else {
                atr = szr-1-(at-szl);
            }
            at = -1;
            
            ++szl;
            ++szr;
            szres -= 2;
            
            if (atl != -1) {
                int k = left % szl;
                atl = (atl-k+szl) % szl;
            } else {
                int k = right % szr;
                atr = (atr-k+szr) % szr;
            }
            
            sz += 2;
            if (atl != -1) {
                at = sz-1-2*atl;
            } else {
                at = sz-2-2*atr;
            }
        }
        
        return n - at;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 0; int Arg3 = 1; verify_case(0, Arg3, shuffle(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 3; verify_case(1, Arg3, shuffle(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 0; int Arg2 = 0; int Arg3 = 2; verify_case(2, Arg3, shuffle(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 17; int Arg1 = 12; int Arg2 = 21; int Arg3 = 17; verify_case(3, Arg3, shuffle(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheCardShufflingDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
