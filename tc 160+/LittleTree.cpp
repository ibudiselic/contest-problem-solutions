#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[101][101];
vector< vector<int> > E;
int H;

int go(int x, int L) {
	if (L > H) {
		return 123456789;
	}
	int &ret = dp[x][L];
	if (ret != -1) {
		return ret;
	}

	ret = 0;
	for (int i=0; i<(int)E[x].size(); ++i) {
		int y = E[x][i];
		int cur = go(y, L+1);
		for (int l=1; l<=L; ++l) {
			cur = min(cur, (L-l+1) + go(y, l));
		}
		ret += cur;
	}
	
	ret = min(ret, 123456789);
	return ret;
}

class LittleTree {
	public:
	int minCost(int N, vector <string> edges, int height) {
		H = height;
		E.clear();
		E.resize(N);
		string s;
		for (int i=0; i<(int)edges.size(); ++i) {
			s += edges[i];
		}
		istringstream is(s);
		string t;
		while (is >> t) {
			int x, y;
			sscanf(t.c_str(), "%d,%d", &x, &y);
			E[x].push_back(y);
		}

		memset(dp, 0xff, sizeof dp);
		return go(0, 0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; string Arr1[] = {"0,1 1,2 2,3 2,4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 1; verify_case(0, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; string Arr1[] = {"0,1 1,2 2,3 2,4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 3; verify_case(1, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; string Arr1[] = {"0,1 1,2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 0; verify_case(2, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 9; string Arr1[] = {"0,3 3,1 1,8 ","8,","6 2,7 4,2 0,4 7",",5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 2; verify_case(3, Arg3, minCost(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    LittleTree ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
