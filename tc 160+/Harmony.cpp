#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	return a ? gcd(b%a, a) : b;
}
struct Frac {
	int n, d;
	Frac(int nn, int dd): n(nn), d(dd) { int t = gcd(n, d); n /= t; d /= t; if (d > n) { t = n; n = d; d = t; } }
};
bool operator<(const Frac &a, const Frac &b) {
	return a.d > b.d;
}
struct Harm {
	vector<Frac> f;
	vector<int> freq;
	Harm(const vector<Frac> &ff, const vector<int> &fr): f(ff), freq(fr) {}
};
bool operator<(const Harm &a, const Harm &b) {
	for (int i=0; i<3; ++i)
		if (a.f[i].d != b.f[i].d)
			return a.f[i].d < b.f[i].d;
	for (int i=0; i<3; ++i)
		if (a.freq[i] != b.freq[i])
			return a.freq[i] < b.freq[i];
	return false;
}

class Harmony {
	public:
	vector <int> mostHarmonious(vector <int> freq) {
		sort(freq.begin(), freq.end());

		vector<Frac> t;
		vector<int> tt;
		for (int i=0; i<3; ++i) {
			t.push_back(Frac(1000001, 1000000));
			tt.push_back(100000);
		}
		Harm best(t, tt);
		for (int i=0; i+2 < (int)freq.size(); ++i)
		for (int j=i+1; j+1 < (int)freq.size(); ++j)
		for (int k=j+1; k < (int)freq.size(); ++k) {
			vector<int> vv;
			vv.push_back(freq[i]);
			vv.push_back(freq[j]);
			vv.push_back(freq[k]);
			vector<Frac> v;

			v.push_back(Frac(vv[0], vv[1]));
			v.push_back(Frac(vv[0], vv[2]));
			v.push_back(Frac(vv[1], vv[2]));
			sort(v.begin(), v.end());
			Harm novo(v, vv);
			if (novo < best)
				best = novo;
		}
		return best.freq;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {200,250,400,320,350}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 200,  250,  400 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, mostHarmonious(Arg0)); }
	void test_case_1() { int Arr0[] = {440, 320, 750,660, 500,550}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 440,  550,  660 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, mostHarmonious(Arg0)); }
	void test_case_2() { int Arr0[] = {1960,1000,3050,2341,7253,7864,2000,2352,2940,1534,7234}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1960,  2352,  2940 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, mostHarmonious(Arg0)); }
	void test_case_3() { int Arr0[] = {100,200,300,400,500,600,700,800,900,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 100,  200,  400 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, mostHarmonious(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Harmony ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
