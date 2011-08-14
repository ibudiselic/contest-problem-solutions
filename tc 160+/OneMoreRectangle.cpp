#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

vector<int> x1, y1, x2, y2; // ll, ur
int N;
inline bool contains(int a, int b, int c, int d, int i) {
	return a<=x1[i] && b<=y1[i] && c>=x1[i] && d>=y1[i]
			&&
		   a<=x2[i] && b<=y2[i] && c>=x2[i] && d>=y2[i];
}
int cnt(int a, int b, int c, int d) {
	int ret = 0;
	for (int i=0; i<N; ++i)
		ret += contains(a, b, c, d, i);
	return ret;
}
class OneMoreRectangle {
	public:
	int maxCover(vector <string> rectangles, int qa, int qb) {
		N = rectangles.size();
		x1.assign(N, 0);
		x2.assign(N, 0);
		y1.assign(N, 0);
		y2.assign(N, 0);
		for (int i=0; i<N; ++i)
			sscanf(rectangles[i].c_str(), "%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);

		set<int> xx;
		set<int> yy;
		for (int i=0; i<N; ++i) {
			xx.insert(x1[i]);
			xx.insert(x2[i]);
			yy.insert(y1[i]);
			yy.insert(y2[i]);
		}

		vector<int> x(xx.begin(), xx.end());
		vector<int> y(yy.begin(), yy.end());

		int sol = 0;
		for (int i=0; i<(int)x.size(); ++i)
			for (int j=0; j<(int)y.size(); ++j) {
				sol = max(sol, cnt(x[i], y[j], x[i]+qa, y[j]+qb));
				sol = max(sol, cnt(x[i], y[j], x[i]+qb, y[j]+qa));
			}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 1 2 2","2 2 3 3","3 3 4 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; verify_case(0, Arg3, maxCover(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"1 1 5 5","1 1 4 2","1 1 2 4", "2 3 5 5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; int Arg3 = 2; verify_case(1, Arg3, maxCover(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"1 1 4 2","1 2 2 5","4 1 5 4","2 4 5 5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; int Arg3 = 1; verify_case(2, Arg3, maxCover(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"1 1 4 2","1 2 2 5","4 1 5 4","2 4 5 5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 4; int Arg3 = 4; verify_case(3, Arg3, maxCover(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"1 4 6573 345","23 4366 23545 366783","54 7895 2565 23567","3456 345 475457 45767654",
"-234 -654885 0 0","-32654 -43256 -34 -5463","-10000 -10000 10000 10000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100000; int Arg2 = 100000; int Arg3 = 4; verify_case(4, Arg3, maxCover(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    OneMoreRectangle ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
