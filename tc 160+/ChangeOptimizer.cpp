#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <map>

using namespace std;

vector< pair<int, int> > v;
map< pair<int, int> , pair<int, vector<int> > > M;

pair<int, vector<int> > go(int pos, int value) {
	const pair<int, int> t(pos, value);
	pair<int, vector<int> > &ret = M[t];

	if (ret.first != 0)
		return ret;

	if (pos == 0) {
		ret.second.assign(v.size(), 0);
		ret.second[0] = value;
		ret.first = value;

		return ret;
	}

	if ((value+1)%v[pos].first != 0)
		return go(pos-1, value);

	ret = go(pos-1, v[pos].first - 1);
	ret.first += (value+1)/v[pos].first - 1;
	ret.second[pos] += (value+1)/v[pos].first - 1;

	const pair<int, vector<int> > &without = go(pos-1, value);

	if (without.first < ret.first)
		ret = without;

	return ret;
}
class ChangeOptimizer {
	public:
	vector <int> fewestCoins(vector <int> coinTypes, int value) {
		v.clear();
		M.clear();
		for (int i=0; i<(int)coinTypes.size(); ++i)
			v.push_back(make_pair(coinTypes[i], i));

		sort(v.begin(), v.end());

		vector<int> cnt = go(v.size()-1, value).second;
		vector<int> sol(cnt.size(), 0);

		for (int i=0; i<(int)cnt.size(); ++i)
			sol[v[i].second] = cnt[i];

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,10,25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 49; int Arr2[] = { 9,  4,  0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, fewestCoins(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,3,6,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; int Arr2[] = { 2,  1,  1,  0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, fewestCoins(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1234567; int Arr2[] = { 1,  1,  0,  1,  0,  0,  0,  154320,  0,  0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, fewestCoins(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {91001,3567,222123,4456,1,732234,123793,982312,14781}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 65864135; int Arr2[] = { 0,  0,  0,  0,  14780,  0,  0,  0,  4455 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, fewestCoins(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,10,100,1000,10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000; int Arr2[] = { 1000000,  0,  0,  0,  0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, fewestCoins(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {147323, 544149, 649, 26, 3473340, 267243, 6946680, 587,
 13893360, 17103552, 27786720, 60400539, 83360160, 68414208,
 72482916, 1, 687, 4758}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 333440639; int Arr2[] = { 0,  0,  0,  182,  1,  0,  1,  0,  1,  0,  2,  0,  3,  0,  0,  25,  0,  729 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, fewestCoins(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ChangeOptimizer ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
