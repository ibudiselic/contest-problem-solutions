#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

string sol;
string S;
int n;

void inc(string &s, int by, int from) {
    int c = by;
    for (int i=from; i>=0 && c>0; --i) {
        int nd = s[i]-'0' + c;
        s[i] = nd%10 + '0';
        c = (nd>=10);
    }
    if (c) {
        s = '1' + s;
    }
}
string make_next(string a, string b) {
    assert(a.size() >= b.size());
    if (a.size() > b.size()) {
        for (int i=0; i<(int)a.size(); ++i) {
            if (a[i] == '?') {
                a[i] = (i==0 ? '1' : '0');
            }
        }
        return a;
    } else {
        string found;
        string zeros = a;
        for (int i=0; i<(int)zeros.size(); ++i) {
            if (zeros[i] == '?') {
                zeros[i] = (i==0 ? '1' : '0');
            }
        }
        for (int i=0; i<(int)a.size(); ++i) {
            if (a[i] == '?') {
                if (b[i] < '9') {
                    found = a.substr(0, i) + char(b[i]+1) + (i+1<(int)zeros.size() ? zeros.substr(i+1) : string());
                }
                a[i] = b[i];
            } else if (a[i] > b[i]) {
                return a.substr(0, i+1) + (i+1<(int)zeros.size() ? zeros.substr(i+1) : string());
            } else if (a[i] < b[i]) {
                break;
            }
        }
        return found;
    }
}
void upd() {
    string last;
    string cand;
    for (int i=0; i<n; ++i) {
        int j = i+1;
        while (j<n && S[j]!=',') {
            ++j;
        }
        assert(j-i >= (int)last.size());
        last = make_next(S.substr(i, j-i), last);
        if (last.size() == 0) {
            return;
        }
        if (last[0] == '0') {
            return;
        }
        cand += last + ',';
        i = j;
    }
    sol = min(sol, cand);
}

void go(int pos, int start, int last_len) {
    if (pos == n-1) {
        if (n-start >= last_len) {
            upd();
        }
        return;
    }
    if (S[pos] == ',') {
        if (pos-start < last_len) {
            return;
        }
        go(pos+1, pos+1, pos-start);
        return;
    }
    if (pos>0 && S[pos]=='?' && S[pos+1]!='0' && pos-start>=last_len) {
        S[pos] = ',';
        go(pos+1, pos+1, pos-start);
        S[pos] = '?';
    }
    go(pos+1, start, last_len);
}
class IncreasingLists {
	public:
	string makeIncreasingList(string mask) {
        if (mask[0]==',' || mask[mask.size()-1]==',') {
            return "impossible";
        }
	    sol = string(mask.size()+10, '9');
        S = mask;
        n = S.size();
        go(0, 0, 1);
        if (sol.size()-1 == S.size()) {
            return sol.substr(0, sol.size()-1);
        } else {
            return "impossible";
        }
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "??"; string Arg1 = "10"; verify_case(0, Arg1, makeIncreasingList(Arg0)); }
	void test_case_1() { string Arg0 = "???"; string Arg1 = "1,2"; verify_case(1, Arg1, makeIncreasingList(Arg0)); }
	void test_case_2() { string Arg0 = "?????????,9"; string Arg1 = "1,2,3,4,5,9"; verify_case(2, Arg1, makeIncreasingList(Arg0)); }
	void test_case_3() { string Arg0 = "??????????,9"; string Arg1 = "impossible"; verify_case(3, Arg1, makeIncreasingList(Arg0)); }
	void test_case_4() { string Arg0 = "?,10,?????????????????,16,??"; string Arg1 = "impossible"; verify_case(4, Arg1, makeIncreasingList(Arg0)); }
	void test_case_5() { string Arg0 = "?2?5??7?,??"; string Arg1 = "12,50,70,71"; verify_case(5, Arg1, makeIncreasingList(Arg0)); }
	void test_case_6() { string Arg0 = "???????????????????????????????,???"; string Arg1 = "1,10,11,100,101,102,103,104,105,106"; verify_case(6, Arg1, makeIncreasingList(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    IncreasingLists ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
