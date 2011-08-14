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

int mod = 1000000007;
int dp[2502];
int next[4][2502];
inline char val(char c) {
    switch (c) {
        case 'A': return '0';
        case 'C': return '1';
        case 'G': return '2';
        case 'T': return '3';
        default: assert(0); return '4';
    }
}

map<string, vector<string> > T;
string s;
class DNADeletion {
	public:
	int differentProteins(vector <string> DNASequence, vector <string> codonTable) {
		memset(dp, 0, sizeof dp);
        dp[0] = 1;
        s = DNASequence[0];
        s.reserve(2500);
        for (int i=1; i<(int)DNASequence.size(); ++i) {
            s += DNASequence[i];
        }
        for (int i=0; i<(int)s.size(); ++i) {
            s[i] = val(s[i]);
        }
        
        T.clear();
        for (int i=0; i<(int)codonTable.size(); ++i) {
            string a, b;
            istringstream is(codonTable[i]);
            is >> a >> b;
            for (int i=0; i<(int)a.size(); ++i) {
                a[i] = val(a[i]);
            }
            T[b].push_back(a);
        }
        
        int cur[4];
        for (int i=0; i<4; ++i) {
            cur[i] = -1;
        }
        for (int i=(int)s.size()-1; i>=0; --i) {
            for (int j=0; j<4; ++j) {
                next[j][i] = cur[j];
            }
            cur[s[i]-'0'] = i;
        }
        
        for (int i=0; i<(int)s.size(); ++i) {
            for (map<string, vector<string> >::const_iterator it=T.begin(); it!=T.end(); ++it) {
                const vector<string> &t = it->second;
                int end_pos = 12345678;
                for (int j=0; j<(int)t.size(); ++j) {
                    int cur = i;
                    const string &u = t[j];
                    for (int k=0; k<3; ++k, ++cur) {
                        if (cur == (int)s.size()) {
                            cur = 12345678;
                            break;
                        }
                        if (u[k] != s[cur]) {
                            int x = next[u[k]-'0'][cur];
                            if (x == -1) {
                                cur = 12345678;
                                break;
                            } else {
                                cur = x;
                            }
                        }
                    }
                    if (cur < 12345678) {
                        end_pos = min(end_pos, cur);
                    }
                }
                if (end_pos < 12345678) {
                    dp[end_pos] += dp[i];
                    if (dp[end_pos] >= mod) {
                        dp[end_pos] -= mod;
                    }
                }
            }
        }
        
        int sol = 0;
        for (int i=1; i<=(int)s.size(); ++i) {
            sol = (sol + dp[i]) % mod;
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ACTG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ACT gua", "ACG cys", "ATG leu", "CTG thr"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, differentProteins(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"AAACCC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"AAA thr", "CCC cys"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, differentProteins(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"AAATCCC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"AAA gua","TCC dop","AAT dop","CCC gua"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(2, Arg2, differentProteins(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"ATGCGCATTAACCTCCTACCATGGAAGGGACGTAACCCGGCAATTTGATC",
 "CTGATGACGGCATAAGCTACCCCTAGAGGTAAAAATGCATACTGCGTGCT",
 "ATGCAG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"AAC RpjZt","AAT ZeiC","GCA ChZwh","TCC RpjZt","GAA I",
 "TAG ZeiC","CTG dVK","GAG ZeiC","GTG I","AAG q","ATT dVK",
 "AGA cJEjM","GGG KONUd","GTC ZRV","GGC ZeiC","TTA KONUd",
 "GAC q","CCA q","GCC ZRV","GCG RpjZt","CCT ZRV","ATG dVK",
 "ATC ChZwh","CTC cJEjM","CCC q","ATA dWjz","TTG DkEG",
 "CAG q","CAA ZRV","ACT dVK","TCG dVK","ACC I","CGC dVK"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 455985264; verify_case(3, Arg2, differentProteins(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    DNADeletion ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
