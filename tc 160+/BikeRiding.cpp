#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long dist[50][50];
class BikeRiding {
	public:
	int countRoutes(vector <string> paths, vector <int> startPoints, int endPoint, int lim) {
		int n = (int)paths.size();
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				dist[i][j] = paths[i][j]-'0';

		for (int k=0; k<n; ++k)
			for (int i=0; i<n; ++i)
				for (int j=0; j<n; ++j)
					dist[i][j] += dist[i][k]*dist[k][j];

		for (int i=0; i<(int)startPoints.size(); ++i) {
			int x = startPoints[i];
			for (int y=0; y<n; ++y)
				if (dist[x][y] && dist[y][endPoint] && dist[y][y])
					return -1;
		}

		long long sol = 0;
		for (int i=0; i<(int)startPoints.size(); ++i) {
			if (sol > lim)
				return -1;
			sol += dist[startPoints[i]][endPoint];
		}

		return sol>lim ? -1:sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"011" ,"001", "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 5; int Arg4 = 3; verify_case(0, Arg4, countRoutes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"01000",
 "00100",
 "00010",
 "01001",
 "00000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 10; int Arg4 = -1; verify_case(1, Arg4, countRoutes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"000111000000000","000111000000000","000111000000000",
 "000000111000000","000000111000000","000000111000000",
 "000000000111000","000000000111000","000000000111000",
 "000000000000111","000000000000111","000000000000111",
 "000000000000001","000000000000001","000000000000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; int Arg3 = 1000; int Arg4 = 243; verify_case(2, Arg4, countRoutes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"010", "100", "001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 10; int Arg4 = 0; verify_case(3, Arg4, countRoutes(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BikeRiding ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
