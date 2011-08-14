#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

const long long inf = 123456789012345LL;
long long dist[50][50];
long long dp[50][50][50];
class TimeTravellingTour {
	public:
	long long determineCost(int N, vector <int> cities, vector <string> roads) {
		string R = accumulate(roads.begin(), roads.end(), string());
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                dist[i][j] = inf;
            }
        }
        istringstream is(R);
        string s;
        while (is >> s) {
            int a, b, d;
            sscanf(s.c_str(), "%d,%d,%d", &a, &b, &d);
            dist[a][b] = dist[b][a] = d;
        }
        
        for (int k=0; k<N; ++k) {
            for (int i=0; i<N; ++i) {
                for (int j=0; j<N; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        int M = cities.size();
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                for (int k=0; k<M; ++k) {
                    dp[i][j][k] = inf;
                }
                dp[i][j][j] = (i==cities[j] ? 0 : dist[i][cities[j]]);
            }
        }
        for (int d=1; d<M; ++d) {
            for (int i=0; i+d<M; ++i) {
                int j = i + d;
                for (int u=0; u<N; ++u) {
                    for (int k=i+1; k<=j; ++k) {
                        dp[u][i][j] = min(dp[u][i][j], dp[u][i][k-1] + dp[u][k][j]);
                    }
                }
                for (int u=0; u<N; ++u) {
                    for (int k=0; k<N; ++k) {
                        dp[u][i][j] = min(dp[u][i][j], dp[k][i][j] + dist[u][k]);
                    }
                }
            }
        }
        
        return dp[0][0][M-1]==inf ? -1 : dp[0][0][M-1];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {2,3,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0,2,4 0,1,2 2,1,2 1,3,3 4,0,4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 13LL; verify_case(0, Arg3, determineCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {1,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0,2,1"," 2",",1,5"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 12LL; verify_case(1, Arg3, determineCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0,1,2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = -1LL; verify_case(2, Arg3, determineCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 6; int Arr1[] = {4, 1, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0,1,5 0,2,5 0,5,2 2,3,5 2,4,2 3,4,4 3,5,1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 19LL; verify_case(3, Arg3, determineCost(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TimeTravellingTour ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
