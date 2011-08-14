#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int EC;
int n;
int deg[30];
vector<string> B;
void next(int x, int start, vector<int> &ret) {
	ret.push_back(x);
	if (x == start)
		return;

	for (int i=0; i<n; ++i)
		if (B[x][i] == '1') {
			B[x][i] = '0';
			B[i][x] = '0';
			EC -= 2;
			--deg[x];
			--deg[i];
			next(i, start, ret);
			break;
		}
}
vector<int> go(int x) {
	vector<int> ret;

	ret.push_back(x);
	for (int i=0; i<n; ++i)
		if (B[x][i] == '1') {
			B[x][i] = '0';
			B[i][x] = '0';
			EC -= 2;
			--deg[x];
			--deg[i];
			next(i, x, ret);
			break;
		}
	return ret;
}
class EulerianRace {
	public:
	vector <int> planRoute(vector <string> bridges) {
		memset(deg, 0, sizeof deg);
		EC = 0;
		B = bridges;
		n = B.size();
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j) {
				EC += (B[i][j]=='1');
				deg[i] += (B[i][j]=='1');
			}

		vector<int> sol = go(0);

		while (EC > 0) {
			int i=0;
			for (i=0; i<(int)sol.size(); ++i)
				if (deg[sol[i]] != 0)
					break;
			assert(i < (int)sol.size());
			const vector<int> t = go(sol[i]);
			sol.erase(sol.begin()+i);
			sol.insert(sol.begin()+i, t.begin(), t.end());
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { "0110000",
  "1001000",
  "1001110",
  "0110011",
  "0010010",
  "0011101",
  "0001010" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  1,  3,  5,  2,  4,  5,  6,  3,  2,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, planRoute(Arg0)); }
	void test_case_1() { string Arr0[] =
{ "0101000000",
  "1010110000",
  "0101000000",
  "1010000011",
  "0100011100",
  "0100100000",
  "0000100100",
  "0000101000",
  "0001000001",
  "0001000010" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  1,  4,  6,  7,  4,  5,  1,  2,  3,  8,  9,  3,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, planRoute(Arg0)); }
	void test_case_2() { string Arr0[] = { "01111",
  "10111",
  "11011",
  "11101",
  "11110" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  3,  2,  4,  3,  1,  4,  0,  1,  2,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, planRoute(Arg0)); }
	void test_case_3() { string Arr0[] = { "01000000001",
  "10100000000",
  "01010000000",
  "00101000000",
  "00010100000",
  "00001010000",
  "00000101000",
  "00000010100",
  "00000001010",
  "00000000101",
  "10000000010" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, planRoute(Arg0)); }
	void test_case_4() { string Arr0[] = { "00011",
  "00101",
  "01001",
  "10001",
  "11110" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  3,  4,  1,  2,  4,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, planRoute(Arg0)); }
	void test_case_5() { string Arr0[] = {"011111111",
 "101000000",
 "110000000",
 "100010000",
 "100100000",
 "100000100",
 "100001000",
 "100000001",
 "100000010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  7,  8,  0,  5,  6,  0,  3,  4,  0,  1,  2,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, planRoute(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    EulerianRace ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
