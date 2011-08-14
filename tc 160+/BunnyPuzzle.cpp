#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int can_jump(int i, int j, const vector<int> &p) {
    int a = p[i];
    int b = p[j];
    int c = 2*b - a;
    return (i>j && j>0 && p[j-1]>=c || i<j && j+1<(int)p.size() && p[j+1]<=c) ? 0 : 1;
}
        
class BunnyPuzzle {
	public:
	int theCount(vector <int> bunnies) {
		int sol = 0;
        for (int i=1; i<(int)bunnies.size(); ++i) {
            sol += can_jump(i, i-1, bunnies) + can_jump(i-1, i, bunnies);
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { int Arr0[] = {-1, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { int Arr0[] = {0, 1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { int Arr0[] = {-677, -45, -2, 3, 8, 29, 384, 867}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { int Arr0[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, theCount(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BunnyPuzzle ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
