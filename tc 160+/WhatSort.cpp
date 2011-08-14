#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Entry {
	string name;
	int age, wt;
	Entry(string s, int x, int y): name(s), age(x), wt(y) {}
};

bool nm(const Entry &a, const Entry &b) {
	return a.name < b.name;
}
bool ag(const Entry &a, const Entry &b) {
	return a.age < b.age;
}
bool wtt(const Entry &a, const Entry &b) {
	return a.wt > b.wt;
}
inline bool operator!=(const Entry &a, const Entry &b) {
	if (a.name != b.name || a.age != b.age || a.wt != b.wt)
		return true;
	else return false;
}
bool operator==(const vector<Entry> &a, const vector<Entry> &b) {
	for (int i=0; i<(int)a.size(); ++i)
		if (a[i]!=b[i])
			return false;
	return true;
}

class WhatSort {
	public:
	string sortType(vector <string> name, vector <int> age, vector <int> wt) {
		vector<Entry> vec;

		for (int i=0; i<(int)name.size(); ++i)
			vec.push_back(Entry(name[i], age[i], wt[i]));

		string letters = "NAW";
		string sol = "Empty";

		bool (*a[3])(const Entry &, const Entry &) = { nm, ag, wtt };
		vector<int> order;
		for (int i=0; i<3; ++i)
			order.push_back(i);

		do {
			vector<Entry> t = vec;
			for (int i=0; i<3; ++i)
				stable_sort(t.begin(), t.end(), a[order[i]]);
			if (t==vec) {
				if (sol=="Empty") {
					sol.clear();
					for (int j=2; j>=0; --j)
						sol += letters[order[j]];
				} else {
					sol = "IND";
					break;
				}
			}
		} while (next_permutation(order.begin(), order.end()));

		return (sol=="Empty")?("NOT"):(sol);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BOB","BOB","DAVE","JOE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {22, 35, 35, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] =  {122, 122, 195,  200}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "IND"; verify_case(0, Arg3, sortType(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"BOB","BOB","DAVE","DAVE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {22, 35, 35, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] =  {122, 122, 195,  200}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NOT"; verify_case(1, Arg3, sortType(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"BOB","BOB","DAVE","DAVE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] =  {22, 35, 35, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {122, 122, 195,  190}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NWA"; verify_case(2, Arg3, sortType(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WhatSort ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
