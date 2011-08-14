#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int maxpath;
class PowerOutage {
	public:
	void go(const vector<vector<int> > &a, int v, int len) {
		if (len > maxpath)
			maxpath = len;

		for (int i=0; i<(int)a[0].size(); ++i)
			if (a[v][i])
				go(a, i, len+a[v][i]);
	}
	int estimateTimeOut(vector <int> from, vector <int> to, vector <int> len) {
		int sol = 0;
		vector<vector<int> > a(50, vector<int>(50, 0));

		for (int i=0; i<(int)from.size(); ++i) {
			a[from[i]][to[i]] = len[i];
			sol += len[i];
		}
		maxpath = 0;
		go(a, 0, 0);

		return 2*sol-maxpath;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(0, Arg3, estimateTimeOut(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,10,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 40; verify_case(1, Arg3, estimateTimeOut(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,0,0,1,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,4,2,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,10,100,10,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 165; verify_case(2, Arg3, estimateTimeOut(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,0,1,4,4,6,7,7,7,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,4,2,5,6,7,20,9,10,31}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,10,100,10,5,1,1,100,1,1,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 281; verify_case(3, Arg3, estimateTimeOut(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100,200,300,400,500}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2500; verify_case(4, Arg3, estimateTimeOut(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PowerOutage ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
