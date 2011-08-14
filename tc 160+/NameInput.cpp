#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

const int inf = 987654321;
int dp[2][2501];
int L[128][2501];
int R[128][2501];
class NameInput {
	public:
	int countUpDownKeyPresses(vector <string> p, vector <string> name) {
		string P = accumulate(p.begin(), p.end(), string());
        string N = accumulate(name.begin(), name.end(), string());
        for (int i=1; i<(int)P.size(); ++i) {
            dp[0][i] = dp[1][i] = inf;
        }
        dp[0][0] = inf;
        dp[1][0] = 0;
        memset(L, 0xff, sizeof L);
        memset(R, 0xff, sizeof R);
        for (int i=0; i<128; ++i) {
            int tmp = find(P.rbegin(), P.rend(), i) - P.rbegin();
            if (tmp == (int)P.size()) {
                tmp = -1;
            } else {
                tmp = (int)P.size()-1-tmp;
            }
            L[i][0] = (P[0]==i ? 0 : tmp);
            for (int j=1; j<(int)P.size(); ++j) {
                if (P[j] == i) {
                    L[i][j] = j;
                } else {
                    L[i][j] = L[i][j-1];
                }
            }
        }
        
        for (int i=0; i<128; ++i) {
            int tmp = find(P.begin(), P.end(), i) - P.begin();
            if (tmp == (int)P.size()) {
                tmp = -1;
            }
            R[i][(int)P.size()-1] = (P[(int)P.size()-1]==i ? (int)P.size()-1 : tmp);
            for (int j=(int)P.size()-2; j>=0; --j) {
                if (P[j] == i) {
                    R[i][j] = j;
                } else {
                    R[i][j] = R[i][j+1];
                }
            }
        }
        
        int t = 0;
        for (int i=0; i<(int)N.size(); ++i, t=1-t) {
            for (int j=0; j<(int)P.size(); ++j) {
                if (dp[1-t][j] < inf) {
                    const char c = N[i];
                    const int start = dp[1-t][j];
                    if (L[c][j] != -1) {
                        int pos = L[c][j];
                        int dist = inf;
                        if (pos <= j) {
                            dist = min(j-pos, pos+(int)P.size()-j);
                        } else {
                            dist = min(pos-j, j+(int)P.size()-pos);
                        }
                        dp[t][pos] = min(dp[t][pos], start + dist);
                    }
                    if (R[c][j] != -1) {
                        int pos = R[c][j];
                        int dist = inf;
                        if (pos <= j) {
                            dist = min(j-pos, pos+(int)P.size()-j);
                        } else {
                            dist = min(pos-j, j+(int)P.size()-pos);
                        }
                        dp[t][pos] = min(dp[t][pos], start + dist);
                    }
                }
                dp[1-t][j] = inf;
            }
        }
        
        t = 1-t;
        int sol = *min_element(dp[t], dp[t]+(int)P.size());
        return sol<inf ? sol : -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Jjhon"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"John"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(0, Arg2, countUpDownKeyPresses(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"abcdefghijklmnopqrstuvwxyz","ABCDEFGHIJKLMNOPQRSTUVWXYZ","0123456789"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Joh","nAndFr","iends"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 186; verify_case(1, Arg2, countUpDownKeyPresses(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"aaaabbbab","baabbabaabba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"bbaaababba","baababababbb"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 16; verify_case(2, Arg2, countUpDownKeyPresses(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"john"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"John"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, countUpDownKeyPresses(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"4444444444444"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, countUpDownKeyPresses(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"abcABC123","cbaCBA321"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"aB32C2AaB3c","c32bA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 38; verify_case(5, Arg2, countUpDownKeyPresses(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NameInput ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
