#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool a[6];
int n, sol;
vector<int> t;
class BridgeCrossing {
	public:
	void go(int cnt, int cost) {
		if (cnt==n) {
			if (cost < sol)
				sol = cost;
			return;
		}
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				if (i!=j && a[i] && a[j]) {
					a[i] = a[j] = false;
					if (cnt+2 == n)
						go(cnt+2, cost + ::max(t[i], t[j]));
					else
						for (int k=0; k<n; ++k)
							if (!a[k]) {
								a[k] = true;
								go(cnt+1, cost + ::max(t[i], t[j]) + t[k]);
								a[k] = false;
							}
					a[i] = a[j] = true;
				}
	}
	int minTime(vector <int> times) {
		n = (int)times.size();
		for (int i=0; i<n; ++i)
			a[i] = true;

		t = times;
		sol = 2000000000;
		if (n==1) return t[0];
		go(0, 0);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 2, 5, 10 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(0, Arg1, minTime(Arg0)); }
	void test_case_1() { int Arr0[] = { 1, 2, 3, 4, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(1, Arg1, minTime(Arg0)); }
	void test_case_2() { int Arr0[] = { 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; verify_case(2, Arg1, minTime(Arg0)); }
	void test_case_3() { int Arr0[] = { 1, 2, 3, 50, 99, 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 162; verify_case(3, Arg1, minTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BridgeCrossing ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
