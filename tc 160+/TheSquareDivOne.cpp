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

int R[18];
int N;
int nodes[18][18];
int col_joiner[18];
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const int INF = 1<<30;

typedef int flow_type;
typedef int cost_type;
struct edge_t {
    int from, to;
    flow_type capacity, flow;
    cost_type cost;
    int rev_ind; // index of reverse edge
    edge_t(int from_, int to_, flow_type capacity_, flow_type flow_, cost_type cost_, int rev_ind_):
        from(from_), to(to_), capacity(capacity_), flow(flow_), cost(cost_), rev_ind(rev_ind_) {}
};

class flow_network {
    public:
    flow_network(): source(-1), sink(-1) {}
    
    int add_source() {
        source = add_node();
        return source;
    }
    int add_sink() {
        sink = add_node();
        return sink;
    }
    int add_node() {
        edges.push_back(vector<edge_t>());
        return (int)edges.size() - 1;
    }
    void add_edge(int from, int to, flow_type capacity, cost_type cost) {
        assert(from < (int)edges.size());
        assert(to < (int)edges.size());
        edges[from].push_back(edge_t(from, to, capacity, 0, cost, (int)edges[to].size()));
        edges[to].push_back(edge_t(to, from, 0, 0, -cost, (int)edges[from].size() - 1));
    }

    pair<cost_type, flow_type> min_cost_max_flow() {
        assert(source != -1);
        assert(sink != -1);
        cost_type cost = 0;
        flow_type flow = 0;
        vector< edge_t* > arrive_by(edges.size());
        while (can_augment(arrive_by)) {
            flow_type add_flow = INF;
            int u = sink;
            while (u != source) { // calculate augmenting flow
                assert(arrive_by[u] != 0);
                const edge_t *edge = arrive_by[u];
                assert(edge->to == u);
                const int v = edge->from;
                add_flow = min(add_flow, edge->capacity - edge->flow);
                u = v;
            }
            u = sink;
            cost_type add_cost = 0;
            while (u != source) { // update the network and calculate the cost of the augmentation
                edge_t *edge = arrive_by[u];
                const int v = edge->from;
                edge->flow += add_flow;
                edges[u][edge->rev_ind].flow -= add_flow;
                add_cost += add_flow * edge->cost;
                u = v;
            }
            
            cost += add_cost;
            flow += add_flow;
        }
        
        return make_pair(cost, flow);
    }
    
    private:
    int source, sink;
    vector< vector<edge_t> > edges;
    
    bool can_augment(vector< edge_t* > &arrive_by) { // semantically const
        fill(arrive_by.begin(), arrive_by.end(), (edge_t *)0);
        vector< cost_type > best(edges.size(), INF);
        vector<int> changed_in_pass(edges.size(), 0);
        int pass_cnt = 0;
        int in_pass_cnt = 0;
        queue<int> active;
        active.push(source);
        best[source] = 0;
        while (!active.empty()) { // bellman-ford
            if (in_pass_cnt == 0) {
                if (pass_cnt++ == (int)edges.size()) {
                    break;
                }
                in_pass_cnt = active.size();
                fill(changed_in_pass.begin(), changed_in_pass.end(), 0);
            }
            int u = active.front();
            active.pop();
            --in_pass_cnt;
            for (int i=0; i<(int)edges[u].size(); ++i) {
                if (edges[u][i].capacity-edges[u][i].flow > 0) {
                    const cost_type new_cost = best[u] + edges[u][i].cost;
                    const int v = edges[u][i].to;
                    if (new_cost < best[v]) {
                        best[v] = new_cost;
                        // ok to take address of vector element because it doesn't change during the algorithm
                        arrive_by[v] = &edges[u][i];
                        if (!changed_in_pass[v]) {
                            changed_in_pass[v] = 1;
                            active.push(v);
                        }
                    }
                }
            }
        }
        
        return best[sink] < INF;
    }
};
    
class TheSquareDivOne {
	public:
	vector <string> solve(vector <string> board) {
        N = board.size();
        for (int i=0; i<N; ++i) {
            R[i] = count(board[i].begin(), board[i].end(), 'C');
        }
        
        vector<string> sol = board; // copy just for size
        flow_network common;
        int source = common.add_source();
        int sink = common.add_sink();
        
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                nodes[i][j] = common.add_node();
                if (board[i][j] == 'C') {
                    common.add_edge(source, nodes[i][j], 1, 0);
                }
            }
        }
        
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                for (int d=0; d<4; ++d) {
                    const int r = i + di[d];
                    const int c = j + dj[d];
                    if (0<=r && r<N && 0<=c && c<N) {
                        common.add_edge(nodes[i][j], nodes[r][c], INF, 1<<N);
                    }
                }
            }
        }
        
        for (int i=0; i<N; ++i) {
            col_joiner[i] = common.add_node();
            common.add_edge(col_joiner[i], sink, R[i], 0);
        }

        for (int t=0; t<N; ++t) { // solve t-th row
            flow_network G = common;
            for (int i=0; i<t; ++i) { // enforce already calculated solution
                for (int j=0; j<N; ++j) {
                    if (sol[i][j] == 'C') {
                        G.add_edge(nodes[i][j], col_joiner[j], 1, 0);
                    }
                }
            }
            
            for (int j=0; j<N; ++j) { // find out the order for row t
                G.add_edge(nodes[t][j], col_joiner[j], 1, 1<<(N-1-j));
            }
            
            for (int i=t+1; i<N; ++i) { // rest of the nodes are "free" (i.e. don't care about order)
                for (int j=0; j<N; ++j) {
                    G.add_edge(nodes[i][j], col_joiner[j], 1, 0);
                }
            }
            
            pair<int, int> res = G.min_cost_max_flow();
            int cost = res.first; // contains a repesentation of the arangement in row t
            for (int j=0; j<N; ++j) {
                if ((cost>>j) & 1) {
                    sol[t][N-1-j] = 'C';
                } else {
                    sol[t][N-1-j] = '.';
                }
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"...",
 "...",
 "C.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"...", "...", "..C" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arr0[] = {"CCC",
 ".C.",
 "CCC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"C.C", "C.C", "CCC" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arr0[] = {"C..",
 ".C.",
 "..C"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"C..", ".C.", "..C" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { string Arr0[] = {"C....","CCCCC","...CC",".CC..",".C.C."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".C...", "CCCCC", ".C..C", ".CC..", ".C.C." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, solve(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheSquareDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
