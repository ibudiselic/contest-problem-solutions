#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define INF (987654321987654321LL)

long long dist[50][50];
string toStr(int x) {
	ostringstream os;
	os << x;
	return os.str();
}
class SalesmansDilemma {
	public:
	string bestRoute(int towns, int origin, int destination, vector <string> travelCosts, vector <int> profits) {
		for (int i=0; i<towns; ++i)
			for (int j=0; j<towns; ++j)
				dist[i][j] = -INF;

		for (int k=0; k<(int)travelCosts.size(); ++k) {
			int i, j, x;
			sscanf(travelCosts[k].c_str(), "%d %d %d", &i, &j, &x);
			dist[i][j] = max(dist[i][j], (long long)profits[j]-x);
		}

		for (int i=0; i<towns; ++i)
			dist[i][i] = max(dist[i][i], 0LL);

		for (int k=0; k<towns; ++k)
			for (int i=0; i<towns; ++i)
				for (int j=0; j<towns; ++j)
					if (dist[i][k]!=-INF && dist[k][j]!=-INF)
						dist[i][j] = max(dist[i][j], dist[i][k] + dist[k][j]);

		long long sol = dist[origin][destination];

		if (sol == -INF)
			return "IMPOSSIBLE";

		for (int k=0; k<towns; ++k)
			for (int i=0; i<towns; ++i)
				for (int j=0; j<towns; ++j)
					if (dist[i][k]!=-INF && dist[k][j]!=-INF)
						if (dist[i][k]+dist[k][j] > dist[i][j] && dist[origin][i]!=-INF && dist[j][destination]!=-INF)
							return "ENDLESS PROFIT";

		return "BEST PROFIT: " + toStr(sol+profits[origin]);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 0; int Arg2 = 4; string Arr3[] = {"0 1 10", "1 2 10", "2 3 10", "3 1 10", "2 4 10"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 10, 10, 110, 10}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = "ENDLESS PROFIT"; verify_case(0, Arg5, bestRoute(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 0; int Arg2 = 4; string Arr3[] = {"0 1 13", "1 2 17", "2 4 20", "0 3 22", "1 3 4747", "2 0 10", "3 4 10"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 0, 0, 0, 0}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = "BEST PROFIT: -32"; verify_case(1, Arg5, bestRoute(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 2; string Arr3[] = {"0 1 10", "1 0 10", "2 1 10"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1000, 1000, 47000}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = "IMPOSSIBLE"; verify_case(2, Arg5, bestRoute(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 1; string Arr3[] = {"0 1 1000", "1 1 10"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {11, 11}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = "ENDLESS PROFIT"; verify_case(3, Arg5, bestRoute(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 0; string Arr3[] = {"0 0 10"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {7}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = "BEST PROFIT: 7"; verify_case(4, Arg5, bestRoute(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 5; int Arg1 = 0; int Arg2 = 4; string Arr3[] = {"0 1 13", "1 2 17", "2 4 20", "0 3 22", "1 3 4747", "2 0 10", "3 4 10"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {8, 10, 20, 1, 100000}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = "BEST PROFIT: 99988"; verify_case(5, Arg5, bestRoute(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SalesmansDilemma ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
