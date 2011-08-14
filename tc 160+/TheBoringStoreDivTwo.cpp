#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string better(const string &a, const string &b) {
    if (a.size() != b.size()) {
        return a.size()>b.size() ? a : b;
    } else {
        return min(a, b);
    }
}
class TheBoringStoreDivTwo {
	public:
	string find(string J, string B) {
		string sol;
        for (int i=0; i<(int)J.size(); ++i) { // [i,j>
            for (int j=i+1; j<=(int)J.size(); ++j) {
                const string AA = J.substr(i, j-i);
                for (int k=j; k<(int)J.size(); ++k) { // [j,l>
                    for (int l=k+1; l<=(int)J.size(); ++l) {
                        if (l-k<=j-i && J[i+l-k-1]!=J[l-1]) {
                            break;
                        }
                        const string BB = J.substr(k, l-k);
                        
                        for (int a=(int)B.size(); a>0; --a) {
                            for (int b=a-1; b>=0; --b) { // [b,a>
                                const string CC = B.substr(b, a-b);
                                for (int c=b; c>0; --c) {
                                    int d = c+(int)BB.size()-(int)AA.size()-(int)CC.size();
                                    if (d>=0 && d<c) {
                                        const string DD = B.substr(d, c-d);
                                        assert((AA+CC).size() == (BB+DD).size());
                                        if (AA+CC == BB+DD) {
                                            sol = better(sol, AA+CC);
                                        }
                                    }
                                    d = c+(int)AA.size()-(int)BB.size()-(int)CC.size();
                                    if (d>=0 && d<c) {
                                        const string DD = B.substr(d, c-d);
                                        assert((AA+DD).size() == (BB+CC).size());
                                        if (AA+DD == BB+CC) {
                                            sol = better(sol, AA+DD);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
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
	void test_case_2() { string Arg0 = "JohnPlaysGames"; string Arg1 = "BrusAlsoPlays"; string Arg2 = "ays"; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abacaba"; string Arg1 = "abacabadabacaba"; string Arg2 = "abaabacaba"; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheBoringStoreDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
