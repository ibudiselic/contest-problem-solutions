#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class ProbabilityTree {
	public:
	vector <int> getOdds(vector <string> tree, int lowerBound, int upperBound) {
		vector<int> sol;
		vector<double> prob(tree.size(), -1.0);
		{
			istringstream is(tree[0]);
			int p;
			is >> p;
			prob[0] = p/100.0;
			if (lowerBound<=p && p<=upperBound)
				sol.push_back(0);
		}
		for (int t=0; t<(int)tree.size(); ++t)
		for (int i=0; i<(int)tree.size(); ++i) {
			if (prob[i] > -1e-9) continue;
			istringstream is(tree[i]);
			int parent, yes, no;
			is >> parent >> yes >> no;
			if (prob[parent] < -1e-9) continue;
			double p = prob[parent]*yes + (1-prob[parent])*no;
			if (lowerBound<=p+1e-9 && p-1e-9<=upperBound)
				sol.push_back(i);
			prob[i] = p/100.0;
		}
		sort(sol.begin(), sol.end());
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"40","0 70 10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; int Arg2 = 50; int Arr3[] = { 0,  1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, getOdds(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"20","2 50 50","0 50 50"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 49; int Arg2 = 51; int Arr3[] = { 1,  2 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, getOdds(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"10","0 99 41","1 40 3","2 91 43"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 81; int Arg2 = 88; int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, getOdds(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"79","0 64 52","1 70 87","0 38 99","1 24 8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 47; int Arg2 = 81; int Arr3[] = { 0,  1,  2,  3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, getOdds(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"51",
 "29 58 3",
 "6 56 86",
 "18 97 1",
 "44 99 25",
 "33 69 90",
 "27 67 49",
 "32 15 19",
 "33 1 21",
 "45 12 33",
 "29 24 40",
 "45 86 74",
 "40 30 65",
 "0 18 27",
 "1 90 65",
 "0 47 62",
 "40 81 72",
 "42 25 56",
 "45 16 81",
 "8 94 92",
 "29 41 92",
 "24 4 29",
 "32 56 91",
 "20 16 77",
 "1 35 79",
 "45 77 61",
 "6 50 19",
 "20 69 43",
 "4 6 16",
 "15 55 26",
 "42 73 90",
 "40 8 49",
 "33 16 33",
 "15 95 47",
 "9 66 40",
 "25 80 39",
 "35 72 70",
 "27 10 36",
 "40 36 10",
 "32 2 48",
 "33 44 23",
 "22 51 45",
 "25 8 43",
 "18 32 96",
 "45 41 74",
 "0 51 6",
 "18 48 15"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 82; int Arr3[] = { 0,  1,  2,  3,  4,  5,  6,  7,  9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  20,  21,  23,  24,  25,  26,  27,  28,  29,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, getOdds(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ProbabilityTree ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
