#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class CarrotBoxesEasy {
	public:
	int theIndex(vector <int> carrots, int K) {
		int last = -1;
        while (K--) {
            int maxi = 0;
            for (int i=1; i<(int)carrots.size(); ++i) {
                if (carrots[i] > carrots[maxi]) {
                    maxi = i;
                }
            }
            last = maxi;
            --carrots[maxi];
        }
        return last;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 1; verify_case(0, Arg2, theIndex(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 0; verify_case(1, Arg2, theIndex(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4, 9, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; int Arg2 = 2; verify_case(2, Arg2, theIndex(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {13, 75, 24, 55}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 140; int Arg2 = 0; verify_case(3, Arg2, theIndex(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {14, 36, 52, 86, 27, 97, 3, 67}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 300; int Arg2 = 4; verify_case(4, Arg2, theIndex(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CarrotBoxesEasy ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
