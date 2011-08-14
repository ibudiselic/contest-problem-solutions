#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>
#include <map>
#include <utility>
#include <set>

using namespace std;

vector<string> cutUp(const string &s, const string &delim=" ") {
	int lastPos = 0, pos = 0;
	vector<string> ret;

	while (pos+delim.size() <= s.size()) {
		if (s.substr(pos, delim.size()) == delim) {
			ret.push_back(s.substr(lastPos, pos-lastPos));

			pos += (int)delim.size()-1;
			lastPos = pos+1;
		}
		++pos;
	}

	if (lastPos < (int)s.size())
		ret.push_back(s.substr(lastPos));

	return ret;
}

struct tri {
    int a, b, c;
    tri(int a_, int b_, int c_): a(a_), b(b_), c(c_) {}
};
vector<tri> E;
int K[51];
int N;
int bc[1<<10];
int side[100];
map< pair<int, int>, vector< pair<int, int> > > edges;

void upd(vector< vector<int> > &v, 
         map< pair<int, int>, int > &ind, 
         map< pair<int, int>, int > &other, 
         map< pair<int, int>, vector< pair<int, int> > > &edges) {
    for (map< pair<int, int>, int>::const_iterator it=ind.begin(); it!=ind.end(); ++it) {
        const int here = it->second;
        vector<int> &neigh = v[here];
        const vector< pair<int, int> > &goes_to = edges[it->first];
        for (int i=0; i<(int)goes_to.size(); ++i) {
            if (other.count(goes_to[i])) {
                neigh.push_back(other[goes_to[i]]);
            }
        }
    }
}

int match[100], rmatch[100];
bool vis[100];
bool make_match(int u, const vector< vector<int> > &L, const vector< vector<int> > &R) {
    vis[u] = true;
    const vector<int> &here = L[u];
    for (int i=0; i<(int)here.size(); ++i) {
        const int v = here[i];
        if (rmatch[v]==-1 || !vis[rmatch[v]] && make_match(rmatch[v], L, R)) {
            match[u] = v;
            rmatch[v] = u;
            return true;
        }
    }
    return false;
}
int bipartite_match(const vector< vector<int> > &L, const vector< vector<int> > &R) {
    memset(match, 0xff, sizeof match);
    memset(rmatch, 0xff, sizeof rmatch);
    int sol = 0;
    for (int i=0; i<(int)L.size(); ++i) {
        memset(vis, 0, sizeof vis);
        sol += make_match(i, L, R);
    }
    return sol;
}
class MallSecurity {
	public:
	int maxGuards(int n, vector <string> escDescription) {
        N = n;
		string s = accumulate(escDescription.begin(), escDescription.end(), string());
        
        vector<string> t = cutUp(s, ",");
        E.clear();
        for (int i=0; i<(int)t.size(); ++i) {
            tri tmp(0, 0, 0);
            sscanf(t[i].c_str(), "%d %d %d", &tmp.a, &tmp.b, &tmp.c);
            E.push_back(tmp);
        }

        edges.clear();
        memset(K, 0, sizeof K);
        for (int i=0; i<(int)E.size(); ++i) {
            if (E[i].c == N) {
                K[N] = max(K[N], E[i].a);
                K[1] = max(K[1], E[i].b);
                const pair<int, int> p1(N, E[i].a);
                const pair<int, int> p2(1, E[i].b);
                edges[p1].push_back(p2);
                edges[p2].push_back(p1);
            } else {
                K[E[i].c] = max(K[E[i].c], E[i].a);
                K[E[i].c + 1] = max(K[E[i].c + 1], E[i].b);
                const pair<int, int> p1(E[i].c, E[i].a);
                const pair<int, int> p2(E[i].c + 1, E[i].b);
                edges[p1].push_back(p2);
                edges[p2].push_back(p1);
            }
        }
        
        int sol = 0;
        if (N & 1) {
            int m_ind = 1;
            for (int i=2; i<=N; ++i) {
                if (K[i] < K[m_ind]) {
                    m_ind = i;
                }
            }
            const int k = K[m_ind];
            
            bc[0] = 0;
            for (int i=1; i<(1<<k); ++i) {
                bc[i] = bc[i>>1] + (i&1);
            }
            
            for (int mask=0; mask<(1<<k); ++mask) {
                set< pair<int, int> > F;
                for (int j=0; j<k; ++j) {
                    if (mask & (1<<j)) {
                        F.insert(edges[make_pair(m_ind, j + 1)].begin(), edges[make_pair(m_ind, j + 1)].end());
                    }
                }
                map< pair<int, int>, int > ind[2];
                int cur[2] = {0};
                int t = 0;
                for (int i=m_ind-1; i>0; --i) {
                    for (int j=1; j<=K[i]; ++j) {
                        if (!F.count(make_pair(i, j))) {
                            ind[t][make_pair(i, j)] = cur[t]++;
                        }
                    }
                    side[i] = t;
                    t = 1-t;
                }
                for (int i=N; i>m_ind; --i) {
                    for (int j=1; j<=K[i]; ++j) {
                        if (!F.count(make_pair(i, j))) {
                            ind[t][make_pair(i, j)] = cur[t]++;
                        }
                    }
                    side[i] = t;
                    t = 1-t;
                }
                
                vector< vector<int> > L(cur[0]), R(cur[1]);
                upd(L, ind[0], ind[1], edges);
                upd(R, ind[1], ind[0], edges);
                int vert = cur[0] + cur[1];
                sol = max(sol, vert + bc[mask] - bipartite_match(L, R));
            }
        } else {
            map< pair<int, int>, int > ind[2];
            int cur[2] = {0};
            int t = 0;
            for (int i=1; i<=N; ++i) {
                for (int j=1; j<=K[i]; ++j) {
                    ind[t][make_pair(i, j)] = cur[t]++;
                }
                side[i] = t;
                t = 1-t;
            }
            
            vector< vector<int> > L(cur[0]), R(cur[1]);
            upd(L, ind[0], ind[1], edges);
            upd(R, ind[1], ind[0], edges);
            int vert = cur[0] + cur[1];
            sol = max(sol, vert - bipartite_match(L, R));
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; string Arr1[] = {"1 1 1,1 1 2,1 1 3,1 1 4,1 1 5,1 1 6,1 1 7,1 1 8,1 ", 
 "1 9,1 1 10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(0, Arg2, maxGuards(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 11; string Arr1[] = {"1 1 1,1 1 2,1 1 3,1 1 4,1 1 5,1 1 6,1 1 7,1 1 8,1 ", 
 "1 9,1 1 10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(1, Arg2, maxGuards(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; string Arr1[] = {"1 1 7,1 2 9,2 1", 
 " 8,1 2 6,1 1 8,1 2 3,1 2 2,2 ", 
 "2 4,1 1 1,2 1 2,3 2 3,1 1 5,2 1 1,4 ", 
 "1 7,1 1 10,3 2 5,1 2 5,3 3 1,", 
 "3 2 8,3 1 2,1 1 3,4 4 2,2", 
 " 4 6,4 2 5,2 3 3,6 4 1,5 2 8,1 3 6,1 3 7,", 
 "4 3 8,1 3 8,5 2 3,4 2 8,2 6 7,1 3 9,", 
 "1 1 4,6 1 1,2 3 1,5 1 5,6 1 8,5 ", 
 "2 2,3 2 10,3 3 9,1 5 2,4 1 1,1 5 10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25; verify_case(2, Arg2, maxGuards(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MallSecurity ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
