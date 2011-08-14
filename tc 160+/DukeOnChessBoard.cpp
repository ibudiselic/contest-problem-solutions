#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool used[8][8];
void parse(const string &s, int &i, int &j) {
	i = s[0]-'a';
	j = s[1]-'1';
}

string encode(int i, int j) {
	string s(2, ' ');
	s[0] = 'a' + i;
	s[1] = '1' + j;
	return s;
}

class DukeOnChessBoard {
	public:
	string dukePath(int n, string initPosition) {
		vector<string> v;

		memset(used, 0, sizeof used);
		v.push_back(initPosition);
		while (1) {
			int i, j;
			parse(v.back(), i, j);
			used[i][j] = 1;

			vector<string> t;
			for (int di=-1; di<2; ++di) {
				for (int dj=-1; dj<2; ++dj) {
					if (abs(di) + abs(dj) == 1) {
						const int r = i + di;
						const int c = j + dj;
						if (r<0 || c<0 || r>=n || c>=n || used[r][c]) {
							continue;
						}
						t.push_back(encode(r, c));
					}
				}
			}
			if (t.size() == 0) {
				break;
			}
			sort(t.begin(), t.end());
			v.push_back(t.back());
		}

		string s;
		for (int i=0; i<(int)v.size(); ++i) {
			s += v[i] + '-';
		}
		s = s.substr(0, s.size()-1);
		if (s.size() > 40u) {
			s = s.substr(0, 20) + "..." + s.substr(s.size()-20);
		}
		return s;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arg1 = "b2"; string Arg2 = "b2-c2-c3-b3-a3-a2-a1-b1-c1"; verify_case(0, Arg2, dukePath(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; string Arg1 = "d4"; string Arg2 = "d4-d3-d2-d1-c1-c2-c3...b3-b2-b1-a1-a2-a3-a4"; verify_case(1, Arg2, dukePath(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; string Arg1 = "a2"; string Arg2 = "a2-b2-c2-c3-b3-a3"; verify_case(2, Arg2, dukePath(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; string Arg1 = "d3"; string Arg2 = "d3-d4-c4-c3-c2-d2-d1...b2-b3-b4-a4-a3-a2-a1"; verify_case(3, Arg2, dukePath(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 8; string Arg1 = "a8"; string Arg2 = "a8-b8-c8-d8-e8-f8-g8...a1-a2-a3-a4-a5-a6-a7"; verify_case(4, Arg2, dukePath(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    DukeOnChessBoard ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
