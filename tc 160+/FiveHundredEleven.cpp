#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> C;
int dp[2][51][51][512]; // player, used nonzero cards, num zero cards remaining, cur mem

int go(bool ciel, int nused, int nz, int mem) {
    int &ret = dp[ciel][nused][nz][mem];
    if (ret != -1) {
        return ret;
    }
    
    if (mem == 511) { // the other guy lost
        return (ret = 1);
    }

    if (nz>0 && !go(!ciel, nused, nz-1, mem)) { // use zero
        return (ret = 1);
    }

    int ncovered = 0;
    for (int i=0; i<(int)C.size(); ++i) {
        if ((mem|C[i]) == mem) {
            ++ncovered;
        }
    }
    if (ncovered>nused && !go(!ciel, nused+1, nz, mem)) { // there must be one unused, doesn't matter which
        return (ret = 1);
    }

    for (int i=0; i<(int)C.size(); ++i) { // try one of the uncovered ones
        if ((mem|C[i]) != mem) {
            if (!go(!ciel, nused+1, nz, mem|C[i])) {
                return (ret = 1);
            }
        }
    }
    
    return (ret = 0);
}

class FiveHundredEleven {
	public:
	string theWinner(vector <int> cards) {
		C = cards;
        sort(C.begin(), C.end());
        reverse(C.begin(), C.end());
        int nz = 0;
        while (C.size()>0 && C.back()==0) {
            ++nz;
            C.pop_back();
        }

        memset(dp, 0xff, sizeof dp);
        return go(0, 0, nz, 0) ? "Fox Ciel" : "Toastman";
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 5, 7, 9, 510}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Fox Ciel"; verify_case(0, Arg1, theWinner(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Toastman"; verify_case(1, Arg1, theWinner(Arg0)); }
	void test_case_2() { int Arr0[] = {511}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Toastman"; verify_case(2, Arg1, theWinner(Arg0)); }
	void test_case_3() { int Arr0[] = {5, 58, 192, 256}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Fox Ciel"; verify_case(3, Arg1, theWinner(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FiveHundredEleven ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
