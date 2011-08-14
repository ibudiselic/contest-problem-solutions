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

vector<string> S;
int M, N;

int grundy[1<<20];
bool test(int mask, int i, int j) {
    const int offset = i*N + j;
    return (mask>>offset) & 1;
}
void set_bit(int &mask, int i, int j) {
    const int offset = i*N + j;
    mask |= (1<<offset);
}
void reset_bit(int &mask, int i, int j) {
    const int offset = i*N + j;
    mask &= ~(1<<offset);
}
int di[] = { 0, 0, 1, 1 };
int dj[] = { 0, 1, 0, 1 };
bool is_square(int mask, int i, int j) {
    for (int d=0; d<4; ++d) {
        int r = i + di[d];
        int c = j + dj[d];
        if (test(mask, r, c)) {
            return false;
        }
    }
    return true;
}
void set_square(int &mask, int i, int j) {
    for (int d=0; d<4; ++d) {
        int r = i + di[d];
        int c = j + dj[d];
        set_bit(mask, r, c);
    }
}
void reset_square(int &mask, int i, int j) {
    for (int d=0; d<4; ++d) {
        int r = i + di[d];
        int c = j + dj[d];
        reset_bit(mask, r, c);
    }
}
class LittleSquares {
	public:
	string winner(vector <string> state) {
        S = state;
        M = S.size();
        N = S[0].size();

        int mask = 0;
        for (int i=0; i<2; ++i) {
            for (int j=0; j<N; ++j) {
                set_bit(mask, i, j);
            }
        }
        grundy[mask] = 0;
        while (--mask >= 0) {
            set<int> taken;
            for (int i=0; i<2; ++i) {
                for (int j=0; j<N; ++j) {
                    if (!test(mask, i, j)) {
                        set_bit(mask, i, j);
                        taken.insert(grundy[mask]);
                        reset_bit(mask, i, j);
                        if (i==0 && j+1<N && is_square(mask, 0, j)) {
                            set_square(mask, 0, j);
                            taken.insert(grundy[mask]);
                            reset_square(mask, 0, j);
                        }
                    }
                }
            }
            grundy[mask] = -1;
            int last = -1;
            for (set<int>::const_iterator it=taken.begin(); it!=taken.end(); ++it) {
                if (last+1 != *it) {
                    break;
                } else {
                    ++last;
                }
            }
            grundy[mask] = last + 1;
        }

        int sol = 0;
        for (int i=0; i<M; i+=2) {
            mask = 0;
            for (int r=i; r<i+2; ++r) {
                for (int c=0; c<N; ++c) {
                    if (S[r][c] == '#') {
                        set_bit(mask, r-i, c);
                    }
                }
            }
            sol ^= grundy[mask];
        }

        return sol!=0 ? "first" : "second";


	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "..",
  ".." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "first"; verify_case(0, Arg1, winner(Arg0)); }
	void test_case_1() { string Arr0[] = { "...#",
  "..##" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "first"; verify_case(1, Arg1, winner(Arg0)); }
	void test_case_2() { string Arr0[] = { "..",
  "..",
  "..",
  ".." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "second"; verify_case(2, Arg1, winner(Arg0)); }
	void test_case_3() { string Arr0[] = { "....",
  "...." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "first"; verify_case(3, Arg1, winner(Arg0)); }
	void test_case_4() { string Arr0[] = { ".##.",
  "#..#",
  "#..#",
  ".##." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "second"; verify_case(4, Arg1, winner(Arg0)); }
	void test_case_5() { string Arr0[] = { "#.......",
  ".....##.",
  ".....##.",
  "........",
  "........",
  "........",
  "........",
  "#......#" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "first"; verify_case(5, Arg1, winner(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    LittleSquares ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
