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

int n;
vector<string> L;

inline int hate_in(int i) {
    return 2 + i;
}
inline int hate_out(int i) {
    return n+2 + i;
}
inline int boy(int i) {
    return 2*n + 2 + i;
}
inline int girl(int i) {
    return 3*n + 2 + i;
}

struct FlowInfo {
    int target, capacity, flow, rev_ind;
};
const int source = 0;
const int sink = 1;
vector< vector<FlowInfo> > graph;
void connect(int a, int b, int capacity) {
    FlowInfo t;
    t.target = b;
    t.capacity = capacity;
    t.flow = 0;
    t.rev_ind = (int)graph[b].size();

    graph[a].push_back(t);

    t.target = a;
    t.capacity = 0;
    t.flow = 0;
    t.rev_ind = (int)graph[a].size()-1;
    graph[b].push_back(t);
}

vector<int> mf_path;
bool mf_bfs() {
    vector<int> parent(graph.size(), -1);
    queue<int> Q;
    Q.push(source);
    parent[source] = -2;

    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();

        for (int i=0; i<(int)graph[x].size(); ++i) {
            if (graph[x][i].capacity - graph[x][i].flow <= 0) {
                continue;
            }

            int y = graph[x][i].target;
            if (parent[y] != -1) {
                continue;
            }

            if (y == sink) {
                mf_path.clear();
                mf_path.push_back(sink);
                while (parent[x] != -2) {
                    mf_path.push_back(x);
                    x = parent[x];
                }
                assert(x == source);
                reverse(mf_path.begin(), mf_path.end());
                return true;
            }

            parent[y] = x;
            Q.push(y);
        }
    }

    return false;
}

int max_flow() {
    int ret = 0;

    while (mf_bfs()) {
        int inc_by = 1234567890;

        int start = source;
        for (int i=0; i<(int)mf_path.size(); ++i) {
            int x = mf_path[i];
            for (int j=0; j<(int)graph[start].size(); ++j) {
                if (graph[start][j].target == x) {
                    inc_by = min(inc_by, graph[start][j].capacity - graph[start][j].flow);
                }
            }
            start = x;
        }
        assert(start == sink);

        start = source;
        for (int i=0; i<(int)mf_path.size(); ++i) {
            int x = mf_path[i];
            for (int j=0; j<(int)graph[start].size(); ++j) {
                if (graph[start][j].target == x) {
                    graph[start][j].flow += inc_by;
                    graph[graph[start][j].target][graph[start][j].rev_ind].flow = -graph[start][j].flow;
                }
            }
            start = x;
        }

        ret += inc_by;
    }

    return ret;
}

class DancingParty {
	public:
	int maxDances(vector <string> likes, int k) {
	    L = likes;
        n = L.size();

        graph.assign(4*n + 2, vector<FlowInfo>());
        for (int i=0; i<n; ++i) {
            connect(source, boy(i), 1);
            connect(girl(i), sink, 1);
        }

        for (int i=0; i<n; ++i) {
            connect(boy(i), hate_in(i), k);
            connect(hate_out(i), girl(i), k);
        }

        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (L[i][j] == 'Y') {
                    connect(boy(i), girl(j), 1);
                } else {
                    connect(hate_in(i), hate_out(j), 1);
                }
            }
        }

        int sol = 0;
        int cnt = 0;
        while (1) {
            cnt += max_flow();
            if (cnt != (sol+1) * n) {
                break;
            }
            ++sol;
            for (int i=0; i<n; ++i) {
                assert(graph[source][i].target == boy(i));
                ++graph[source][i].capacity;
                assert(graph[girl(i)][0].target == sink);
                ++graph[girl(i)][0].capacity;
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"YYY", "YYY", "YYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 3; verify_case(0, Arg2, maxDances(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"YYY", "YYN", "YNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 2; verify_case(1, Arg2, maxDances(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"YN", "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; verify_case(2, Arg2, maxDances(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"YN", "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; verify_case(3, Arg2, maxDances(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    DancingParty ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
