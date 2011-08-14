#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

/*
sum(N) is the sum of the decimal digits of N.
prod(N) is the product of the decimal digits of N.
prod3(N) is the product of the three largest decimal digits of N. If N has less than three digits, prod3(N)=prod(N).
smallest(N) is the smallest decimal digit of N.
first(N) is the first (most significant) decimal digit of N.
Now we may define the binary operator @ as follows:
X@Y = 5 * prod3(X) + first(X) * sum(Y) + smallest(Y)
*/
#define maxx 1000001

int p3[maxx], f[maxx], s[maxx], sm[maxx];

int prod3(int x) {
	int &ret = p3[x];
	if (ret != -1)
		return ret;

	vector<int> dx;
	while (x > 0) {
		dx.push_back(x%10);
		x /= 10;
	}

	ret = 0;
	if (dx.size() > 0) {
		ret = 1;
		sort(dx.begin(), dx.end());
		for (int i=(int)dx.size()-1; i>=0 && (int)dx.size()-i<=3; --i)
			ret *= dx[i];
	}

	return ret;
}
int first(int x) {
	int &ret = f[x];
	if (ret != -1)
		return ret;

	while (x >= 10)
		x /= 10;

	return ret = x;
}
int sum(int x) {
	int &ret = s[x];
	if (ret != -1)
		return ret;

	vector<int> dx;
	while (x > 0) {
		dx.push_back(x%10);
		x /= 10;
	}

	return ret = accumulate(dx.begin(), dx.end(), 0);
}
int smallest(int x) {
	int &ret = sm[x];
	if (ret != -1)
		return ret;

	vector<int> dx;
	while (x > 0) {
		dx.push_back(x%10);
		x /= 10;
	}

	return ret = *min_element(dx.begin(), dx.end());
}

int calc(int a, int b) {
	return 5*prod3(a) + first(a)*sum(b) + smallest(b);
}

int best[1000001];
class NewOperator {
	public:
	int minimumCount(int x, int goal) {
		if (goal == x)
			return 0;
		if (goal > 10000)
			return -1;

		vector< vector<int> > cost;
		memset(best, 0xff, sizeof best);
		memset(f, 0xff, sizeof f);
		memset(s, 0xff, sizeof s);
		memset(sm, 0xff, sizeof sm);
		memset(p3, 0xff, sizeof p3);

		cost.push_back(vector<int>(1, x));
		best[x] = 0;
		int maxd = 1;

		for (int d=1; d<=2*maxd; ++d) {
			vector<int> dist_d;
			for (int d1=0; d1<d; ++d1) {
				int d2 = d-d1-1;
				for (int i=0; i<(int)cost[d1].size(); ++i)
					for (int j=0; j<(int)cost[d2].size(); ++j) {
						x = calc(cost[d1][i], cost[d2][j]);
						if (best[x] == -1) {
							best[x] = d;
							maxd = d;
							dist_d.push_back(x);
						}
					}
			}
			cost.push_back(dist_d);
		}

		return best[goal];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 13; int Arg1 = 13; int Arg2 = 0; verify_case(0, Arg2, minimumCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 374; int Arg1 = 465; int Arg2 = 1; verify_case(1, Arg2, minimumCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 374; int Arg1 = 469; int Arg2 = 2; verify_case(2, Arg2, minimumCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 374; int Arg1 = 659; int Arg2 = 2; verify_case(3, Arg2, minimumCount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 374; int Arg1 = 1024; int Arg2 = 8; verify_case(4, Arg2, minimumCount(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 654321; int Arg1 = 12; int Arg2 = 10; verify_case(5, Arg2, minimumCount(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 654321; int Arg1 = 1234567; int Arg2 = -1; verify_case(6, Arg2, minimumCount(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    NewOperator ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
