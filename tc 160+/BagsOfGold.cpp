#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[50][50];
int sum[50][50];
bool done[50][50];
vector<int> B;
int go(int l, int r) {
	if (l == r)
		return B[l];

	if (done[l][r])
		return dp[l][r];

	done[l][r] = 1;
	return dp[l][r] = max(B[l] + sum[l+1][r]-go(l+1, r), B[r] + sum[l][r-1]-go(l, r-1));
}
class BagsOfGold {
	public:
	int netGain(vector <int> bags) {
		B = bags;
		memset(done, 0, sizeof done);
		memset(sum, 0, sizeof sum);

		for (int i=0; i<(int)bags.size(); ++i)
			sum[i][i] = bags[i];

		for (int l=2; l<=(int)bags.size(); ++l)
			for (int i=0; i+l<=(int)bags.size(); ++i)
				sum[i][i+l-1] = sum[i][i+l-2] + bags[i+l-1];

		return 2*go(0, bags.size()-1) - sum[0][bags.size()-1];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, netGain(Arg0)); }
	void test_case_1() { int Arr0[] = {2,7,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -2; verify_case(1, Arg1, netGain(Arg0)); }
	void test_case_2() { int Arr0[] = {1000,1000,1000,1000,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; verify_case(2, Arg1, netGain(Arg0)); }
	void test_case_3() { int Arr0[] = {823,912,345,100000,867,222,991,3,40000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -58111; verify_case(3, Arg1, netGain(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BagsOfGold ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
