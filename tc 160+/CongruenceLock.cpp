#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int best[100000];
class CongruenceLock {
	public:
	int minPushes(int current, int target, vector <int> buttons) {
		vector<int> a = buttons;

		vector<bool> used(100000, false);
		best[current] = 0;
		queue<int> pos, cnt;
		pos.push(current);
		cnt.push(0);
		used[current] = true;

		while (pos.size() != 0) {
			int cur = pos.front();
			pos.pop();
			int c = cnt.front();
			cnt.pop();
			best[cur] = c;

			for (int i=0; i<(int)a.size(); ++i) {
				const int t = (cur+a[i])%100000;
				if (!used[t]) {
					used[t] = true;
					pos.push(t);
					cnt.push(c+1);
				}
			}
		}

		return used[target] ? best[target] : -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10000; int Arg1 = 10004; int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(0, Arg3, minPushes(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 99880; int Arg1 = 89; int Arr2[] = {100, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(1, Arg3, minPushes(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 11111; int Arg1 = 22222; int Arr2[] = {4, 6, 2222, 3456}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(2, Arg3, minPushes(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 1; int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 66667; verify_case(3, Arg3, minPushes(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 172; int Arg1 = 172; int Arr2[] = {1, 2, 3, 5, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(4, Arg3, minPushes(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CongruenceLock ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
