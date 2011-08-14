#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long cnt[1185922];
vector<string> C;
int N;
int cur[4];
long long total;
const int LIM = 33*33*33*33 - 1;
void upd(int pos, int code) {
    if (pos == 4) {
        if (code < LIM) {
            ++cnt[code];
        }
    } else {
        upd(pos+1, code*33 + 32);
        upd(pos+1, code*33 + cur[pos]);
    }
}
    
void go(int pos) {
    if (pos == 4) {
        ++total;
        upd(0, 0);
        return;
    }
    int forbid = -1;
    int forbid2 = -1;
    if (pos > 0) {
        forbid = cur[pos-1];
    }
    if (pos == 3) {
        forbid2 = cur[0];
    }
    
    for (int i=0; i<N; ++i) {
        if (i!=forbid && i!=forbid2 && C[pos][i]=='Y') {
            cur[pos] = i;
            go(pos+1);
        }
    }
}
long long calc(int pos, int code, int sgn) {
    if (pos == 4) {
        return sgn * cnt[code];
    } else {
        return calc(pos+1, code*33 + 32, sgn) + calc(pos+1, code*33 + cur[pos], sgn*-1);
    }
}
long long go2(int pos) {
    if (pos == 8) {
        return total - calc(0, 0, -1);
    }
    int forbid = -1;
    int forbid2 = -1;
    if (pos > 4) {
        forbid = cur[pos-5];
    }
    if (pos == 7) {
        forbid2 = cur[0];
    }
    
    long long ret = 0;
    for (int i=0; i<N; ++i) {
        if (i!=forbid && i!=forbid2 && C[pos][i]=='Y') {
            cur[pos-4] = i;
            ret += go2(pos+1);
        }
    }
    return ret;
}
class CubeColoring {
	public:
	long long theCount(vector <string> colors) {
        total = 0;
        C = colors;
        N = C[0].size();
        memset(cnt, 0, sizeof cnt);
		go(0);
        
        return go2(4);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Y", "Y", "Y", "Y", "Y", "Y", "Y", "Y"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { string Arr0[] = {"YNNNNNNN", "NYNNNNNN", "NNYNNNNN", "NNNYNNNN", "NNNNYNNN", "NNNNNYNN", "NNNNNNYN", "NNNNNNNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { string Arr0[] = {"YNNYN", "YYYYY", "NYYNY", "YNYYN", "YNNYY", "YNNYY", "NNNYY", "NYYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 250LL; verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { string Arr0[] = {"YNNYN", "YYYYY", "NNNNN", "YNYYN", "YNNYY", "YNNYY", "NNNYY", "NYYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { string Arr0[] = {"YNNYNYYYYYNN", "NNNYNYYNYNNY", "YYNNYYNNNYYN", "YYYYYNNYYYNN", "NNNYYYNNYNYN", "YYYNYYYYNYNN", "NNNNNNYYNYYN", "NNYNYYNNYNYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 611480LL; verify_case(4, Arg1, theCount(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CubeColoring ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
