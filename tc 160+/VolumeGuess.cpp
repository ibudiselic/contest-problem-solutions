#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int smallerVol[10][10];
int vol[10];
class VolumeGuess {
	public:
	int correctVolume(vector <string> queries, int n, int ithBox) {
		vector<int> order(n, 0);
		for (int i=1; i<n; ++i)
			order[i] = i;

		--ithBox;
		for (int i=0; i<(int)queries.size(); ++i) {
			int a, b, v;
			sscanf(queries[i].c_str(), "%d,%d,%d", &a, &b, &v);
			--a;
			--b;
			smallerVol[a][b] = smallerVol[b][a] = v;
		}

		do {
			for (int i=0; i<n-1; ++i) {
				vol[order[i]] = smallerVol[order[i]][order[i+1]];
				for (int j=i+2; j<n; ++j)
					if (vol[order[i]] != smallerVol[order[i]][order[j]])
						goto skip;
			}

			return vol[ithBox];

			skip: ;
		} while (next_permutation(order.begin(), order.end()));

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1,2,10","1,3,10","2,3,20"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 1; int Arg3 = 10; verify_case(0, Arg3, correctVolume(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"1,02,10","2,3,010","1,3,20"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; int Arg3 = 10; verify_case(1, Arg3, correctVolume(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"1,2,31","1,3,9","1,4,31","2,4,32","3,4,9","3,2,9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 1; int Arg3 = 31; verify_case(2, Arg3, correctVolume(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"1,2,31","1,3,9","1,4,31","2,4,32","3,4,9","3,2,9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; int Arg3 = 9; verify_case(3, Arg3, correctVolume(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    VolumeGuess ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
