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

bool done[50][5000];
struct state {
    int at, cost;
    state(int  at_, int  cost_): at(at_), cost(cost_) {}
};
class SteeplechaseTrack {
	public:
	int maxComplexity(vector <string> fences, vector <string> tracks, int N) {
        memset(done, 0, sizeof done);
        queue<state> Q; 
        for (int i=0; i<(int)fences.size(); ++i) {
            if (fences[i][1] > '0') {
                done[i][fences[i][0]-'0' + fences[i][1]-'0'] = 1;
                Q.push(state(i, fences[i][0]-'0' + fences[i][1]-'0'));
            }
        }
        const int inf = 123456;
        int sol = -inf;
        
        int t = 0;
        int moves = 0;
        while (!Q.empty()) {
            if (t == 0) {
                t = Q.size();
                ++moves;
            }
            --t;
            const state s = Q.front();
            Q.pop();
            int at = s.at;
            int cost = s.cost;
            
            if (fences[at][2] != '0') {
                sol = max(sol, cost + fences[at][2]-'0');
            }
            
            if (moves+1 <= N) {
                for (int i=0; i<(int)fences.size(); ++i) {
                    if (tracks[at][i] != '0') {
                        int ncost = cost + tracks[at][i]-'0' + fences[i][0]-'0';
                        if (!done[i][ncost]) {
                            done[i][ncost] = true;
                            Q.push(state(i, ncost));
                        }
                    }
                }
            }
        }
        
        return sol==-inf ? -1 : sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"310",
 "300",
 "301"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"010",
 "001",
 "000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 13; verify_case(0, Arg3, maxComplexity(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"923"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = 1004; verify_case(1, Arg3, maxComplexity(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"111",
 "222",
 "333"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"743",
 "985",
 "380"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 9; verify_case(2, Arg3, maxComplexity(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"101",
 "202",
 "303"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"659",
 "431",
 "770"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = -1; verify_case(3, Arg3, maxComplexity(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"693",
 "982",
 "236"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"603",
 "986",
 "780"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; int Arg3 = 172; verify_case(4, Arg3, maxComplexity(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SteeplechaseTrack ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
