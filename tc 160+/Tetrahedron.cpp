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

int D[4][4];
double sqr(double x) { return x*x; }
double dist(double x1, double y1, double x2, double y2) {
	return sqrt(sqr(x1-x2) + sqr(y1-y2));
}
class Tetrahedron {
	public:
	string exists(vector <string> d) {
		for (int i=0; i<4; ++i) {
			istringstream is(d[i]);
			for (int j=0; j<4; ++j)
				is >> D[i][j];
		}

		for (int i=0; i<4; ++i)
			for (int j=0; j<4; ++j)
				for (int k=0; k<4; ++k)
					if (D[i][j] + D[j][k] < D[i][k])
						return "NO";

		double x1 = 0;
		double y1 = 0;
		double x2 = D[0][1];
		double y2 = 0;
		double x3 = (sqr(D[0][2])-sqr(D[1][2])+sqr(x2))/2/x2;
		double y3 = sqrt(sqr(D[0][2])-sqr(x3));
		double x4 = (sqr(D[0][3])-sqr(D[1][3])+sqr(x2))/2/x2;
		double y4 = sqrt(sqr(D[0][3])-sqr(x4));

		if (dist(x3, y3, x4, y4) <= D[2][3]+1e-9 && dist(x3, y3, x4, -y4) >= D[2][3]-1e-9)
			return "YES";
		return "NO";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0 1 1 1",
 "1 0 1 1",
 "1 1 0 1",
 "1 1 1 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, exists(Arg0)); }
	void test_case_1() { string Arr0[] = {"0 1 2 3",
 "1 0 1 2",
 "2 1 0 1",
 "3 2 1 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(1, Arg1, exists(Arg0)); }
	void test_case_2() { string Arr0[] = {"0 1 2 4",
 "1 0 1 2",
 "2 1 0 1",
 "4 2 1 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(2, Arg1, exists(Arg0)); }
	void test_case_3() { string Arr0[] = {"0 6 6 3",
 "6 0 4 5",
 "6 4 0 4",
 "3 5 4 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(3, Arg1, exists(Arg0)); }
	void test_case_4() { string Arr0[] = {"0 6 6 2",
 "6 0 4 5",
 "6 4 0 4",
 "2 5 4 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(4, Arg1, exists(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Tetrahedron ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
