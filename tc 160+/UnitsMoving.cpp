#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

double D[50][50];
int N;
bool G[50][50];
bool done[50];
int match[50], rmatch[50];

bool dfs(int x) {
	done[x] = true;

	for (int i=0; i<N; ++i)
		if (G[x][i])
			if (rmatch[i]==-1 || !done[rmatch[i]] && dfs(rmatch[i])) {
				match[x] = i;
				rmatch[i] = x;
				return true;
			}
	return false;
}
int bipartiteMatch() {
	int sz = 0;
	memset(match, 0xff, sizeof match);
	memset(rmatch, 0xff, sizeof rmatch);

	for (int i=0; i<N; ++i) {
		memset(done, 0, sizeof done);
		sz += dfs(i);
	}

	return sz;
}
class UnitsMoving {
	public:
	double bestTime(vector <string> start, vector <string> finish) {
		N = start.size();

		for (int i=0; i<N; ++i) {
			int x, y, v;
			sscanf(start[i].c_str(), "%d %d %d", &x, &y, &v);
			for (int j=0; j<N; ++j) {
				int xx, yy;
				sscanf(finish[j].c_str(), "%d %d", &xx, &yy);
				D[i][j] = sqrt((xx-x)*(xx-x) + (yy-y)*(yy-y))/v;
			}
		}

		double lo = 0, hi = 1000000;
		for (int t=0; t<1000; ++t) {
			double mid = (lo+hi)/2;
			memset(G, 0, sizeof G);
			for (int i=0; i<N; ++i)
				for (int j=0; j<N; ++j)
					G[i][j] = (D[i][j] <= mid);

			if (bipartiteMatch() == N)
				hi = mid;
			else
				lo = mid;
		}

		return (lo+hi)/2;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0 0 1", "0 1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 1", "1 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(0, Arg2, bestTime(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"0 0 1", "0 1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 1", "2 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.0; verify_case(1, Arg2, bestTime(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"0 0 1", "5 0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"5 12", "10 12"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 13.0; verify_case(2, Arg2, bestTime(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"0 0 2", "5 0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"5 12", "10 12"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 12.0; verify_case(3, Arg2, bestTime(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"308 994 10", "157 22 9", "282 975 5", "993 17 8", "925 771 2", "843 110 6",
"860 629 8", "947 143 6", "921 348 7", "520 607 6", "735 306 3",
"253 861 7", "562 56 9", "243 168 2", "521 971 1", "745 537 7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"431 911", "109 951", "177 721", "295 831", "937 256", "608 180", "863 994", "148 406",
"275 531", "635 297", "681 404", "909 151", "569 730", "332 391", "94 97", "376 142"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 115.72920979597156; verify_case(4, Arg2, bestTime(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    UnitsMoving ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
