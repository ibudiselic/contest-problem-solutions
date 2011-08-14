#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

string T, R;
bool repeat[52];
bool done[52][52];
int dp[52][52];
string S[52][52];
int INF = 123456789;

string val(int i) {
    string s;
    for (; i<(int)R.size(); ++i) {
        s += R[i];
        if (repeat[i])
            s += '*';
    }
    return s;
}
int go(int i, int j) {
    if (done[i][j]) {
        return dp[i][j];
    }
    done[i][j] = 1;
    
    int &ret = dp[i][j];
    ret = INF;
    S[i][j] = string(55, 'z'+1);
    if (i==(int)T.size() && j==(int)R.size()) {
        S[i][j] = "";
        return (ret = 0);
    }

    if (j<(int)R.size() && repeat[j]) {
        int t = go(i, j+1);
        if (t<ret || t==ret && S[i][j+1]<S[i][j]) {
            S[i][j] = S[i][j+1];
            ret = t;
        }
    }
    
    if (i==(int)T.size() || j==(int)R.size()) {
        return ret;
    }

    int t = go(i+1, j+1) + (T[i]!=R[j]);
    if (t<ret || t==ret && R[j]+S[i+1][j+1]<S[i][j]) {
        ret = t;
        S[i][j] = R[j] + S[i+1][j+1];
    }

    if (repeat[j]) {
        int t = go(i+1, j) + (T[i]!=R[j]);
        if (t<ret || t==ret && R[j]+S[i+1][j]<S[i][j]) {
            ret = t;
            S[i][j] = R[j] + S[i+1][j];
        }
    }
    
    //cerr << i << ' ' << j << ' ' << ' ' << T.substr(i) << ' ' << val(j) << ' ' << ret << ' ' << S[i][j] << '\n';
    return ret;
}
    
class ClosestRegex {
	public:
	string closestString(string text, string regex) {
		T = text; 
        R = "";
        cerr << text << ' ' << regex << '\n';
        for (int i=0; i<(int)regex.size(); ++i) {
            if (regex[i] == '*') {
                continue;
            } else {
                R += regex[i];
                if (i+1<(int)regex.size() && regex[i+1]=='*') {
                    repeat[(int)R.size()-1] = 1;
                } else {
                    repeat[(int)R.size()-1] = 0;
                }
            }
        }
        assert(val(0) == regex);
        memset(done, 0, sizeof done);
        
        //cerr << go(0, 0) << '\n';
        return (go(0, 0) < INF ? S[0][0] : string());
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abcd"; string Arg1 = "bcdd"; string Arg2 = "bcdd"; verify_case(0, Arg2, closestString(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "topcoder"; string Arg1 = "t*px*coa*de*"; string Arg2 = "ttpcodee"; verify_case(1, Arg2, closestString(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "cmu"; string Arg1 = "c*m*fm*u*"; string Arg2 = "cfu"; verify_case(2, Arg2, closestString(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "aaaaacccc"; string Arg1 = "a*abc*"; string Arg2 = "aaaaabccc"; verify_case(3, Arg2, closestString(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "short"; string Arg1 = "lo*ts*of*let*ter*s"; string Arg2 = ""; verify_case(4, Arg2, closestString(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ClosestRegex ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
