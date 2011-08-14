#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int source=81, sink=82;
const int n = 83;
long long G[n][n], A[n][n], pT[n][n], mT[n][n];
const long long mod = 600921647;
void mul(long long (*a)[n], long long (*b)[n]) {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            mT[i][j] = 0;
            for (int k=0; k<n; ++k) {
                mT[i][j] += a[i][k]*b[k][j];
                if (mT[i][j] >= mod) {
                    mT[i][j] %= mod;
                }
            }
        }
    }
    memcpy(a, mT, sizeof mT);
}
void go(int len) {
    memset(pT, 0, sizeof pT);
    for (int i=0; i<n; ++i) {
        pT[i][i] = 1;
    }
    
    while (len > 0) {
        if (len & 1) {
            mul(pT, A);
        }
        mul(A, A);
        len >>= 1;
    }
    memcpy(A, pT, sizeof A);
}
long long calc(int len) {
    memcpy(A, G, sizeof A);
    go(len);
    return A[source][sink];
}

vector<string> cutUp(const string &s, const string &delim=" ") {
	int lastPos = 0, pos = 0;
	vector<string> ret;

	while (pos+delim.size() <= s.size()) {
		if (s.substr(pos, delim.size()) == delim) {
			ret.push_back(s.substr(lastPos, pos-lastPos));

			pos += (int)delim.size()-1;
			lastPos = pos+1;
		}
		++pos;
	}

	if (lastPos < (int)s.size())
		ret.push_back(s.substr(lastPos));

	return ret;
}

class ShuffledPlaylist {
	public:
	int count(vector <string> songs, vector <string> transitions, int minLength, int maxLength) {
		memset(G, 0, sizeof G);
        string s = songs[0];
        for (int i=1; i<(int)songs.size(); ++i) {
            s += songs[i];
        }
        vector<string> t = cutUp(s, ",");
        for (int i=0; i<(int)t.size(); ++i) {
            istringstream is(t[i]);
            int g, l;
            is >> g >> l;
            ++G[source][g*9 + l-1];
            for (int g1=0; g1<(int)transitions.size(); ++g1) {
                if (transitions[g1][g] == 'Y') {
                    ++G[g1*9][g*9 + l-1];
                }
            }
        }
        
        for (int g=0; g<9; ++g) {
            for (int l=1; l<9; ++l) {
                ++G[g*9 + l][g*9 + l-1];
            }
            ++G[g*9][sink];
        }
        G[sink][sink] = 1;
        
        return (calc(maxLength+1)+mod-calc(minLength))%mod;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0 3,1 2,0 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YY","YY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 4; int Arg4 = 7; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"0 3,1 2,0 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN","NY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 4; int Arg4 = 5; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"0 9",",1 8,","2 3,2 5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYY","NYY","NNY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 9; int Arg4 = 7; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"0 8,","5 6,2"," 2,2 3,6 8,5 8,5 3,0 6,0 7,6 5,3 2",
",0 9,2 3,3 4,5 4,3 3,3 3,2 8,2 9,5 7,2 8,0 1,5 9,1",
" 8,2 9,1 6,3 6,2 6,0 4,6 3,1 5,2 7,4 5,3 3,0",
" 5,6 1,5 6,4 8,5 9,1 4,2 9,5 6,5 6,0 8,3 5,4 6,0 3",
",4 2,5 6,6 2,4 3,1 3,6 3,0 8,2 8,3 7,4 2,0 7,0 2,1",
" 3,4 7,6 3,6 4,3 9,0 2,0 7,0 8,6 4,1 3,2 5,0 6,5 4",
",3 2,3 2,1 5,2 1,5 2,4 8,0 5,1"," ","7,2 6,5 7",",",
"6 9,5 5,","4 2",",4"," 9,0 5,4 8,6 5,5 9,5 8,3 ","2",
",5 ","6,2 3,0 7,1 7,","2 1,0 4",",2 9",",","3"," ","4"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYYYYYY","YYYYYYY","YYYYYYY","YYYYYYY","YYYYYYY","YYYYYYY","YYYYYYY"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 10000; int Arg4 = 348387817; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ShuffledPlaylist ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
