#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Group {
	int num, skill;
	Group(int num_, int skill_): num(num_), skill(skill_) {}
};
bool operator<(const Group &a, const Group &b) {
	if (a.skill != b.skill)
		return a.skill < b.skill;
	else
		return a.num < b.num;
}
class GroupWork {
	public:
	long long bestGroup(vector <int> p, vector <int> s) {
		vector<Group> G;
		for (int i=0; i<(int)p.size(); ++i)
			G.push_back(Group(p[i], s[i]));

		sort(G.begin(), G.end());
		vector<long long> cnt(G.size(), 0);
		cnt[cnt.size()-1] = G[G.size()-1].num;
		for (int i=(int)cnt.size()-2; i>=0; --i)
			cnt[i] = G[i].num + cnt[i+1];

		long long sol = 0;
		for (int i=0; i<(int)G.size(); ++i)
			sol = max(sol, G[i].skill * cnt[i]);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,5,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 15LL; verify_case(0, Arg2, bestGroup(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,1,1,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 20LL; verify_case(1, Arg2, bestGroup(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {31,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 31LL; verify_case(2, Arg2, bestGroup(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1000000000,1000000000,1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000,999,998}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2994000000000LL; verify_case(3, Arg2, bestGroup(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GroupWork ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
