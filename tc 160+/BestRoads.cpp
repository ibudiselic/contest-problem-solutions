#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <utility>

using namespace std;

bool v[50];
int N;
bool G[50][50];
bool cur[50][50];

int dfs_(int x, bool (*A)[50]) {
    v[x] = 1;
    int ret = 1;
    for (int i=0; i<N; ++i) {
        if (A[x][i] && !v[i]) {
            ret += dfs_(i, A);
        }
    }
    
    return ret;
}
int dfs(int x, bool (*A)[50]) {
    memset(v, 0, sizeof v);
    return dfs_(x, A);
}
class BestRoads {
	public:
	vector <int> numberOfRoads(vector <string> roads, int M) {
		N = roads.size();
        int total = 0;
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                G[i][j] = (roads[i][j] == 'Y');
                total += G[i][j];
            }
        }
        
        total /= 2;
        if (M>total || dfs(0, G)<N) {
            return vector<int>();
        }
        
        memset(cur, 0, sizeof cur);
        set< pair<int, int> > S;
        int prev = 1;
        while ((int)S.size() < N-1) {
            for (int i=0; i<N; ++i) {
                for (int j=i+1; j<N; ++j) {
                    if (G[i][j] && !cur[i][j]) {
                        cur[i][j] = cur[j][i] = 1;
                        int t = dfs(0, cur);
                        if (prev == t) {
                            cur[i][j] = cur[j][i] = 0;
                        } else {
                            S.insert(make_pair(i, j));
                            prev = t;
                            goto AGAIN;
                        }
                    }
                }
            }
            AGAIN: ;
        }
        
        assert((int)S.size() == N-1);
        assert(dfs(0, cur) == N);
        
        M -= N - 1;
        if (M > 0) {
            for (int i=0; i<N; ++i) {
                for (int j=i+1; j<N; ++j) {
                    if (G[i][j]) {
                        if (S.insert(make_pair(i, j)).second) {
                            if (--M == 0) {
                                goto FINISH;
                            }
                        }
                    }
                }
            }
        }
        
        FINISH:;
        vector<int> sol(N, 0);
        for (set<pair<int, int> >::const_iterator it=S.begin(); it!=S.end(); ++it) {
            ++sol[it->first];
            ++sol[it->second];
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"NYYYY","YNYYY","YYNYY","YYYNY","YYYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arr2[] = {4, 4, 4, 4, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, numberOfRoads(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"NYY","YNY","YYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arr2[] = {2, 1, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, numberOfRoads(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NYNNY","YNNNY","NNNNN","NNNNY","YYNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, numberOfRoads(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"NYYNYYYN","YNNNNYYN","YNNNYNNN","NNNNNNYY","YNYNNNNN","YYNNNNYY","YYNYNYNY","NNNYNYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arr2[] = {5, 3, 2, 2, 2, 2, 3, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, numberOfRoads(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"NNYY","NNYY","YYNN","YYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, numberOfRoads(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BestRoads ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
