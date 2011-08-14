/*
ID: ivan.bu1
PROG: clocks
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

vector<int> moves[9];
void init(int pos, const char *s) {
    while (*s) {
        moves[pos].push_back(*s - 'A');
        ++s;
    }
}
struct State {
    vector< vector<int> > repr;
    State() {
        repr.assign(3, vector<int> (3, 0));
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                repr[i][j] = -12345;
            }
        }
    }
    State(ifstream &fin) {
        repr.assign(3, vector<int> (3, 0));
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                fin >> repr[i][j];
                repr[i][j] = (repr[i][j]==3 ? 1 : repr[i][j]==6 ? 2 : repr[i][j]==9 ? 3 : 0);
            }
        }
    }
    void apply(int move, int times) {
        for (int i=0; i<(int)moves[move].size(); ++i) {
            int a = moves[move][i]/3;
            int b = moves[move][i]%3;
            repr[a][b] = (repr[a][b] + times) % 4;
        }
    }
    bool is_done() const {
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                if (repr[i][j] != 0) {
                    return false;
                }
            }
        }
        return true;
    }
};
int main() {
    init(0, "ABDE");
    init(1, "ABC");
    init(2, "BCEF");
    init(3, "ADG");
    init(4, "BDEFH");
    init(5, "CFI");
    init(6, "DEGH");
    init(7, "GHI");
    init(8, "EFHI");
	ifstream fin("clocks.in");
    State start(fin);
    fin.close();
    
    int min_moves = 3*9 + 1;
    vector<int> sol;
    for (int mask=0; mask<(1<<18); ++mask) {
        int move_cnt = 0;
        vector<int> per_move(9, 0);
        State t = start;
        for (int i=0; i<9; ++i) {
            int x = (mask>>(2*i)) & 3;
            if (x > 0) {
                move_cnt += x;
                per_move[i] = x;
                t.apply(i, x);
            }
        }
        
        if (move_cnt<min_moves && t.is_done()) {
            min_moves = move_cnt;
            sol = per_move;
        }
    }
    ofstream fout("clocks.out");
    ostringstream os;
    for (int i=0; i<9; ++i) {
        while (sol[i]--) {
            os << ' ' << (i+1);
        }
    }
    fout << os.str().substr(1) << '\n';
    fout.close();
	return 0;
}
