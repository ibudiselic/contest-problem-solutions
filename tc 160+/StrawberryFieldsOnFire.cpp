#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <set>

using namespace std;
vector< pair<int, int> > F;
int W, H;

long long calc(int t) {
	set<int> X, Y;
	X.insert(0);
	X.insert(W);
	Y.insert(0);
	Y.insert(H);

	for (int i=0; i<(int)F.size(); ++i) {
		if (F[i].first - t > 0)
			X.insert(F[i].first - t);
		if (F[i].first + t+1 < W)
			X.insert(F[i].first + t+1);
		if (F[i].second - t > 0)
			Y.insert(F[i].second - t);
		if (F[i].second + t+1 < H)
			Y.insert(F[i].second + t+1);
	}
	vector<int> x(X.begin(), X.end());
	vector<int> y(Y.begin(), Y.end());

	long long ret = 0;
	for (int i=0; i<(int)x.size()-1; ++i)
		for (int j=0; j<(int)y.size()-1; ++j) {
			bool on_fire = false;
			for (int k=0; k<(int)F.size(); ++k)
				if (F[k].first-t <= x[i] && x[i] <= F[k].first+t
					&&
					F[k].second-t <= y[j] && y[j] <= F[k].second+t) {
						on_fire = true;
						break;
					}
			if (!on_fire)
				ret += (long long)(x[i+1]-x[i])*(y[j+1]-y[j]);
		}
	return ret;
}
class StrawberryFieldsOnFire {
	public:
	int timeLimit(int w, int h, string need_, vector <string> fire) {
		long long need;
		istringstream(need_) >> need;
		F.clear();
		W = w;
		H = h;
		for (int i=0; i<(int)fire.size(); ++i) {
			int x, y;
			istringstream is(fire[i]);
			is >> x >> y;
			F.push_back(make_pair(x-1, y-1));
		}

		int lo = 0;
		int hi = max(w, h)+1;

		while (lo < hi) {
			int mid = lo + (hi-lo+1)/2;
			long long rem = calc(mid);
			if (rem < need)
				hi = mid-1;
			else
				lo = mid;
		}

		return lo;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 5; string Arg2 = "12"; string Arr3[] = {"1 4","2 2"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(0, Arg4, timeLimit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 5; string Arg2 = "1"; string Arr3[] = {"1 4","2 2"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(1, Arg4, timeLimit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 5; string Arg2 = "13"; string Arr3[] = {"1 4","2 2"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(2, Arg4, timeLimit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1000000000; int Arg1 = 1; string Arg2 = "1"; string Arr3[] = {"1 1"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 999999998; verify_case(3, Arg4, timeLimit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 101; int Arg1 = 101; string Arg2 = "400"; string Arr3[] = {"51 51"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 49; verify_case(4, Arg4, timeLimit(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    StrawberryFieldsOnFire ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
