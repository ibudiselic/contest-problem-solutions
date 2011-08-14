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
int n;
map<string, int> ind;
vector<char> gender;
vector< vector<int> > parent;
vector< vector<int> > common;
bool cycle(int y, int x) {
	if (y == x) return true;
	const vector<int> &v = parent[y];
	if (v[0] != -1) {
		if (v[1] != -1) return cycle(v[0], x) || cycle(v[1], x);
		else return cycle(v[0], x);
	}
	return false;
}
vector< vector<int> > a;
vector<char> color;
int ok, wrong;

bool go(int x, char c) {
	color[x] = c;
	if (gender[x] != 0) {
		ok += gender[x]==c;
		wrong += gender[x]!=c;
	}
	for (int i=0; i<n; ++i)
		if (common[x][i]) {
			if (color[i]!=0 && color[i]==c) {
				return false;
		  } else if (color[i] == 0) {
				if (!go(i, c=='m' ? 'f':'m'))
					return false;
			}
		}
	return true;
}
bool colorable() {
	a = common;
	color.assign(n, 0);
	for (int i=0; i<n; ++i)
		if (color[i] == 0) {
			ok = 0;
			wrong = 0;
			if (!go(i, 'm') || (wrong!=0 && ok!=0))
				return false;
		}
	return true;
}
class FamilyTree {
	public:
	int firstBad(vector <string> data) {
		n = 0;
		ind.clear();
		for (int i=0; i<(int)data.size(); ++i) {
			string a, b;
			istringstream is(data[i]);
			is >> a >> b;
			if (ind.count(a) == 0)
				ind[a] = n++;
			if (b[0]<'a' && ind.count(b)==0)
				ind[b] = n++;
		}

		gender.assign(n, 0);
		parent.assign(n, vector<int>(2, -1));
		common.assign(n, vector<int>(n, 0));
		for (int i=0; i<(int)data.size(); ++i) {
			string a, b;
			istringstream is(data[i]);
			is >> a >> b;
			const int x = ind[a];
			if (b[0] > 'Z') {
				if (gender[x] == 0) gender[x] = b[0];
				else if (gender[x] != b[0])
					return i;
			} else {
				const int y = ind[b];
				vector<int> &v = parent[x];
				if (v[0] == -1) {
					v[0] = y;
					if (cycle(y, x))
						return i;
				} else if (v[0] != y) {
					if (v[1] == -1) {
						v[1] = y;
						common[y][v[0]] = 1;
						common[v[0]][y] = 1;
						if (cycle(y, x))
							return i;
					} else if (v[1] != y) {
						return i;
					}
				}
			}
			if (!colorable())
				return i;
		}
		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BOB JOHN","BOB JOHN","BOB MARY","BOB m","AL f"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(0, Arg1, firstBad(Arg0)); }
	void test_case_1() { string Arr0[] = {"BOB JOHN","BOB MARY","MARY JOHN","JOHN f","MARY f","AL f"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, firstBad(Arg0)); }
	void test_case_2() { string Arr0[] = {"BOB JOHN", "CARLA BOB", "JOHN CARLA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, firstBad(Arg0)); }
	void test_case_3() { string Arr0[] = {"BOB RICK", "AL RICK", "AL PAULA", "PAULA LINUS", "LINUS BOB","BOB PAULA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, firstBad(Arg0)); }
	void test_case_4() { string Arr0[] = {"JOHN f", "JOHN m"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, firstBad(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FamilyTree ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
