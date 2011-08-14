#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Permutation {
	public:
	vector<int> prime_factorization(int x) {
		vector<int> ret;
		for (int i=2; i*i<x; ++i) {
			int t = 1;
			while (x%i == 0) {
				x /= i;
				t *= i;
			}
			if (t > 1)
				ret.push_back(t);
		}
		if (x > 1)
			ret.push_back(x);
		return ret;
	}
	int sum(vector<int> a) {
		int ret = 0;
		for (int i=0; i<(int)a.size(); ++i)
			ret += a[i];
		return ret;
	}
	string best(int n) {
		int max = 0;
		string pool = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		for (int i=1; i<200000; ++i) {
			vector<int> pf = prime_factorization(i);
			if (sum(pf) <= n)
				max = i;
		}
		vector<int> pf = prime_factorization(max);
		sort(pf.begin(), pf.end());
		int s = sum(pf);
		string sol;
		for (int i=0; i<n-s; ++i) {
			sol += pool[0];
			pool = pool.substr(1);
		}
		for (int i=0; i<(int)pf.size(); ++i) {
			string t = pool.substr(1, pf[i]-1) + pool[0];
			pool = pool.substr(pf[i]);
			sol += t;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; string Arg1 = "ACBEFD"; verify_case(0, Arg1, best(Arg0)); }
	void test_case_1() { int Arg0 = 7; string Arg1 = "BCAEFGD"; verify_case(1, Arg1, best(Arg0)); }
	void test_case_2() { int Arg0 = 29; string Arg1 = "BCDEAGHIJKLFNOPQRSTMVWXYZabcU"; verify_case(2, Arg1, best(Arg0)); }
	void test_case_3() { int Arg0 = 1; string Arg1 = "A"; verify_case(3, Arg1, best(Arg0)); }
	void test_case_4() { int Arg0 = 8; string Arg1 = "BCAEFGHD"; verify_case(4, Arg1, best(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Permutation ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
