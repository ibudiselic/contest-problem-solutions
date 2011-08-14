#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <cmath>

using namespace std;

bool flt(const pair<int, int> &a, const pair<int, int> &b) {
	return a.second*b.first > a.first*b.second;
}
class PuckShot {
	public:
	double caromAngle(int a, vector <int> x, vector <int> y) {
		a *= 2;

		vector< pair<int, int> > p;
		vector<int> d;

		for (int i=0; i<(int)x.size(); ++i) {
			x[i] *= 2;
			y[i] *= 2;
			p.push_back(make_pair(x[i]-50-a, y[i])); d.push_back(1);
			p.push_back(make_pair(x[i]+50-a, y[i])); d.push_back(-1);
			p.push_back(make_pair(12000-x[i]-50-a, y[i])); d.push_back(1);
			p.push_back(make_pair(12000-x[i]+50-a, y[i])); d.push_back(-1);
		}
		p.push_back(make_pair(9000-183-a, 2*1733)); d.push_back(-1000);
		p.push_back(make_pair(9000+183-a, 2*1733)); d.push_back(1000);

		for (int i=0; i<(int)p.size(); ++i)
			for (int j=i+1; j<(int)p.size(); ++j)
				if (flt(p[j], p[i])) {
					swap(p[i], p[j]);
					swap(d[i], d[j]);
				}

		int t = 1000;
		int i = 0;
		for (i=0; i<(int)p.size(); ++i) {
			t += d[i];
			while (i+1<(int)p.size() && !flt(p[i], p[i+1]) && !flt(p[i+1], p[i]))
				t += d[++i];
			if (t == 0)
				break;
		}

		if (i == (int)p.size())
			return -1;

		return atan2(p[i].second, p[i].first) * 180/acos(-1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2833; int Arr1[] = {1500, 1580}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1730, 1730}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 47.022170720170784; verify_case(0, Arg3, caromAngle(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2833; int Arr1[] = {2690}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {500}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 44.88563731851585; verify_case(1, Arg3, caromAngle(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2833; int Arr1[] = {2690, 2676}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {500, 500}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = -1.0; verify_case(2, Arg3, caromAngle(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 55; int Arr1[] = {1479, 1427, 2556, 2834, 2866, 2958, 2763, 2899, 2630}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1708, 1726, 487, 471, 121, 446, 473, 266, 380}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 21.706043385046158; verify_case(3, Arg3, caromAngle(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1809; int Arr1[] = {1571}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1730}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 33.18726534329994; verify_case(4, Arg3, caromAngle(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PuckShot ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
