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

class FoxProgression {
	public:
	int theCount(vector <int> seq) {
		if (seq.size() == 1) {
            return -1;
        }
        int add = seq[1] - seq[0];
        int mul = seq[1] / seq[0];
        
        vector<int> possible;
        bool ok = true;
        for (int i=1; i<(int)seq.size(); ++i) {
            if (seq[i-1]+add != seq[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            possible.push_back(seq.back() + add);
        }
        
        if (seq[1]>=seq[0] && seq[1]%seq[0]==0) {
            ok = true;
            for (int i=1; i<(int)seq.size(); ++i) {
                if (seq[i-1]*mul != seq[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                possible.push_back(seq.back()*mul);
            }
        }
        
        sort(possible.begin(), possible.end());
        return unique(possible.begin(), possible.end()) - possible.begin();
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 4, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { int Arr0[] = {8, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, theCount(Arg0)); }
	void test_case_5() { int Arr0[] = {4, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(5, Arg1, theCount(Arg0)); }
	void test_case_6() { int Arr0[] = {1, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(6, Arg1, theCount(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FoxProgression ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
