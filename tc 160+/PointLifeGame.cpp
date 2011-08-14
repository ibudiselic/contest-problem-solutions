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

struct point {
	long long x, y;
	point(long long x_, long long y_): x(x_), y(y_) {}
};
bool operator<(const point &a, const point &b) {
	if (a.y != b.y)
		return a.y > b.y;
	else
		return a.x > b.x;
}
class PointLifeGame {
	public:
	string simulate(vector <int> xs, vector <int> ys, int rnds) {
		set<point> S;
		long long div = 1;
		for (int i=0; i<(int)xs.size(); ++i)
			S.insert(point(xs[i], ys[i]));

		while (rnds--) {
			div *= 10;
			const vector<point> tmp(S.begin(), S.end());
			S.clear();
			for (int i=0; i+1<min((int)tmp.size(), 10); ++i)
				for (int j=i+1; j<min((int)tmp.size(), 10); ++j)
					S.insert(point((tmp[i].x + tmp[j].x)*5, (tmp[i].y + tmp[j].y)*5));
		}

		long long x = S.begin()->x;
		long long y = S.begin()->y;
		char buff[100];
		sprintf(buff, "%04lld.%04lld %04lld.%04lld", x/div, (x*10000/div)%10000, y/div, (y*10000/div)%10000);

		return string(buff);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,10,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,10,0,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; string Arg3 = "0005.0000 0010.0000"; verify_case(0, Arg3, simulate(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,0,10,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,10,0,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; string Arg3 = "0005.0097 0007.5000"; verify_case(1, Arg3, simulate(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,10,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,10,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; string Arg3 = "0015.0000 0005.0000"; verify_case(2, Arg3, simulate(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10,
 1,2,3,4,5,6,7,8,9,10,
 1,2,3,4,5,6,7,8,9,10,
 1,2,3,4,5,6,7,8,9,10,
 1,2,3,4,5,6,7,8,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1,1,1,1,1,1,1,1,
 2,2,2,2,2,2,2,2,2,2,
 3,3,3,3,3,3,3,3,3,3,
 4,4,4,4,4,4,4,4,4,4,
 5,5,5,5,5,5,5,5,5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; string Arg3 = "0009.0009 0005.0000"; verify_case(3, Arg3, simulate(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {3,3,8,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,1,1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; string Arg3 = "0002.4658 0002.1875"; verify_case(4, Arg3, simulate(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PointLifeGame ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
