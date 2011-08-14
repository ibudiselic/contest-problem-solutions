#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

bool G[50][50];
int match[50];
int rmatch[50];
bool v[50];
int m, n;

int get(int x) {
    v[x] = 1;
    for (int y=0; y<m; ++y) {
        if (G[x][y] && (rmatch[y]==-1 || !v[rmatch[y]] && get(rmatch[y]))) {
            match[x] = y;
            rmatch[y] = x;
            return 1;
        }
    }
    return 0;
}
int match_size() {
    memset(match, 0xff, sizeof match);
    memset(rmatch, 0xff, sizeof rmatch);
    int ret = 0;
    
    for (int i=0; i<m; ++i) {
        if (match[i] == -1) {
            memset(v, 0, sizeof v);
            ret += get(i);
        }
    }
    
    return ret;
}
class PeopleYouMayKnow {
	public:
	int maximalScore(vector <string> friends, int person1, int person2) {
        vector<int> left, right;
        int sol = 0;
        const int n = friends.size();
        for (int i=0; i<n; ++i) {
            if (friends[person1][i]=='Y' && friends[i][person2]=='Y') {
                ++sol;
            } else if (friends[person1][i] == 'Y') {
                left.push_back(i);
            } else if (friends[i][person2] == 'Y') {
                right.push_back(i);
            }
        }
        
        memset(G, 0, sizeof G);
        
        for (int i=0; i<(int)left.size(); ++i) {
            for (int j=0; j<(int)right.size(); ++j) {
                if (friends[left[i]][right[j]] == 'Y') {
                    G[i][j] = G[j][i] = 1;
                }
            }
        }
        
        ::m = left.size();
        ::n = right.size();
        return sol + match_size();
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NN"
,"NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; int Arg3 = 0; verify_case(0, Arg3, maximalScore(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"NYNN"
,"YNYN"
,"NYNY"
,"NNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 3; int Arg3 = 1; verify_case(1, Arg3, maximalScore(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"NYNYYYN"
,"YNYNNYY"
,"NYNNNNY"
,"YNNNNNN"
,"YNNNNYN"
,"YYNNYNY"
,"NYYNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; int Arg3 = 1; verify_case(2, Arg3, maximalScore(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"NYYYYNNNN"
,"YNNNNYYYN"
,"YNNNNNNYN"
,"YNNNNNNYN"
,"YNNNNNNNY"
,"NYNNNNNNY"
,"NYNNNNNNY"
,"NYYYNNNNY"
,"NNNNYYYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 0; int Arg3 = 3; verify_case(3, Arg3, maximalScore(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PeopleYouMayKnow ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
