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

void update(map<string, string> &M, const string &rem, const string &cand) {
    if (M.count(rem) == 0) {
        M[rem] = cand;
    } else {
        const string &tmp = M[rem];
        if (tmp.size()<cand.size() || tmp.size()==cand.size() && cand<tmp) {
            M[rem] = cand;
        }
    }
}
void update(string &s, const string &cand) {
    if (s.size()<cand.size() || s.size()==cand.size() && cand<s) {
        s = cand;
    }
}
class TheBoringStoreDivOne {
	public:
	string find(string X, string Y) {
	    map<string, string> L, R;
        int m = X.size();
        for (int i=0; i<m; ++i) {
            for (int j=i+1; j<=m; ++j) {
                const int len = j-i;
                for (int k=0; k<i; ++k) {
                    for (int l=k+1; l<=i && l-k<=len; ++l) {
                        if (X[i+l-1-k] != X[l-1]) {
                            break;
                        }
                        update(L, X.substr(i+l-k, len-l+k), X.substr(k, l-k));
                    }
                }
                for (int k=j; k<m; ++k) {
                    for (int l=k+1; l<=m && l-k<=len; ++l) {
                        if (X[i+l-1-k] != X[l-1]) {
                            break;
                        }
                        update(L, X.substr(i+l-k, len-l+k), X.substr(k, l-k));
                    }
                }
            }
        }
        
//        for (map<string, string>::const_iterator it=L.begin(); it!=L.end(); ++it) {
//            cerr << '|' << it->first << '|' <<  " |" << it->second << "|\n";
//        }

        int n = Y.size();
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<=n; ++j) {
                const int len = j-i;
                for (int l=i; l>0; --l) {
                    for (int k=l-1; k>=0 && l-k<=len; --k) {
                        if (Y[j-l+k] != Y[k]) {
                            break;
                        }
                        update(R, Y.substr(i, len-l+k), Y.substr(k, l-k));
                    }
                }
                for (int l=n; l>j; --l) {
                    for (int k=l-1; k>=j && l-k<=len; --k) {
                        if (Y[j-l+k] != Y[k]) {
                            break;
                        }
                        update(R, Y.substr(i, len-l+k), Y.substr(k, l-k));
                    }
                }
            }
        }
//        cerr << '\n';
 //       for (map<string, string>::const_iterator it=R.begin(); it!=R.end(); ++it) {
  //          cerr << '|' << it->first << '|' <<  " |" << it->second << "|\n";
   //     }
        
        string sol;
        for (map<string, string>::const_iterator it=L.begin(); it!=L.end(); ++it) {
            if (R.count(it->first)) {
    //            cerr << it->second << ' ' << it->first << ' ' << R[it->first] << '\n';
                update(sol, it->second + it->first + R[it->first]);
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "StoreOfJohn"; string Arg1 = "StoreOfBrus"; string Arg2 = "or"; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "JohnAndJohn"; string Arg1 = "John"; string Arg2 = ""; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "JohnLikesToPlayGames"; string Arg1 = "BrusAlsoLikesToPlayGames"; string Arg2 = "esToPlayGames"; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abacaba"; string Arg1 = "abacabadabacaba"; string Arg2 = "abaabacaba"; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheBoringStoreDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
