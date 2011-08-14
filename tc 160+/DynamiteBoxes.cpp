#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
#define SINGLE 121

bool done[31][1<<4][121][122];
double dp[31][1<<4][121][122];
int sz;
template<class T> int bitcount(T x) {
	int ret = 0;
	while (x != 0) {
		++ret;
		x &= (x-1);
	}
	return ret;
}
double go1(int h, int mask, int cnt);

double go2(int h, int mask, int cnt1, int cnt2) {
	if (cnt1>=sz || cnt2>=sz)
		return 1.0;
	if (h == 0)
		return 0.0;
	if (done[h][mask][cnt1][cnt2])
		return dp[h][mask][cnt1][cnt2];
	done[h][mask][cnt1][cnt2] = 1;
	double &ret = dp[h][mask][cnt1][cnt2];
	ret = 0.0;
	assert(mask==6 || mask==9);
	const int special = (mask==6 ? 9 : 6);
	ret += go1(h-1, 0, 0);
	ret += go1(h-1, 1, ((mask&1) ? cnt1+1 : 1));
	ret += go1(h-1, 2, ((mask&2) ? cnt1+1 : 1));
	ret += go1(h-1, 3, cnt1+2);
	ret += go1(h-1, 4, ((mask&4) ? cnt2+1 : 1));
	ret += go1(h-1, 5, ((mask&1) ? cnt1+2 : cnt2+2));
	ret += go2(h-1, special, 1, 1);
	ret += go1(h-1, 7, cnt1+cnt2+3);
	ret += go1(h-1, 8, ((mask&8) ? cnt2+1 : 1));
 	ret += go2(h-1, mask, cnt1+1, cnt2+1);
 	ret += go1(h-1, 10, ((mask&2) ? cnt1+2 : cnt2+2));
 	ret += go1(h-1, 11, cnt1+cnt2+3);
	ret += go1(h-1, 12, cnt2+2);
	ret += go1(h-1, 13, cnt1+cnt2+3);
	ret += go1(h-1, 14, cnt1+cnt2+3);
	ret += go1(h-1, 15, cnt1+cnt2+4);
	ret /= 16;

	return ret;
}

double go1(int h, int mask, int cnt) {
	if (cnt >= sz)
		return 1.0;
	if (h == 0)
		return 0.0;
	if (done[h][mask][cnt][SINGLE])
		return dp[h][mask][cnt][SINGLE];

	const int bc = bitcount(mask);
	done[h][mask][cnt][SINGLE] = 1;
	double &ret = dp[h][mask][cnt][SINGLE];
	ret = 0.0;

	ret += go1(h-1, 0, 0);
	ret += go1(h-1, 1, ((mask&1) ? cnt+1 : 1));
	ret += go1(h-1, 2, ((mask&2) ? cnt+1 : 1));
	ret += go1(h-1, 3, ((mask&3) ? cnt+2 : 2));
	ret += go1(h-1, 4, ((mask&4) ? cnt+1 : 1));
	ret += go1(h-1, 5, ((mask&5) ? cnt+2 : 2));
	if (bc >= 3)
		ret += go1(h-1, 6, cnt+2);
	else {
		if (mask != 6)
			ret += go2(h-1, 6, ((mask&2) ? cnt+1 : 1), ((mask&4) ? cnt+1 : 1));
		else
			ret += go1(h-1, 6, cnt+2);
	}
	ret += go1(h-1, 7, ((mask&7) ? cnt+3 : 3));
	ret += go1(h-1, 8, ((mask&8) ? cnt+1 : 1));
	if (bc >= 3)
		ret += go1(h-1, 9, cnt+2);
	else {
		if (mask != 9)
			ret += go2(h-1, 9, ((mask&1) ? cnt+1 : 1), ((mask&8) ? cnt+1 : 1));
		else
			ret += go1(h-1, 9, cnt+2);
	}
	ret += go1(h-1, 10, ((mask&10) ? cnt+2 : 2));
	ret += go1(h-1, 11, ((mask&11) ? cnt+3 : 3));
	ret += go1(h-1, 12, ((mask&12) ? cnt+2 : 2));
	ret += go1(h-1, 13, ((mask&13) ? cnt+3 : 3));
	ret += go1(h-1, 14, ((mask&14) ? cnt+3 : 3));
	ret += go1(h-1, 15, ((mask&15) ? cnt+4 : 4));
	ret /= 16;
	return ret;
}
class DynamiteBoxes {
	public:
	double getProbability(int height, int dangerousClusterSize) {
		memset(done, 0, sizeof done);
		sz = dangerousClusterSize;

		return go1(height, 0, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; double Arg2 = 0.9375; verify_case(0, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 2; double Arg2 = 0.5625; verify_case(1, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 4; double Arg2 = 0.51171875; verify_case(2, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 3; double Arg2 = 0.859130859375; verify_case(3, Arg2, getProbability(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DynamiteBoxes ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
