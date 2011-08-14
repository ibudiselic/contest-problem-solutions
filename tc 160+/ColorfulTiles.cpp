#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const long long mod = 1000000007;
const string colors = "RGBY";
long long dp2[51][5][2502];
long long dp[51][4][4][2501];
long long go(const vector<string> &room, int r, int c1, int c2, int changes_left) {
    long long &ret = dp[r][c1][c2][changes_left];
    if (ret != -1) {
        return ret;
    }
    const int m = room.size();
    const int n = room[0].size();
    
    int r_changes = 0;
    int c[2] = { c1, c2 };
    for (int i=0; i<n; ++i) {
        r_changes += (room[r][i] != c[i%2]);
    }
    if (r_changes > changes_left) {
        return (ret = 0);
    }
    if (r+1 == m) {
        return (ret = 1);
    }

    changes_left -= r_changes;
    ret = 0;
    for (int c3=0; c3<4; ++c3) {
        if (c3==c1 || c3==c2) {
            continue;
        }
        int c4 = 0;
        while (c4==c1 || c4==c2 || c4==c3) {
            ++c4;
        }
        ret += go(room, r+1, c3, c4, changes_left);
    }
    ret %= mod;
    //cerr << r << ' ' << c1 << ' ' << c2 << ' ' << changes_left << ' ' << r_changes << ' ' << ' ' << ret << '\n';
    return ret;
}
class ColorfulTiles {
	public:
	int theCount(vector <string> room, int K) {
        for (int i=0; i<(int)room.size(); ++i) {
            for (int j=0; j<(int)room[i].size(); ++j) {
                room[i][j] = char(colors.find(room[i][j]));
            }
        }
        if (room[0].size() == 1) {
            vector<string> tmp(1, string(room.size(), ' '));
            for (int i=0; i<(int)room.size(); ++i) {
                tmp[0][i] = room[i][0];
            }
            room.swap(tmp);
        }
        if (room.size() == 1) {
            memset(dp2, 0, sizeof dp2);
            const int n = room[0].size();
            dp2[0][4][0] = 1;
            for (int i=0; i<n; ++i) {
                for (int c=0; c<5; ++c) {
                    for (int k=0; k<=K; ++k) {
                        if (dp2[i][c][k] > 0) {
                            for (int nc=0; nc<4; ++nc) {
                                if (nc != c) {
                                    dp2[i+1][nc][k + (nc!=room[0][i])] += dp2[i][c][k];
                                    dp2[i+1][nc][k + (nc!=room[0][i])] %= mod;
                                }
                            }
                        }
                    }
                }
            }
            long long sol = 0;
            for (int c=0; c<4; ++c) {
                for (int i=0; i<=K; ++i) {
                    sol = (sol + dp2[n][c][i])%mod;
                }
            }
            return sol;
        }

        long long sol = 0;
        for (int twice=0; twice<2; ++twice) {
            memset(dp, 0xff, sizeof dp);
            for (int c1=0; c1<4; ++c1) {
                for (int c2=0; c2<4; ++c2) {
                    if (c1 != c2) {
                        sol += go(room, 0, c1, c2, K);
                    }
                }
            }
            vector<string> tmp(room[0].size(), string(room.size(), ' '));
            for (int i=0; i<(int)room.size(); ++i) {
                for (int j=0; j<(int)room[i].size(); ++j) {
                    tmp[j][i] = room[i][j];
                }
            }
            room.swap(tmp);
        }
        
        long long overlap = 0;
        int corner[2][2];
        int m = room.size();
        int n = room[0].size();
        for (corner[0][0]=0; corner[0][0]<4; ++corner[0][0]) {
            for (corner[0][1]=0; corner[0][1]<4; ++corner[0][1]) {
                if (corner[0][1] == corner[0][0]) {
                    continue;
                }
                for (corner[1][0]=0; corner[1][0]<4; ++corner[1][0]) {
                    if (corner[1][0]==corner[0][0] || corner[1][0]==corner[0][1]) {
                        continue;
                    }
                    corner[1][1] = 0;
                    while (corner[1][1]==corner[1][0] || corner[1][1]==corner[0][0] || corner[1][1]==corner[0][1]) {
                        ++corner[1][1];
                    }
                    
                    int changes = 0;
                    for (int i=0; i<m; ++i) {
                        for (int j=0; j<n; ++j) {
                            changes += (room[i][j] != corner[i%2][j%2]);
                        }
                    }
                    overlap += (changes <= K);
                }
            }
        }
        
        sol -= overlap;
        if (sol < 0) {
            int mul = (-sol + mod - 1)/mod;
            sol += mul*mod;
        }
        assert(sol >= 0);
        
        return sol % mod;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"RG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 5; verify_case(0, Arg2, theCount(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"BY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 12; verify_case(1, Arg2, theCount(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"RG",
 "GR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 8; verify_case(2, Arg2, theCount(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"BRYBGYRB"
,"GRYGYBBG"
,"RGBGYBYG"
,"YRBRGBYG"
,"RBGRBRGG"
,"RBGYRYBY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 34; int Arg2 = 489; verify_case(3, Arg2, theCount(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
,"BBBBBBYYYBBBBBBBBBBBBBBBBBBBBBBBBBYYYYYBBBBBBBBBBB"
,"BBBBBBYYYBBBBBBBBBBBBBBBBBBBBBBYYYYYYYYYYYBBBBBBBB"
,"BBBBBBYYYYYYYYYYYYYYYYBBBBBBBBYYYYBBBBBYYYYBBBBBBB"
,"BBBBBBYYYYYYYYYYYYYYYYBBBBBBBYYYBBBBBBBBBYYYBBBBBB"
,"BBBBBBYYYBBBBBBBBBBBBBBBBBBBBYYYBBBBBBBBBYYYBBBBBB"
,"BBBBBBYYYBBBBBBBBBBBBBBBBBBBBYYYBBBBBBBBBYYYBBBBBB"
,"BBBBBBYYYBBBBBBBBBBBBBBBBBBBBYYYBBBBBBBBBYYYBBBBBB"
,"BBBBBBYYYBBBBBBBBBBBBBBBBBBBBYYYBBBBBBBBBYYYBBBBBB"
,"BBBBBBYYYBBBBBBBBBBBBBBBBBBBBBYYYYBBBBBYYYYBBBBBBB"
,"BBBBBBYYYBBBBBBBBBBBBBBBBBBBBBBBYYYYYYYYYBBBBBBBBB"
,"BBBBBBYYYYYYYYYYYYBBBBBBBBBBBBBBYYYYYYYYYBBBBBBBBB"
,"BBBBBBYYYYYYYYYYYYYYBBBBBBBBBBYYYYBBBBBYYYYBBBBBBB"
,"BBBBBBBBBBBBBBBBYYYYYBBBBBBBBYYYBBBBBBBBBYYYBBBBBB"
,"BBBBBBBBBBBBBBBBBBYYYBBBBBBBBYYYBBBBBBBBBYYYBBBBBB"
,"BBBBBBBBBBBBBBBBBBYYYBBBBBBBBYYYBBBBBBBBBYYYBBBBBB"
,"BBBBBBYYYBBBBBBBBBYYYBBBBBBBBYYYBBBBBBBBBYYYBBBBBB"
,"BBBBBBYYYBBBBBBBBBYYYBBBBBBBBYYYBBBBBBBBBYYYBBBBBB"
,"BBBBBBBYYYYBBBBBYYYYBBBBBBBBBBYYYYBBBBBYYYYBBBBBBB"
,"BBBBBBBBYYYYYYYYYYYBBBBBBBBBBBBYYYYYYYYYYYBBBBBBBB"
,"BBBBBBBBBBBYYYYYBBBBBBBBBBBBBBBBBBYYYYYBBBBBBBBBBB"
,"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 825; int Arg2 = 404506540; verify_case(4, Arg2, theCount(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ColorfulTiles ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
