#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <utility>

using namespace std;

long long W[50], P[50];
map<pair<int, long long>, long long> M;
int N;
long long lim;
long long sum[50], val[50];

long long go(int pos, long long w) {
	if (pos == N)
		return 0;
	if (w + sum[pos] <= lim)
		return val[pos];

	const pair<int, long long> key(pos, w);
	if (M.count(key))
		return M[key];

	long long &ret = M[key];

	ret = go(pos+1, w);
	if (w+W[pos] <= lim)
		ret = max(ret, P[pos] + go(pos+1, w+W[pos]));

	return ret;
}
class FibonacciKnapsack {
	public:
	long long maximalCost(vector <string> items, string C) {
		N = items.size();
		for (int i=0; i<N; ++i)
			sscanf(items[i].c_str(), "%lld %lld", &W[i], &P[i]);
		sscanf(C.c_str(), "%lld", &lim);

		for (int i=0; i<N; ++i)
			for (int j=i+1; j<N; ++j)
				if (W[i] < W[j]) {
					swap(W[i], W[j]);
					swap(P[i], P[j]);
				}
		sum[N-1] = W[N-1];
		val[N-1] = P[N-1];
		for (int i=N-2; i>=0; --i) {
			sum[i] = W[i] + sum[i+1];
			val[i] = P[i] + val[i+1];
		}

		M.clear();
		return go(0, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"5 555", "8 195", "13 651"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "15"; long long Arg2 = 750LL; verify_case(0, Arg2, maximalCost(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"5 555", "8 195", "13 751"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "15"; long long Arg2 = 751LL; verify_case(1, Arg2, maximalCost(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"55 1562", "5 814", "55 1962", "8 996", "2 716", "34 1792"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "94"; long long Arg2 = 4568LL; verify_case(2, Arg2, maximalCost(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"13 89"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "1"; long long Arg2 = 0LL; verify_case(3, Arg2, maximalCost(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"27777890035288 9419696870097445",
 "53316291173 6312623457097563",
 "165580141 8848283653257131"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "27777900000000"; long long Arg2 = 15160907110354694LL; verify_case(4, Arg2, maximalCost(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FibonacciKnapsack ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
