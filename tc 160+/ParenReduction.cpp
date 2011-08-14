#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Tree {
	bool isLeaf;
	char varName, op;
	Tree *left, *right;
	Tree(): isLeaf(0), varName('?'), op('?'), left(0), right(0) {}
	~Tree() {
		if (!isLeaf) {
			delete left;
			delete right;
		}
	}
};
string ops("+-*/^");
bool isOp(char c) {
	return ops.find(c) != string::npos;
}
int getPrec(char op) {
	assert(isOp(op));
	if (op=='+' || op=='-')
		return 1;
	else if (op=='*' || op=='/')
		return 2;
	else
		return 3;
}
void parse(const string &s, Tree *node) {
	if (s.size() == 1) {
		node->isLeaf = 1;
		node->varName = s[0];
		return;
	} else {
		assert(s[0]=='(' && s[s.size()-1]==')');
		node->isLeaf = 0;
		int bc = 0;
		int i = 1;
		while (bc || !isOp(s[i])) {
			bc += (s[i]=='(') - (s[i]==')');
			++i;
			assert(i<(int)s.size());
		}
		node->op = s[i];

		node->left = new Tree;
		parse(s.substr(1, i-1), node->left);
		node->right = new Tree;
		parse(s.substr(i+1, s.size()-1-(i+1)), node->right);
	}
}
string construct(Tree *node, int minLvlWOB) {
	if (node->isLeaf)
		return string(1, node->varName);

	int l, r;
	switch (node->op) {
		case '+': l = r = 1; break;
		case '-': l = 1; r = 2; break;
		case '*': l = r = 2; break;
		case '/': l = 2; r = 3; break;
		case '^': l = 4; r = 3; break;
		default: assert(0);
	}

	string left = construct(node->left, l);
	string right = construct(node->right, r);
	int level = getPrec(node->op);
	if (level >= minLvlWOB)
		return left + (node->op) + right;
	else
		return '(' + left + (node->op) + right + ')';
}
void ispisi(Tree *node) {
	if (node->isLeaf) {
		cerr << (node->varName);
		return;
	}
	cerr << '(';
	ispisi(node->left);
	cerr << (node->op);
	ispisi(node->right);
	cerr << ')';
}
class ParenReduction {
	public:
	string pretty(string expr) {
		Tree T;
		parse(expr, &T);

		return construct(&T, 1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "(a-(b/(c^d)))"; string Arg1 = "a-b/c^d"; verify_case(0, Arg1, pretty(Arg0)); }
	void test_case_1() { string Arg0 = "(e*((f+(g+h))*i))"; string Arg1 = "e*(f+g+h)*i"; verify_case(1, Arg1, pretty(Arg0)); }
	void test_case_2() { string Arg0 = "(((a-(b-c))-d)^((e/f)/(g/h)))"; string Arg1 = "(a-(b-c)-d)^(e/f/(g/h))"; verify_case(2, Arg1, pretty(Arg0)); }
	void test_case_3() { string Arg0 = "x"; string Arg1 = "x"; verify_case(3, Arg1, pretty(Arg0)); }
	void test_case_4() { string Arg0 = "((a+((l-g)+o))^((r/i)*((t/h)*m)))"; string Arg1 = "(a+l-g+o)^(r/i*t/h*m)"; verify_case(4, Arg1, pretty(Arg0)); }
	void test_case_5() { string Arg0 = "(((((t-(k/(o*m)))*(c*f))*((n/j)+(v-z)))^l)/(x-h))"; string Arg1 = "((t-k/(o*m))*c*f*(n/j+v-z))^l/(x-h)"; verify_case(5, Arg1, pretty(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ParenReduction ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
