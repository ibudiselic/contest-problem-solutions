#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>
#include <queue>
#include <set>

using namespace std;

/*
struct State {
    int u, timeslot;
    long long t;
    State(int u_, int timeslot_, long long t_): u(u_), timeslot(timeslot_), t(t_) {}
};
bool operator<(const State &a, const State &b) {
    if (a.t != b.t) {
        return a.t > b.t;
    } else if (a.u != b.u) {
        return a.u < b.u;
    } else {
        return a.timeslot < b.timeslot;
    }
}

long long dist[20][20];
const long long inf = 12345679814567LL;
vector<int> S, E;
long long get_to[20][21];
int timeslots;
int end_time(int timeslot) {
    return timeslot==0 ? 0 : E[timeslot-1];
}
int N;
bool forward_done[20][21];
long long forward_memo[20][21][20];
long long forward(int u, int timeslot, int v) { // earliest time that you can reach v from basic state (u, timeslot)
    if (forward_done[u][timeslot]) {
        return forward_memo[u][timeslot][v];
    }
    forward_done[u][timeslot] = true;
    
    priority_queue< pair<long long, int> > PQ;
    PQ.push(make_pair(-end_time(timeslot), u));
    forward_memo[u][timeslot][u] = end_time(timeslot);
    while (!PQ.empty()) {
        const pair<long long, int> tmp = PQ.top();
        PQ.pop();
        long long t = -tmp.first;
        int w = tmp.second;
        if (t > forward_memo[u][timeslot][w]) {
            continue;
        }
        
        int end_ind = upper_bound(E.begin(), E.end(), t) - E.begin();
        if (end_ind == (int)E.size()) {
            continue;
        }

        for (int k=0; k<N; ++k) {
            if (t+dist[w][k] >= forward_memo[u][timeslot][k]) {
                continue;
            }
            int i = end_ind;
            while (i<(int)E.size() && dist[w][k]>E[i]-max(t, (long long)S[i])) {
                ++i;
            }
            if (i < (int)E.size()) {
                long long cand_t = max(t, (long long)S[i]) + dist[w][k];
                if (cand_t < forward_memo[u][timeslot][k]) {
                    forward_memo[u][timeslot][k] = cand_t;
                    PQ.push(make_pair(-cand_t, k));
                }
            }
        }
    }
    return forward_memo[u][timeslot][v];
}

bool backward_done[20][21];
long long backward_memo[20][21][20];
long long backward(int u, int timeslot, int v) { // latest time we must leave from v to get to basic state (u, timeslot)
    if (backward_done[u][timeslot]) {
        return backward_memo[u][timeslot][v];
    }
    backward_done[u][timeslot] = true;
    
    priority_queue< pair<long long, int> > PQ;
    PQ.push(make_pair(end_time(timeslot), u));
    backward_memo[u][timeslot][u] = end_time(timeslot);
    
    while (!PQ.empty()) {
        const pair<long long, int> tmp = PQ.top();
        PQ.pop();
        
        long long t = tmp.first;
        long long w = tmp.second;
        if (t < backward_memo[u][timeslot][w]) {
            continue;
        }
        
        int start_ind = lower_bound(S.begin(), S.end(), t) - S.begin();
        if (start_ind == 0) {
            continue;
        }
        --start_ind;
        
        for (int k=0; k<N; ++k) {
            if (t-dist[w][k] <= backward_memo[u][timeslot][k]) {
                continue;
            }
            int i = start_ind;
            while (i>=0 && dist[w][k]>min(t, (long long)E[i])-S[i]) {
                --i;
            }
            if (i >= 0) {
                long long cand_t = min(t, (long long)E[i]) - dist[w][k];
                if (cand_t > backward_memo[u][timeslot][k]) {
                    backward_memo[u][timeslot][k] = cand_t;
                    PQ.push(make_pair(cand_t, k));
                }
            }
        }
    }

    return backward_memo[u][timeslot][v];
}

long long sol1(int N_, vector <int> sunnyStart, vector <int> sunnyEnd, vector <string> roads, int machineStartTime) {
    N = N_;
    S = sunnyStart;
    E = sunnyEnd;
    timeslots = E.size() + 1;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            dist[i][j] = inf;
        }
    }
    string R = accumulate(roads.begin(), roads.end(), string());
    istringstream is(R);
    string s;
    while (is >> s) {
        int a, b, d;
        sscanf(s.c_str(), "%d,%d,%d", &a, &b, &d);
        dist[a][b] = dist[b][a] = d;
    }
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<timeslots; ++j) {
            for (int k=0; k<N; ++k) {
                forward_memo[i][j][k] = inf;
            }
        }
    }
    memset(forward_done, 0, sizeof forward_done);
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<timeslots; ++j) {
            for (int k=0; k<N; ++k) {
                backward_memo[i][j][k] = -inf;
            }
        }
    }
    memset(backward_done, 0, sizeof backward_done);
    
    priority_queue<State> PQ;
    PQ.push(State(0, 0, 0));
    for (int i=0; i<N; ++i) {
        for (int j=0; j<timeslots; ++j) {
            get_to[i][j] = inf;
        }
    }
    get_to[0][0] = 0;
    while (!PQ.empty()) {
        State s = PQ.top();
        PQ.pop();
        
        if (s.t > get_to[s.u][s.timeslot]) {
            continue;
        }
        
        for (int v=0; v<N; ++v) {
            long long forward_time = forward(s.u, s.timeslot, v);
            for (int timeslot2=0; timeslot2<timeslots; ++timeslot2) {
                long long cand = inf;
                if (forward_time <= end_time(timeslot2)) {
                    cand = s.t + end_time(timeslot2) - end_time(s.timeslot);
                }
                for (int w=0; w<N; ++w) {
                    long long fw = forward(s.u, s.timeslot, w);
                    long long bckw = backward(v, timeslot2, w);
                    if (fw<inf && bckw>=0 && fw>=bckw) {
                        cand = min(cand, s.t
                                         + (fw - end_time(s.timeslot))
                                         + machineStartTime + (fw - bckw)
                                         + (end_time(timeslot2) - bckw));
                    }
                }
                
                if (cand < get_to[v][timeslot2]) {
                    get_to[v][timeslot2] = cand;
                    PQ.push(State(v, timeslot2, cand));
                }
            }
        }
    }
    
    long long sol = inf;
    for (int u=0; u<N; ++u) {
        for (int timeslot=0; timeslot<timeslots; ++timeslot) {
            sol = min(sol, get_to[u][timeslot] + (forward(u, timeslot, N-1)-end_time(timeslot)));
        }
    }
    
    return sol==inf ? -1 : sol;
}*/

long long dist[20][20];
const long long inf = 123456789245LL;
long long key_times[20][1000];
long long cnt_times[20];
priority_queue< pair< long long, pair<int, int> > > PQ;
long long get_to[20][1000];
void pq_insert(int u, int tind, long long d) {
    if (d < get_to[u][tind]) {
        get_to[u][tind] = d;
        PQ.push(make_pair(-d, make_pair(u, tind)));
    }
}
long long sol2(int N, vector <int> S, vector <int> E, vector <string> roads, int machineStartTime) {
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            dist[i][j] = inf;
        }
        dist[i][i] = 0;
    }
    string R = accumulate(roads.begin(), roads.end(), string());
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
    
    for (int i=0; i<N; ++i) {
        set<long long> T;
        for (int j=0; j<(int)S.size(); ++j) {
            T.insert(S[j]);
            T.insert(E[j]);
        }
        for (int j=0; j<N; ++j) {
            if (i != j) {
                for (int k=0; k<(int)S.size(); ++k) {
                    if (S[k]+dist[i][j] < E[k]) {
                        T.insert(S[k] + dist[i][j]);
                    }
                    if (E[k]-dist[i][j] > S[k]) {
                        T.insert(E[k] - dist[i][j]);
                    }
                }
            }
        }
        cnt_times[i] = 0;
        for (set<long long>::const_iterator it=T.begin(); it!=T.end(); ++it) {
            key_times[i][cnt_times[i]++] = *it;
        }
    }
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<cnt_times[i]; ++j) {
            get_to[i][j] = inf;
        }
    }
    while (!PQ.empty()) {
        PQ.pop();
    }
    pq_insert(0, 0, 0);
    
    while (!PQ.empty()) {
        const pair<long long, pair<int, int> > tmp = PQ.top();
        PQ.pop();
        int u = tmp.second.first;
        int tind = tmp.second.second;
        long long d = -tmp.first;
        
        if (d > get_to[u][tind]) {
            continue;
        }
        
        if (u == N-1) {
            return d + key_times[0][0];
        }
        int interval = upper_bound(E.begin(), E.end(), key_times[u][tind]) - E.begin();
        if (interval<(int)S.size() && S[interval]<=key_times[u][tind]) {
            for (int v=0; v<N; ++v) {
                if (v != u) {
                    if (key_times[u][tind]==S[interval] && S[interval]+dist[u][v]<=E[interval]
                            || key_times[u][tind]+dist[u][v]==E[interval]) {
                        int tind2 = lower_bound(key_times[v], key_times[v] + cnt_times[v], key_times[u][tind] + dist[u][v]) - key_times[v];
                        assert(key_times[v][tind2] == key_times[u][tind] + dist[u][v]);
                        pq_insert(v, tind2, d + dist[u][v]); // make a move to v
                    }
                }
            }
        }
        if (tind+1 < cnt_times[u]) { // wait at u
            pq_insert(u, tind+1, d + key_times[u][tind+1] - key_times[u][tind]);
        }
        for (int tind2=0; tind2<tind; ++tind2) {
            pq_insert(u, tind2, d + machineStartTime + key_times[u][tind] - key_times[u][tind2]);
        }
    }
    
    return -1;
}
class TimeTravellingGogo {
	public:
	long long determineTime(int N_, vector <int> sunnyStart, vector <int> sunnyEnd, vector <string> roads, int machineStartTime) {
        //return sol1(N_, sunnyStart, sunnyEnd, roads, machineStartTime);
        return sol2(N_, sunnyStart, sunnyEnd, roads, machineStartTime);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {0,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,12}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"0,1,3 1,2,3"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; long long Arg5 = 9LL; verify_case(0, Arg5, determineTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {0,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,12}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"0,1,3 1,2,4"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 18; long long Arg5 = 12LL; verify_case(1, Arg5, determineTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"0,1,2"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; long long Arg5 = -1LL; verify_case(2, Arg5, determineTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 3; int Arr1[] = {0,17}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {15,37}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"0,1,1","5"," 1,2,12 2,0,17"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 10; long long Arg5 = 29LL; verify_case(3, Arg5, determineTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TimeTravellingGogo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
