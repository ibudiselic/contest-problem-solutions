#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;

class CuttingPoles {
	public:
	bool same(const vector<int> &p) {
		const int t = p[0];
		for (int i=1; i<(int)p.size(); ++i)
			if (t != p[i])
				return false;
		return true;
	}
	int avg(const vector<int> &p) {
		int t = accumulate(p.begin(), p.end(), 0);
		return t/(int)p.size();
	}
	int countCuts(vector <int> poles) {
		int sol = 0;
		while (!same(poles)) {
			++sol;
			sort(poles.begin(), poles.end(), greater<int>());
			const int t = avg(poles);
			poles[poles.size()-1] += (poles[0]-t);
			poles[0] = t;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, countCuts(Arg0)); }
	void test_case_1() { int Arr0[] = {10,10,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, countCuts(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, countCuts(Arg0)); }
	void test_case_3() { int Arr0[] = {10,10,10,10,10,10,10,18}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, countCuts(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CuttingPoles ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
