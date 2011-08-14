#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>
#include <set>

using namespace std;

char turn;
vector<string> B;
int transform_row;
bool valid(int i, int j) {
    if (i<0 || j<0 || i>=8 || j>=8) {
        return false;
    }
    return true;
}
inline bool is_my_piece(int i, int j) {
    return (toupper(B[i][j]) == turn);
}
inline bool is_opp_piece(int i, int j) {
    return B[i][j]!='.' && !is_my_piece(i, j);
}
inline bool is_empty(int i, int j) {
    return B[i][j] == '.';
}
inline bool is_king(int i, int j) {
    return isupper(B[i][j]);
}
inline bool is_man(int i, int j) {
    return islower(B[i][j]);
}
bool dead[8][8];

const int di[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
const int dj[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

const int diagi[] = { -1, -1, 1, 1 };
const int diagj[] = { -1, 1, 1, -1 };

int mi[2], mj[] = {-1, 1};

char buff[3];
string to_str(int i, int j) {
    sprintf(buff, "%c%d", char('a'+j), 8-i);
    return string(buff, buff+2);
}

set<string> sol;
vector<string> cur;
void add(char delim) {
    string s = cur[0];
    for (int i=1; i<(int)cur.size(); ++i) {
        s += delim + cur[i];
    }
    sol.insert(s);
}

bool can_capture(int i, int j) {
    for (int d=0; d<4; ++d) {
        int k = 1;
        while (valid(i+k*diagi[d], j+k*diagj[d]) && is_empty(i+k*diagi[d], j+k*diagj[d])) {
            ++k;
        }
        if (!valid(i+k*diagi[d], j+k*diagj[d]) || is_my_piece(i+k*diagi[d], j+k*diagj[d]) || dead[i+k*diagi[d]][j+k*diagj[d]]) {
            continue;
        }
        assert(is_opp_piece(i+k*diagi[d], j+k*diagj[d]));
        if (!valid(i+(k+1)*diagi[d], j+(k+1)*diagj[d]) || !is_empty(i+(k+1)*diagi[d], j+(k+1)*diagj[d])) {
            continue;
        }
        return true;
    }
    return false;
}
void capture_king(int i, int j) {
    cur.push_back(to_str(i, j));
    bool can_stop = true;
    for (int d=0; d<4; ++d) {
        int k = 1;
        while (valid(i+k*diagi[d], j+k*diagj[d]) && is_empty(i+k*diagi[d], j+k*diagj[d])) {
            ++k;
        }
        if (!valid(i+k*diagi[d], j+k*diagj[d]) || is_my_piece(i+k*diagi[d], j+k*diagj[d]) || dead[i+k*diagi[d]][j+k*diagj[d]]) {
            continue;
        }
        assert(is_opp_piece(i+k*diagi[d], j+k*diagj[d]));
        if (!valid(i+(k+1)*diagi[d], j+(k+1)*diagj[d]) || !is_empty(i+(k+1)*diagi[d], j+(k+1)*diagj[d])) {
            continue;
        }
        can_stop = false;
        dead[i+k*diagi[d]][j+k*diagj[d]] = 1;
        bool further_captures = false;
        int kk = k + 1;
        while (valid(i+kk*diagi[d], j+kk*diagj[d]) && is_empty(i+kk*diagi[d], j+kk*diagj[d])) {
            if (can_capture(i+kk*diagi[d], j+kk*diagj[d])) {
                further_captures = true;
                capture_king(i+kk*diagi[d], j+kk*diagj[d]);
            }
            ++kk;
        }
        if (!further_captures) {
            kk = k + 1;
            while (valid(i+kk*diagi[d], j+kk*diagj[d]) && is_empty(i+kk*diagi[d], j+kk*diagj[d])) {
                cur.push_back(to_str(i+kk*diagi[d], j+kk*diagj[d]));
                add(':');
                cur.pop_back();
                ++kk;
            }
        }
        dead[i+k*diagi[d]][j+k*diagj[d]] = 0;
    }

    if (can_stop) {
        add(':');
    }
    cur.pop_back();
}

void move_king(int i, int j) {
    cur.push_back(to_str(i, j));
    bool must_capture = false;

    for (int d=0; d<4; ++d) {
        int k = 1;
        while (valid(i+k*diagi[d], j+k*diagj[d]) && is_empty(i+k*diagi[d], j+k*diagj[d])) {
            ++k;
        }
        if (!valid(i+k*diagi[d], j+k*diagj[d]) || is_my_piece(i+k*diagi[d], j+k*diagj[d]) || dead[i+k*diagi[d]][j+k*diagj[d]]) {
            continue;
        }
        assert(is_opp_piece(i+k*diagi[d], j+k*diagj[d]));
        if (!valid(i+(k+1)*diagi[d], j+(k+1)*diagj[d]) || !is_empty(i+(k+1)*diagi[d], j+(k+1)*diagj[d])) {
            continue;
        }
        must_capture = true;
        dead[i+k*diagi[d]][j+k*diagj[d]] = 1;
        bool further_captures = false;
        int kk = k + 1;
        while (valid(i+kk*diagi[d], j+kk*diagj[d]) && is_empty(i+kk*diagi[d], j+kk*diagj[d])) {
            if (can_capture(i+kk*diagi[d], j+kk*diagj[d])) {
                further_captures = true;
                capture_king(i+kk*diagi[d], j+kk*diagj[d]);
            }
            ++kk;
        }
        if (!further_captures) {
            kk = k + 1;
            while (valid(i+kk*diagi[d], j+kk*diagj[d]) && is_empty(i+kk*diagi[d], j+kk*diagj[d])) {
                cur.push_back(to_str(i+kk*diagi[d], j+kk*diagj[d]));
                add(':');
                cur.pop_back();
                ++kk;
            }
        }
        dead[i+k*diagi[d]][j+k*diagj[d]] = 0;
    }

    if (must_capture) {
        cur.pop_back();
        return;
    }

    for (int d=0; d<4; ++d) {
        int k = 1;
        while (valid(i+k*diagi[d], j+k*diagj[d]) && is_empty(i+k*diagi[d], j+k*diagj[d])) {
            cur.push_back(to_str(i+k*diagi[d], j+k*diagj[d]));
            add('-');
            cur.pop_back();
            ++k;
        }
    }

    cur.pop_back();
}

void capture_man(int i, int j) {
    cur.push_back(to_str(i, j));
    bool can_stop = true;
    for (int d=0; d<4; ++d) {
        const int r = i + diagi[d];
        const int c = j + diagj[d];
        const int rr = r + diagi[d];
        const int cc = c + diagj[d];
        if (valid(rr, cc) && is_empty(rr, cc) && is_opp_piece(r, c) && !dead[r][c]) {
            can_stop = false;
            dead[r][c] = 1;
            if (rr == transform_row) {
                capture_king(rr, cc);
            } else {
                capture_man(rr, cc);
            }
            dead[r][c] = 0;
        }
    }
    if (can_stop) {
        add(':');
    }
    cur.pop_back();
}

void move_man(int i, int j) {
    cur.push_back(to_str(i, j));
    bool must_capture = false;
    for (int d=0; d<4; ++d) {
        const int r = i + diagi[d];
        const int c = j + diagj[d];
        const int rr = r + diagi[d];
        const int cc = c + diagj[d];
        if (valid(rr, cc) && is_empty(rr, cc) && is_opp_piece(r, c) && !dead[r][c]) {
            must_capture = true;
            dead[r][c] = 1;
            if (rr == transform_row) {
                capture_king(rr, cc);
            } else {
                capture_man(rr, cc);
            }
            dead[r][c] = 0;
        }
    }

    if (must_capture) {
        cur.pop_back();
        return;
    }

    for (int d=0; d<2; ++d) {
        const int r = i + mi[d];
        const int c = j + mj[d];
        if (valid(r, c) && is_empty(r, c)) {
            cur.push_back(to_str(r, c));
            add('-');
            cur.pop_back();
        }
    }
    cur.pop_back();
}

class RussianCheckers {
	public:
	vector <string> listMoves(vector <string> board, string turn_) {
        B = board;
		turn = turn_[0];
        if (turn == 'W') {
            transform_row = 0;
            mi[0] = mi[1] = -1;
        } else {
            mi[0] = mi[1] = +1;
            transform_row = 7;
        }
        sol.clear();

        for (int i=0; i<8; ++i) {
            for (int j=0; j<8; ++j) {
                if (is_my_piece(i, j)) {
                    char c = B[i][j];
                    if (is_man(i, j)) {
                        B[i][j] = '.';
                        move_man(i, j);
                    } else {
                        B[i][j] = '.';
                        move_king(i, j);
                    }
                    B[i][j] = c;
                }
            }
        }

        bool can_capture = false;
        for (set<string>::const_iterator it=sol.begin(); it!=sol.end(); ++it) {
            if (it->find(':') != string::npos) {
                can_capture = true;
                break;
            }
        }
        if (!can_capture) {
            return vector<string>(sol.begin(), sol.end());
        } else {
            vector<string> t;
            for (set<string>::const_iterator it=sol.begin(); it!=sol.end(); ++it) {
                if (it->find(':') != string::npos) {
                    t.push_back(*it);
                }
            }
            return t;
        }
    }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {".b.b.b.b",
 "b.b.b.b.",
 ".b.b.b.b",
 "........",
 "........",
 "w.w.w.w.",
 ".w.w.w.w",
 "w.w.w.w."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WHITE"; string Arr2[] = {"a3-b4", "c3-b4", "c3-d4", "e3-d4", "e3-f4", "g3-f4", "g3-h4" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, listMoves(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".......B",
 "......w.",
 "........",
 "........",
 ".......W",
 "........",
 "...W.W..",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BLACK"; string Arr2[] = {"h8:c3:e1:g3", "h8:d4:g1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, listMoves(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"........",
 "........",
 "...b....",
 "........",
 "...b.b..",
 "..w.....",
 ".....w..",
 "........"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WHITE"; string Arr2[] = {"c3:e5:c7", "c3:e5:g3" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, listMoves(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"........",
 "..b.....",
 ".w......",
 "......B.",
 "........",
 "........",
 "........",
 "........"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WHITE"; string Arr2[] = {"b6:d8:h4" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, listMoves(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"........",
 "......b.",
 "........",
 "........",
 "...W....",
 "........",
 ".b......",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WHITE"; string Arr2[] = {"d4:a1", "d4:h8" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, listMoves(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"........",
 "..w.w...",
 "........",
 "....w...",
 "........",
 "..B.w...",
 "........",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BLACK"; string Arr2[] = {"c3:f6:d8:b6:f2", "c3:f6:d8:b6:g1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, listMoves(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {".......b",
 "....w.w.",
 "........",
 "....b...",
 ".w.w.w..",
 "........",
 "...w.w..",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BLACK"; string Arr2[] = {"e5:c3:a5", "e5:c3:e1:g3:d6:a3", "e5:c3:e1:g3:d6:f8:h6", "e5:c3:e1:h4:d8", "e5:g3:e1:c3:a5", "e5:g3:e1:c3:f6:d8", "h8:f6:d8" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(6, Arg2, listMoves(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RussianCheckers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
