#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int mod = 1000000007;
int cnt_I[2501], cnt_Q[2501];
int pow2[2501];
class IOIString {
	public:
	int countIOIs(vector <string> mask) {
		string s = mask[0];
        for (int i=1; i<(int)mask.size(); ++i) {
            s += mask[i];
        }
        if (s.size() < 3) {
            return 0;
        }
        
        pow2[0] = 1;
        for (int i=1; i<2501; ++i) {
            pow2[i] = pow2[i-1] * 2;
            if (pow2[i] >= mod) {
                pow2[i] -= mod;
            }
        }
        
        cnt_I[0] = 0;
        cnt_Q[0] = 0;
        for (int i=0; i<(int)s.size(); ++i) {
            cnt_I[i+1] = cnt_I[i] + (s[i]=='I');
            cnt_Q[i+1] = cnt_Q[i] + (s[i]=='?');
        }
        if (cnt_I[s.size()] + cnt_Q[s.size()] < 2) {
            return 0;
        }
        
        int cnt_not = 0;
        if (cnt_I[s.size()] == 0) {
            cnt_not += cnt_Q[s.size()] + 1;
        } else if (cnt_I[s.size()] == 1) {
            cnt_not = 1;
        }
        for (int i=0; i<(int)s.size(); ++i) {
            if (s[i] != 'O') {
                for (int d=1; d<(int)s.size()-i; d+=2) {
                    int j = i + d;
                    for (; j<(int)s.size(); j+=d) {
                        if (s[j]=='O' || cnt_I[j]-cnt_I[j-d+1]>0) {
                            break;
                        }
                        cnt_not += (cnt_I[s.size()]-cnt_I[j+1] == 0);
                    }
                }
            }
            if (s[i] == 'I') {
                break;
            }
        }
        
        return (pow2[cnt_Q[s.size()]] - cnt_not + mod) % mod;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"IO?"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, countIOIs(Arg0)); }
	void test_case_1() { string Arr0[] = {"????"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, countIOIs(Arg0)); }
	void test_case_2() { string Arr0[] = {"?II"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, countIOIs(Arg0)); }
	void test_case_3() { string Arr0[] = {"I??O??I"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(3, Arg1, countIOIs(Arg0)); }
	void test_case_4() { string Arr0[] = {"???I???????O???","???????????O??IO????????I???"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 438952513; verify_case(4, Arg1, countIOIs(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    IOIString ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
