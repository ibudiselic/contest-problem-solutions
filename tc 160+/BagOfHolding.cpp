#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool used[10];
int good;
int cnt;
int I;
int cur;
vector<int> A;
int B[10];
void go(int x) {
	if (x == (int)A.size()) {
		bool ok = true;
		for (int i=cur+1; i<(int)A.size(); ++i)
			if (B[i] >= B[cur]) {
				ok = false;
				break;
			}
		++cnt;
		good += ok;
		return;
	}

	for (int i=0; i<(int)A.size(); ++i)
		if (!used[i]) {
			used[i] = 1;
			B[x] = A[i];
			if (i == I)
				cur = x;
			go(x+1);
			used[i] = 0;
		}
}
class BagOfHolding {
	public:
	double oddsReachable(vector <int> sizes, int item) {


		for (int i=0; i<(int)sizes.size(); ++i)
			for (int j=i+1; j<(int)sizes.size(); ++j)
				if (sizes[i] > sizes[j]) {
					swap(sizes[i], sizes[j]);
					if (item == i)
						item = j;
					else if (item == j)
						item = i;
				}

		memset(used, 0, sizeof used);
		good = cnt = 0;
		I = item;
		A = sizes;
		go(0);

		return double(good)/cnt;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 0.5; verify_case(0, Arg2, oddsReachable(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 1.0; verify_case(1, Arg2, oddsReachable(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 0.5; verify_case(2, Arg2, oddsReachable(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 0.16666666666666666; verify_case(3, Arg2, oddsReachable(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BagOfHolding ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
