#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int SZ = 1000000;
int m[SZ], M[SZ];

bool bet(int c, int a, int b) {
	return a<=c && c<=b;
}

string encode(int x, int y) {
	char buff[50];
	sprintf(buff, "(%06d, %06d)", x, y);

	return string(buff);
}

void mark(int x, int a, int b) {
	if (a > b) {
		swap (a, b);
	}

	if (m[x] == -1) {
		m[x] = a;
		M[x] = b;
	} else {
		m[x] = min(m[x], a);
		M[x] = max(M[x], b);
	}
}
class DukeOnLargeChessBoard {
	public:
	string lastCell(string p) {
		int x, y;
		sscanf(p.c_str(), "(%d, %d)", &x, &y);

		for (int i=0; i<SZ; ++i) {
			m[i] = M[i] = -1;
		}
		
		while (true) {
			if (x+1<SZ && !bet(y, m[x+1], M[x+1])) {
				mark(x, y, y);
				++x;
			} else if (y+1<SZ && !bet(y+1, m[x], M[x])) {
				int ny = SZ-1;
				if (m[x]!=-1 && m[x]>y) {
					ny = m[x]-1;
				}
				if (x+1 < SZ) {
					assert(m[x+1] != -1);
					ny = min(ny, M[x+1]+1);
				}

				mark(x, y, ny);
				y = ny;
			} else if (y>0 && !bet(y-1, m[x], M[x])) {
				int ny = 0;
				if (M[x]!=-1 && M[x]<y) {
					ny = M[x]+1;
				}
				if (x+1 < SZ) {
					assert(m[x+1] != -1);
					ny = max(ny, m[x+1]-1);
				}
				mark(x, y, ny);
				y = ny;
			} else if (x>0 && !bet(y, m[x-1], M[x-1])) {
				mark(x, y, y);
				--x;
			} else {
				return encode(x, y);
			}
		}

		return encode(x, y);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "(999999, 999999)"; string Arg1 = "(000000, 999999)"; verify_case(0, Arg1, lastCell(Arg0)); }
	void test_case_1() { string Arg0 = "(999999, 000000)"; string Arg1 = "(000000, 000000)"; verify_case(1, Arg1, lastCell(Arg0)); }
	void test_case_2() { string Arg0 = "(000000, 999998)"; string Arg1 = "(000000, 999999)"; verify_case(2, Arg1, lastCell(Arg0)); }
	void test_case_3() { string Arg0 = "(999998, 000001)"; string Arg1 = "(999999, 000000)"; verify_case(3, Arg1, lastCell(Arg0)); }
	void test_case_4() { string Arg0 = "(123456, 235711)"; string Arg1 = "(000000, 112256)"; verify_case(4, Arg1, lastCell(Arg0)); }
	void test_case_5() { string Arg0 = "(987654, 123456)"; string Arg1 = "(864197, 000000)"; verify_case(5, Arg1, lastCell(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    DukeOnLargeChessBoard ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
