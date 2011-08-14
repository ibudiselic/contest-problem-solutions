#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool canEat[100][50];
int match[100];
int rmatch[100];
int N;

bool done[100];
bool makeMatch(int x) {
	done[x] = 1;
	for (int i=0; i<N; ++i)
		if (canEat[x][i])
			if (rmatch[i]==-1 || (!done[rmatch[i]] && makeMatch(rmatch[i]))) {
				match[x] = i;
				rmatch[i] = x;
				return true;
			}
	return false;
}
int bipartiteMatch() {
	int cardinality = 0;
	for (int i=0; i<2*N; ++i)
		if (match[i] == -1) {
			memset(done, 0, sizeof done);
			cardinality += makeMatch(i);
		}

	return cardinality;
}
class SharksDinner {
	public:
	int minSurvivors(vector <int> S, vector <int> V, vector <int> I) {
		N = S.size();
		memset(canEat, 0, sizeof canEat);

		for (int i=0; i<N; ++i)
			for (int j=0; j<N; ++j)
				if (i != j)
					if (S[i]>=S[j] && V[i]>=V[j] && I[i]>=I[j])
						if (S[i]!=S[j] || V[i]!=V[j] || I[i]!=I[j] || i>j) {
							canEat[2*i  ][j] = 1;
							canEat[2*i+1][j] = 1;
						}

		memset(match, 0xff, sizeof match);
		memset(rmatch, 0xff, sizeof rmatch);

		return N - bipartiteMatch();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 4, 3 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2, 3, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1, 5, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, minSurvivors(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = { 4, 10, 5, 8, 8 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 5, 10, 7, 7, 10 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 5, 8, 10, 7, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, minSurvivors(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = { 1, 2, 3, 4, 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 4, 3, 2, 1, 100 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 2, 4, 1, 3, 100 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(2, Arg3, minSurvivors(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = { 4, 4, 4, 4 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 3, 3, 3, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 8, 8, 8, 8 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(3, Arg3, minSurvivors(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SharksDinner ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
