#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int best[51][51][51];
class KindAndCruel {
	public:
	int crossTheField(string A, int K, int C) {
		int n = A.size();
        
        priority_queue< pair<int, int> > PQ;
        memset(best, 0xff, sizeof best);
        best[0][0][0] = 0;
        PQ.push(make_pair(-0, 0));
        while (!PQ.empty()) {
            pair<int, int> tmp = PQ.top();
            PQ.pop();
            
            int t = -tmp.first;
            int p = tmp.second;
            
            for (int d=-1; d<2; ++d) {
                int dest = p + d;
                if (dest<0 || dest>=n) {
                    continue;
                }
                int tk = (t+1)%K;
                int tc = (t+1)%C;
                if (A[dest]=='K' && tk==0) {
                    continue;
                }
                if (A[dest]=='C' && tc!=0) {
                    continue;
                }
                if (dest == n-1) {
                    return t + 1;
                }
                if (best[dest][tk][tc]==-1 || t+1<best[dest][tk][tc]) {
                    best[dest][tk][tc] = t+1;
                    PQ.push(make_pair(-t-1, dest));
                }
            }
        }
        
        return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "..."; int Arg1 = 2; int Arg2 = 5; int Arg3 = 2; verify_case(0, Arg3, crossTheField(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = ".K.C."; int Arg1 = 3; int Arg2 = 4; int Arg3 = 5; verify_case(1, Arg3, crossTheField(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = ".CCCC."; int Arg1 = 3; int Arg2 = 5; int Arg3 = -1; verify_case(2, Arg3, crossTheField(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = ".CKKKKCKKKKC.KKKKCKKKKC.CKKKKCKKKKCKKKKCKKKKCKKKK."; int Arg1 = 5; int Arg2 = 5; int Arg3 = 60; verify_case(3, Arg3, crossTheField(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    KindAndCruel ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
