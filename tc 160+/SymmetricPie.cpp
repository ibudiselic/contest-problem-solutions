#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int calc(const vector<int> &v) {
    int ret = 0;
    vector<int> cuts;
    cuts.push_back(0);
    for (int i=0; i<(int)v.size(); ++i) {
        int x = cuts.back() + v[i];
        if (x>=50 && x<100 && find(cuts.begin(), cuts.end(), x-50)!=cuts.end()) {
            ++ret;
        }
        cuts.push_back(x);
    }

    return ret;
}

class SymmetricPie {
	public:
	int getLines(vector <int> dogs) {
		sort(dogs.begin(), dogs.end());

        int sol = 0;
        do {
            sol = max(sol, calc(dogs));
        } while (next_permutation(dogs.begin(), dogs.end()));

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10,40,10,40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getLines(Arg0)); }
	void test_case_1() { int Arr0[] = {10,50,40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getLines(Arg0)); }
	void test_case_2() { int Arr0[] = {50,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, getLines(Arg0)); }
	void test_case_3() { int Arr0[] = {1,48,1,1,48,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, getLines(Arg0)); }
	void test_case_4() { int Arr0[] = {2,2,96}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, getLines(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SymmetricPie ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
