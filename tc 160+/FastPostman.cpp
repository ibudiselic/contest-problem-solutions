#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

struct state {
	int left, right, pos, t;
	state(int left_, int right_, int pos_, int t_): left(left_), right(right_), pos(pos_), t(t_) {}
};
bool operator<(const state &a, const state &b) {
	if (a.t != b.t)
		return a.t > b.t;
	else if (a.left != b.left)
		return a.left < b.left;
	else if (a.right != b.right)
		return a.right < b.right;
	else
		return a.pos < b.pos;
}
int best[51][51][51];
class FastPostman {
	public:
	int minTime(vector <int> AA, vector <int> TT, int initialPos) {
		set<int> A_(AA.begin(), AA.end());

		vector<int> A, T;
		int start = -1;
		for (set<int>::const_iterator it=A_.begin(); it!=A_.end(); ++it) {
			if (initialPos < *it) {
				A.push_back(initialPos);
				T.push_back(0);
				start = A.size()-1;
				initialPos = 1234567890;
			}
			A.push_back(*it);
			int t = 1234567890;
			for (int i=0; i<(int)AA.size(); ++i)
				if (AA[i] == *it)
					t = min(t, TT[i]);
			T.push_back(t);
		}
		if (start == -1) {
			A.push_back(initialPos);
			T.push_back(0);
			start = A.size()-1;
		}

		memset(best, 0xff, sizeof best);
		priority_queue<state> Q;
		Q.push(state(start, start, start, 0));
		best[start][start][start] = 0;

		while (!Q.empty()) {
			const state &s = Q.top();
			int left = s.left;
			int right = s.right;
			int pos = s.pos;
			int t = s.t;
			Q.pop();

			if (left==0 && right==(int)A.size()-1)
				return t;

			if (pos==left && pos==right) {
				if (pos > 0) {
					int d = A[pos] - A[pos-1];
					if (t+d<=T[left-1] && (best[left-1][right][left-1]==-1 || t+d<best[left-1][right][left-1])) {
						Q.push(state(left-1, right, left-1, t+d));
						best[left-1][right][left-1] = t+d;
					}
				}
				if (pos < (int)A.size()-1) {
					int d = A[pos+1] - A[pos];
					if (t+d<=T[right+1] && (best[left][right+1][right+1]==-1 || t+d<best[left][right+1][right+1])) {
						Q.push(state(left, right+1, right+1, t+d));
						best[left][right+1][right+1] = t+d;
					}
				}
			} else if (pos == left) {
				if (pos > 0) {
					int d = A[pos] - A[pos-1];
					if (t+d<=T[left-1] && (best[left-1][right][left-1]==-1 || t+d<best[left-1][right][left-1])) {
						Q.push(state(left-1, right, left-1, t+d));
						best[left-1][right][left-1] = t+d;
					}
				}
				if (pos < (int)A.size()-1) {
					int d = A[pos+1] - A[pos];
					if (best[left][right][pos+1]==-1 || t+d<best[left][right][pos+1]) {
						Q.push(state(left, right, pos+1, t+d));
						best[left][right][pos+1] = t+d;
					}
				}
			} else if (pos == right) {
				if (pos < (int)A.size()-1) {
					int d = A[pos+1] - A[pos];
					if (t+d<=T[right+1] && (best[left][right+1][right+1]==-1 || t+d<best[left][right+1][right+1])) {
						Q.push(state(left, right+1, right+1, t+d));
						best[left][right+1][right+1] = t+d;
					}
				}
				if (pos > 0) {
					int d = A[pos] - A[pos-1];
					if (best[left][right][pos-1]==-1 || t+d<best[left][right][pos-1]) {
						Q.push(state(left, right, pos-1, t+d));
						best[left][right][pos-1] = t+d;
					}
				}
			} else {
				if (pos > 0) {
					int d = A[pos] - A[pos-1];
					if (best[left][right][pos-1]==-1 || t+d<best[left][right][pos-1]) {
						Q.push(state(left, right, pos-1, t+d));
						best[left][right][pos-1] = t+d;
					}
				}
				if (pos < (int)A.size()-1) {
					int d = A[pos+1] - A[pos];
					if (best[left][right][pos+1]==-1 || t+d<best[left][right][pos+1]) {
						Q.push(state(left, right, pos+1, t+d));
						best[left][right][pos+1] = t+d;
					}
				}
			}
		}

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,5,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9,2,5,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 13; verify_case(0, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 6; verify_case(1, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {45634}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 876; int Arg3 = -1; verify_case(2, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1,7,10,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {15,6,28,39}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 20; verify_case(3, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1000000,1000000,1000000,1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {563,23452,32426,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000000; int Arg3 = 0; verify_case(4, Arg3, minTime(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FastPostman ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
