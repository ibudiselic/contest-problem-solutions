#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
	int val, cnt;
	bool nused;
	Node *left, *right;
	Node(int v): val(v), cnt(1), nused(true), left(0), right(0) {}
};
void inc(Node *p) {
	if (p != 0) {
		++p->cnt;
		inc(p->left);
		inc(p->right);
	}
}
void dec(Node **p) {
	if (*p != 0) {
		dec(&(*p)->left);
		dec(&(*p)->right);
		if (0 == --(*p)->cnt) {
			delete *p;
			*p = 0;
		}
	}
}
void ubaci(int val, Node *source, Node **d) {
	if (source == 0) {
		*d = new Node(val);
		assert(*d != 0);
		return;
	}
	if (*d == 0) {
		*d = new Node(source->val);
		assert(*d != 0);
	}
	Node *dest = *d;
	if (val < source->val) {
		dest->right = source->right;
		inc(source->right);
		ubaci(val, source->left, &dest->left);
	} else {
		dest->left = source->left;
		inc(source->left);
		ubaci(val, source->right, &dest->right);
	}
}
int izbroji(Node *p) {
	if (p != 0) {
		int t = (p->nused ? 1:0) + izbroji(p->left) + izbroji(p->right);
		p->nused = false;
		return t;
	} else {
		return 0;
	}
}
void ispisi(const Node *p, int indent) {
	if (p != 0) {
		ispisi(p->right, indent+2);
		cerr << string(indent, ' ') << '(' << p->val << ' ' << p->cnt << ')' << '\n';
		ispisi(p->left, indent+2);
	}
}
class ImmutableTrees {
	public:
	int numNodes(vector <int> values, vector <int> trees, vector <int> garbage) {
		vector<Node*> t;

		for (int i=0; i<(int)values.size(); ++i) {
			const int newval = values[i];
			const int tt = trees[i];

			if (tt == -1) {
				t.push_back(new Node(newval));
			} else {
				t.push_back(0);
				ubaci(newval, t[tt], &t[i]);
			}
			/*ispisi(t[i], 0);
			cerr << '\n';*/
		}

		for (int i=0; i<(int)garbage.size(); ++i) {
			dec(&t[garbage[i]]);
		}

		/*cerr << "\n----------\n\n";
		for (int i=0; i<(int)t.size(); ++i) {
			ispisi(t[i], 0);
		}*/
		int cnt = 0;
		for (int i=0; i<(int)t.size(); ++i) {
			cnt += izbroji(t[i]);
		}

		for (int i=0; i<(int)t.size(); ++i) {
			dec(&t[i]);
		}
		return cnt;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 3, 2, 5, 4, 1, 6 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 0, 1, 2, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0, 1, 2, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(0, Arg3, numNodes(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = { 8, 6, 4, 7, 9, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 0, 1, 0,-1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 3, 1, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(1, Arg3, numNodes(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = { 1, 2, 3, 4 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 0, 1, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0, 1, 2, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, numNodes(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = { 61,67,46,42,38,11,88,33,9,20,31,68,48,17,74,91,15,62,21,73 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { -1,0,0,2,3,3,-1,6,5,4,2,0,10,0,0,8,3,10,6,12 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 17,11,18,1,10,12,2,6,0,4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 34; verify_case(3, Arg3, numNodes(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = { 37,12,11,7,10,36,17,19,18,23,8,31,32,15,21,4,25,33,29,22,5,3,34,20,13,30,1,35,2,9,14,27,28,16,24 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { -1,0,1,2,3,3,3,2,-1,1,0,5,11,1,4,12,3,15,6,12,4,13,19,1,0,14,7,12,18,12,3,26,21,29,24 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 13,14,6,31,9,30,15,5,24,3,27,8,34,16,20 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 85; verify_case(4, Arg3, numNodes(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ImmutableTrees ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
