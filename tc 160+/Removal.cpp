#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct int_set {
	vector<int> lo;
	vector<int> hi;
};

class Removal {
	public:
	int kti(const int_set &x, int k) {
		int cur = 0;
		for (int i=0; i<(int)x.hi.size(); ++i) {
			cur += x.hi[i]-x.lo[i]+1;
			if (cur >= k) {
				cur -= x.hi[i]-x.lo[i]+1;
				return x.lo[i] + k-cur-1;
			}
		}
		return -1;
	}
	void izbaci(int_set &x, int lo, int hi) {
		int left = kti(x, lo);
		int right = kti(x, hi);
		assert(left != -1 && right != -1);

		const int n = x.hi.size();
		int_set novi;
		for (int i=0; i<n; ++i)
			if (x.lo[i]<=left && left<=x.hi[i]) {
				if (x.lo[i]<=right && right<=x.hi[i]) {
					int lh = left-1;
					int rl = right+1;
					if (x.lo[i] <= lh) {
						novi.lo.push_back(x.lo[i]);
						novi.hi.push_back(lh);
					}
					if (x.hi[i] >= rl) {
						novi.lo.push_back(rl);
						novi.hi.push_back(x.hi[i]);
					}
				} else {
					int lh = left-1;
					if (x.lo[i] <= lh) {
						novi.lo.push_back(x.lo[i]);
						novi.hi.push_back(lh);
					}
				}
			} else if (left < x.lo[i]) {
				if (x.lo[i]<=right && right<=x.hi[i]) {
					int rl = right+1;
					if (x.hi[i] >= rl) {
						novi.lo.push_back(rl);
						novi.hi.push_back(x.hi[i]);
					}
				} else if (right > x.hi[i]) {
					continue;
				} else {
					novi.hi.push_back(x.hi[i]);
					novi.lo.push_back(x.lo[i]);
				}
			} else {
				novi.hi.push_back(x.hi[i]);
				novi.lo.push_back(x.lo[i]);
			}
		x = novi;
	}
	int finalPos(int n, int k, vector <string> remove) {
		int_set x;
		x.lo.push_back(1);
		x.hi.push_back(n);

		for (int i=0; i<(int)remove.size(); ++i) {
			int lo, hi;
			sscanf(remove[i].c_str(), "%d-%d", &lo, &hi);
			izbaci(x, lo, hi);
		}
		return kti(x, k);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; int Arg1 = 3; string Arr2[] = {"3-4","4-5"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(0, Arg3, finalPos(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 13; string Arr2[] = {"19-50","19-50","19-19"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 13; verify_case(1, Arg3, finalPos(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 39; string Arr2[] = {"19-50","19-50","19-19"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(2, Arg3, finalPos(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Removal ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
