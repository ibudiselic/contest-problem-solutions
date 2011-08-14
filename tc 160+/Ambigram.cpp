#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <map>

using namespace std;

//H I N O S X Z look unchanged after rotation
//M W look like each other after rotation
map< pair<bool, string>, pair<int, string> > M;

pair<int, string> best_char(char c) {
	static const string unchanged = "HINOSXZ";
	pair<int, string> ret;
	ret.first = 1000000000;
	for (int i=0; i<(int)unchanged.size(); ++i) {
		const int cost = abs(c-unchanged[i]);
		if (cost < ret.first) {
			ret.first = cost;
			ret.second = string(1, unchanged[i]);
		}
	}
	return ret;
}
pair<int, char> match_cost(char a, char b) {
	static const string unchanged = "HIMNOSWXZ";
	pair<int, char> ret(1000000000, ' ');
	for (int i=0; i<(int)unchanged.size(); ++i) {
		int cost = 0;
		if (unchanged[i]=='M' || unchanged[i]=='W')
			cost = abs(a - (unchanged[i]=='M' ? 'M':'W'))+abs(b - (unchanged[i]=='M' ? 'W':'M'));
		else
			cost = abs(a-unchanged[i]) + abs(b-unchanged[i]);
		if (cost < ret.first) {
			ret.first = cost;
			ret.second = unchanged[i];
		}
	}
	return ret;
}
int remove_cost(char c) {
	return min(c-'A', 'Z'-c) + 1;
}
pair<int, string> better(const pair<int, string> &a, const pair<int, string> &b) {
	if (a.first < b.first)
		return a;
	else if (b.first < a.first)
		return b;
	if (a.second.size() > b.second.size())
		return a;
	else if (b.second.size() > a.second.size())
		return b;
	if (a.second < b.second)
		return a;
	else
		return b;
}
pair<int, string> go(bool canEmpty, const string &word) {
	if (M.count(make_pair(canEmpty, word)))
		return M[make_pair(canEmpty, word)];
	const int n = word.size();
	if (n == 0)
		if (canEmpty)
			return M[make_pair(canEmpty, word)] = make_pair(0, string());
		else
			return M[make_pair(canEmpty, word)] = make_pair(1000000000, string());
	if (n == 1) {
		pair<int, string> t = best_char(word[0]);
		if (canEmpty)
			t = better(t, make_pair(remove_cost(word[0]), ""));
		return M[make_pair(canEmpty, word)] = t;
	}

	pair<int, string> ret = go(canEmpty, word.substr(1));
	ret.first += remove_cost(word[0]);
	pair<int, string> cur = go(canEmpty, word.substr(0, word.size()-1));
	cur.first += remove_cost(word[word.size()-1]);
	ret = better(ret, cur);
	cur = go(1, word.substr(1, word.size()-2));
	const pair<int, char> t = match_cost(word[0], word[word.size()-1]);
	cur.first += t.first;
	if (t.second=='M' || t.second=='W')
		cur.second = t.second + cur.second + (t.second=='M' ? 'W':'M');
	else
		cur.second = t.second + cur.second + t.second;
	ret = better(ret, cur);

	return M[make_pair(canEmpty, word)] = ret;
}
class Ambigram {
	public:
	string ambiword(string word) {
		M.clear();

		return go(0, word).second;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BXC"; string Arg1 = "X"; verify_case(0, Arg1, ambiword(Arg0)); }
	void test_case_1() { string Arg0 = "XIXHZMOAOSHXIX"; string Arg1 = "XIXHMOOWHXIX"; verify_case(1, Arg1, ambiword(Arg0)); }
	void test_case_2() { string Arg0 = "C"; string Arg1 = "H"; verify_case(2, Arg1, ambiword(Arg0)); }
	void test_case_3() { string Arg0 = "AMWZ"; string Arg1 = "MW"; verify_case(3, Arg1, ambiword(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Ambigram ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
