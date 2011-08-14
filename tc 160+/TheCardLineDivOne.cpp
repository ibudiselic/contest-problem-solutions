#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

// main idea: two level dynamic programming
// at first level match cards by rank
// at second level match "card blocks" by color
const int mod = 1234567891;
int have[13][2];

int dp_calc[51][51][51][2];
// puts color patterns into a line (red, black, redblack)
int calc(int cnt[3], int last) {
    int &ret = dp_calc[cnt[0]][cnt[1]][cnt[2]][last];
    if (ret != -1) {
        return ret;
    }
    if (cnt[0]==0 && cnt[1]==0 && cnt[2]==0) {
        return (ret = 1);
    }
    
    ret = 0;
    if (cnt[2] > 0) {
        --cnt[2];
        ret = int((long long)(cnt[2]+1) * calc(cnt, 1-last) % mod);
        ++cnt[2];
    }
    if (cnt[last] > 0) {
        --cnt[last];
        ret = int((ret + (long long)(cnt[last]+1) * calc(cnt, last)) % mod);
        ++cnt[last];
    }
    return ret;
}

int dp_match[14][51][51][51];
// matches cards by rank into start-end color patterns
// red = red-...-red
// black = black-...-black
// redblack = red-...-black (can be rotated - accounted for in calc)
// count all combinations that don't contain the same color in succession (would cause overcounting)
int match(int rank, int red, int black, int redblack) {
    int &ret = dp_match[rank][red][black][redblack];
    if (ret != -1) {
        return ret;
    }
    if (rank == 13) {
        int tmp[] = { red, black, redblack };
      //  cerr << tmp[0] << ' ' << tmp[1] << ' ' << tmp[2] << '\n';
        return (ret = ((long long)calc(tmp, 0) + calc(tmp, 1)) % mod);
    }
    //cerr << rank << ' ' << red << ' ' << black << ' ' << redblack << '\n';
    
    int r = have[rank][0];
    int b = have[rank][1];
    if (r==0 && b==0) {
        ret = match(rank+1, red, black, redblack);
    } else if (r==0 && b==1) {
        ret = match(rank+1, red, black+1, redblack);
    } else if (r==0 && b==2) {
        ret = match(rank+1, red, black+2, redblack);
    } else if (r==1 && b==0) {
        ret = match(rank+1, red+1, black, redblack);
    } else if (r==1 && b==1) {
        ret = int(((long long)match(rank+1, red+1, black+1, redblack) +
                            match(rank+1, red, black, redblack+1)) % mod);
    } else if (r==1 && b==2) {
        ret = int((2LL * match(rank+1, red, black+1, redblack+1) + // red-black + black (2 options)
                         match(rank+1, red+1, black+2, redblack) + // red + black + black
                   2LL * match(rank+1, red, black+1, redblack)) % mod); // black-red-black pattern (2 options)
    } else if (r==2 && b==0) {
        ret = match(rank+1, red+2, black, redblack); // red + red
    } else if (r==2 && b==1) {
        ret = int((2LL * match(rank+1, red+1, black, redblack+1) + // red-black + red (2 options)
                         match(rank+1, red+2, black+1, redblack) + // red + red + black
                   2LL * match(rank+1, red+1, black, redblack)) % mod); // red-black-red pattern (2 options)
    } else if (r==2 && b==2) {
        ret = int((4LL * match(rank+1, red+1, black+1, redblack) + // black-red-black + red (4 options, red in pattern + black order)
                   4LL * match(rank+1, red+1, black+1, redblack) + // red-black-red + black (4 options, black in pattern + red order)
                   4LL * match(rank+1, red+1, black+1, redblack+1) + // red-black + red + black (4 options)
                   4LL * match(rank+1, red, black, redblack+1) + // red-black-red-black (4 options: order of reds + order of blacks)
                   2LL * match(rank+1, red, black, redblack+2) + // red-black + red-black (2 options)
                         match(rank+1, red+2, black+2, redblack)) % mod); // red + red + black + black
    }
    
    return ret;
}

class TheCardLineDivOne {
	public:
	int count(vector <string> cards) {
		memset(have, 0, sizeof have);
        for (int i=0; i<(int)cards.size(); ++i) {
            int rank = isdigit(cards[i][0]) ? cards[i][0]-'2' : cards[i][0]=='T' ? 8 : cards[i][0]=='J' ? 9 : cards[i][0]=='Q' ? 10 : cards[i][0]=='K' ? 11 : 12;
            bool is_black = cards[i][1]=='S' || cards[i][1]=='C';
            ++have[rank][is_black];
        }
        
        memset(dp_match, 0xff, sizeof dp_match);
        memset(dp_calc, 0xff, sizeof dp_calc);
        
        return match(0, 0, 0, 0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"KH", "QD", "KC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"JS", "JC", "JD", "JH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"2S", "3C", "4C", "5S", "6C", "7S", "8S", "9H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"KD", "KC", "AD", "7C", "AH", "9C", "4H", "4S", "AS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2416; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arr0[] = {"5S", "AS", "9S", "4D", "3H", "2S", "2D", "3D", "2H", "7C", "JD", "9C", "5D", "TS", "8S", "6C", "KD", "2C", "TC", "3S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1176318675; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheCardLineDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
