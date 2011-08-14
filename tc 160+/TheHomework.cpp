#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct State {
	int sz, same;
};

bool done[101][101];
class TheHomework {
	public:
	int transform(vector <int> first, vector <int> second) {
		int T = second.size();
		sort(first.begin(), first.end());
		sort(second.begin(), second.end());
		if (first == second) {
			return 0;
		}

		int same = 0;
		int i = 0;
		int j = 0;
		while (i<(int)first.size() && j<(int)second.size()) {
			if (first[i] == second[j]) {
				++same;
				++i;
				++j;
			} else if (first[i] < second[j]) {
				++i;
			} else {
				++j;
			}
		}

		memset(done, 0, sizeof done);
		queue<State> Q;
		Q.push((State) { first.size(), same });
		done[first.size()][same] = 1;
		int sol = 0;
		int t = 0;
		while (!Q.empty()) {
			if (t == 0) {
				t = Q.size();
				++sol;
			}
			--t;
			int sz = Q.front().sz;
			same = Q.front().same;
			Q.pop();

			for (int add=1; add<=sz; ++add) {
				int nsz = sz + add;
				int nsame = min(same + add, T);
				if (nsz > 100) {
					break;
				}
				if (nsz==T && nsame==T) {
					return sol;
				}
				if (!done[nsz][nsame]) {
					done[nsz][nsame] = 1;
					Q.push((State) { nsz, nsame });
				}
			}

			for (int sub=1; sub<=sz/2; ++sub) {
				int nsz = sz - sub;
				int nsame = min(nsz, same);
				if (nsz==T && nsame==T) {
					return sol;
				}
				if (!done[nsz][nsame]) {
					done[nsz][nsame] = 1;
					Q.push((State) { nsz, nsame });
				}
			}

			for (int change=1; change<=min(sz-same, sz/2); ++change) {
				int nsz = sz;
				int nsame = min(same+change, T);
				if (nsz==T && nsame==T) {
					return sol;
				}
				if (!done[nsz][nsame]) {
					done[nsz][nsame] = 1;
					Q.push((State) { nsz, nsame });
				}
			}
		}

		return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, transform(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, transform(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5,2,7,999,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7,7,2,999,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, transform(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {12,13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1,1,1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(3, Arg2, transform(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheHomework ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
