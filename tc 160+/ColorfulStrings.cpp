#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool prod[500000];
string sol;
int K;
int cur;
bool go(int p) {
    if (p == (int)sol.size()) {
        if (++cur == K) {
            return true;
        } else {
            return false;
        }
    }
    
    for (int i=2; i<10; ++i) {
        if (!prod[i]) {
            vector<int> prods(1, i);
            int t = i;
            bool ok = true;
            for (int j=p-1; j>=0; --j) {
                t *= sol[j]-'0';
                prods.push_back(t);
                if (prod[t]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                sol[p] = i + '0';
                for (int j=0; j<(int)prods.size(); ++j) {
                    prod[prods[j]] = true;
                }
                if (go(p+1)) {
                    return true;
                }
                for (int j=0; j<(int)prods.size(); ++j) {
                    prod[prods[j]] = false;
                }
            }
        }
    }
    
    return false;
}
class ColorfulStrings {
	public:
	string getKth(int n, int k) {
		if (n > 10) {
            return "";
        }
        if (n == 1) {
            if (k > 10) {
                return "";
            }
            return string(1, k-1+'0');
        }
        K = k;
        cur = 0;
        sol = string(n, ' ');
        memset(prod, 0, sizeof prod);
        return go(0) ? sol : string();
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; string Arg2 = "238"; verify_case(0, Arg2, getKth(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 2000; string Arg2 = ""; verify_case(1, Arg2, getKth(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 1; string Arg2 = "23457"; verify_case(2, Arg2, getKth(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 22; string Arg2 = "52"; verify_case(3, Arg2, getKth(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 464; string Arg2 = "257936"; verify_case(4, Arg2, getKth(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ColorfulStrings ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
