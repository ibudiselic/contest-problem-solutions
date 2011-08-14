#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dx[] = { -1, -1,  0,  1,  1,  1,  0, -1 };
int dy[] = {  0,  1,  1,  1,  0, -1, -1, -1 };

class Tothello {
	public:
	inline bool inbounds(int i, int j) {
		return i>=0&&i<8 && j>=0&&j<8;
	}
	int bestMove(vector <string> red, vector <string> black, string who) {
		char a[8][8], b[8][8];
		char c, d;

		memset(a, 0, sizeof a);
		for (int i=0; i<(int)red.size(); ++i) {
			istringstream is(red[i]);
			string t;
			while (is >> t)
				a[t[1]-'0'][t[0]-'A'] = 'R';
		}
		for (int i=0; i<(int)black.size(); ++i) {
			istringstream is(black[i]);
			string t;
			while (is >> t)
				a[t[1]-'0'][t[0]-'A'] = 'B';
		}
		c = (who=="Black") ? 'B':'R';
		d = (c=='R') ? 'B':'R';

		int sol = 0;
		for (int i=0; i<8; ++i)
			for (int j=0; j<8; ++j) {
				memcpy(b, a, sizeof b);
				b[i][j] = c;
				bool done = true;
				do {
					done = true;
					for (int x=0; x<8; ++x)
						for (int y=0; y<8; ++y)
							if (b[x][y]==d) {
								for (int k=0; k<4; ++k) {
									int m1, m2;
									for (m1=1; inbounds(x+m1*dx[k], y+m1*dy[k]) && b[x+m1*dx[k]][y+m1*dy[k]]; ++m1)
										if (b[x+m1*dx[k]][y+m1*dy[k]] == c)
											break;
									if (!inbounds(x+m1*dx[k], y+m1*dy[k]) || b[x+m1*dx[k]][y+m1*dy[k]]!=c) continue;
									for (m2=1; inbounds(x+m2*dx[k+4], y+m2*dy[k+4]) && b[x+m2*dx[k+4]][y+m2*dy[k+4]]; ++m2)
										if (b[x+m2*dx[k+4]][y+m2*dy[k+4]] == c)
											break;
									if (!inbounds(x+m2*dx[k+4], y+m2*dy[k+4]) || b[x+m2*dx[k+4]][y+m2*dy[k+4]]!=c) continue;
									b[x][y] = c;
									done = false;
									break;
								}
							}
				} while (!done);
				int cnt = 0;
				for (int x=0; x<8; ++x)
					for (int y=0; y<8; ++y)
						cnt += b[x][y]==c;
				if (cnt > sol)
					sol = cnt;
			}
		return sol;
	}







   // *** WARNING *** No test cases defined for this problem
};

// BEGIN CUT HERE
int main()
    {
    Tothello ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
