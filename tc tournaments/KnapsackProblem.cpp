#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

vector<int> X;
map<long long, long long> M;
vector<long long> A, B;

void go(int pos, long long val) {
	if (pos == (int)X.size()/2) {
		++M[val];
		return;
	}

	go(pos+1, val);
	go(pos+1, val+X[pos]);
}

int go2(int pos, long long rem) {
	if (pos == (int)X.size()) {
		const vector<long long>::const_iterator it = lower_bound(A.begin(), A.end(), rem);
		assert(it != A.end());
		return *it==rem ? B[it-A.begin()] : (it-A.begin() > 0 ? B[it-A.begin()-1] : 0);
	}

	int ret = go2(pos+1, rem);
	if (rem >= X[pos])
		ret += go2(pos+1, rem-X[pos]);

	return ret;
}
class KnapsackProblem {
	public:
	int numberOfWays(vector <int> x, int C) {
		if (x.size() < 16) {
			int n = x.size();
			int sol = 0;
			for (int m=0; m<(1<<n); ++m) {
				long long val = 0;
				for (int i=0; i<n; ++i)
					if (m & (1<<i))
						val += x[i];
				sol += (val <= C);
			}

			return sol;
		}

		X = x;
		M.clear();
		go(0, 0);
		A.clear();
		B.clear();

		long long last = 0;
		for (map<long long, long long>::iterator it=M.begin(); it!=M.end(); ++it) {
			last += it->second;
			A.push_back(it->first);
			B.push_back(last);
		}
		A.push_back(C+1);
		B.push_back(last);

		return go2(x.size()/2, C);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, numberOfWays(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; verify_case(1, Arg2, numberOfWays(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; verify_case(2, Arg2, numberOfWays(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 4; verify_case(3, Arg2, numberOfWays(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 3; verify_case(4, Arg2, numberOfWays(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; int Arg2 = 1073741824; verify_case(5, Arg2, numberOfWays(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    KnapsackProblem ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
