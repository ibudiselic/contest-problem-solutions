#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

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
int subtreeCnt(int x, int user, const vector< vector<int> > &kids, const vector< set<int> > &rights) {
	int ret = rights[x].count(user);

	for (int i=0; i<(int)kids[x].size(); ++i)
		if (kids[x][i] != x)
			ret += subtreeCnt(kids[x][i], user, kids, rights);

	return ret;
}
class PermissionTree {
	public:
	vector <int> findHome(vector <string> folders, vector <string> users) {
		vector<int> P(folders.size(), -1);
		vector< vector<int> > kids(folders.size(), vector<int> ());
		vector<int> depth(P.size(), -1);
		vector<int> cntRights(users.size(), 0);
		vector< set<int> > right(folders.size(), set<int>());

		for (int i=0; i<(int)folders.size(); ++i) {
			sscanf(folders[i].c_str(), "%d", &P[i]);

			kids[P[i]].push_back(i);
			vector<string> ppl = cutUp(folders[i].substr(folders[i].find(' ')+1), ",");
			for (int j=0; j<(int)ppl.size(); ++j) {
				int ind = find(users.begin(), users.end(), ppl[j]) - users.begin();
				if (ind == users.end() - users.begin())
					continue;

				if (right[i].insert(ind).second)
					++cntRights[ind];
			}
		}

		depth[0] = 0;
		int cnt = 51;
		while (cnt--)
			for (int i=0; i<(int)folders.size(); ++i)
				if (depth[P[i]]!=-1 && depth[i]==-1)
					depth[i] = depth[P[i]] + 1;

		vector<int> sol(users.size(), 0);
		for (int i=0; i<(int)sol.size(); ++i) {
			if (cntRights[i] == 0) {
				sol[i] = -1;
			} else {
				sol[i] = 0;
				for (int fold=1; fold<(int)folders.size(); ++fold)
					if (depth[fold]>depth[sol[i]] && subtreeCnt(fold, i, kids, right)==cntRights[i])
						sol[i] = fold;
			}
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"0 Admin", "0 Joe,Phil", "0 Joe"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Admin", "Joe", "Phil"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0,  0,  1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, findHome(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"0 Admin"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Peter", "Paul", "Mary"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { -1,  -1,  -1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, findHome(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"0 Admin", "2 John", "0 Peter,John", "0 Tim", "1 John"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"John"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, findHome(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"0 Admin",
"0 Jeff", "1 Mark,Tim", "1 Tim,Jeff",
"0 Dan", "4 Ed", "4 Tom", "4 Kyle,Ed",
"0 Ben", "8 Rich", "8 Sam", "8 Tim"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Jeff", "Ed", "Tim", "Steve"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1,  4,  0,  -1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, findHome(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"0 Admin", "0 Bob,Joe,Bob", "0 Joe"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Joe", "Bob"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0,  1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, findHome(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PermissionTree ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
