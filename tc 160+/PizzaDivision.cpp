#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Point {
	int x, y;
	Point(int x_, int y_): x(x_), y(y_) {}
	Point(const string &s) { istringstream(s) >> x >> y; }
};
bool beautiful(int x, int y, const vector<Point> &p) {
	for (int i=0; i<(int)p.size(); ++i) {
		bool ok = false;
		for (int j=0; j<(int)p.size(); ++j)
			if (x*(p[i].y+p[j].y) - y*(p[i].x+p[j].x) == 0
				&&
				x*(p[j].x-p[i].x) + y*(p[j].y-p[i].y) == 0) {
					ok = true;
					break;
			}
		if (!ok)
			return false;
	}
	return true;
}
int gcd(int a, int b) {
	if (a == 0) return b;
	else return gcd(b%a, a);
}
class PizzaDivision {
	public:
	int howMany(vector <string> toppings) {
		vector<Point> p;
		for (int i=0; i<(int)toppings.size(); ++i)
			p.push_back(Point(toppings[i]));

		int sol = 0;
		for (int x=-1000; x<=1000; ++x)
			for (int y=1; y<=1000; ++y)
				if (gcd(x>=0 ? x:-x, y) == 1)
					sol += beautiful(x, y, p);
		sol += beautiful(1, 0, p);

		return (sol>10000 ? -1:sol);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0 110", "0 70", "-75 20", "75 20", "-25 -50", "25 -50"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { string Arr0[] = {"0 70", "70 0", "0 -70", "-70 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { string Arr0[] = {"0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { string Arr0[] = {"3 -4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, howMany(Arg0)); }
	void test_case_4() { string Arr0[] = {"3 -4", "-3 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, howMany(Arg0)); }
	void test_case_5() { string Arr0[] = {"1 2", "3 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, howMany(Arg0)); }
	void test_case_6() { string Arr0[] = {"-300 100", "-200 100", "-100 100", "100 100",
"200 100", "300 100", "-300 -100", "-200 -100",
"-100 -100", "100 -100", "200 -100", "300 -100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(6, Arg1, howMany(Arg0)); }
	void test_case_7() { string Arr0[] = {"-54 -83", "-46 54", "-5 -44", "-1 -31", "-14 47",
"7 -5", "-45 -63", "-88 47", "-17 -9", "-26 -66",
"40 56", "-67 69", "-49 -2", "2 62", "61 78",
"-81 -32", "87 33", "-22 -53", "-43 -38", "57 28",
"35 12", "-53 -15", "52 -16", "32 -44", "-73 68",
"79 44", "3 56", "-66 26", "-87 41", "4 87",
"22 53", "59 16", "-3 55", "3 19", "-26 8",
"43 38", "54 46", "-16 22", "-3 -93", "45 63",
"0 -37", "-7 5", "-40 -56", "40 19", "-8 -63",
"-16 -89", "29 11", "-52 -21", "-58 -22", "4 -61"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(7, Arg1, howMany(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PizzaDivision ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
