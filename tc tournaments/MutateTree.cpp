#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

string T;
int X;
struct Node {
	char x;
	Node *left, *right;
	Node(char x_=0, Node *left_=0, Node *right_=0): x(x_), left(left_), right(right_) {}
	string postorder() {
		string ret;
		if (left != 0)
			ret += left->postorder();
		if (right != 0)
			ret += right->postorder();
		ret += x;

		return ret;
	}
	Node *find(int y) {
		if (x == y)
			return this;
		Node *ret = 0;
		if (left != 0)
			ret = left->find(y);
		if (ret==0 && right!=0)
			ret = right->find(y);
		return ret;
	}
	bool is2Tree() {
		if (left==0 && right==0)
			return isupper(x);

		if (left!=0 && right==0 || left==0 && right!=0)
			return false;

		return islower(x) && left->is2Tree() && right->is2Tree();
	}
	~Node() {
		if (left != 0)
			delete left;
		if (right != 0)
			delete right;
	}
};

Node *parse() {
	--X;
	if (X < 0)
		return 0;

	if (isupper(T[X])) {
		return new Node(T[X], 0, 0);
	} else {
		Node *root = new Node(T[X], 0, 0);
		root->right = parse();
		root->left = parse();

		return root;
	}
}
class MutateTree {
	public:
	string newTree(string tree, int root1, int root2) {
		T = tree;
		X = T.size();

		Node *root = parse();


		string t = root->postorder();
		if (t!=T || !(root->is2Tree()))
			return "BADTREE";

		Node *r1 = root->find(T[root1]);
		Node *r2 = root->find(T[root2]);

		if (r1->find(T[root2]) || r2->find(T[root1]))
			return "OVERLAP";

		Node tt;
		memcpy(&tt, r1, sizeof tt);
		memcpy(r1, r2, sizeof tt);
		memcpy(r2, &tt, sizeof tt);
		tt.left = tt.right = 0;

		string sol = root->postorder();

		delete root;
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABxCRQgzq"; int Arg1 = 3; int Arg2 = 2; string Arg3 = "CABxRQgzq"; verify_case(0, Arg3, newTree(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "rAB"; int Arg1 = 1; int Arg2 = 2; string Arg3 = "BADTREE"; verify_case(1, Arg3, newTree(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "ABxCRQgzq"; int Arg1 = 3; int Arg2 = 7; string Arg3 = "OVERLAP"; verify_case(2, Arg3, newTree(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "CEGHfdbIa"; int Arg1 = 3; int Arg2 = 2; string Arg3 = "CEHGfdbIa"; verify_case(3, Arg3, newTree(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "X"; int Arg1 = 0; int Arg2 = 0; string Arg3 = "OVERLAP"; verify_case(4, Arg3, newTree(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "IPDqWmSbEa"; int Arg1 = 9; int Arg2 = 1; string Arg3 = "BADTREE"; verify_case(5, Arg3, newTree(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MutateTree ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
