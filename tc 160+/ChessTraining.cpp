#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

int G[100][100];
void upd(int i, int j, set<int> &S) {
	if (i<0 || j<0) {
		return;
	}
	S.insert(G[i][j]);
}
class ChessTraining {
	public:
	string game(vector <int> x, vector <int> y) {
		for (int i=0; i<(int)x.size(); ++i) {
			if (x[i]==0 || y[i]==0 || x[i]==y[i]) {
				return "Alice will win";
			}
		}

		memset(G, 0xff, sizeof G);
		for (int i=0; i<100; ++i) {
			G[0][i] = -2;
			G[i][0] = -2;
			G[i][i] = -2;
		}

		for (int i=0; i<100; ++i) {
			for (int j=0; j<100; ++j) {
				if (i+j>0 && G[i][j]==-1) {
					set<int> S;
					for (int k=1; k<=max(i, j); ++k) {
						upd(i-k, j, S);
						upd(i, j-k, S);
						upd(i-k, j-k, S);
					}
					int g = 0;
					while (S.find(g) != S.end()) {
						++g;
					}
					G[i][j] = g;
				}
			}
		}

		int m = 0;
		for (int i=0; i<(int)x.size(); ++i) {
			m ^= G[x[i]][y[i]];
		}

		return string(m>0 ? "Alice" : "Bob") + " will win";
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Alice will win"; verify_case(0, Arg2, game(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Bob will win"; verify_case(1, Arg2, game(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5,7,3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8,3,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Bob will win"; verify_case(2, Arg2, game(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {3,3,18,6,0,14,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,4,11,9,9,9,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Alice will win"; verify_case(3, Arg2, game(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Alice will win"; verify_case(4, Arg2, game(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {3,4,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Bob will win"; verify_case(5, Arg2, game(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ChessTraining ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
