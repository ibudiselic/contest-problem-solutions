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

vector<string> names;
map<string, int> ind;
int getInd(const string &s) {
	if (!ind.count(s)) {
		ind[s] = names.size();
		names.push_back(s);
	}
	return ind[s];
}

double best[100], t[100];
double R[100][100];
bool used[100];
bool canReach(int x, int y) {
	if (x == y)
		return 1;

	used[x] = 1;
	for (int i=0; i<(int)names.size(); ++i)
		if (!used[i] && R[x][i]>1e-9)
			if (canReach(i, y))
				return true;
	return false;
}
class MoneyExchange {
	public:
	double bestRate(vector <string> rates, string type1, string type2) {
		names.clear();
		ind.clear();

		for (int i=0; i<100; ++i)
			for (int j=0; j<100; ++j)
				R[i][j] = 0.0;

		for (int i=0; i<(int)rates.size(); ++i) {
			istringstream is(rates[i]);
			string a, b;
			double x, y;
			is >> a >> x >> b >> y;
			R[getInd(a)][getInd(b)] >?= y/x;
		}

		memset(used, 0, sizeof used);
		if (!canReach(getInd(type1), getInd(type2)))
			return -1.0;

		int n = names.size();
		for (int i=0; i<n; ++i)
			best[i] = t[i] = 0.0;

		best[getInd(type1)] = 1.0;
		for (int cnt=0; cnt<1000; ++cnt) {
			memcpy(t, best, sizeof t);
			for (int i=0; i<n; ++i)
				for (int j=0; j<n; ++j)
					t[i] = max(t[i], best[j]*R[j][i]);
			memcpy(best, t, sizeof best);
		}

		return best[getInd(type2)];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"EUR 8 USD 10", "USD 10 EUR 7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "EUR"; string Arg2 = "USD"; double Arg3 = 1.25; verify_case(0, Arg3, bestRate(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"EUR 0008 USD 0010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "USD"; string Arg2 = "EUR"; double Arg3 = -1.0; verify_case(1, Arg3, bestRate(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"EUR 8 USD 10","EUR 1 GOODBUY 2","GOODBUY 1 USD 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "EUR"; string Arg2 = "USD"; double Arg3 = 4.0; verify_case(2, Arg3, bestRate(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"A 1 B 2","A 1 C 3","B 2 D 3","C 9 D 10","D 7 E 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A"; string Arg2 = "E"; double Arg3 = 0.9523809523809523; verify_case(3, Arg3, bestRate(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "TYPEA"; string Arg2 = "TYPEB"; double Arg3 = -1.0; verify_case(4, Arg3, bestRate(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"A 7 A 5","A 1 B 1","B 2 A 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A"; string Arg2 = "A"; double Arg3 = 1.0; verify_case(5, Arg3, bestRate(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MoneyExchange ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
