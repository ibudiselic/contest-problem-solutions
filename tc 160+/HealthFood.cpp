#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct meal {
	int p, c, f, t, i;
	meal(int p_, int c_, int f_, int i_): p(p_), c(c_), f(f_), t((p_+c_)*5 + f_*9), i(i_) {}
};
struct Cmp {
	string plan;
	Cmp(const string &plan_): plan(plan_) {}
	bool operator()(const meal &a, const meal &b) {
		for (int i=0; i<(int)plan.size(); ++i) {
			if (plan[i] == 'p') {
				if (a.p != b.p)
					return a.p < b.p;
			} else if (plan[i] == 'P') {
				if (a.p != b.p)
					return a.p > b.p;
			} else if (plan[i] == 'c') {
				if (a.c != b.c)
					return a.c < b.c;
			} else if (plan[i] == 'C') {
				if (a.c != b.c)
					return a.c > b.c;
			} else if (plan[i] == 'f') {
				if (a.f != b.f)
					return a.f < b.f;
			} else if (plan[i] == 'F') {
				if (a.f != b.f)
					return a.f > b.f;
			} else if (plan[i] == 't') {
				if (a.t != b.t)
					return a.t < b.t;
			} else if (plan[i] == 'T') {
				if (a.t != b.t)
					return a.t > b.t;
			}
		}
		return a.i < b.i;
	}
};
class HealthFood {
	public:
	vector <int> selectMeals(vector <int> protein, vector <int> carbs, vector <int> fat, vector <string> dietPlans) {
		vector<meal> v;
		for (int i=0; i<(int)protein.size(); ++i)
			v.push_back(meal(protein[i], carbs[i], fat[i], i));

		vector<int> sol(dietPlans.size(), -1);
		for (int i=0; i<(int)dietPlans.size(); ++i) {
			sort(v.begin(), v.end(), Cmp(dietPlans[i]));
			sol[i] = v[0].i;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"P", "p", "C", "c", "F", "f", "T", "t"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { 1,  0,  1,  0,  0,  1,  1,  0 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, selectMeals(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {3, 4, 1, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 8, 5, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 2, 4, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"tFc", "tF", "Ftc"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { 3,  2,  0 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, selectMeals(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {18, 86, 76,  0, 34, 30, 95, 12, 21}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {26, 56,  3, 45, 88,  0, 10, 27, 53}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {93, 96, 13, 95, 98, 18, 59, 49, 86}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"f", "Pt", "PT", "fT", "Cp", "C", "t", "",
 "cCp", "ttp", "PCFt", "P", "pCt", "cP", "Pc"}
; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { 2,  6,  6,  2,  4,  4,  5,  0,  5,  5,  6,  6,  3,  5,  6 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, selectMeals(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    HealthFood ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
