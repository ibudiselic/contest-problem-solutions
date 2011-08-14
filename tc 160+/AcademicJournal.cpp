#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <set>

using namespace std;

struct Journal {
	int cCnt, pCnt;
	string name;
	Journal(int c, int p, const string &s): cCnt(c), pCnt(p), name(s) {}
};
bool operator<(const Journal &a, const Journal &b) {
	if (a.cCnt*b.pCnt != b.cCnt*a.pCnt)
		return a.cCnt*b.pCnt > b.cCnt*a.pCnt;
	else if (a.pCnt != b.pCnt)
		return a.pCnt > b.pCnt;
	else
		return a.name < b.name;
}
class AcademicJournal {
	public:
	vector <string> rankByImpact(vector <string> papers) {
		map<string, int> pCnt, cCnt;
		vector<string> name;
		vector< set<int> > cites;

		for (int i=0; i<(int)papers.size(); ++i) {
			int x = papers[i].find('.');
			name.push_back(papers[i].substr(0, x));
			++pCnt[name.back()];

			cites.push_back(set<int>());
			if (x+1 < (int)papers[i].size()) {
				istringstream is(papers[i].substr(x+1));
				int t;
				while (is >> t)
					cites.back().insert(t);
			}
		}

		for (int i=0; i<(int)papers.size(); ++i)
			for (set<int>::const_iterator it=cites[i].begin(); it!=cites[i].end(); ++it)
				if (name[*it] != name[i])
					++cCnt[name[*it]];

		set<Journal> S;
		for (int i=0; i<(int)name.size(); ++i)
			S.insert(Journal(cCnt[name[i]], pCnt[name[i]], name[i]));

		vector<string> sol;
		for (set<Journal>::const_iterator it=S.begin(); it!=S.end(); ++it)
			sol.push_back(it->name);


		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"A.", "B. 0", "C. 1 0 3", "C. 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A", "B", "C" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, rankByImpact(Arg0)); }
	void test_case_1() { string Arr0[] = {"RESPECTED JOURNAL.", "MEDIOCRE JOURNAL. 0", "LOUSY JOURNAL. 0 1",
"RESPECTED JOURNAL.", "MEDIOCRE JOURNAL. 3", "LOUSY JOURNAL. 4 3 3 4",
"RESPECTED SPECIFIC JOURNAL.", "MEDIOCRE SPECIFIC JOURNAL. 6", "LOUSY SPECIFIC JOURNAL. 6 7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"RESPECTED JOURNAL", "RESPECTED SPECIFIC JOURNAL", "MEDIOCRE JOURNAL", "MEDIOCRE SPECIFIC JOURNAL", "LOUSY JOURNAL", "LOUSY SPECIFIC JOURNAL" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, rankByImpact(Arg0)); }
	void test_case_2() { string Arr0[] = {"NO CITATIONS.", "COMPLETELY ORIGINAL."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"COMPLETELY ORIGINAL", "NO CITATIONS" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, rankByImpact(Arg0)); }
	void test_case_3() { string Arr0[] = {"CONTEMPORARY PHYSICS. 5 4 6 8 7 1 9",
"EUROPHYSICS LETTERS. 9",
"J PHYS CHEM REF D. 5 4 6 8 7 1 9",
"J PHYS SOC JAPAN. 5 4 6 8 7 1 9",
"PHYSICAL REVIEW LETTERS. 5 6 8 7 1 9",
"PHYSICS LETTERS B. 6 8 7 1 9",
"PHYSICS REPORTS. 8 7 1 9",
"PHYSICS TODAY. 1 9",
"REP PROGRESS PHYSICS. 7 1 9",
"REV MODERN PHYSICS."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"REV MODERN PHYSICS", "EUROPHYSICS LETTERS", "PHYSICS TODAY", "REP PROGRESS PHYSICS", "PHYSICS REPORTS", "PHYSICS LETTERS B", "PHYSICAL REVIEW LETTERS", "CONTEMPORARY PHYSICS", "J PHYS CHEM REF D", "J PHYS SOC JAPAN" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, rankByImpact(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AcademicJournal ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
