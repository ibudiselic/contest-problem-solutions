#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <utility>

using namespace std;

struct Player {
	int w, p;
	string name;
	Player(int w_, int p_, const string &n_): w(w_), p(p_), name(n_) {}
};
bool operator<(const Player &a, const Player &b) {
	if (a.p==0 && b.p==0)
		return a.name < b.name;
	if (a.p == 0)
		return false;
	if (b.p == 0)
		return true;

	if (a.w*b.p != b.w*a.p)
		return a.w*b.p > b.w*a.p;
	else
		return a.name < b.name;
}
class TheTournament {
	public:
	string findLeader(vector <string> matches) {
		map<string, pair<int, int> > M;
		for (int i=0; i<(int)matches.size(); ++i) {
			string a, b, c;
			istringstream is(matches[i]);
			is >> a >> b >> c;
			++M[a].first;
			++M[a].second;
			++M[c].second;
		}

		vector<Player> v;
		for (map<string, pair<int, int> >::const_iterator it=M.begin(); it!=M.end(); ++it)
			v.push_back(Player((it->second).first, (it->second).second, it->first));

		sort(v.begin(), v.end());

		return v[0].name;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Ted defeats Kate", "Kate defeats Billy", "Ted defeats Billy"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Ted"; verify_case(0, Arg1, findLeader(Arg0)); }
	void test_case_1() { string Arr0[] = {"Ted defeats Kate", "Kate defeats Billy", "Billy defeats Ted"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Billy"; verify_case(1, Arg1, findLeader(Arg0)); }
	void test_case_2() { string Arr0[] = {"Ted defeats Kate", "Kate defeats Billy", "Ted defeats Billy", "Tommy defeats Ted"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Tommy"; verify_case(2, Arg1, findLeader(Arg0)); }
	void test_case_3() { string Arr0[] = {"B defeats BA", "B defeats BB", "BC defeats B", "A defeats AB",
 "A defeats AC", "A defeats AD", "A defeats AE", "AF defeats A",
 "AG defeats A", "AB defeats AF", "AC defeats AG", "BB defeats BC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A"; verify_case(3, Arg1, findLeader(Arg0)); }
	void test_case_4() { string Arr0[] = {"defeats defeats def", "defeats defeats defe", "defe defeats ded", "defeat defeats defeats"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "defeat"; verify_case(4, Arg1, findLeader(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TheTournament ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
