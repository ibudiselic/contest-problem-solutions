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

map<string, int> M;
vector<string> names;
vector<int> where;
int getInd(const string &s) {
	if (M.count(s) == 0) {
		M[s] = names.size();
		where.push_back(names.size());
		names.push_back(s);
	}
	return M[s];
}

class DVDPlayer {
	public:
	vector <string> findMovies(vector <string> watched) {
		M.clear();
		names.clear();
		where.clear();

		for (int i=0; i<(int)watched.size(); ++i)
			getInd(watched[i]);

		int in = -1;
		for (int i=0; i<(int)watched.size(); ++i) {
			int x = getInd(watched[i]);
			assert(where[x] != -1);
			if (in == -1) {
				in = x;
				where[x] = -1;
			} else {
				where[in] = where[x];
				where[x] = -1;
				in = x;
			}
		}

		vector<string> sol;
		for (map<string, int>::const_iterator it=M.begin(); it!=M.end(); ++it)
			if (where[it->second]!=-1 && where[it->second]!=it->second)
				sol.push_back(it->first + " is inside " + names[where[it->second]] + "'s case");

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"citizenkane", "casablanca", "thegodfather"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"casablanca is inside thegodfather's case", "citizenkane is inside casablanca's case" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findMovies(Arg0)); }
	void test_case_1() { string Arr0[] = {"starwars", "empirestrikesback", "returnofthejedi",
 "empirestrikesback", "returnofthejedi",
 "phantommenace", "starwars"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"empirestrikesback is inside returnofthejedi's case", "phantommenace is inside empirestrikesback's case", "returnofthejedi is inside phantommenace's case" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findMovies(Arg0)); }
	void test_case_2() { string Arr0[] = {"a", "x", "a", "y", "a", "z", "a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findMovies(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DVDPlayer ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
