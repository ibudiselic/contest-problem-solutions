#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

vector<int> sol;
vector<int> d;
vector<bool> used;
int n;

class PointsOnAxis {
	public:
	bool go(int x) {
		if (x == n)
			return true;

		for (int i=0; i<(int)d.size(); ++i) {
			if (!used[i]) {
				used[i] = true;
				const int t = sol[x-1]-d[i];
				vector<bool> update(used.size(), false);
				int cnt = 0;
				for (int j=0; j<x; ++j) {
					if (sol[j] != t) {
						++cnt;
					}
				}
				if (cnt != x) {
					used[i] = false;
					break;
				} else {
					cnt = 0;
				}
				for (int j=0; j<x-1; ++j) {
					const int a = abs(sol[j]-t);
					for (int k=0; k<(int)d.size(); ++k) {
						if (!used[k] && !update[k] && a==d[k]) {
							update[k] = true;
							++cnt;
							break;
						}
					}
					if (cnt < j+1) break;
				}
				if (cnt==x-1) { // nasao sve potrebne distance, ubaci t u novi niz i pokreni rekurziju
					int j = x-1;
					while (j>=0 && sol[j] > t) {
						sol[j+1] = sol[j];
						--j;
					}
					sol[++j] = t; // j je mjesto na koje je ubacena nova tocka - to treba kasnije vratiti nazad
					// obavi update - kasnije vratiti nazad
					for (int k=0; k<(int)used.size(); ++k) {
						if (update[k]) {
							used[k] = true;
						}
					}
					if (go(x+1)) {
						return true;
					}
					for (int k=0; k<(int)used.size(); ++k) {
						if (update[k]) {
							used[k] = false;
						}
					}
					while (j<x) {
						sol[j] = sol[j+1];
						++j;
					}
				}
				used[i] = false;
				break;
			}
		}
		for (int i=0; i<(int)d.size(); ++i) {
			if (!used[i]) {
				used[i] = true;
				const int t = d[i];
				vector<bool> update(used.size(), false);
				int cnt = 0;
				for (int j=0; j<x; ++j) {
					if (sol[j] != t) {
						++cnt;
					}
				}
				if (cnt != x) {
					used[i] = false;
					break;
				} else {
					cnt = 0;
				}
				for (int j=1; j<x; ++j) {
					const int a = abs(sol[j]-t);
					for (int k=0; k<(int)d.size(); ++k) {
						if (!used[k] && !update[k] && a==d[k]) {
							update[k] = true;
							++cnt;
							break;
						}
					}
					if (cnt < j) break;
				}
				if (cnt==x-1) { // nasao sve potrebne distance, ubaci t u novi niz i pokreni rekurziju
					int j = x-1;
					while (j>=0 && sol[j] > t) {
						sol[j+1] = sol[j];
						--j;
					}
					sol[++j] = t; // j je mjesto na koje je ubacena nova tocka - to treba kasnije vratiti nazad
					// obavi update - kasnije vratiti nazad
					for (int k=0; k<(int)used.size(); ++k) {
						if (update[k]) {
							used[k] = true;
						}
					}
					if (go(x+1)) {
						return true;
					}
					for (int k=0; k<(int)used.size(); ++k) {
						if (update[k]) {
							used[k] = false;
						}
					}
					while (j<x) {
						sol[j] = sol[j+1];
						++j;
					}
				}
				used[i] = false;
				break;
			}
		}
		return false;
	}
	vector <int> findPoints(vector <int> distances) {
		d = distances;
		n = 0;
		while (n*(n-1)/2 != (int)d.size())
			++n;
		sol.resize(n);
		sort(d.begin(), d.end(), greater<int>());
		sol[0] = 0;
		sol[1] = d[0];
		used.clear();
		used.push_back(true);
		for (int i=1; i<(int)d.size(); ++i)
			used.push_back(false);

		if (go(2))
			return sol;
		else
			return vector<int>();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {5, 2, 1, 6, 2, 3, 3, 4, 5, 6, 3, 9, 1, 4, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  3,  4,  5,  6,  9 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findPoints(Arg0)); }
	void test_case_1() { int Arr0[] = {20,100,120}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  20,  120 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findPoints(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  2,  3,  7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findPoints(Arg0)); }
	void test_case_3() { int Arr0[] = {1,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, findPoints(Arg0)); }
	void test_case_4() { int Arr0[] = {237601, 843904, 56786, 429289, 52254, 83576, 220417,
606303, 180815, 191688, 185347, 154025, 17184, 787118,
414615, 791650, 760328, 623487, 372503, 4532, 26790,
163631, 377035, 345713, 208872, 31322, 168163, 136841}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  52254,  56786,  83576,  220417,  237601,  429289,  843904 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, findPoints(Arg0)); }
	void test_case_5() { int Arr0[] = {1, 1, 1, 1, 2, 2, 3, 4, 4, 5, 5, 5, 6, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  1,  2,  5,  6,  7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, findPoints(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PointsOnAxis ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
