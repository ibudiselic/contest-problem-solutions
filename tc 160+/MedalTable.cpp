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

struct Country {
	int g, s, b;
	string name;
	Country(int g_, int s_, int b_, const string &name_): g(g_), s(s_), b(b_), name(name_) {}
	string str() {
		ostringstream os;
		os << name << ' ' << g << ' ' << s << ' ' << b;
		return os.str();
	}
};
bool operator<(const Country &a, const Country &b) {
	if (a.g != b.g)
		return a.g > b.g;
	else if (a.s != b.s)
		return a.s > b.s;
	else if (a.b != b.b)
		return a.b > b.b;
	else
		return a.name < b.name;
}
class MedalTable {
	public:
	vector <string> generate(vector <string> results) {
		int n = 0;
		vector<Country> v;
		map<string, int> ind;

		for (int i=0; i<(int)results.size(); ++i) {
			string g, s, b;
			istringstream is(results[i]);
			is >> g >> s >> b;

			if (ind.count(g) == 0) {
				ind[g] = n++;
				v.push_back(Country(0, 0, 0, g));
			}
			if (ind.count(s) == 0) {
				ind[s] = n++;
				v.push_back(Country(0, 0, 0, s));
			}
			if (ind.count(b) == 0) {
				ind[b] = n++;
				v.push_back(Country(0, 0, 0, b));
			}

			++v[ind[g]].g;
			++v[ind[s]].s;
			++v[ind[b]].b;
		}

		sort(v.begin(), v.end());

		vector<string> sol;
		for (int i=0; i<(int)v.size(); ++i)
			sol.push_back(v[i].str());

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"ITA JPN AUS", "KOR TPE UKR", "KOR KOR GBR", "KOR CHN TPE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "KOR 3 1 0",  "ITA 1 0 0",  "TPE 0 1 1",  "CHN 0 1 0",  "JPN 0 1 0",  "AUS 0 0 1",  "GBR 0 0 1",  "UKR 0 0 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, generate(Arg0)); }
	void test_case_1() { string Arr0[] = {"USA AUT ROM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "USA 1 0 0",  "AUT 0 1 0",  "ROM 0 0 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, generate(Arg0)); }
	void test_case_2() { string Arr0[] = {"GER AUT SUI", "AUT SUI GER", "SUI GER AUT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "AUT 1 1 1",  "GER 1 1 1",  "SUI 1 1 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, generate(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MedalTable ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
