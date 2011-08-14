#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;


long long len[50];
string I, P;
char get(int p, int s) {
    if (s == 0) {
        return p < (int)I.size() ? I[p] : '-';
    } else {
        int sz = 0;
        for (int i=0; i<(int)P.size(); ++i) {
            if (P[i] == '$') {
                int next = sz + len[s-1];
                if (p < next) {
                    return get(p-sz, s-1);
                }
                sz = next;
            } else {
                ++sz;
                if (p < sz) {
                    return P[i];
                }
            }
        }
        return '-';
    }
}
class EndlessStringMachine {
	public:
	string getFragment(const string &input, const string &program, int s, int m, int M) {
        --m;
        --M;
        long long a = 0;
        long long b = 0;
        I = input;
        P = program;
        for (int i=0; i<(int)program.size(); ++i) {
            if (program[i] == '$') {
                ++a;
            } else {
                ++b;
            }
        }
        if (a == 1) {
            long long total = input.size() + (long long)s * (program.size()-1);
            string ret;
            for (int i=m; i<=M; ++i) {
                if (i < (int)input.size()) {
                    ret += input[i];
                } else if (i < total) {
                    ret += program[(i-input.size())%(program.size()-1) + 1];
                } else {
                    ret += '-';
                }
            }
            return ret;
        } else {
            len[0] = input.size();
            for (int i=1; i<=s; ++i) {
                len[i] = a*len[i-1] + b;
                if (len[i] > M) {
                    s = i;
                    break;
                }
            }
            string ret;
            for (int i=m; i<=M; ++i) {
                ret += get(i, s);
            }
            return ret;
        }
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "a"; string Arg1 = "$meric$"; int Arg2 = 6; int Arg3 = 1; int Arg4 = 35; string Arg5 = "americamericamericamericamericameri"; verify_case(0, Arg5, getFragment(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arg0 = "top"; string Arg1 = "$coder"; int Arg2 = 1; int Arg3 = 1; int Arg4 = 20; string Arg5 = "topcoder------------"; verify_case(1, Arg5, getFragment(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arg0 = "abc"; string Arg1 = "$x$y$z$"; int Arg2 = 10; int Arg3 = 30; int Arg4 = 50; string Arg5 = "bcyabcxabcyabczabczab"; verify_case(2, Arg5, getFragment(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { string Arg0 = "xy"; string Arg1 = "$a$bb"; int Arg2 = 12; int Arg3 = 5000; int Arg4 = 5099; string Arg5 = "xybbbbaxyaxybbaxyaxybbbbbbbbaxyaxybbaxyaxybbbbaxyaxybbaxyaxybbbbbbaxyaxybbaxyaxybbbbaxyaxybbaxyaxybb"; verify_case(3, Arg5, getFragment(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    EndlessStringMachine ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
