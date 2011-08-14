#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

int final;
int dp[50][201][201];
vector<int> A;
const int INF = 123456789;
int go(int p, int w, int d) {
    if (p == (int)A.size()) {
        return d<=w ? 1 : 0;
    }
    int &ret = dp[p][w][d];
    if (ret != -1) {
        return ret;
    }
    
    for (int i=0; i<=4; ++i) {
        for (int j=0; i+j<=4; ++j) {
            const int k = 4-i-j;
            const int cur = A[p] + 3*i + j;
            if (w>=k && cur<=final) {
                for (int l=0; l<=j; ++l) {
                    if (l > d) {
                        break;
                    }
                    if (go(p+1, w+i-k, d-l+(j-l))) {
                        return (ret = 1);
                    }
                }
            }
        }
    }
    
    return (ret = 0);
}
    
class TheSoccerDivOne {
	public:
	int find(vector <int> points) {
		vector< pair<int, int> > v;
        for (int i=0; i<(int)points.size(); ++i) {
            v.push_back(make_pair(-points[i], i));
        }
        sort(v.begin(), v.end());
        
        if (v[0].second == 0) {
            return 1;
        }
        
        int me = -1;
        for (int i=1; i<(int)v.size(); ++i) {
            if (v[i].second == 0) {
                me = i;
                break;
            }
        }
        
        int can_win = ((int)v.size() - me) * 4;
        int j = 0;
        final = points[0] + 12;
        while (j<me && points[v[j].second]>final) {
            ++j;
            can_win += 4;
        }
        
        A.clear();
        for (int i=j; i<me; ++i) {
            A.push_back(points[v[i].second]);
        }
        reverse(A.begin(), A.end());
        while (A.size() > 0) {
            memset(dp, 0xff, sizeof dp);
            if (go(0, can_win, 0)) {
                return me - (int)A.size() + 1;
            }
            A.pop_back();
            can_win += 4;
        }
        return me + 1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 18, 21, 19}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arr0[] = {4, 1, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arr0[] = {4, 16, 4, 16, 16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheSoccerDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
