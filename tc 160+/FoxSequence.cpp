#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class FoxSequence {
	public:
	string isValid(vector <int> seq) {
        int n = seq.size();
        if (n < 2) {
            return "NO";
        }
        int diff0 = seq[1] - seq[0];
        if (diff0 <= 0) {
            return "NO";
        }
        for (int a=1; a<n-1; ++a) {
            if (seq[a]-seq[a-1] != diff0) {
                break;
            }
            int diff1 = seq[a+1] - seq[a];
            if (diff1 >= 0) {
                continue;
            }
            for (int b=a+1; b<n; ++b) {
                if (seq[b]-seq[b-1] != diff1) {
                    break;
                }
                for (int c=b; c<n-1; ++c) {
                    if (seq[c] != seq[b]) {
                        break;
                    }
                    int diff2 = seq[c+1] - seq[c];
                    if (diff2 <= 0) {
                        continue;
                    }
                    for (int d=c+1; d<n-1; ++d) {
                        if (seq[d]-seq[d-1] != diff2) {
                            break;
                        }
                        int diff3 = seq[d+1]-seq[d];
                        if (diff3 >= 0) {
                            continue;
                        }
                        bool ok = true;
                        for (int i=d+1; i<n; ++i) {
                            if (seq[i]-seq[i-1] != diff3) {
                                ok = false;
                                break;
                            }
                        }
                        if (ok) {
                            return "YES";
                        }
                    }
                }
            }
        }
        return "NO";
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,5,7,5,3,1,1,1,3,5,7,5,3,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, isValid(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3,4,5,4,3,2,2,2,3,4,5,6,4}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(1, Arg1, isValid(Arg0)); }
	void test_case_2() { int Arr0[] = {3,6,9,1,9,5,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(2, Arg1, isValid(Arg0)); }
	void test_case_3() { int Arr0[] = {1,2,3,2,1,2,3,2,1,2,3,2,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, isValid(Arg0)); }
	void test_case_4() { int Arr0[] = {1,3,4,3,1,1,1,1,3,4,3,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(4, Arg1, isValid(Arg0)); }
	void test_case_5() { int Arr0[] = {6,1,6}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(5, Arg1, isValid(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FoxSequence ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
