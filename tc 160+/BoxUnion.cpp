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

bool inside(int x1, int y1, int x2, int y2, const vector<string> &r) {
	for (int i=0; i<(int)r.size(); ++i) {
		int a, b, c, d;
		sscanf(r[i].c_str(), "%d %d %d %d", &a, &b, &c, &d);
		if (a<=x1 && x1<=c && b<=y1 && y1<=d
		&&
		    a<=x2 && x2<=c && b<=y2 && y2<=d)
		    return true;
	}
	return false;
}
class BoxUnion {
	public:
	int area(vector <string> rectangles) {
		set<int> x_, y_;
		for (int i=0; i<(int)rectangles.size(); ++i) {
			int a, b, c, d;
			sscanf(rectangles[i].c_str(), "%d %d %d %d", &a, &b, &c, &d);
			x_.insert(a);
			x_.insert(c);
			y_.insert(b);
			y_.insert(d);
		}

		vector<int> x(x_.begin(), x_.end());
		vector<int> y(y_.begin(), y_.end());

		int sol = 0;
		for (int i=0; i+1<(int)x.size(); ++i)
			for (int j=0; j+1<(int)y.size(); ++j)
				if (inside(x[i], y[j], x[i+1], y[j+1], rectangles))
					sol += (x[i+1]-x[i])*(y[j+1]-y[j]);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "200 300 203 304" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(0, Arg1, area(Arg0)); }
	void test_case_1() { string Arr0[] = { "0 0 10 10",
  "20 20 30 30" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 200; verify_case(1, Arg1, area(Arg0)); }
	void test_case_2() { string Arr0[] = { "0 500 20000 501",
  "500 0 501 20000" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 39999; verify_case(2, Arg1, area(Arg0)); }
	void test_case_3() { string Arr0[] = { "4 6 18 24",
  "7 2 12 19",
  "0 0 100 100" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10000; verify_case(3, Arg1, area(Arg0)); }
	void test_case_4() { string Arr0[] = { "1 3 5 6",
  "3 1 7 5",
  "4 4 9 7" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 35; verify_case(4, Arg1, area(Arg0)); }
	void test_case_5() { string Arr0[] = { "0 0 20000 20000",
  "0 0 20000 20000",
  "0 0 20000 20000" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 400000000; verify_case(5, Arg1, area(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BoxUnion ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
