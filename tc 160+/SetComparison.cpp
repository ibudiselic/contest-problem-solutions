#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <cctype>

using namespace std;

struct Entry;
struct Entry {
	set<string> atoms;
	set<Entry> subsets;
};
bool operator<(const Entry &a, const Entry &b) {
	if (a.atoms != b.atoms)
		return a.atoms < b.atoms;
	else return a.subsets < b.subsets;
}
void parse(Entry &a, const string &s) {
	if (s.size()==0)
		return;
	vector<string> t;
	string cur;
	for (int i=0, bc=0; i<(int)s.size(); ++i)
		if (s[i]==',' && bc==0) {
			t.push_back(cur);
			cur.clear();
		} else {
			cur += s[i];
			if (s[i]=='}')
				--bc;
			else if (s[i]=='{')
				++bc;
		}
	t.push_back(cur);

	for (int i=0; i<(int)t.size(); ++i)
		if (t[i][0]=='{') {
			Entry tt;
			parse(tt, t[i].substr(1, t[i].size()-2));
			a.subsets.insert(tt);
		} else {
			assert(isalpha(t[i][0]));
			a.atoms.insert(t[i]);
		}
}
inline bool operator==(const Entry &a, const Entry &b) {
	return !(a<b || b<a);
}
inline bool member(const Entry &a, const Entry &b) {
	return find(b.subsets.begin(), b.subsets.end(), a) != b.subsets.end();
}
inline bool equi(const Entry &a, const Entry &b) {
	return !(a<b || b<a);
}
bool subset(const Entry &a, const Entry &b) {
	for (set<string>::const_iterator it=a.atoms.begin(); it!=a.atoms.end(); ++it)
		if (find(b.atoms.begin(), b.atoms.end(), *it)==b.atoms.end())
			return false;
	for (set<Entry>::const_iterator it=a.subsets.begin(); it!=a.subsets.end(); ++it)
		if (find(b.subsets.begin(), b.subsets.end(), *it) == b.subsets.end())
			return false;

	return true;
}
bool powerset(const Entry &a, const Entry &b) {
	if (a.atoms.size()==0 && a.subsets.size()==(1u<<(b.atoms.size()+b.subsets.size()))) {
		for (set<Entry>::const_iterator it=a.subsets.begin(); it!=a.subsets.end(); ++it)
			if (!subset(*it, b))
				return false;
		return true;
	}
	return false;
}
class SetComparison {
	public:
	vector <string> relation(string a, string b) {
		Entry A, B;

		parse(A, a.substr(1, a.size()-2));
		parse(B, b.substr(1, b.size()-2));

		vector<string> sol;
		if (member(A,B))
			sol.push_back("MEMBER");
		if (equi(A,B))
			sol.push_back("EQUIVALENT");
		if (subset(A,B))
			sol.push_back("SUBSET");
		if (subset(A,B) && !equi(A,B))
			sol.push_back("PROPER SUBSET");
		if (powerset(A,B))
			sol.push_back("POWERSET");
		if (A.atoms.size()+A.subsets.size() == B.atoms.size()+B.subsets.size())
			sol.push_back("EQUIPOTENT");

		sort(sol.begin(), sol.end());
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "{}"; string Arg1 = "{a,b,c,c,c,d,d,d}"; string Arr2[] = { "PROPER SUBSET",  "SUBSET" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, relation(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "{{a,b},{a},{b},{}}"; string Arg1 = "{a,b}"; string Arr2[] = { "POWERSET" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, relation(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "{a,b,c,d,e}"; string Arg1 = "{a,a,b,b,c,c,d,d,e,e}"; string Arr2[] = { "EQUIPOTENT",  "EQUIVALENT",  "SUBSET" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, relation(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "{{a}}"; string Arg1 = "{{{a}},{a}}"; string Arr2[] = { "MEMBER",  "PROPER SUBSET",  "SUBSET" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, relation(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "{a,a,{a},{a},{a,a,a},{},{},a,aa}"; string Arg1 = "{a,{a},{},aa}"; string Arr2[] = { "EQUIPOTENT",  "EQUIVALENT",  "SUBSET" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, relation(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "{frank,bob}"; string Arg1 = "{{},{frank,frank},{bob},{frank,bob,bob},{}}"; string Arr2[] = { "MEMBER" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, relation(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "{{a,b},{a},{a,b},{},{b},{b,a}}"; string Arg1 = "{a,b}"; string Arr2[] = { "POWERSET" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(6, Arg2, relation(Arg0, Arg1)); }
	void test_case_7() { string Arg0 = "{a,b,c,d}"; string Arg1 = "{a,b}"; string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(7, Arg2, relation(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SetComparison ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
