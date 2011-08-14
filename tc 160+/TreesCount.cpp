#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int G[50][50];
int mindist[50];
const int INF = 123456789;
const long long mod = 1000000007;
class TreesCount {
	public:
	int count(vector <string> graph) {
		int n = graph.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                G[i][j] = graph[i][j]-'0';
            }
        }
        mindist[0] = 0;
        for (int i=1; i<n; ++i) {
            mindist[i] = INF;
        }
        
        vector<int> done;
        done.push_back(0);
        long long sol = 1;
        for (int iter=1; iter<n; ++iter) {
            int best_i = -1;
            int best_dist = INF;
            int best_ways = 0;
            for (int next=1; next<n; ++next) {
                if (mindist[next] < INF) {
                    continue;
                }
                int dist = INF;
                int ways = 0;
                for (int i=0; i<(int)done.size(); ++i) {
                    const int u = done[i];
                    if (G[u][next] == 0) {
                        continue;
                    }
                    int ndist = mindist[u] + G[u][next];
                    if (ndist < dist) {
                        dist = ndist;
                        ways = 1;
                    } else if (ndist == dist) {
                        ++ways;
                    }
                }
                
                if (dist < best_dist) {
                    best_dist = dist;
                    best_i = next;
                    best_ways = ways;
                }
            }
            
            done.push_back(best_i);
            mindist[best_i] = best_dist;
            sol = (sol * best_ways) % mod;
        }
        
        return int(sol);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"01",
 "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"011",
 "101",
 "110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"021",
 "201",
 "110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"0123",
 "1012",
 "2101",
 "3210"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arr0[] = {"073542",
 "705141",
 "350721",
 "517031",
 "442304",
 "211140"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TreesCount ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
