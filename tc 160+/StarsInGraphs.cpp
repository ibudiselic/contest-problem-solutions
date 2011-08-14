#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

vector<string> G;
int starNum[50];
int N;
int maxNum;
int calcNum(int x, int C) {
	int outdeg = 0;
	for (int i=0; i<N; ++i)
		outdeg += (G[x][i]=='1');

	long long val = (1LL<<outdeg) - outdeg*(outdeg+1)/2 - 1;

	if (val>C || val<=0)
		return C+1;
	else
		return int(val);
}
bool used[50];
bool hasCycle(int x, int target) {
	used[x] = 1;
	for (int i=0; i<N; ++i)
		if (G[x][i]=='1' && starNum[i]==starNum[x])
			if (i == target)
				return true;
			else if (!used[i] && hasCycle(i, target))
				return true;

	return false;
}
int pathLen[50];
class StarsInGraphs {
	public:
	int starryPaths(vector <string> adjacencyMatrix, int C) {
		G = adjacencyMatrix;
		N = G.size();

		for (int i=0; i<N; ++i)
			starNum[i] = calcNum(i, C);

		vector<int> t(starNum, starNum+N);
		sort(t.begin(), t.end());
		t.erase(unique(t.begin(), t.end()), t.end());

		map<int, int> newVal;
		for (int i=0; i<(int)t.size(); ++i)
			newVal[t[i]] = i;

		if (t[0] > C)
			return 0;

		if (t.back() > C)
			maxNum = newVal[t.back()]-1;
		else
			maxNum = newVal[t.back()];

		for (int i=0; i<N; ++i)
			starNum[i] = newVal[starNum[i]];

		for (int i=0; i<N; ++i)
			if (starNum[i] <= maxNum) {
				memset(used, 0, sizeof used);
				if (hasCycle(i, i))
					return -1;
			}

		memset(pathLen, 0, sizeof pathLen);
		for (int num=maxNum; num>=0; --num) {
			for (int i=0; i<N; ++i)
				if (starNum[i] == num)
					pathLen[i] = max(pathLen[i], 1);

			for (int k=0; k<N; ++k)
				for (int i=0; i<N; ++i)
					if (starNum[i] == num)
						for (int j=0; j<N; ++j)
							if (G[i][j]=='1' && starNum[j]>=num)
								pathLen[i] = max(pathLen[i], pathLen[j]+1);
		}

		return *max_element(pathLen, pathLen+N);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"01110",
 "10111",
 "00000",
 "00000",
 "00000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 2; verify_case(0, Arg2, starryPaths(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"01011",
 "00111",
 "10011",
 "00000",
 "00000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = -1; verify_case(1, Arg2, starryPaths(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"0111",
 "0000",
 "0000",
 "0000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; verify_case(2, Arg2, starryPaths(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"01111",
 "00000",
 "00000",
 "00000",
 "00000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 0; verify_case(3, Arg2, starryPaths(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"010001100",
 "001001100",
 "000101110",
 "000010111",
 "000001111",
 "010000000",
 "000110000",
 "000100001",
 "100001000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 5; verify_case(4, Arg2, starryPaths(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    StarsInGraphs ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
