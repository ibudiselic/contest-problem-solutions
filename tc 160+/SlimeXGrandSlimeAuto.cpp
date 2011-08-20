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

const int INF = 987654321;
struct edge_t {
    int from, to;
    int cost;
    edge_t(int from_, int to_, int cost_): from(from_), to(to_), cost(cost_) {}
    void reverse() { swap(from, to); cost = -cost; }
};

int n;
int G[50][50];
int cost(char c) {
    if (c == '.') {
        return INF;
    } else if (c <= '9') {
        return c - '0' + 1;
    } else if (c <= 'Z') {
        return c - 'A' + 37;
    } else {
        return c - 'a' + 11;
    }
}
class SlimeXGrandSlimeAuto {
	public:
	int travel(vector <int> cars, vector <int> districts, vector <string> roads, int walk, int drive) {
        n = roads.size();
        int ncars = cars.size();
        int ndist = districts.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                G[i][j] = cost(roads[i][j]);
            }
            G[i][i] = 0;
        }
        for (int k=0; k<n; ++k) {
            for (int i=0; i<n; ++i) {
                for (int j=0; j<n; ++j) {
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }
        
        vector<edge_t> E;
        const int source = 0;
        const int sink = 1;
        for (int i=0; i<ncars; ++i) {
            E.push_back(edge_t(source, 2+i, 0));
        }
        
        int last = 0;
        for (int i=0; i<ndist; ++i) {
            E.push_back(edge_t(source, 2+ncars+i, G[last][districts[i]]*walk));
            E.push_back(edge_t(2+ncars+i, sink, 0));
            for (int j=0; j<ncars; ++j) {
                E.push_back(edge_t(2+j, 2+ncars+i, G[last][cars[j]]*walk + G[cars[j]][districts[i]]*drive));
            }
            last = districts[i];
        }
        
        vector<edge_t*> F(2+ncars+ndist);
        int sol = 0;
        for (int i=0; i<ndist; ++i) {
            vector<int> dist(2+ncars+ndist, INF);
            dist[source] = 0;
            bool change = true;
            while (change) {
                change = false;
                for (int i=0; i<(int)E.size(); ++i) {
                    if (dist[E[i].to] > dist[E[i].from] + E[i].cost) {
                        dist[E[i].to] = dist[E[i].from] + E[i].cost;
                        F[E[i].to] = &E[i];
                        change = true;
                    }
                }
            }
            // F[u]->to because we reverse it in the body
            for (int u=sink; u!=source; u=F[u]->to) {
                F[u]->reverse();
            }
            sol += dist[sink];
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {
"..0.",
"...1",
"0..2",
".12."}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; int Arg4 = 1; int Arg5 = 36; verify_case(0, Arg5, travel(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {
".A.",
"A.B",
".B."}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 1; int Arg5 = 262; verify_case(1, Arg5, travel(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {
".a4",
"a..",
"4.."}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 1; int Arg5 = 95; verify_case(2, Arg5, travel(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {
".B.",
"B.A",
".A."}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 1; int Arg5 = 262; verify_case(3, Arg5, travel(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arr0[] = {2,5,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,5,1,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {
".12.4.",
"1....7",
"2..3..",
"..3..5",
"4.....",
".7.5.."}
; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 53; int Arg4 = 37; int Arg5 = 1259; verify_case(4, Arg5, travel(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SlimeXGrandSlimeAuto ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
