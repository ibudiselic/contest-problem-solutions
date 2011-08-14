#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool G[50][50];
int C[50];
bool F[50][50];
int match[50];
int rmatch[50];
int n;
bool v[50];
bool can_match(int x) {
    v[x] = true;
    for (int i=0; i<n; ++i) {
        if (F[x][i] && (rmatch[i]==-1 || !v[rmatch[i]] && can_match(rmatch[i]))) {
            match[x] = i;
            rmatch[i] = x;
            return true;
        }
    }
    return false;
}
int max_bipartite() {
    int ret = 0;
    memset(match, 0xff, sizeof match);
    memset(rmatch, 0xff, sizeof rmatch);
    for (int i=0; i<n; ++i) {
        if (match[i] == -1) {
            memset(v, 0, sizeof v);
            ret += can_match(i);
        }
    }
    return ret;
}
class CompanyRestructuring {
	public:
	int fewestDivisions(vector <string> hasManaged) {
		n = hasManaged.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                G[i][j] = (hasManaged[i][j]=='Y');
            }
        }
        
        for (int i=0; i<n; ++i) {
            G[i][i] = true;
        }
        for (int k=0; k<n; ++k) {
            for (int i=0; i<n; ++i) {
                for (int j=0; j<n; ++j) {
                    if (!G[i][j]) {
                        G[i][j] = G[i][k] && G[k][j];
                    }
                }
            }
        }
        
        memset(C, 0xff, sizeof C);
        int cnt = 0;
        vector< vector<int> > cmp;
        for (int i=0; i<n; ++i) {
            if (C[i] == -1) {
                cmp.push_back(vector<int>());
                cmp.back().push_back(i);
                C[i] = cnt;
                for (int j=i+1; j<n; ++j) {
                    if (G[i][j] && G[j][i]) {
                        assert(C[j] == -1);
                        C[j] = cnt;
                        cmp.back().push_back(j);
                    }
                }
                ++cnt;
            }
        }
        
        int sol = n;
        for (int c=0; c<cnt; ++c) {
            memset(F, 0, sizeof F);
            for (int i=0; i<(int)cmp[c].size(); ++i) {
                const int x = cmp[c][i];
                for (int y=0; y<n; ++y) {
                    if (hasManaged[y][x]=='Y' && C[y]!=c) {
                        F[y][x] = 1;
                    }
                }
            }
            sol -= max_bipartite();
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NNNN","NNYN","NNNN","YYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, fewestDivisions(Arg0)); }
	void test_case_1() { string Arr0[] = {"NNYN","NNYN","YNNN","YYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, fewestDivisions(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYNNN","NNYNN","NNNYN","NNNNY","YNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, fewestDivisions(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYNYYYNN"
,"NNNNYYNN"
,"NYNNYYNN"
,"NNYNYYNN"
,"NNNNNNNN"
,"NYYNYNNN"
,"YYNYYYNN"
,"YYNYYYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, fewestDivisions(Arg0)); }
	void test_case_4() { string Arr0[] = {"NYNYNNYYNYNNNYYNYNYY"
,"YNNNNNYYNNNYYNYNYNYY"
,"NNNNNNYYNNNYYNYNNNNY"
,"YNYNNNNYNNNYNNYNYNNY"
,"NYNNNNNYYYYNYNYYNNYN"
,"YYYYNNYNYNNNNNYYNYNY"
,"NNNNNNNNNNNYYNNNNNYY"
,"NNNNNNYNNNNYYNYNNNYN"
,"NYYYNNNYNNNNYYNYYNYY"
,"NNYNNNYYNNNNYNNNNNYY"
,"YYNNNYNNYNNNNYNNYNYY"
,"NNNNNNNYNNNNYNYNNNNY"
,"NNNNNNYNNNNYNNNNNNNN"
,"NNYNNNNNNNNYYNYNNYYN"
,"NNNNNNNNNNNYNNNNNNNY"
,"YNYYNYYNNNYYNNNNYNYY"
,"NYNNNNNYNYNYYYYNNNNY"
,"NNYNNNNYNYNYYYNNNNYY"
,"NNNNNNNYNNNYNNNNNNNY"
,"NNNNNNYYNNNYYNYNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, fewestDivisions(Arg0)); }
	void test_case_5() { string Arr0[] = {"NNNYNNNNNNNYNNNNNNNN"
,"NNNNNNYNNYNNNNNYNYYN"
,"YNNNNNYNYNNNNNNNNNNY"
,"YNNNNNNNNNNNNNNNNNNN"
,"NNYNNNYNYNNYNNYNNNNY"
,"NNNYNNNNNNNYNNYYYNYY"
,"NNYYNNNNYNNNNNNNNNNY"
,"NYNNNYNNYNNNYNYNYNNN"
,"NNNNNNNNNNNNNNNNNNNN"
,"YNNNNNNNNNNYNNYYNNYN"
,"NNYYNYNNYYNNNNYYNYNN"
,"NNNNNNNNYNNNNNNNNNNN"
,"NNNYYNYNYYYYNNNNYNYY"
,"NNYYNYNNYYYYNNNNNYNY"
,"NNYYYNNNYNNNNNNNNNNN"
,"YNNYYYNNNNNNNNYNYNYY"
,"NNNNYNYNNNNYNNYNNNNN"
,"YNNYYYYNNYNNYNNNYNYN"
,"YNNYYYYNYNNYNNYYYNNY"
,"YNYNNNNNYNNYNNNNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(5, Arg1, fewestDivisions(Arg0)); }
	void test_case_6() { string Arr0[] = {"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(6, Arg1, fewestDivisions(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CompanyRestructuring ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
