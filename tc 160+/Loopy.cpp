#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <queue>

using namespace std;

/*
NE RADI
*/

struct state {
	int x, p;
	state(int x_, int p_): x(x_), p(p_) {}
};

vector<string> C;
int n, entry;
bool reachable[50];
vector<vector<int> > fw;
bool simple(int x, const vector<state> &Q, int h) {
	while (h != -1)
		if (x == Q[h].x)
			return false;
		else
			h = Q[h].p;

	return true;
}
int doit(int x) {
	vector<state> Q;
	Q.push_back(state(x, -1));
	int head = 0;

	cerr << "ep = " << entry << '\n';
	while (head < (int)Q.size()) {
		x = Q[head].x;

		++head;

		if (C[x] == "RETURN")
			continue;
		assert(C[x] != "DEAD");

		int a, b;
		sscanf(C[x].c_str(), "IF %d ELSE %d", &a, &b);

		if (a==entry || b==entry) {
			vector<int> cyc;
			int t = head-1;

			while (t != -1) {
				cyc.push_back(Q[t].x);
				t = Q[t].p;
			}
			for (int i=0; i<(int)cyc.size(); ++i)
				cerr << cyc[i] << ' ';
			cerr << '\n';

			for (int i=0; i+1<(int)cyc.size(); ++i)
				for (int j=0; j<(int)fw[cyc[i]].size(); ++j)
					if (reachable[fw[cyc[i]][j]] && C[fw[cyc[i]][j]]!="DEAD" && find(cyc.begin(), cyc.end(), fw[cyc[i]][j])==cyc.end())
						goto FAIL;

			if (entry!=0 && find(cyc.begin(), cyc.end(), 0)!=cyc.end())
				goto FAIL;

			return cyc.size();

			FAIL:;
		} else {
			if (C[a]!="DEAD" && a!=0 && simple(a, Q, head-1))
				Q.push_back(state(a, head-1));

			if (b!=a && C[b]!="DEAD" && b!=0 && simple(b, Q, head-1))
				Q.push_back(state(b, head-1));
		}
	}

	return 1234567890;
}
void go(int x) {
	if (C[x] == "DEAD")
		return;

	reachable[x] = 1;

	if (C[x] == "RETURN")
		return;

	int a, b;
	sscanf(C[x].c_str(), "IF %d ELSE %d", &a, &b);
	if (!reachable[a])
		go(a);
	if (!reachable[b])
		go(b);
}

class Loopy {
	public:
	int minLoop(vector <string> code) {
		n = code.size();

		set<int> alive;
		vector< vector<int> > fromWhere(n, vector<int>());
		for (int i=0; i<n; ++i)
			if (code[i] == "RETURN") {
				alive.insert(i);
			} else {
				int a, b;
				sscanf(code[i].c_str(), "IF %d ELSE %d", &a, &b);
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
			alive.swap(next);
		}

		C = code;
		for (int i=0; i<n; ++i)
			if (alive.count(i) == 0)
				C[i] = "DEAD";

		memset(reachable, 0, sizeof reachable);
		go(0);

		fw = fromWhere;
		int sol = 1234567890;
		for (entry=0; entry<n; ++entry)
			if (reachable[entry] && C[entry]!="DEAD")
				sol = min(sol, doit(entry));

		return sol<1234567890 ? sol : 0;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"RETURN", "IF 0 ELSE 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, minLoop(Arg0)); }
	void test_case_1() { string Arr0[] = {"IF 1 ELSE 2","IF 1 ELSE 2","RETURN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minLoop(Arg0)); }
	void test_case_2() { string Arr0[] = {"IF 1 ELSE 2","RETURN", "IF 3 ELSE 2", "IF 2 ELSE 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, minLoop(Arg0)); }
	void test_case_3() { string Arr0[] = {"IF 1 ELSE 2","IF 3 ELSE 3","IF 4 ELSE 1",
 "IF 4 ELSE 5","RETURN","IF 0 ELSE 6",
 "IF 6 ELSE 6","IF 7 ELSE 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, minLoop(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Loopy ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
