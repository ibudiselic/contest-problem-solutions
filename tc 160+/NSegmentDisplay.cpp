#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

void trans(const vector<string> &a, vector<long long> &b) {
    for (int i=0; i<(int)a.size(); ++i) {
        long long t = 0;
        for (int j=0; j<(int)a[i].size(); ++j) {
            if (a[i][j] == '1') {
                t |= (1LL << j);
            }
        }
        b.push_back(t);
    }
}

class NSegmentDisplay {
	public:
	string brokenSegments(vector <string> S_, vector <string> P_) {
	    vector<long long> S, P;

        trans(S_, S);
        trans(P_, P);

        int n = S_[0].size();
        long long dead = 0;
        long long alive = 0;
        while (1) {
            bool change = false;

            for (int i=0; i<(int)P.size(); ++i) {
                set<long long> d;
                for (int j=0; j<(int)S.size(); ++j) {
                    if ((P[i] & S[j]) == P[i]) {
                        long long care_d = dead & S[j];
                        long long care_a = alive & S[j];
                        if (care_d & P[i]) {
                            continue;
                        }
                        if ((care_a & P[i]) != care_a) {
                            continue;
                        }

                        d.insert(S[j] ^ P[i]);
                    }
                }
                if (d.size() == 0) {
                    return "INCONSISTENT";
                }

                long long dd = (1LL<<n) - 1;
                for (set<long long>::const_iterator it=d.begin(); it!=d.end(); ++it) {
                    dd &= *it;
                }
                long long ndead = dead | dd;
                long long nalive = alive | P[i];
                if (ndead!=dead || nalive!=alive) {
                    change = true;
                    dead = ndead;
                    alive = nalive;
                }
            }
            if (!change) {
                break;
            }
        }

        string sol(n, '?');
        for (int i=0; i<n; ++i) {
            if (dead & (1LL<<i)) {
                sol[i] = 'N';
            } else if (alive & (1LL<<i)) {
                sol[i] = 'Y';
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1011111","0000011","1110110","1110011","0101011"
,"1111001","1111101","1000011","1111111","1111011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1011111"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Y?YYYYY"; verify_case(0, Arg2, brokenSegments(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1011111","0000011","1110110","1110011","0101011"
,"1111001","1111101","1000011","1111111","1111011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0111111"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NYYYYYY"; verify_case(1, Arg2, brokenSegments(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"1011111","0000011","1110110","1110011","0101011"
,"1111001","1111101","1000011","1111111","1111011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1000000","0010000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "INCONSISTENT"; verify_case(2, Arg2, brokenSegments(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"1011111","0000011","1110110","1110011","0101011"
,"1111001","1111101","1000011","1111111","1111011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0010110","0010010","0010000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NNYNYYN"; verify_case(3, Arg2, brokenSegments(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"110000111001","100000101000","000001010000"
,"101100010011","111111111101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"010000000000","010000000000","000000000000"
,"000000000000","000000000000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NY????NNN??N"; verify_case(4, Arg2, brokenSegments(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"00000000001000000010","01010000001011101110"
,"01010101110110011010","00111001111001000100"
,"10010111010110110000","11011011001000110001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00011000010000000000","10010110010000100000"
,"00010100010000001000","00010100010000001000"
,"00010000000000101000","00000000000000000000"
,"00010100010000001000","00011000010000000000"
,"00011000010000000000","00000000000000000000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YNNYYYYNNYNNNNYNYNN?"; verify_case(5, Arg2, brokenSegments(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"001000111101000","000001111011001"
,"010010100100010","111000100010011"
,"011011011010001","010011111101000"
,"000101011110011","010000011111000"
,"000001100100011","000000111110000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"001000110001000","000101110000011"
,"000101010000011","001000110101000"
,"010001100000111"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "INCONSISTENT"; verify_case(6, Arg2, brokenSegments(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NSegmentDisplay ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
