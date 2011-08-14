#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <utility>
#include <map>

using namespace std;

inline int L(int x, int y) {
    return x*x + y*y;
}
class SettingTents {
	public:
	int countSites(int N, int M) {
		int sol = 0;
        map< int, vector< pair<int, int> > > l2p;
        for (int i=0; i<=N; ++i) {
            for (int j=-M; j<=M; ++j) {
                if (i!=0 || j>0) {
                    l2p[L(i, j)].push_back(make_pair(i, j));
                }
            }
        }
        
        for (map<int, vector< pair<int, int> > >::const_iterator it=l2p.begin(); it!=l2p.end(); ++it) {
            const vector< pair<int, int> > &t = it->second;
            for (int i=0; i<(int)t.size(); ++i) {
                for (int j=i+1; j<(int)t.size(); ++j) {
                    int x = min(0, min(t[i].first, min(t[j].first, t[i].first + t[j].first)));
                    int X = max(0, max(t[i].first, max(t[j].first, t[i].first + t[j].first)));
                    int y = min(0, min(t[i].second, min(t[j].second, t[i].second + t[j].second)));
                    int Y = max(0, max(t[i].second, max(t[j].second, t[i].second + t[j].second)));
                    int a = X - x;
                    int b = Y - y;
                    if (a>0 && b>0 && a<=N && b<=M) {
                        sol += (N-a+1)*(M-b+1);
                    }
                }
            }
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 6; verify_case(0, Arg2, countSites(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 6; int Arg2 = 6; verify_case(1, Arg2, countSites(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 8; int Arg2 = 527; verify_case(2, Arg2, countSites(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SettingTents ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
