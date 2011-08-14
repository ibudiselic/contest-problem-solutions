#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;
typedef pair<int, int> PII;

int n;
vector<PII> child;

vector<int> go(int root) {
	vector<int> ret;
	if (-1 == root)
		return ret;

	vector<int> l = go(child[root].first);
	vector<int> r = go(child[root].second);

	if (l.size()==0 && r.size()==0) {
		ret.push_back(root);
		return ret;
	}
	if (l.size() >= r.size()+2) {
		int i, j;
		for (i=0; i<(int)(l.size()-r.size()); ++i)
			ret.push_back(l[i]);
		ret.push_back(root);
		for (j=0; j<(int)r.size(); ++j, ++i) {
			ret.push_back(r[j]);
			ret.push_back(l[i]);
		}
	} else if (l.size() == r.size()+1) {
		ret.push_back(root);
		ret.push_back(l[0]);
		for (int i=0; i<(int)r.size(); ++i) {
			ret.push_back(r[i]);
			ret.push_back(l[i+1]);
		}
	} else if (l.size()==r.size()) {
		ret.push_back(root);
		for (int i=0; i<(int)l.size(); ++i) {
			ret.push_back(r[i]);
			ret.push_back(l[i]);
		}
	} else {
		int i, j;
		for (i=0; i<(int)(r.size()-l.size()+1); ++i)
			ret.push_back(r[i]);
		ret.push_back(root);
		ret.push_back(l[0]);
		for (j=1; j<(int)l.size(); ++j, ++i) {
			ret.push_back(r[i]);
			ret.push_back(l[j]);
		}
	}
	return ret;
}
class SkewHeaps {
	public:
	vector <int> history(vector <int> parent) {
		n = parent.size()+1;
		child.assign(n, make_pair(-1, -1));

		for (int i=0; i<(int)parent.size(); ++i)
			if (parent[i] >= 100)
				child[parent[i]-100].second = i+1;
			else
				child[parent[i]].first = i+1;

		return go(0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = { 100, 0, 101, 102, 1, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  1,  2,  3,  4,  5,  6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, history(Arg0)); }
	void test_case_1() { int Arr0[] = { 100, 0, 2, 102, 4, 104 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 4,  6,  5,  2,  0,  1,  3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, history(Arg0)); }
	void test_case_2() { int Arr0[] = { 0, 100, 1, 102, 2, 3, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2,  5,  0,  3,  4,  6,  7,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, history(Arg0)); }
	void test_case_3() { int Arr0[] = { 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, history(Arg0)); }
	void test_case_4() { int Arr0[] = { 100, 1, 101, 103, 3, 4, 6, 107, 7, 0, 10, 11, 110, 12, 112, 111, 8, 108, 2, 16 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 8,  18,  17,  7,  9,  0,  11,  6,  12,  4,  16,  3,  15,  1,  20,  2,  10,  5,  13,  19,  14 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, history(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SkewHeaps ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
