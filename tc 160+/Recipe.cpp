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

string toStr(int x) {
	ostringstream os;
	os << x;
	return os.str();
}
string fmt(int x) {
	string ret;
	if (x/(16*3) > 0) {
		ret += toStr(x/(16*3)) + " cups ";
		x %= 16*3;
	}
	if (x/3 > 0) {
		ret += toStr(x/3) + " Tbsp ";
		x %= 3;
	}
	if (x > 0)
		ret += toStr(x) + " tsp ";

	return ret;
}
int gcd(int m, int n) {
	return n==0 ? m : gcd(n, m%n);
}
class Recipe {
	public:
	vector <string> fix(vector <string> recipe, vector <string> mixingBowl) {
		map<string, int> ind;
		vector<string> name;
		vector<int> need;
		int n = recipe.size();
		for (int i=0; i<n; ++i) {
			istringstream is(recipe[i]);
			string a, b, c;
			is >> a >> b >> c;
			ind[c] = name.size();
			name.push_back(c);

			int x = atoi(a.c_str());
			if (b == "Tbsp")
				x *= 3;
			else if (b == "cups")
				x *= 16*3;

			need.push_back(x);
		}

		vector<int> have(n, 0);
		for (int i=0; i<(int)mixingBowl.size(); ++i) {
			istringstream is(mixingBowl[i]);
			string a, b, c;
			is >> a >> b >> c;

			int x = atoi(a.c_str());
			if (b == "Tbsp")
				x *= 3;
			else if (b == "cups")
				x *= 16*3;

			have[ind[c]] += x;
		}

		vector<int> final = have;
		for (int i=0; i<n; ++i)
			if (have[i] < need[i])
				final[i] = need[i];

		int d = need[0];
		for (int i=1; i<n; ++i)
			d = gcd(d, need[i]);

		for (int i=0; i<n; ++i)
			need[i] /= d;

		int mul = 1;
		for (int i=0; i<n; ++i)
			mul = max(mul, (final[i]+need[i]-1)/need[i]);

		for (int i=0; i<n; ++i)
			final[i] = need[i] * mul;

		vector<string> sol;
		for (int i=0; i<n; ++i) {
			string s = fmt(final[i]-have[i]);
			if (s.size() > 0)
				sol.push_back(s + name[i]);
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"4 cups FLOUR", "1 Tbsp SALT", "1 cups SUGAR", "1 tsp VANILLA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"4 cups FLOUR", "1 Tbsp SALT", "1 Tbsp SUGAR", "1 Tbsp VANILLA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"8 cups FLOUR", "2 Tbsp SALT", "2 cups 15 Tbsp SUGAR" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, fix(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"3 cups FLOUR", "1 tsp SALT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3 cups FLOUR", "2 tsp SALT"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"3 cups FLOUR" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, fix(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"1 cups FLOUR", "1 cups SUGAR", "1 cups MILK"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 cups FLOUR", "32 Tbsp SUGAR", "96 tsp MILK"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, fix(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"2 cups FLOUR", "2 tsp SALT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 cups FLOUR", "1 tsp SALT"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 cups FLOUR", "1 tsp SALT" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, fix(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"3 cups FLOUR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 cups FLOUR"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 cups FLOUR" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, fix(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"71 tsp CINNAMON"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 cups 7 Tbsp 2 tsp CINNAMON" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, fix(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"3 cups FLOUR","1 cups SUGAR","9 tsp SALT","9 Tbsp GINGER","2 cups MILK","21 tsp CINNAMON","5 Tbsp VANILLA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 Tbsp SUGAR","8 tsp SALT","5 Tbsp CINNAMON","21 tsp VANILLA","44 tsp GINGER","3 cups FLOUR","3 cups MILK"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 cups FLOUR", "1 cups 9 Tbsp 2 tsp SUGAR", "2 Tbsp 1 tsp SALT", "1 tsp GINGER", "5 Tbsp 1 tsp MILK", "6 Tbsp 2 tsp CINNAMON", "1 Tbsp 1 tsp VANILLA" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(6, Arg2, fix(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Recipe ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
