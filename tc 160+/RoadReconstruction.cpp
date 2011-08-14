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

vector<string> names;
map<string, int> M;
int getInd(const string &s) {
	if (M.count(s) == 0) {
		M[s] = names.size();
		names.push_back(s);
	}
	return M[s];
}
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

class UnionFind {
	public:
	// sz is the size of the structure - the keys can range from 0 to sz-1
	UnionFind(int sz, bool seedRand=true) {
		parent.assign(sz, -1);
		if (seedRand)
			srand(time(NULL));
	}
	// return false if x is already in the structure, true otherwise
	bool insert(int x) {
		if (parent[x] != -1)
			return false;
		parent[x] = x;
		return true;
	}
	// return the root of item with key x
	int root(int x) {
		if (parent[x] == -1)
			return -1;
		if (parent[x] == x)
			return x;
		return parent[x] = root(parent[x]);
	}
	// merge subtrees of items with keys x and y
	bool merge(int x, int y) {
		int a = root(x);
		int b = root(y);

		if (a == -1) {
			insert(x);
			a = x;
		}
		if (b == -1) {
			insert(y);
			b = y;
		}
		if (a == b)
			return false;

		if (rand() < RAND_MAX/2)
			parent[a] = b;
		else
			parent[b] = a;

		return true;
	}
	private:
	vector<int> parent;
};

struct Edge {
	int a, b, c;
	string id;
	Edge(int a_, int b_, int c_, const string &id_): a(a_), b(b_), c(c_), id(id_) {}
};
bool operator<(const Edge &x, const Edge &y) {
	if (x.c != y.c)
		return x.c < y.c;
	else
		return x.id < y.id;
}

class RoadReconstruction {
	public:
	string selectReconstruction(vector <string> roads) {
		M.clear();
		names.clear();
		UnionFind G(100);
		vector<Edge> v;

		for (int i=0; i<(int)roads.size(); ++i) {
			vector<string> t = cutUp(roads[i]);
			if (t.size() == 3) {
				int a = getInd(t[1]);
				int b = getInd(t[2]);
				G.merge(a, b);
			} else {
				assert(t.size() == 4);
				int a = getInd(t[1]);
				int b = getInd(t[2]);
				int x;
				sscanf(t[3].c_str(), "%d", &x);
				v.push_back(Edge(a, b, x, t[0]));
			}
		}

		sort(v.begin(), v.end());
		vector<string> ids;
		for (int i=0; i<(int)v.size(); ++i)
			if (G.merge(v[i].a, v[i].b))
				ids.push_back(v[i].id);

		int n = names.size();
		for (int i=0; i<n; ++i)
			for (int j=i+1; j<n; ++j)
				if (G.merge(i, j))
					return "IMPOSSIBLE";

		if (ids.size() == 0)
			return "";

		sort(ids.begin(), ids.end());
		string sol;
		for (int i=0; i<(int)ids.size(); ++i)
			sol += ' ' + ids[i];

		return sol.substr(1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"M1 Moscow Kiev 1", "M2 Minsk Kiev", "M3 Minsk Warsaw"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "M1"; verify_case(0, Arg1, selectReconstruction(Arg0)); }
	void test_case_1() { string Arr0[] = {"R1 NY Washington", "M1 Moscow StPetersburg 1000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "IMPOSSIBLE"; verify_case(1, Arg1, selectReconstruction(Arg0)); }
	void test_case_2() { string Arr0[] = {"B1 Bratislava Havka"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(2, Arg1, selectReconstruction(Arg0)); }
	void test_case_3() { string Arr0[] = {"M1 Moscow StPetersburg 1", "M2 Moscow Saratov 2", "S0 Saratov StPetersburg"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "M1"; verify_case(3, Arg1, selectReconstruction(Arg0)); }
	void test_case_4() { string Arr0[] = {"O1 Beetown Fearnot 6","N7 Fearnot Hornytown","M8 Hornytown Belcher 10",
 "L5 Belcher Fearnot 8","C7 Fearnot Beetown 4","K7 Quiggleville Beetown 12",
 "H4 Beetown DryFork 6","Z0 Hornytown Belcher 1","O5 Belcher Quiggleville 10",
 "U7 Quiggleville Fearnot 2","A8 Fearnot Quiggleville 8","T6 Beetown DryFork 17",
 "E8 Quiggleville DryFork 8","Y4 DryFork Quiggleville 4","Q8 Hornytown DryFork 2",
 "J9 Quiggleville DryFork 19","M4 DryFork Quiggleville 7","T1 DryFork Fearnot 9",
 "G4 Fearnot DryFork 6","V9 Hornytown Beetown 5","O6 Quiggleville Beetown 4",
 "L8 Beetown Roachtown 5","D5 Belcher DryFork 8","W5 Belcher DryFork 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "C7 L8 U7 W5 Z0"; verify_case(4, Arg1, selectReconstruction(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RoadReconstruction ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
