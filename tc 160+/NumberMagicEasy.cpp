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

class NumberMagicEasy {
	public:
	int theNumber(string answer) {
		vector<int> S[4];
        S[0].push_back(1);
        S[0].push_back(2);
        S[0].push_back(3);
        S[0].push_back(4);
        S[0].push_back(5);
        S[0].push_back(6);
        S[0].push_back(7);
        S[0].push_back(8);
        S[1].push_back(1);
        S[1].push_back(2);
        S[1].push_back(3);
        S[1].push_back(4);
        S[1].push_back(9);
        S[1].push_back(10);
        S[1].push_back(11);
        S[1].push_back(12);
        S[2].push_back(1);
        S[2].push_back(2);
        S[2].push_back(5);
        S[2].push_back(6);
        S[2].push_back(9);
        S[2].push_back(10);
        S[2].push_back(13);
        S[2].push_back(14);
        S[3].push_back(1);
        S[3].push_back(3);
        S[3].push_back(5);
        S[3].push_back(7);
        S[3].push_back(9);
        S[3].push_back(11);
        S[3].push_back(13);
        S[3].push_back(15);
        
        set<int> cand;
        for (int i=0; i<4; ++i) {
            if (answer[i] == 'Y') {
                for (int j=0; j<(int)S[i].size(); ++j) {
                    cand.insert(S[i][j]);
                }
            }
        }
        for (int i=0; i<4; ++i) {
            if (answer[i] == 'N') {
                for (int j=0; j<(int)S[i].size(); ++j) {
                    cand.erase(S[i][j]);
                }
            }
        }
        
        return cand.size() ? *cand.begin() : 16;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "YNYY"; int Arg1 = 5; verify_case(0, Arg1, theNumber(Arg0)); }
	void test_case_1() { string Arg0 = "YNNN"; int Arg1 = 8; verify_case(1, Arg1, theNumber(Arg0)); }
	void test_case_2() { string Arg0 = "NNNN"; int Arg1 = 16; verify_case(2, Arg1, theNumber(Arg0)); }
	void test_case_3() { string Arg0 = "YYYY"; int Arg1 = 1; verify_case(3, Arg1, theNumber(Arg0)); }
	void test_case_4() { string Arg0 = "NYNY"; int Arg1 = 11; verify_case(4, Arg1, theNumber(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NumberMagicEasy ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
