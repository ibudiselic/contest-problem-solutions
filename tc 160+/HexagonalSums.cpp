#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> H;
bool dp[131][5];
bool done[131][5];
bool canMake(int n, int cnt) {
	if (cnt == 0)
		return n==0;

	if (done[n][cnt])
		return dp[n][cnt];

	done[n][cnt] = 1;
	for (int i=0; H[i]<=n; ++i)
		if (canMake(n-H[i], cnt-1))
			return dp[n][cnt] = 1;

	return dp[n][cnt] = 0;
}
bool testOne(int n) {
	return find(H.begin(), H.end(), n) != H.end();
}
bool testTwo(int n) {
	int l=0, r=(int)H.size()-1;

	while (l <= r)
		if (H[l]+H[r] == n)
			return 1;
		else if (H[l]+H[r] < n)
			++l;
		else
			--r;

	return 0;
}
bool testThree(int n) {
	for (int i=0; H[i]<n; ++i)
		if (testTwo(n-H[i]))
			return true;

	return false;
}
class HexagonalSums {
	public:
	int minLength(int N) {
		H.clear();
		H.push_back(1);
		H.push_back(6);

		for (int i=2; ; ++i) {
			const int t = H[i-1] + 2*(i+1) + i + (i-1);
			H.push_back(t);
			if (t > N)
				break;
		}

		if (N <= 130) {
			if (N==11 || N==26)
				return 6;
			memset(done, 0, sizeof done);
			for (int i=1; i<5; ++i)
				if (canMake(N, i))
					return i;
			return 5;
		} else if (N <= 146858) {
			if (testOne(N))
				return 1;
			if (testTwo(N))
				return 2;
			if (testThree(N))
				return 3;
			return 4;
		} else {
			if (testOne(N))
				return 1;
			if (testTwo(N))
				return 2;
			return 3;
		}

		return 0;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 26; int Arg1 = 6; verify_case(0, Arg1, minLength(Arg0)); }
	void test_case_1() { int Arg0 = 130; int Arg1 = 5; verify_case(1, Arg1, minLength(Arg0)); }
	void test_case_2() { int Arg0 = 146858; int Arg1 = 4; verify_case(2, Arg1, minLength(Arg0)); }
	void test_case_3() { int Arg0 = 999999; int Arg1 = 3; verify_case(3, Arg1, minLength(Arg0)); }
	void test_case_4() { int Arg0 = 1000000; int Arg1 = 2; verify_case(4, Arg1, minLength(Arg0)); }
	void test_case_5() { int Arg0 = 145530; int Arg1 = 1; verify_case(5, Arg1, minLength(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    HexagonalSums ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
