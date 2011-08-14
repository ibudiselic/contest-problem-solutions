#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class CircleDance {
	public:
	int arrangeDancers(vector <int> h) {
		sort(h.begin(), h.end());
		vector<int> v;
		for (int i=0; i<(int)h.size(); i+=2)
			v.push_back(h[i]);
		for (int i=(h.size()%2 == 0 ? h.size()-1 : h.size()-2); i>0; i-=2)
			v.push_back(h[i]);

		int sol = abs(v[0]-v.back());
		for (int i=1; i<(int)v.size(); ++i)
			sol = max(sol, abs(v[i]-v[i-1]));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {180,183,178,185}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, arrangeDancers(Arg0)); }
	void test_case_1() { int Arr0[] = {170,180,190}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(1, Arg1, arrangeDancers(Arg0)); }
	void test_case_2() { int Arr0[] = {180,180,180,180,180}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, arrangeDancers(Arg0)); }
	void test_case_3() { int Arr0[] = {184,165,175,186,192,200,176,192,194,168,205,201}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, arrangeDancers(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CircleDance ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
