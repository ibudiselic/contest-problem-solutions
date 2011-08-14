#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

unsigned reach[20], rreach[20];
int bc[1u<<20];
class TeamBuilding {
	public:
	int fewestPaths(vector <string> paths) {
		bc[0] = 0;
		for (int i=1; i<(1<<20); ++i)
			bc[i] = bc[i>>1] + (i&1);

		const int n = paths.size();
		memset(reach, 0, sizeof reach);
		memset(rreach, 0, sizeof rreach);
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				if (paths[i][j] == '1')
					reach[i] |= (1u<<j);

		for (int k=0; k<n; ++k)
			for (int i=0; i<n; ++i)
				if (reach[i] & (1u<<k))
					reach[i] |= reach[k];

		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				if (paths[j][i] == '1')
					rreach[i] |= (1u<<j);

		for (int k=0; k<n; ++k)
			for (int i=0; i<n; ++i)
				if (rreach[i] & (1u<<k))
					rreach[i] |= rreach[k];

		unsigned need = 0;
		for (int i=0; i<n; ++i)
			if ((reach[i] & (1u<<i)) == 0)
				need |= (1u<<i);

		unsigned source = (1u<<n)-1;
		for (unsigned mask=0; mask<(1u<<n); ++mask)
			if (bc[mask] < bc[source]) {
				unsigned to = mask;
				for (int i=0; i<n; ++i)
					if (mask & (1u<<i))
						to |= reach[i];
				if ((to & need) == need)
					source = mask;
			}
		unsigned sink = (1u<<n)-1;
		for (unsigned mask=0; mask<(1u<<n); ++mask)
			if (bc[mask] < bc[sink]) {
				unsigned from = mask;
				for (int i=0; i<n; ++i)
					if (mask & (1u<<i))
						from |= rreach[i];
				if ((from & need) == need)
					sink = mask;
			}

		return max(bc[sink], bc[source]);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"010",
 "100",
 "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, fewestPaths(Arg0)); }
	void test_case_1() { string Arr0[] = {"0110",
 "0001",
 "0101",
 "1000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, fewestPaths(Arg0)); }
	void test_case_2() { string Arr0[] = {"00101",
 "00010",
 "00010",
 "10000",
 "00000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, fewestPaths(Arg0)); }
	void test_case_3() { string Arr0[] = {"001000000",
 "000000010",
 "000001000",
 "000010010",
 "000000000",
 "000000010",
 "000000000",
 "100000001",
 "010000100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, fewestPaths(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TeamBuilding ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
