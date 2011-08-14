#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Domino {
	int a, b, c;
};
bool adj(const Domino &a, const Domino &b) {
	return a.a==b.a || a.a==b.b || a.b==b.a || a.b==b.b;
}

bool G[6][6];
int C[6];
vector<Domino> v;
int val(char c) {
	if (c <= '9') {
		return c-'0';
	} else {
		return -(c-'A'+1);
	}
}
void dfs(int x, int comp) {
	C[x] = comp;
	for (int i=0; i<(int)v.size(); ++i) {
		if (G[x][i] && C[i]==-1) {
			dfs(i, comp);
		}
	}
}
int eval() {
	memset(G, 0, sizeof G);
	int n = v.size();
	for (int i=0; i<n; ++i) {
		for (int j=i+1; j<n; ++j) {
			if (adj(v[i], v[j])) {
				G[i][j] = G[j][i] = 1;
			}
		}
	}

	memset(C, 0xff, sizeof C);
	int comp = 0;
	int ret = 1;
	for (int i=0; i<n; ++i) {
		if (C[i] == -1) {
			dfs(i, comp++);
		}
		ret *= v[i].c;
	}

	if (comp%2 == 0) {
		ret *= -1;
	}

	return ret;
}
class TVGameWinnings {
	public:
	vector <int> getMinMax(vector <string> board) {
		int n = board.size();
		vector<int> choose(n, 0);

		vector<int> sol(2, 0);
		sol[0] = 123456789;
		sol[1] = -123456789;
		for (int i=0; i<n; ++i) {
			choose[i] = i;
		}

		do {
			v.clear();
			for (int i=0; i<n; ++i) {
				v.push_back((Domino) {i, choose[i], val(board[i][choose[i]])});
			}
			int t = eval();
			sol[0] = min(sol[0], t);
			sol[1] = max(sol[1], t);
		} while (next_permutation(choose.begin(), choose.end()));

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"35",
 "44"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-12, 20 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getMinMax(Arg0)); }
	void test_case_1() { string Arr0[] = {"00200",
 "0B000",
 "00020",
 "10000",
 "00001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-8, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getMinMax(Arg0)); }
	void test_case_2() { string Arr0[] = {"12A",
 "A12",
 "2A1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getMinMax(Arg0)); }
	void test_case_3() { string Arr0[] = {"AAAA",
 "BBBB",
 "CCCC",
 "DDDD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-24, 24 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getMinMax(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TVGameWinnings ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
