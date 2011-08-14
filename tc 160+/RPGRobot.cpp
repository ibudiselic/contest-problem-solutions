#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dir[128];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

template<class T> vector<T> tokenize(string s, const string &delim=" ") {
  vector<T> ret;
  string::size_type i=0;
  string::size_type len = delim.length();
  if (delim != " ")
    while ((i=s.find(delim)) != string::npos)
      s.replace(i, len, " ");

  istringstream is(s);
  T val;
  while (is >> val)
    ret.push_back(val);
  return ret;
}

vector< vector<string> > legal;
vector<string> pathLegal;
vector <string> map;
vector<int> move;
int M, N;
string dirs = "NSWE";
bool test(int x, int y) {
	for (int i=0; i<(int)move.size(); ++i) {
		cerr << x-2 << ' ' << y-2 << '\n';
		if (x>=2 && x<N-2 && y>=2 && y<M-2) {
			if (pathLegal[i] != legal[y][x])
				return false;
		} else if (x>=0 && x<N && y>=0 && y<M) {
			for (int k=0; k<(int)pathLegal[i].size(); ++k)
				if (legal[y][x].find(pathLegal[i][k]) == string::npos)
					return false;
		}
		y += 2*dy[move[i]];
		x += 2*dx[move[i]];
	}

	if (x>=2 && x<N-2 && y>=2 && y<M-2) {
		if (pathLegal.back() != legal[y][x])
			return false;
	} else if (x>=0 && x<N && y>=0 && y<M) {
		for (int k=0; k<(int)pathLegal.back().size(); ++k)
			if (legal[y][x].find(pathLegal.back()[k]) == string::npos)
				return false;
	}

	return true;
}
class RPGRobot {
	public:
	vector <string> where(vector <string> map_, string movements) {
		map = map_;
		dir['N'] = 0;
		dir['E'] = 3;
		dir['S'] = 1;
		dir['W'] = 2;

		pathLegal.clear();
		move.clear();
		vector<string> t = tokenize<string>(movements, " ");
		for (int i=0; i<(int)t.size()-1; ++i) {
			move.push_back(dir[t[i][t[i].size()-1]]);
			pathLegal.push_back(t[i].substr(0, t[i].size()-2));
		}
		pathLegal.push_back(t.back());

		M = map.size();
		N = map[0].size();
		map.insert(map.begin(), string(N+4, ' '));
		map.insert(map.begin(), string(N+4, ' '));
		map.push_back(string(N+4, ' '));
		map.push_back(string(N+4, ' '));
		for (int i=2; i<=M+1; ++i)
			map[i] = "  " + map[i] + "  ";
		M += 4;
		N += 4;

		legal.assign(M, vector<string> (N, string()));

		for (int x=1; x<N; x+=2)
			for (int y=1; y<M; y+=2)
				for (int d=0; d<4; ++d) {
					const int r = y + dy[d];
					const int c = x + dx[d];
					if (map[r][c] == ' ')
						legal[y][x] += dirs[d];
				}

		for (int i=0; i<M; ++i) {
			for (int j=0; j<N; ++j)
				cerr << map[i][j];
			cerr << '\n';
		}

		vector<string> sol;
		for (int x=3; x<N-2; x+=2)
			for (int y=3; y<M-2; y+=2) {
				if (test(x, y)) {
					ostringstream os;
					os << x-2 << ',' << y-2;
					sol.push_back(os.str());
				}
			}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"* *",
 "| |",
 "*-*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "N"; string Arr2[] = { "1,1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, where(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"* *-*",
 "| | |",
 "* * *",
 "| | |",
 "*-*-*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "N,N NS"; string Arr2[] = { "1,3" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, where(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"*-*-*",
 "     ",
 "* * *",
 "     ",
 "* * *"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "SWE,S NSWE"; string Arr2[] = { "1,1",  "3,1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, where(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"* *-* *",
 "|     |",
 "* *-* *",
 "|     |",
 "* *-* *"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NSE,E WE,E NSW,N NSW"; string Arr2[] = { "1,1",  "1,3" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, where(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"* *-*",
 "| | |",
 "* * *",
 "| | |",
 "*-*-*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "N,N S"; string Arr2[] = { "3,3" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, where(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"*-*",
 "| |",
 "*-*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "N"; string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, where(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"* * * *",
 "       ",
 "*-*-*-*"}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NWE,N NSE,E SWE,S NWE"; string Arr2[] = { "1,1",  "3,1",  "5,1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(6, Arg2, where(Arg0, Arg1)); }
	void test_case_7() { string Arr0[] = {"* * * *-* * * *-*-* * * * * *-* *",
 "  |     | |     |   |         |  ",
 "* * *-* * *-* * * * * * * * *-* *",
 "| | |   | | |       |     |     |",
 "* * *-*-* *-*-*-* * * * * * *-*-*",
 "  |     | |   | |   |   |     | |",
 "*-* *-* * *-*-* *-*-*-* * *-* *-*",
 "    | |     |     | |   |   | |  ",
 "*-*-* *-*-*-*-* *-*-*-* *-*-* * *",
 "| |   |         | | |       |    ",
 "*-*-* * * *-* *-*-* * * * *-*-* *",
 "  | |     | | | | | |     | | |  ",
 "*-* *-* * * *-* *-*-* *-* * *-*-*",
 "  | |   | | | |   |   | | |   |  ",
 "*-* * * *-* * *-*-*-* * * * * * *",
 "|     | | |   |   |   | | |      ",
 "* *-*-*-*-*-* *-* * * *-* *-* *-*",
 "  | | |         |   | |   |   |  ",
 "* * *-*-*-* *-* *-*-*-*-*-*-*-*-*",
 "| |     |   | | | |     |     | |",
 "* *-* * *-* *-*-*-*-* * *-*-*-* *",
 "    | | | | |   | | | |     | |  ",
 "* *-*-*-*-* *-*-* *-* *-*-* * *-*",
 "  | | | | |   |         | | |    ",
 "*-*-*-* *-*-* * *-* *-* * * *-*-*",
 "|   | |           |   | | |     |",
 "* *-* * * *-*-* *-*-*-* *-* * *-*",
 "      |     | | | |     |       |",
 "*-* * * * * *-*-* * * * * *-* * *",
 "|           | |       |   | |   |",
 "* * *-*-* *-*-* * * *-*-* * * *-*",
 "|   | | | | |   | | | | | |   | |",
 "*-* * *-* * * * * * *-* *-* *-*-*",
 "  |     | | |   |             | |",
 "*-* *-* *-* * * * *-* *-* *-*-*-*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NW,W SE,S NSW,W NSWE"; string Arr2[] = { "1,23" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(7, Arg2, where(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RPGRobot ___test;
    ___test.run_test(7);
    }
// END CUT HERE
