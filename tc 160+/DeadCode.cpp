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

vector<string> C;
bool reachable[50];
void dfs(int x) {
	reachable[x] = 1;
	if (C[x] == "RETURN")
		return;

	int a, b;
	sscanf(C[x].c_str(), "IF %d ELSE %d", &a, &b);
	if (!reachable[a])
		dfs(a);
	if (!reachable[b])
		dfs(b);
}
class DeadCode {
	public:
	int deadCount(vector <string> code) {
		set<int> alive;
		C = code;
		vector< vector<int> > fromWhere(C.size(), vector<int>());

		for (int i=0; i<(int)C.size(); ++i)
			if (C[i] == "RETURN") {
				alive.insert(i);
			} else {
				int a, b;
				sscanf(C[i].c_str(), "IF %d ELSE %d", &a, &b);
				fromWhere[a].push_back(i);
				fromWhere[b].push_back(i);
			}

		while (1) {
			set<int> next = alive;
			for (set<int>::const_iterator it=alive.begin(); it!=alive.end(); ++it)
				for (int i=0; i<(int)fromWhere[*it].size(); ++i)
					next.insert(fromWhere[*it][i]);
			if (next == alive)
				break;
			alive = next;
		}

		memset(reachable, 0, sizeof reachable);
		dfs(0);

		int cntOK = 0;
		for (set<int>::const_iterator it=alive.begin(); it!=alive.end(); ++it)
			cntOK += (reachable[*it]);

		return C.size()-cntOK;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"RETURN", "IF 0 ELSE 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, deadCount(Arg0)); }
	void test_case_1() { string Arr0[] = {"IF 1 ELSE 2","IF 1 ELSE 2","RETURN"} ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, deadCount(Arg0)); }
	void test_case_2() { string Arr0[] = {"IF 1 ELSE 2","RETURN", "IF 3 ELSE 2", "IF 2 ELSE 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, deadCount(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DeadCode ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
