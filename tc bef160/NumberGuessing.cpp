#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int rng, n;
vector<int> a;

class NumberGuessing {
	public:
	int eval(int x) {
		int low, high;
		low = -1; high = 1000001;

		for (int i=0; i<(int)a.size(); ++i)
			if (a[i] < x)
				low = ::max(low, a[i]);
			else if (a[i] > x)
				high = ::min(high, a[i]);
		return 1 + ((low==-1)?(x-1):((x-low-1)/2)) + ((high==1000001)?(rng-x):((high-x-1)/2));
	}
	int go(int x) {
		int best = 0, where = -1;
		vector<int> tmpa;

		if (x==n) {
			if (n == 0)
				return a[n]=1;
			for (int i=0; i<n; ++i)
				tmpa.push_back(a[i]);
			sort(tmpa.begin(), tmpa.end());

			if (tmpa[0]-1 > best) {
				best = tmpa[0]-1;
				where = tmpa[0]-1;
			}
			for (int i=1; i<n; ++i)
				if ((tmpa[i]-tmpa[i-1])/2 > best) {
					best = (tmpa[i]-tmpa[i-1])/2;
					where = tmpa[i-1]+1;
				}
			if (rng-tmpa[n-1] > best) {
				best = rng-tmpa[n-1];
				where = tmpa[n-1]+1;
			}
			return a[n] = where;
		} else {
			for (int i=1; i<=rng; ++i) {
				bool can = true;
				for (int j=0; j<x; ++j)
					if (a[j] == i) {
						can = false;
						break;
					}
				if (can) {
					a[x] = i;
					go(x+1);
					int val = eval(i);
					if (val > best) {
						best = val;
						tmpa = a;
					}
				}
			}
		}
		a = tmpa;
		return a[x];
	}
	int bestGuess(int range, vector <int> guesses, int numLeft) {
		a = guesses;
		n = (int)a.size()+numLeft;
		rng = range;
		for (int i=0; i<=numLeft; ++i)
			a.push_back(1000001);
		int t = go((int)guesses.size());
		return t;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1000; int Arr1[] = {500}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 501; verify_case(0, Arg3, bestGuess(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1000000; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 500000; verify_case(1, Arg3, bestGuess(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1000; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 750; verify_case(2, Arg3, bestGuess(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 100; int Arr1[] = {27,80}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 26; verify_case(3, Arg3, bestGuess(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    NumberGuessing ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
