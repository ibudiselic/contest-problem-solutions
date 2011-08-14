#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Planks {
	public:
	int makeSimilar(vector <int> lengths, int costPerCut, int woodValue) {
		int sol = 0;
		for (int l=1; l<=10000; ++l) {
			int p = 0;
			int cut_cost = 0;
			for (int i=0; i<(int)lengths.size(); ++i) {
				int t = lengths[i]/l;
				if (t*l*woodValue < costPerCut*(t - (t*l == lengths[i]))) {
					continue;
				}
				p += t;
				cut_cost += costPerCut * (t - (t*l == lengths[i]));
			}

			sol = max(sol, p*l*woodValue - cut_cost);
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {26,103,59}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 10; int Arg3 = 1770; verify_case(0, Arg3, makeSimilar(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {26,103,59}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 10; int Arg3 = 1680; verify_case(1, Arg3, makeSimilar(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {26,103,59}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 10; int Arg3 = 1230; verify_case(2, Arg3, makeSimilar(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {5281,5297,5303,5309,5323,5333,5347,5351,5381,5387}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 20; int Arg3 = 1057260; verify_case(3, Arg3, makeSimilar(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {31,73,127,179,181,191,283,353,359,1019} ; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 25; int Arg2 = 10; int Arg3 = 25145; verify_case(4, Arg3, makeSimilar(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {200,200,200,400}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 1; int Arg3 = 600; verify_case(5, Arg3, makeSimilar(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Planks ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
