#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

string S, T, C;
string to_str(int x) {
    ostringstream os;
    os << x;
    return os.str();
}

int sol;

bool ok_mem[9][1<<9][2][2];
bool done[9][1<<9][2][2];

bool ok(int p, int mask, bool lb, bool ub) {
    bool &ret = ok_mem[p][mask][lb][ub];
    if (done[p][mask][lb][ub]) {
        return ret;
    }
    done[p][mask][lb][ub] = true;
    if (p==(int)C.size() || !lb && !ub) {
        return (ret = true);
    }
    
    for (int i=0; i<(int)C.size(); ++i) {
        if (((mask>>i) & 1)==0 && (p>0 || C[i]!='0')) {
            if ((!lb || S[p]<=C[i]) && (!ub || C[i]<=T[p])) {
                if (ok(p+1, mask|(1<<i), lb && C[i]==S[p], ub && C[i]==T[p])) {
                    return (ret = true);
                }
            }
        }
    }

    return (ret = false);
}

bool ok_(int a, int b, bool c, bool d) {
    memset(ok_mem, 0, sizeof ok_mem);
    memset(done, 0, sizeof done);
    return ok(a, b, c, d);
}

void go(int p, int last_d) {
    if (p == (int)C.size()) {
        if (last_d == 0) {
            return;
        }
        sol += ok_(0, 0, 1, 1);
        int i = 0;
        int mask = 0;
        while (i<(int)C.size() && C[i]=='0' && S[i]=='0') {
            mask |= 1<<i;
            ++i;
            sol += ok_(i, mask, 1, 0);
        }
        return;
    }
    
    for (int d=last_d; d<10; ++d) {
        C[p] = '0' + d;
        go(p+1, d);
    }
}

class DistinctDigits {
	public:
	int count(int low, int high) {
        S = to_str(low);
        T = to_str(high);
        if (T.size() > S.size()) {
            S = string(T.size()-S.size(), '0') + S;
        }
        C = S;
        
        sol = 0;
        go(0, 0);
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 20; int Arg2 = 20; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 30; int Arg2 = 29; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 151; int Arg1 = 309; int Arg2 = 98; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 15000; int Arg2 = 1641; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 153697; int Arg1 = 154689; int Arg2 = 318; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 1000; int Arg1 = 10000000; int Arg2 = 19159; verify_case(5, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    DistinctDigits ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
