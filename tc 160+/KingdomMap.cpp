#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

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

struct Edge {
    int to, id;
    Edge(int to_, int id_): to(to_), id(id_) {}
};

vector< vector<Edge> > G;
bool dead[2500];
bool v[300];
int N;

// 0 - separate caterpillar 
// 1 - leaf (num children + make each child separate caterpillar)
// 2 - caterpillar connected to leaf parent (choose max 2 children to be caterpillar connected to nonleaf parent, others leaf or disconnect and separate caterpillar)
// 3 - caterpillar connected to nonleaf parent (choose max 1 child to be caterpillar connected to nonleaf parent, others leaf or disconnect and separate caterpillar)
vector<int> calc(int at, int p) { 
    assert(v[at] == false);
    v[at] = true;
    
    int ignore_all = 0;
    int imp1 = 0, imp2 = 0, imp3 = 0;
    int make_leaf = 0;
    for (int i=0; i<(int)G[at].size(); ++i) {
        if (dead[G[at][i].id]) {
            continue;
        }
        const int to = G[at][i].to;
        if (to == p) {
            continue;
        }
        
        const vector<int> t = calc(to, at);
        int ignore = min(t[1], t[0] + 1); // leaf or disconnect and separate caterpillar
        ignore_all += ignore;
        int imp = ignore - t[3];
        if (imp > imp1) {
            imp2 = imp1;
            imp1 = imp;
        } else if (imp > imp2) {
            imp2 = imp;
        }
        
        make_leaf += t[0] + 1;
        imp3 = max(imp3, t[0] + 1 - t[2]);
    }
    
    vector<int> ret(4, 0);
    ret[1] = make_leaf;
    ret[2] = ignore_all - imp1 - imp2;
    ret[3] = ignore_all - imp1;
    ret[0] = min(ret[2], make_leaf - imp3);
    
    return ret;
}
int go() {
    memset(v, 0, sizeof v);
    int ret = 0;
    for (int i=0; i<N; ++i) {
        if (!v[i]) {
            ret += calc(i, -1)[0];
        }
    }
    return ret;
}

class KingdomMap {
	public:
	vector <int> getRoadsToRemove(int n, vector <string> roads) {
        if (roads.size() == 0) {
            return vector<int>();
        }
        
        N = n;
        
        {
            string s = roads[0];
            for (int i=1; i<(int)roads.size(); ++i) {
                s += roads[i];
            }
            
            G.assign(n, vector<Edge>());
            const vector<string> ss = cutUp(s, ",");
            for (int i=0; i<(int)ss.size(); ++i) {
                int x, y;
                sscanf(ss[i].c_str(), "%d %d", &x, &y);
                G[x].push_back(Edge(y, i));
                G[y].push_back(Edge(x, i));
            }
        }

        memset(dead, 0, sizeof dead);
        int cost = go();
        vector<int> sol;
        int cand = 0;
        while (cost > 0) {
            dead[cand] = true;
            int ncost = go();
            if (ncost == cost) {
                dead[cand] = false;
            } else {
                assert(ncost == cost-1);
                --cost;
                sol.push_back(cand);
            }
            ++cand;
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; string Arr1[] = {"0 1,1 2,2 3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getRoadsToRemove(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; string Arr1[] = {"0 1,1 2,2 3,3 4,5 6,2 5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getRoadsToRemove(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 20; string Arr1[] = {"8 17,9 12,4 7,2 7,2 19,3 12,6 12,1 9,5 18,0 12,6 1", "6,0 11,3 14,10 15,12 13,13 18,13 19,15 17,15 19"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 3, 5, 14 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getRoadsToRemove(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getRoadsToRemove(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    KingdomMap ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
