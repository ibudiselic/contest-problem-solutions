#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Intersect {
	public:
	int area(vector <int> x, vector <int> y) {
		int x1, x2, y1, y2;
		x1 = y1 = -100000;
		x2 = y2 = 100000;

		for (int i=0; 2*i<(int)x.size(); ++i) {
			const int t = 2*i;
			x1 = max(x1, min(x[t], x[t+1]));
			y1 = max(y1, min(y[t], y[t+1]));
			x2 = min(x2, max(x[t], x[t+1]));
			y2 = min(y2, max(y[t], y[t+1]));
		}
		return (x2-x1>0 && y2-y1>0) ? (x2-x1)*(y2-y1) : 0;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,2,3,-4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {17,1000,18,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, area(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {10000,-10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-10000,10000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 400000000; verify_case(1, Arg2, area(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {3,8,6,12,10,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7,17,7,17,7,17}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, area(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,5,5,5,5,5,5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, area(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {2,100,5,32,1000,-20,47,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {29,-1000,-800,-200,-900,300,-600,-650}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; verify_case(4, Arg2, area(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1,7,12,3,16,8,3,12}	; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-90,-60,-70,3,-60,-90,-80,-100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(5, Arg2, area(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Intersect ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
