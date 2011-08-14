#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <map>

using namespace std;

vector<string> cutUp(const string &s, const string &delim=" ") {
	int lastPos = 0, pos = 0;
	vector<string> ret;

	while (pos+delim.size() <= s.size()) {
		if (s.substr(pos, delim.size()) == delim) {
			ret.push_back(s.substr(lastPos, pos-lastPos));

			pos += (int)delim.size()-1;
			lastPos = pos+1;
		}
		++pos;
	}

	if (lastPos < (int)s.size())
		ret.push_back(s.substr(lastPos));

	return ret;
}

map<string, int> M;
vector<string> F;
int getInd(const string &s) {
	if (!M.count(s)) {
		M[s] = F.size();
		F.push_back(s);
	}

	return M[s];
}
void doSet(const string &s, set<int> &S) {
	vector<string> t = cutUp(s, "/");
	for (int i=0; i<(int)t.size(); ++i) {
		S.insert(getInd(t[i]));
	}
}
void doLhs(const string &s, vector< set<int> > &v) {
	vector<string> t = cutUp(s, ",");
	for (int i=0; i<(int)t.size(); ++i) {
		v.push_back(set<int> ());
		doSet(t[i], v.back());
	}
}
bool contains(const set<int> &s, const set<int> &t) {
	for (set<int>::const_iterator it=t.begin(); it!=t.end(); ++it)
		if (s.count(*it))
			return true;
	return false;
}
bool test(const vector< set<int> > &v, const set<int> &s) {
	for (int i=0; i<(int)v.size(); ++i)
		if (!contains(s, v[i]))
			return false;
	return true;
}
class ComputerExpert {
	public:
	vector <string> operate(vector <string> facts, vector <string> rules) {
		M.clear();
		F.clear();
		set<int> S;
		set<int> X;

		for (int i=0; i<(int)facts.size(); ++i)
			S.insert(getInd(facts[i]));

		X = S;
		vector< vector< set<int> > > lhs;
		vector<int> rhs;

		for (int i=0; i<(int)rules.size(); ++i) {
			int pos = rules[i].find('-');
			lhs.push_back(vector< set<int> > ());
			doLhs(rules[i].substr(0, pos-1), lhs.back());
			rhs.push_back(getInd(rules[i].substr(pos+3)));
		}

		vector<bool> done(rules.size(), 0);
		for (int i=0; i<(int)rules.size(); ++i)
			if (S.count(rhs[i]))
				done[i] = 1;

		while (1) {
			set<int> T = S;

			for (int i=0; i<(int)rules.size(); ++i)
				if (!done[i] && test(lhs[i], S)) {
					T.insert(rhs[i]);
					done[i] = 1;
				}
			if (T.size() == S.size())
				break;
			S.swap(T);
		}

		vector<string> sol;
		for (set<int>::const_iterator it=S.begin(); it!=S.end(); ++it)
			if (X.count(*it) == 0)
				sol.push_back(F[*it]);

		sort(sol.begin(), sol.end());
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"SKY_IS_CLOUDY","HAVE_MONEY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"HAVE_MONEY,BAD_WEATHER -> WATCH_MOVIE","SKY_IS_CLOUDY -> BAD_WEATHER",
"GOOD_WEATHER -> PLAY_SOCCER"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"BAD_WEATHER", "WATCH_MOVIE" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, operate(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"NEEDLE_LEAF","KEEPS_LEAVES"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"KEEPS_LEAVES -> EVERGREEN","NEEDLE_LEAF -> GYMNOSPERM",
"EVERGREEN,GYMNOSPERM -> PINE_TREE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"EVERGREEN", "GYMNOSPERM", "PINE_TREE" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, operate(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"I"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"I -> I","P -> CONSONANT", "Z -> CONSONANT", "A/E/I/O/U -> VOWEL"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"VOWEL" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, operate(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"Y","W","L","T","H","J","G","T","F","P","T","P","P","N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"C/V,J,F/T,N,W,L -> M","N/L,F,B/N/E,Y -> C",
"M,G,G,S/F/Q,G,S/G,H/Z,W,F,C,Q/F,M -> E"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"C", "E", "M" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, operate(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"G","H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A/B/C/D/E/F,G/Z -> Y", "H,H,H,H,H,H,H,H -> Z"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Z" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, operate(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"A","B","_X", "X_"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A/B,C -> D","A,B,C -> D","X -> Y","_X_ -> Y"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, operate(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ComputerExpert ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
