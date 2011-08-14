#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

#define MAXTIME(P) P.first
#define VAL(P) P.second.first
#define TIME(P) P.second.second
#define MAKE(MT, V, T) make_pair(MT, make_pair(V,T))

typedef pair<int, pair<int, int> > tri;
vector<tri> d;
int n;
class JimmyLightning {
	public:
	int robTheBank(vector <int> doors, vector <string> diamonds) {
		n = doors.size();
		d.clear();
		for (int i=0; i<(int)diamonds.size(); ++i) {
			istringstream is(diamonds[i]);
			int v, t, r;
			is >> v >> t >> r;
			int mt = *min_element(doors.begin(), doors.begin()+r) - 1;
			if (t <= mt)
				d.push_back(MAKE(mt, v, t));
		}

		vector<int> best(1001, -1);
		best[0] = 0;
		for (int t=1; t<1001; ++t) {
			best[t] = best[t-1];
			for (int i=0; i<(int)d.size(); ++i)
				if (MAXTIME(d[i]) >= t)
					if (TIME(d[i]) <= t)
						best[t] = max(best[t], best[t - TIME(d[i])] + VAL(d[i]));
		}

		return best[1000];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 1 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(0, Arg2, robTheBank(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"999 1 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, robTheBank(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10, 5, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 1 1",
 "2 1 2",
 "3 1 3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; verify_case(2, Arg2, robTheBank(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    JimmyLightning ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
