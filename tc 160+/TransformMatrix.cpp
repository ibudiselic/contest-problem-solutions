#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

#define IN(i, j) (2 + (i)*n + (j))
#define OUT(i, j) (2 + m*n + (i)*n + (j))
const int source = 0;
const int sink = 1;

struct Edge {
    int a, b;
    int cap, cost, flow;
    Edge(int a_, int b_, int cap_, int cost_=0, int flow_=0): a(a_), b(b_), cap(cap_), cost(cost_), flow(flow_) {}
};

struct Graph {
    static const int INF = 987654321;
    int sz;
    vector< vector<Edge> > edges;
    vector< vector<int> > rev_ind;
    Graph(int sz_): sz(sz_), edges(sz_, vector<Edge>()), rev_ind(sz_, vector<int> ()) {}

    void add_edge(const Edge &e) {
        assert(e.a != e.b);
        rev_ind[e.b].push_back(edges[e.a].size());
        edges[e.a].push_back(e);
        rev_ind[e.a].push_back(edges[e.b].size());
        edges[e.b].push_back(Edge(e.b, e.a, 0, -e.cost, 0));
    }

    vector< pair<int, int> > min_path() const { // (start vertex, edges index)
        vector<int> from(sz, -1);
        vector<int> edge_ind(sz, -1);
        vector<int> min_dist(sz, INF);
        queue<int> active;

        active.push(source);
        min_dist[source] = 0;
        int passes = -1;
        int in_pass = 0;
        vector<bool> done_in_pass(sz, 0);
        while (passes<sz && !active.empty()) {
            if (in_pass == 0) {
                if (++passes == sz) {
                    break;
                }
                in_pass = active.size();
                fill(done_in_pass.begin(), done_in_pass.end(), false);
            }

            int x = active.front();
            active.pop();
            --in_pass;

            for (int i=0; i<(int)edges[x].size(); ++i) {
                const Edge &e = edges[x][i];
                assert(x == e.a);
                if (e.cap-e.flow>0 && min_dist[e.b]>min_dist[x]+e.cost) {
                    min_dist[e.b] = min_dist[x] + e.cost;
                    from[e.b] = x;
                    edge_ind[e.b] = i;
                    if (!done_in_pass[e.b]) {
                        done_in_pass[e.b] = true;
                        active.push(e.b);
                    }
                }
            }
        }

        if (from[sink] == -1) {
            return vector< pair<int, int> > (); // no path
        }

        vector< pair<int, int> > path;
        int x = sink;
        while (x != source) {
            path.push_back(make_pair(from[x], edge_ind[x]));
            x = from[x];
        }
        reverse(path.begin(), path.end());

        assert(path.size() > 0);
        assert(path[0].first == source);

        return path;
    }

    pair<int, int> augment(const vector< pair<int, int> > &path) { // (flow, cost)
        int flow = INF;
        for (int i=0; i<(int)path.size(); ++i) {
            const Edge &e = edges[path[i].first][path[i].second];
            flow = min(flow, e.cap - e.flow);
        }
        int cost = 0;
        for (int i=0; i<(int)path.size(); ++i) {
            Edge &e = edges[path[i].first][path[i].second];
            cost += flow * e.cost;

            e.flow += flow;
            const int e_rev_ind = rev_ind[e.a][path[i].second];
            edges[e.b][e_rev_ind].flow -= flow;
        }

        return make_pair(flow, cost);
    }

    pair<int, int> mcmf() { // (flow, cost)
        int flow = 0;
        int cost = 0;

        vector< pair<int, int> > path;
        while ((path = min_path()).size() > 0) {
            pair<int, int> t = augment(path);
            flow += t.first;
            cost += t.second;
        }

        return make_pair(flow, cost);
    }
};

class TransformMatrix {
	public:
	int transform(vector <string> A, vector <string> B, vector <string> C) {
        int m = A.size();
        int n = A[0].size();

        int a1 = 0;
        int b1 = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (A[i][j]=='1' && B[i][j]=='1') {
                    A[i][j] = B[i][j] = '0';
                }
                a1 += (A[i][j]=='1');
                b1 += (B[i][j]=='1');
            }
        }
        if (a1 != b1) {
            return -1;
        }

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (A[i][j]!=B[i][j] && (--C[i][j])<'0') {
                    return -1;
                }
            }
        }
        
        Graph G(2*m*n + 2);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (A[i][j] == '1') {
                    G.add_edge(Edge(source, IN(i, j), 1, 0));
                }
                if (B[i][j] == '1') {
                    G.add_edge(Edge(OUT(i, j), sink, 1, 0));
                }
                if (C[i][j] > '0') {
                    G.add_edge(Edge(OUT(i, j), IN(i, j), (C[i][j]-'0')/2, 0));
                }
                
                for (int di=-1; di<2; ++di) {
                    for (int dj=-1; dj<2; ++dj) {
                        if (abs(di)+abs(dj) > 0) {
                            const int r = i + di;
                            const int c = j + dj;
                            if (r<0 || c<0 || r>=m || c>=n) {
                                continue;
                            }
                            G.add_edge(Edge(IN(i, j), OUT(r, c), 100, 1));
                        }
                    }
                }
            }
        }

        /*for (int i=0; i<(int)G.edges.size(); ++i) {
            for (int j=0; j<(int)G.edges[i].size(); ++j) {
                cerr << G.edges[i][j].a << ' ' << G.edges[i][j].b << ' ' << G.edges[i][j].cap << '\n';
            }
        }*/

        pair<int, int> sol = G.mcmf();
        if (sol.first != a1) {
            return -1;
        } else {
            return sol.second;
        }
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"110", 
 "000",
 "001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"000",
 "110",
 "100"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"222",
 "222",
 "222"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(0, Arg3, transform(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"01"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"11"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, transform(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"111",
 "000",
 "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"111",
 "000",
 "111"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"013",
 "537",
 "136"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, transform(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"001",
 "110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"000",
 "111"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"000",
 "111"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(3, Arg3, transform(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"100",
 "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"000",
 "000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"999",
 "999"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(4, Arg3, transform(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"011101",
 "110000",
 "000011",
 "000000",
 "100000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"110100",
 "000011",
 "000000",
 "110001",
 "000010"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"305713",
 "537211",
 "352421",
 "242212",
 "333313"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(5, Arg3, transform(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arr0[] = {"10",
 "00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00",
 "01"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"11",
 "11"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(6, Arg3, transform(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TransformMatrix ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
