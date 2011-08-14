#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class VendingMachine {
	public:
	int ind_max(const vector<int> &a) {
		int res = 0;

		for (int i=1; i<(int)a.size(); ++i)
			if (a[i] > a[res])
				res = i;
		return res;
	}
	int motorUse(vector <string> prices, vector <string> purchases) {
		vector<vector<int> > a;

		for (int i=0; i<(int)prices.size(); ++i) {
			istringstream is(prices[i]);
			vector<int> t;
			int x;
			while (is >> x)
				t.push_back(x);
			a.push_back(t);
		}
		int n = a[0].size();
		vector<int> suma(n, 0);
		for (int i=0; i<(int)a.size(); ++i)
			for (int j=0; j<n; ++j)
				suma[j] += a[i][j];
		int sol = 0;
		int last_time = 0;
		int where = ind_max(suma);

		sol += ::min(::abs(where-0), ::min(where, 0)+::min(n-where, n-0));
		for (int i=0; i<(int)purchases.size(); ++i) {
			int s, c, t;
			s = c = t = 0;
			int j = 0;
			for (; j<(int)purchases[i].size() && purchases[i][j]!=','; ++j)
				s = s*10 + purchases[i][j]-'0';
			for (++j; j<(int)purchases[i].size() && purchases[i][j]!=':'; ++j)
				c = c*10 + purchases[i][j]-'0';
			for (++j; j<(int)purchases[i].size(); ++j)
				t = t*10 + purchases[i][j]-'0';
			if (!a[s][c])
				return -1;
			if (t-last_time >= 5) {
				int next = ind_max(suma);
				sol += ::min(::abs(next-where), ::min(next, where)+::min(n-next, n-where));
				where = next;
			}
			last_time = t;
			suma[c] -= a[s][c];
			a[s][c] = 0;
			sol += ::min(::abs(c-where), ::min(c, where)+::min(n-c, n-where));
			where = c;
		}
		int next = ind_max(suma);
		sol += ::min(::abs(next-where), ::min(next, where)+::min(n-next, n-where));
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"100 100 100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0,0:0", "0,2:5", "0,1:10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, motorUse(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"100 200 300 400 500 600"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0,2:0", "0,3:5", "0,1:10", "0,4:15"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 17; verify_case(1, Arg2, motorUse(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"100 200 300 400 500 600"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0,2:0", "0,3:4", "0,1:8", "0,4:12"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11; verify_case(2, Arg2, motorUse(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"100 100 100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0,0:10", "0,0:11"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, motorUse(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"100 200 300",
 "600 500 400"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0,0:0", "1,1:10", "1,2:20",
 "0,1:21", "1,0:22", "0,2:35"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(4, Arg2, motorUse(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    VendingMachine ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
