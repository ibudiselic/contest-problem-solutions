#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class PickTeam {
	public:
	vector <string> pickPeople(int teamSize, vector <string> people) {
		int n = (int)people.size();
		int lim = 1<<n;
		vector<string> names;
		int a[20][20];
		vector<string> sol(teamSize);
		int best = -2000000000;

		for (vector<string>::size_type i=0; i<people.size(); ++i) {
			istringstream is(people[i]);
			string t;
			is >> t;
			names.push_back(t);
			for (int j=0; j<n; ++j) {
				int x;
				is >> x;
				a[i][j] = x;
			}
		}
		for (int i=0; i<lim; ++i) {
			int cnt = 0;
			vector<int> team;
			for (int k=0; (1<<k) <= i; ++k)
				if ((1<<k) & i) {
					++cnt;
					team.push_back(k);
				}
			if (cnt == teamSize) {
				int sum = 0;
				for (vector<int>::size_type j=0; j<team.size()-1; ++j)
					for (vector<int>::size_type k=j+1; k<team.size(); ++k)
						sum += a[team[j]][team[k]];
				if (sum > best) {
					for (vector<int>::size_type j=0; j<team.size(); ++j)
						sol[j] = names[team[j]];
					best = sum;
				}
			}
		}
		sort(sol.begin(), sol.end());
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"ALICE 0 1 -1 3",
 "BOB 1 0 2 -4",
 "CAROL -1 2 0 2",
 "DAVID 3 -4 2 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "ALICE",  "CAROL",  "DAVID" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, pickPeople(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = {"ALICE 0 1 -1 3",
 "BOB 1 0 2 -4",
 "CAROL -1 2 0 2",
 "DAVID 3 -4 2 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "ALICE",  "DAVID" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, pickPeople(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; string Arr1[] = {"A 0 -2 -2","B -2 0 -1","C -2 -1 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "B",  "C" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, pickPeople(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 13; string Arr1[] = {"A 0 2 8 7 1 -4 -3 1 8 2 8 2 1 -3 7 1 3 9 -6 -5",
 "A 2 0 0 7 -7 -5 8 -8 -9 -9 6 -9 -4 -8 8 1 7 0 3 3",
 "A 8 0 0 -5 -5 -7 1 -3 1 9 -6 6 1 5 6 -9 8 6 -8 -8",
 "A 7 7 -5 0 7 -5 3 9 8 3 -6 -5 -5 2 -6 2 -2 -1 -2 8",
 "B 1 -7 -5 7 0 7 -2 -9 3 7 0 -2 1 1 -9 -3 -2 2 1 -2",
 "B -4 -5 -7 -5 7 0 4 8 6 0 -1 4 1 -2 -9 4 0 -7 6 -2",
 "B -3 8 1 3 -2 4 0 8 -1 1 -2 -7 5 0 -6 9 0 -3 1 3",
 "B 1 -8 -3 9 -9 8 8 0 0 -2 5 0 5 8 3 5 2 4 5 4",
 "C 8 -9 1 8 3 6 -1 0 0 8 -3 8 -6 -4 7 -4 1 -5 5 4",
 "C 2 -9 9 3 7 0 1 -2 8 0 -9 -6 6 5 -8 -3 -8 2 2 4",
 "C 8 6 -6 -6 0 -1 -2 5 -3 -9 0 2 7 8 2 -6 -4 -6 4 4",
 "C 2 -9 6 -5 -2 4 -7 0 8 -6 2 0 0 -3 6 7 -1 2 -4 -2",
 "D 1 -4 1 -5 1 1 5 5 -6 6 7 0 0 -7 -4 8 -6 -3 4 -6",
 "D -3 -8 5 2 1 -2 0 8 -4 5 8 -3 -7 0 7 -3 5 -8 5 1",
 "D 7 8 6 -6 -9 -9 -6 3 7 -8 2 6 -4 7 0 9 -5 -5 -8 3",
 "D 1 1 -9 2 -3 4 9 5 -4 -3 -6 7 8 -3 9 0 -2 -7 8 -7",
 "E 3 7 8 -2 -2 0 0 2 1 -8 -4 -1 -6 5 -5 -2 0 6 0 5",
 "E 9 0 6 -1 2 -7 -3 4 -5 2 -6 2 -3 -8 -5 -7 6 0 4 8",
 "E -6 3 -8 -2 1 6 1 5 5 2 4 -4 4 5 -8 8 0 4 0 1",
 "E -5 3 -8 8 -2 -2 3 4 4 4 4 -2 -6 1 3 -7 5 8 1 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "A",  "A",  "B",  "B",  "B",  "B",  "C",  "C",  "C",  "D",  "D",  "D",  "E" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, pickPeople(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PickTeam ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
