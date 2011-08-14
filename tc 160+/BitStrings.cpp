#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int ones[20];
int zeroes[20];
int maxOnes, maxZeroes;
int N;
int sol;

void go(int pos, int o, int z, int cur) {
	if (o>maxOnes || z>maxZeroes)
		return;
	if (pos == N) {
		sol = max(sol, cur);
		return;
	}

	go(pos+1, o, z, cur);
	go(pos+1, o+ones[pos], z+zeroes[pos], cur+1);
}
class BitStrings {
	public:
	int maxStrings(vector <string> list, int numZeroes, int numOnes) {
		N = list.size();
		for (int i=0; i<N; ++i) {
			int o = 0, z = 0;
			for (int j=0; j<(int)list[i].size(); ++j)
				if (list[i][j] == '0')
					++z;
				else
					++o;
			ones[i] = o;
			zeroes[i] = z;
		}

		maxZeroes = numZeroes;
		maxOnes = numOnes;

		sol = 0;
		go(0, 0, 0, 0);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1", "00", "100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 1; int Arg3 = 2; verify_case(0, Arg3, maxStrings(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"00", "110", "101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 4; int Arg3 = 2; verify_case(1, Arg3, maxStrings(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"111", "01", "11", "10", "101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 9; int Arg3 = 5; verify_case(2, Arg3, maxStrings(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010",
"10101010101010101010101010101010101010101010101010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 500; int Arg2 = 500; int Arg3 = 20; verify_case(3, Arg3, maxStrings(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BitStrings ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
