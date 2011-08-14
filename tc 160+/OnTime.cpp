#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

long long best[1<<16][50];
class OnTime {
	public:
	int minCost(int N, int T, vector <string> buses) {
		for (int i=0; i<=T+1; ++i)
			for (int j=0; j<N; ++j)
				best[i][j] = 1LL<<62;

		int n = buses.size();
		vector<int> departureTime(n, 0), tripTime(n, 0), start(n, 0), finish(n, 0), cost(n, 0);
		map<int, vector<int> > busInd;

		for (int i=0; i<n; ++i) {
			istringstream is(buses[i]);
			is >> start[i] >> finish[i] >> departureTime[i] >> tripTime[i] >> cost[i];
			busInd[departureTime[i]].push_back(i);
		}

		best[0][0] = 0;

		for (int t=0; t<=T; ++t) {
			const vector<int> &v = busInd[t];
			for (int pos=0; pos<N; ++pos) {
				best[t+1][pos] <?= best[t][pos];
				for (int i=0; i<(int)v.size(); ++i) {
					const int j = v[i];
					if (start[j] == pos)
						best[t+tripTime[j]+1][finish[j]] <?= best[t][pos] + cost[j];
				}
			}
		}

		return (int)(best[T+1][N-1]==1LL<<62 ? -1 : best[T+1][N-1]);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 8; string Arr2[] = {"0 1 0 4 3", "1 2 5 3 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; verify_case(0, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 8; string Arr2[] = {"0 1 0 4 3", "1 2 6 3 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(1, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 7; string Arr2[] = {"0 1 0 5 1", "1 2 6 1 40", "0 1 1 2 5", "1 2 4 2 5"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(2, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 8; string Arr2[] = {"0 1 0 5 3", "1 2 5 3 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(3, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 100; string Arr2[] = {"0 1 0 1 1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(4, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 9; int Arg1 = 100; string Arr2[] = {"0 3 1 6 15", "0 6 0 23 20", "6 2 25 15 30", "6 1 30 15 40", "3 1 15 35 10",
 "3 2 30 80 40", "1 5 55 25 25", "1 2 49 31 10", "2 8 85 10 10", "5 8 83 15 5"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 55; verify_case(5, Arg3, minCost(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    OnTime ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
