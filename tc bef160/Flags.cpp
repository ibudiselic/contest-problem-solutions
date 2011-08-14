#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cassert>

using namespace std;

class Flags {
	public:
	long long numStripes(string numFlags, vector <string> forbidden) {
		int n = (int)forbidden.size();
		long long num = 0;
		for (int i=0; i<(int)numFlags.size(); ++i)
			num = num*10 + numFlags[i]-'0';

		bool a[10][10];
		memset(a, true, sizeof a);
		for (int i=0; i<n; ++i) {
			istringstream is(forbidden[i]);
			int t;
			while (is >> t)
				a[i][t] = false;
		}

		long long BUF1[10], BUF2[10];
		long long *novo, *staro, *tp;
		novo = BUF1; staro = BUF2;
		for (int i=0; i<n; ++i)
			staro[i] = 1;
		long long cnt = n;
		long long last = 0;
		long long sol = 1;

		while (cnt < num) {
			long long sum = 0;
			for (int i=0; i<n; ++i) {
				novo[i] = 0;
				for (int j=0; j<n; ++j)
					if (a[i][j])
						novo[i] += staro[j];
				sum += novo[i];
			}
			cnt += sum;
			if (sum == last) {
				assert(sum!=0);
				return (num-cnt)/sum + sol+1;
			}
			last = sum;
			tp = staro; staro = novo; novo = tp;
			++sol;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "10"; string Arr1[] = {"0","1 2","1 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 3LL; verify_case(0, Arg2, numStripes(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "100"; string Arr1[] = {"0","1","2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 6LL; verify_case(1, Arg2, numStripes(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "100000000000000000"; string Arr1[] = {"0","1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 50000000000000000LL; verify_case(2, Arg2, numStripes(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "10000000000000000"; string Arr1[] = {"0 1", "0 1", "2 3 4", "2 3 4", "2 3 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 40LL; verify_case(3, Arg2, numStripes(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "10000000000000000"; string Arr1[] = {"0 1 2 3 4 5 6 7 8 9", "0 1 3 4 5 6 7 8 9", "0 2 3 4 5 6 7 8 9", "0 1 2 3 4 5 6 7 8 9",
"0 1 2 3 4 5 6 7 8 9", "0 1 2 3 4 5 6 7 8 9", "0 1 2 3 4 5 6 7 8 9",
"0 1 2 3 4 5 6 7 8 9", "0 1 2 3 4 5 6 7 8 9", "0 1 2 3 4 5 6 7 8 9"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 4999999999999996LL; verify_case(4, Arg2, numStripes(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "5"; string Arr1[] = {"0","1","2","3","4","5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(5, Arg2, numStripes(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Flags ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
