#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

typedef long long llint;

llint memo1[52][52][2], memo2[52][52][2];

class HillHike {
	public:
	long long numPaths(int distance, int maxHeight, vector <int> landmarks) {
		llint (*novo)[52][2], (*staro)[52][2], (*tmp)[52][2];

		novo = memo1; staro = memo2;
		memset(staro, 0, 52 * sizeof *staro);
		memset(novo, 0, 52 * sizeof *novo);

		staro[0][0][0] = 1;
		landmarks.push_back(-1);
		for (int i=1; i<distance; ++i) {
			memset(novo, 0, 52 * sizeof *novo);
			for (int j=1; j<=maxHeight; ++j) {
				int got_max_h = (j==maxHeight ? 1:0);
				for (int k=0; k<(int)landmarks.size(); ++k) {
					int lm = (j==landmarks[k] ? (k+1):k);
					for (int d=-1; d<=1; ++d) {
						novo[j][lm][got_max_h] += staro[j+d][k][0];
						novo[j][lm][        1] += staro[j+d][k][1];
					}
				}
			}
			tmp = staro; staro = novo; novo = tmp;
		}
		return staro[1][landmarks.size()-1][1];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 2; int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 3LL; verify_case(0, Arg3, numPaths(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 45; int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 0LL; verify_case(1, Arg3, numPaths(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 2; int Arr2[] = {2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 1LL; verify_case(2, Arg3, numPaths(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 3; int Arr2[] = {2,2,3,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 7LL; verify_case(3, Arg3, numPaths(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 38; int Arg1 = 11; int Arr2[] = {4,5,8,5,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 201667830444LL; verify_case(4, Arg3, numPaths(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    HillHike ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
