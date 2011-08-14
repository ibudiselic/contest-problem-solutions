#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;


class MixingLiquids {
	public:
	double howMuch(vector <int> percent, vector <int> amount, int need) {
		vector< pair<int, int> > v;
		int num = 0;
		int den = 0;
		for (int i=0; i<(int)percent.size(); ++i) {
			v.push_back(make_pair(percent[i], amount[i]));
			num += amount[i]*percent[i];
			den += amount[i]*100;
		}

		sort(v.begin(), v.end());
		if (100*num < den*need) {
			while (v.size() > 0)
				if (100*(num-v[0].first*v[0].second) < (den-100*v[0].second)*need) {
					num -= v[0].first*v[0].second;
					den -= 100*v[0].second;
					v.erase(v.begin());
				} else {
					num -= v[0].first*v[0].second;
					den -= 100*v[0].second;
					double p = 0;
					if (den > 0)
						p = num*100.0/den;
					double a = den/100.0;

					return a + (p-need)*a/(need-v[0].first);
				}
		} else if (100*num > den*need) {
			reverse(v.begin(), v.end());
			while (v.size() > 0)
				if (100*(num-v[0].first*v[0].second) > (den-100*v[0].second)*need) {
					num -= v[0].first*v[0].second;
					den -= 100*v[0].second;
					v.erase(v.begin());
				} else {
					num -= v[0].first*v[0].second;
					den -= 100*v[0].second;
					double p = 0;
					if (den > 0)
						p = num*100.0/den;
					double a = den/100.0;

					return a + (p-need)*a/(need-v[0].first);
				}
		}
		return double(den)/100;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 50; double Arg3 = 40.0; verify_case(0, Arg3, howMuch(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 60; double Arg3 = 50.0; verify_case(1, Arg3, howMuch(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {90, 70, 80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 10, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 50; double Arg3 = 0.0; verify_case(2, Arg3, howMuch(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {30, 80, 60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {40, 10, 15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 57; double Arg3 = 35.18518518518519; verify_case(3, Arg3, howMuch(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {50,50,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {395,971,964}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 50; double Arg3 = 2330.0; verify_case(4, Arg3, howMuch(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MixingLiquids ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
