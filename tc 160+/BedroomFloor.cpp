#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct rect {
    int x1, x2, y1, y2;
    int sz() {
        return (x2-x1)*(y2-y1);
    }
};

rect room;
long long need[6];

bool is_vert(int x, int y) {
    if ((y/5) & 1) {
        return ((x/5) & 1) == 0;
    } else {
        return ((x/5) & 1);
    }   
}
rect get_board(int x, int y) {
    if (is_vert(x, y)) {
        y -= y%5;
        return (rect){x, x+1, y, y+5};
    } else {
        x -= x%5;
        return (rect){x, x+5, y, y+1};
    }
}
void add(int x, int y) {
    rect board = get_board(x, y);
    board.x1 = max(board.x1, room.x1);
    board.x2 = min(board.x2, room.x2);
    board.y1 = max(board.y1, room.y1);
    board.y2 = min(board.y2, room.y2);
    
    if (board.x1==x && board.y1==y) {
        ++need[board.sz()];
    }
}
class BedroomFloor {
	public:
	long long numberOfSticks(int x1, int y1, int x2, int y2) {
		memset(need, 0, sizeof need);
        room = (rect){x1, x2, y1, y2};
        
        if (x2-x1<=15 || y2-y1<=15) {
            for (int i=x1; i<x2; ++i) {
                for (int j=y1; j<y2; ++j) {
                    add(i, j);
                }
            }
        } else {
            long long xl, xr, yu, yd;
            xl = (x1+4)/5 * 5;
            xr = x2/5 * 5;
            yu = (y1+4)/5 * 5;
            yd = y2/5 * 5;
            for (int i=x1; i<xl; ++i) {
                for (int j=y1; j<y2; ++j) {
                    add(i, j);
                }
            }
            for (int i=xr; i<x2; ++i) {
                for (int j=y1; j<y2; ++j) {
                    add(i, j);
                }
            }
            for (int i=y1; i<yu; ++i) {
                for (int j=xl; j<xr; ++j) {
                    add(j, i);
                }
            }
            for (int i=yd; i<y2; ++i) {
                for (int j=xl; j<xr; ++j) {
                    add(j, i);
                }
            }
            
            need[5] += (xr-xl)*(yd-yu)/5;
        }
        
        while (need[4]) {
            ++need[5];
            --need[4];
            if (need[1]) {
                --need[1];
            }
        }
        while (need[3]) {
            ++need[5];
            --need[3];
            if (need[2]) {
                --need[2];
            } else {
                for (int t=0; t<2; ++t) {
                    if (need[1]) {
                        --need[1];
                    } else {
                        break;
                    }
                }
            }
        }
        while (need[2]) {
            ++need[5];
            --need[2];
            if (need[2]) {
                --need[2];
                if (need[1]) {
                    --need[1];
                }
            } else {
                for (int t=0; t<3; ++t) {
                    if (need[1]) {
                        --need[1];
                    } else {
                        break;
                    }
                }
            }
        }
                
        return need[5] + (need[1]+4)/5;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 5; int Arg3 = 5; long long Arg4 = 5LL; verify_case(0, Arg4, numberOfSticks(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 10; int Arg3 = 2; long long Arg4 = 5LL; verify_case(1, Arg4, numberOfSticks(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 8; int Arg3 = 8; long long Arg4 = 12LL; verify_case(2, Arg4, numberOfSticks(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 5; int Arg2 = 20; int Arg3 = 16; long long Arg4 = 27LL; verify_case(3, Arg4, numberOfSticks(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 1000000; int Arg3 = 1000000; long long Arg4 = 200000000000LL; verify_case(4, Arg4, numberOfSticks(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BedroomFloor ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
