#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
vector<int> sol;
int best;
int n;
int L;
vector<int> s;
vector<int> cur;
int l[502];
enum {
	RED=0, GREEN=1
};
class GreenWave {
	public:
	int doit() {
		vector<char> lights(n, RED);
		vector<int> cars(s.size(), -1);
		vector<int> t(cur.size(), 0);
		vector<int> used = cur;
		int ret = 0;

		if (cars.size()==0) return 0;
		for (;;) {
			for (int i=0; i<(int)cars.size(); ++i) {
				if (cars[i]==-1 && (i==0 || cars[i-1]>0))
					cars[i] = 0;
				else if (cars[i]!=-1) {
					int ss = s[i];
					while (ss>0 && cars[i]<=L && (i==0 || cars[i-1]-1>cars[i]) && (l[cars[i]]==0 || lights[l[cars[i]]-1]==GREEN)) {
						++cars[i];
						--ss;
					}
					if (cars[i]>L) {
						cars[i] = 100*L;
						if (i==(int)cars.size()-1)
							return ret+1;
					}
				} else
					break;
			}
			++ret;
			for (int i=0; i<(int)t.size(); ++i) {
				if (t[i]%5 == cur[i]-1)
					lights[i] = !lights[i];
				++t[i];
			}
		}
		return 1000000000;
	}

	void go(int x) {
		if (x == n) {
			const int t = doit();
			if (t < best) {
				best = t;
				sol = cur;
			}
			return;
		}
		for (int i=1; i<=5; ++i) {
			cur[x] = i;
			go(x+1);
		}
	}
	vector <int> getFirstRed(int L_, vector <int> speeds, vector <int> lights) {
		sol.assign(lights.size(), 0);
		L = L_-1;
		cur.assign(lights.size(), 0);
		n = lights.size();
		memset(l, 0, sizeof l);
		for (int i=0; i<(int)lights.size(); ++i)
			l[lights[i]] = i+1;
		s = speeds;
		best = 1000000000;

		go(0);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 10; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, getFirstRed(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 50; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 5, 6, 7, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 2, 3, 4, 5 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, getFirstRed(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 300; int Arr1[] = {2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {16}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, getFirstRed(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 300; int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {16}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, getFirstRed(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 60; int Arr1[] = {12, 15, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {58}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, getFirstRed(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 340; int Arr1[] = {16, 15, 29, 7, 9, 15, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {125, 156, 274, 309, 211}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5, 1, 1, 1, 1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(5, Arg3, getFirstRed(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 494; int Arr1[] = {11, 7, 11, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {438, 251}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(6, Arg3, getFirstRed(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GreenWave ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
