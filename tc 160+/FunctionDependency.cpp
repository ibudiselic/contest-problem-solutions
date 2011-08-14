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

bool used[50];
int indeg[50];
bool G[50][50];
vector<string> F;

struct Item {
	int ind;
	int indeg;
	Item(int ind_, int indeg_): ind(ind_), indeg(indeg_) {}
};
bool operator<(const Item &a, const Item &b) {
	if (a.indeg != b.indeg)
		return a.indeg > b.indeg;
	return F[a.ind] > F[b.ind];
}

class FunctionDependency {
	public:
	vector <string> scriptingOrder(vector <string> funcs, vector <string> depends) {
		memset(G, 0, sizeof G);
		F = funcs;
		const int n = funcs.size();
		for (int i=0; i<n; ++i) {
			istringstream is(depends[i]);
			int j;
			while (is >> j) {
				if (!G[j][i]) {
					G[j][i] = 1;
					++indeg[i];
				}
			}
		}

		priority_queue<Item> PQ;
		for (int i=0; i<n; ++i)
			PQ.push(Item(i, indeg[i]));

		memset(used, 0, sizeof used);
		vector<string> sol;
		while (!PQ.empty()) {
			const Item t = PQ.top();
			PQ.pop();
			if (used[t.ind])
				continue;
			used[t.ind] = true;
			sol.push_back(F[t.ind]);

			for (int i=0; i<n; ++i)
				if (G[t.ind][i])
					PQ.push(Item(i, --indeg[i]));
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"B", "C", "A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1", "", "1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"C", "A", "B" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, scriptingOrder(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"B", "C", "A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1", "", "0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"C", "B", "A" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, scriptingOrder(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"K", "A", "B", "C", "D", "E", "F", "G", "H", "I"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"", "", "1 1", "2", "3", "4", "5", "6", "7", "8"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "K" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, scriptingOrder(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FunctionDependency ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
