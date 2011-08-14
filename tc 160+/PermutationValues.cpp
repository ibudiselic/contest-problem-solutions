#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class PermutationValues {
	public:
	vector <int> getValues(vector <int> lows, vector <int> highs, string lexPos, vector <string> retInts) {
		long long perm[21] = {0};
		perm[0] = 1;
		for (int i=1; i<21; ++i)
			perm[i] = perm[i-1]*i;

		sort(lows.begin(), lows.end());
		sort(highs.begin(), highs.end());
		long long n = 0;
		for (int i=0; i<(int)lows.size(); ++i)
			n += (long long)highs[i]-lows[i]+1;

		long long pos = 0;
		for (int i=0; i<(int)lexPos.size(); ++i)
			pos = pos*10 + lexPos[i]-'0';
		if (n<=20 && pos>=perm[n])
			pos %= perm[n];

		int a[22] = {0};
		int cnt  = -1;
		for (int i=21; i>0; --i) {
			a[i] = pos/perm[i-1];
			if (cnt==-1 && a[i])
				cnt = i;
			pos %= perm[i-1];
		}

		int b[21] = {0};
		if (cnt > 0) {
			int t = cnt;
			set<int> s;
			for (int i=(int)highs.size()-1; i>=0 && t; --i)
				for (int j=highs[i]; j>=lows[i] && t; --j) {
					s.insert(j);
					--t;
				}
			assert(cnt == (int)s.size());

			for (int i=cnt; i>0; --i) {
				set<int>::const_iterator it;
				for (it=s.begin(); a[i] && it!=s.end(); ++it, --a[i]);
					;
				assert(it != s.end());
				b[i-1] = *it;
				s.erase(*it);
			}

		}

		vector<int> sol;
		for (int i=0; i<(int)retInts.size(); ++i) {
			long long x = 0;
			for (int j=0; j<(int)retInts[i].size(); ++j)
				x = x*10 + retInts[i][j]-'0';
			assert(x < n);

			if (n-x-1 < cnt) {
				sol.push_back(b[n-1-x]);
				continue;
			}
			int j = 0;
			while (x >= (long long)highs[j]-lows[j]+1) {
				x -= (long long)highs[j]-lows[j]+1;
				++j;
				assert(j<(int)highs.size());
			}
			sol.push_back(lows[j]+x);
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "0"; string Arr3[] = {"0","1","2","3"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { 1,  2,  3,  4 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, getValues(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "5"; string Arr3[] = {"0","1","2"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { 3,  2,  1 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, getValues(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1,16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "1000000"; string Arr3[] = {"0","1","2","3","4","5","6","7","8","9","1","2","3"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { 3,  18,  19,  4,  20,  2,  16,  17,  1,  5,  18,  19,  4 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, getValues(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "100000000000001"; string Arr3[] = {"0","1","2","3","4"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { 2,  4,  5,  3,  1 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, getValues(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {-1000000000,500000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "99999999999999999"; string Arr3[] = {"2999500000","1234123","123344","9293939","2999500001","2999499950"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { 1999999987,  -998765877,  -999876656,  -990706061,  1999999982,  1999999949 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, getValues(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "999999"; string Arr3[] = {"0"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { 9 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(5, Arg4, getValues(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arr0[] = {0,-100,101}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {99,-11,100000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "100000000000009"; string Arr3[] = {"4","100000087","7"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { -96,  99999993,  -93 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(6, Arg4, getValues(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PermutationValues ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
