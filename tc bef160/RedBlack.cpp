#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cassert>

using namespace std;

struct Node {
	int x;
	bool color;
	struct Node *left, *right;
	Node() {
		x = 0;
		color = true;
		left = right = 0;
	}
	Node(int xx, bool c=true, struct Node *l=0, struct Node *r=0): x(xx), color(c), left(l), right(r) {}
};
int sol;
class RedBlack {
	public:
	void obrisi(Node *t) {
		if (t->left) obrisi(t->left);
		if (t->right) obrisi(t->right);
		free(t);
	}
	Node *twist(Node *x, Node *y, Node *z, Node *t1, Node *t2, Node *t3, Node *t4) {
		++sol;
		assert(x);
		assert(y);
		assert(z);
		y->color = true;
		x->color = false;
		z->color = false;
		y->left = x;
		y->right = z;
		x->left = t1;
		x->right = t2;
		z->left = t3;
		z->right = t4;
		return y;
	}
	Node *doit(Node *t, int x) {
		if (!t) {
			t = (Node *)malloc(sizeof *t);
			assert(t);
			*t = Node(x);
		} else {
			if (x < t->x)
				t->left = doit(t->left, x);
			else if (x > t->x)
				t->right = doit(t->right, x);
			if (t->left && t->left->color && t->left->left && t->left->left->color)
				t = twist(t->left->left, t->left, t, t->left->left->left, t->left->left->right, t->left->right, t->right);
			else if (t->left && t->left->color && t->left->right && t->left->right->color)
				t = twist(t->left, t->left->right, t, t->left->left, t->left->right->left, t->left->right->right, t->right);
			else if (t->right && t->right->color && t->right->left && t->right->left->color)
				t = twist(t, t->right->left, t->right, t->left, t->right->left->left, t->right->left->right, t->right->right);
			else if (t->right && t->right->color && t->right->right && t->right->right->color)
				t = twist(t, t->right, t->right->right, t->left, t->right->left, t->right->right->left, t->right->right->right);
		}
		return t;
	}
	void ubaci(Node **a, int x) {
		*a = doit(*a, x);
		(*a)->color = false;
	}
	int numTwists(vector <int> keys) {
		Node *root = 0;
		sol = 0;

		for (vector<int>::size_type i=0; i<keys.size(); ++i)
			ubaci(&root, keys[i]);

		obrisi(root);
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1,2,3 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, numTwists(Arg0)); }
	void test_case_1() { int Arr0[] = { 1,2,3,4,5,6,7 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, numTwists(Arg0)); }
	void test_case_2() { int Arr0[] = { 7,1,4,6,3,5,2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, numTwists(Arg0)); }
	void test_case_3() { int Arr0[] = { 5,10,15,14,3,4,11,2,1,12,6,9,7,13,8 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(3, Arg1, numTwists(Arg0)); }
	void test_case_4() { int Arr0[] = { 6,8,10,12,4,2,18,14,16,19,7,15,9,17,13,5,11,3,1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, numTwists(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RedBlack ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
