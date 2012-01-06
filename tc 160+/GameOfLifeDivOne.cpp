#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool can_alt[98][51][2]; // can we make an alternating sequence from i with length j, starting with k
bool can_block[98][51][2]; // can we make a blok from i with length j consist only of k-bits

long long block[100][2][51]; // ways to be at i with the preceeding section being a block of j-bits, and have k ones after T steps
long long alt[100][2][51]; // similarly with the preceeding section being an alt sequence ending with a j-bit

class GameOfLifeDivOne {
	public:
	long long theCount(string init, int T, int K) {
		const int n = init.size();
        string A = init + init;
        
        memset(can_alt, 0, sizeof can_alt);
        memset(can_block, 0, sizeof can_block);
        for (int start=0; start<2*n-2; ++start) { // blocks must be at least 2 bits long, and can't contain the last doubled bit because of wraparound
            if (A[start] == '?') {
                can_alt[start][1][0] = can_alt[start][1][1] = 1;
            } else {
                can_alt[start][1][A[start]-'0'] = 1;
            }

            for (int bit=0; bit<2; ++bit) {
                can_alt[start][2][bit] = (A[start]=='0'+bit || A[start]=='?') && (A[start+1]=='0'+(1-bit) || A[start+1]=='?');
                can_block[start][2][bit] = (A[start]=='0'+bit || A[start]=='?') && (A[start+1]=='0'+bit || A[start+1]=='?');
            }
            for (int len=3; len<=n; ++len) {
                for (int bit=0; bit<2; ++bit) {
                    can_alt[start][len][bit] = can_alt[start][len-1][bit] // prefix is an alt seq and the new bit is
                                                && (A[start+len-1]=='?' // either any bit
                                                  || (len&1) && A[start+len-1]=='0'+bit // or a specific bit based on parity of the lenght
                                                  || ((len+1)&1) && A[start+len-1]=='0'+(1-bit));
                    can_block[start][len][bit] = can_block[start][len-1][bit] && (A[start+len-1]=='0'+bit || A[start+len-1]=='?');
                }
            }
        }
        if (A[2*n-2] == '?') {
            can_alt[2*n-2][1][0] = can_alt[2*n-2][1][1] = 1;
        } else {
            can_alt[2*n-2][1][A[2*n-2]-'0'] = 1;
        }
        
        long long sol = 0;
        if (n%2 == 0) {
            for (int bit=0; bit<2; ++bit) {
                if (can_alt[0][n][bit]) { // make the whole thing one alt seq
                    sol += (K <= n/2);
                }
            }
        }
        
        // one-block solutions
        if (K<=n && can_block[0][n][1]) {
            ++sol;
        }
        if (K==0 && can_block[0][n][0]) {
            ++sol;
        }
        
        for (int start=0; start<n; ++start) {
            for (int len=2; len<n; ++len) { // one-block solutions handled as a special case
                for (int startbit=0; startbit<2; ++startbit) {
                    if (can_block[start][len][startbit]) {
                        memset(alt, 0, sizeof alt);
                        memset(block, 0, sizeof block);
                        block[start+len][startbit][len*startbit] = 1;
                        
                        for (int i=start+len; i+1<=start+n; ++i) {
                            for (int bit=0; bit<2; ++bit) {
                                for (int ones=0; ones<=i-start; ++ones) {
                                    if (block[i][bit][ones] > 0) {
                                        // extend by an other-bit block
                                        // can only do it in the "first part" because the invariant is that the first block is the block that starts leftmost in the "first part"
                                        if (i < n) { 
                                            for (int nlen=2; i+nlen<=start+n; ++nlen) {
                                                if (can_block[i][nlen][1-bit]) { // can only do other-bit blocks
                                                    block[i+nlen][1-bit][ones + (1-bit)*nlen] += block[i][bit][ones];
                                                }
                                            }
                                        }
                                        // extend by an alt sequence
                                        for (int nlen=1; i+nlen<=start+n; ++nlen) {
                                            if (can_alt[i][nlen][1-bit]) {
                                                int nones = ones;
                                                if (nlen & 1) {
                                                    if (bit) {
                                                        nones += min(nlen, nlen/2 + T); // number of ones grows by 1 each iteration
                                                    } else {
                                                        nones += max(0, (nlen+1)/2 - T); // number of ones drops by 1 each iteration
                                                    }
                                                } else {
                                                    nones += nlen/2; // number of ones in this seq doesn't change
                                                }
                                                alt[i+nlen][(nlen&1) ? 1-bit : bit][nones] += block[i][bit][ones];
                                            }
                                        }
                                    }
                                    
                                    if (alt[i][bit][ones] > 0) {
                                        // only extendable by a block
                                        // again, only in the "first part"
                                        if (i < n) {
                                            for (int nlen=2; i+nlen<=start+n; ++nlen) {
                                                if (can_block[i][nlen][1-bit]) { // can only do other-bit blocks
                                                    block[i+nlen][1-bit][ones + (1-bit)*nlen] += alt[i][bit][ones];
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        
                        for (int ones=K; ones<=n; ++ones) {
                            sol += block[start+n][1-startbit][ones];
                            sol += alt[start+n][1-startbit][ones];
                        }
                    }
                }
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "0?1"; int Arg1 = 1; int Arg2 = 1; long long Arg3 = 1LL; verify_case(0, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "?????????"; int Arg1 = 0; int Arg2 = 1; long long Arg3 = 511LL; verify_case(1, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "??0???????"; int Arg1 = 58; int Arg2 = 6; long long Arg3 = 151LL; verify_case(2, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "?????????1"; int Arg1 = 47; int Arg2 = 3; long long Arg3 = 453LL; verify_case(3, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "?????????1???0???1??1??????0??????0??0????1???????"; int Arg1 = 12; int Arg2 = 40; long long Arg3 = 31577324313LL; verify_case(4, Arg3, theCount(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    GameOfLifeDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
