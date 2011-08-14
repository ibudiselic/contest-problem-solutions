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

bool G[200][200];
int n;
int T;
map<string, int> M;
vector<string> C;
int ind(const string &s) {
    if (M.count(s) == 0) {
        M[s] = C.size();
        C.push_back(s);
    }

    return M[s];
}

int mask[200];
int dp[1<<16];
int go(int m) {
    if (m == (1<<T)-1) {
        return 0;
    }
    int &ret = dp[m];
    if (ret != -1) {
        return ret;
    }

    ret = 12345789;
    for (int i=0; i<n; ++i) {
        int nm = m | mask[i];
        if (nm != m) {
            ret = min(ret, 1+go(nm));
        }
    }

    return ret;
}

class PowerAdapters {
	public:
	int needed(vector <string> A, vector <string> I, string H) {
		memset(G, 0, sizeof G);
        M.clear();
        C.clear();
        T = (int)I.size();
        for (int i=0; i<(int)I.size(); ++i) {
            ind(I[i]);
        }
        ind(H);

        for (int i=0; i<(int)A.size(); ++i) {
            istringstream is(A[i]);
            string a, b;
            is >> a >> b;
            int aa = ind(a);
            int bb = ind(b);
            G[aa][bb] = 1;
        }

        n = C.size();
        for (int i=0; i<n; ++i) {
            G[i][i] = 1;
        }

        for (int k=0; k<n; ++k) {
            for (int i=0; i<n; ++i) {
                if (G[i][k]) {
                    for (int j=0; j<n; ++j) {
                        G[i][j] |= G[k][j];
                    }
                }
            }
        }

        memset(mask, 0, sizeof mask);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<T; ++j) {
                if (G[i][j]) {
                    mask[i] |= (1<<j);
                }
            }
        }

        memset(dp, 0xff, sizeof dp);
        return go(mask[ind(H)]);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"USA EUROPE","EUROPE UK"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"UK","EUROPE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "USA"; int Arg3 = 0; verify_case(0, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"USA CANADA","USA UK","GERMANY AUSTRALIA","GERMANY CANADA","AUSTRALIA USA","UK CANADA","JAPAN USA","JAPAN USA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"AUSTRALIA","CANADA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "UK"; int Arg3 = 1; verify_case(1, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"INDIA EGYPT","USA GERMANY","CHINA SPAIN","GERMANY NETHERLANDS","NETHERLANDS CHINA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"CHINA","GERMANY","SPAIN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NETHERLANDS"; int Arg3 = 1; verify_case(2, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"AUSTRALIA GERMANY","CANADA INDIA","AUSTRALIA USA","USA INDIA","USA AUSTRALIA","CANADA GERMANY","USA AUSTRALIA","USA CANADA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"AUSTRALIA","CANADA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "CANADA"; int Arg3 = 1; verify_case(3, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"SPAIN AUSTRALIA","SPAIN NETHERLANDS","AUSTRALIA EGYPT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"AUSTRALIA","EGYPT","NETHERLANDS"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "UK"; int Arg3 = 1; verify_case(4, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"CMCUG MEIACWT","CMCUG QLLUJCMB","MEIACWT UKINFV"
,"ODK QLLUJCMB","MEIACWT SXGBGF","CWW TUQ","YUAYI MEIACWT"
,"MEIACWT ODK","QLLUJCMB AGNAE","AGNAE GACPM","QLLUJCMB MAO"
,"KNCUTEW NNA","ODK MEIACWT","QJQUY ODK","AGNAE MEIACWT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"AGNAE","ODK","TUQ","YUAYI"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "AGNAE"; int Arg3 = 2; verify_case(5, Arg3, needed(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arr0[] = {"LALJ DMZEQ","ANKNMMUQ YINE","MAYNYVOM KQWCGASA"
,"YWEU DMZEQ","MAO YAE","CWNFS IAWGRCX","KQWCGASA CNUL"
,"CWNFS DMZEQ","QBHQCU EPMAKOI","CNUL KQWCGASA"
,"ANKNMMUQ YOXOQVO","YAE MAYNYVOM","IAWGRCX DMZEQ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"CWNFS","DMZEQ","ISO","YOKKMK"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YINE"; int Arg3 = 3; verify_case(6, Arg3, needed(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PowerAdapters ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
