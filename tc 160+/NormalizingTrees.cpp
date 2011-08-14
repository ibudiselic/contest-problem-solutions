#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector< vector<int> > G;
vector<int> leafVector;
vector<int> go(int root, int prev) {
	vector< vector<int> > children;

	for (int i=0; i<(int)G[root].size(); ++i)
		if (G[root][i] != prev)
			children.push_back(go(G[root][i], root));

	if (children.empty())
		return leafVector;

	sort(children.begin(), children.end());

	vector<int> ret;
	ret.push_back(-1);

	vector< vector<int> > label(children.size(), vector<int>());
	vector<int> pos(children.size(), 0);

	int lab = 1;
	for (int i=0; i<(int)children.size(); ++i) {
		ret.push_back(0);
		label[i].push_back(lab++);
		++pos[i];
	}

	while (1) {
		int choice = 1234567890;
		int choiceInd = -1;
		for (int i=0; i<(int)children.size(); ++i) {
			assert(children[i][pos[i]] != -1);
			if (children[i][pos[i]]<1234567890 && label[i][children[i][pos[i]]]<choice) {
				choice = label[i][children[i][pos[i]]];
				choiceInd = i;
			}
		}
		if (choiceInd == -1)
			break;

		ret.push_back(choice);
		label[choiceInd].push_back(lab++);
		++pos[choiceInd];
	}

	ret.push_back(1234567890);
	return ret;
}
class NormalizingTrees {
	public:
	vector <int> normalize(vector <int> tree) {
		if (tree.size() == 1)
			return tree;

		G.assign(tree.size(), vector<int>());
		for (int i=0; i<(int)tree.size(); ++i)
			if (tree[i] != -1) {
				G[i].push_back(tree[i]);
				G[tree[i]].push_back(i);
			}

		leafVector.clear();
		leafVector.push_back(-1);
		leafVector.push_back(1234567890);

		vector<int> sol(100, 1234567890);

		for (int i=0; i<(int)tree.size(); ++i)
			sol = min(sol, go(i, -1));

		return vector<int>(sol.begin(), sol.begin()+sol.size()-1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {2,0,-1,4,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 0, 0, 0, 1, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, normalize(Arg0)); }
	void test_case_1() { int Arr0[] = {-1,0,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 0, 0, 1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, normalize(Arg0)); }
	void test_case_2() { int Arr0[] = {3,3,3,4,-1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 0, 0, 0, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, normalize(Arg0)); }
	void test_case_3() { int Arr0[] = {10,9,6,10,6,9,7,-1,9,7,7,10,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 0, 0, 0, 0, 1, 1, 5, 5, 5, 6, 6, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, normalize(Arg0)); }
	void test_case_4() { int Arr0[] = {-1, 0, 0, 0, 0, 1, 1, 5, 5, 5, 6, 6, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 0, 0, 0, 0, 1, 1, 5, 5, 5, 6, 6, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, normalize(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    NormalizingTrees ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
