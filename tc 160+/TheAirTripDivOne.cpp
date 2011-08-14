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
#include <utility>

using namespace std;

int n;
long long time_limit;
long long safety;
vector<int> F[500][500], P[500][500], T[500][500];
long long best[500];
bool can_do_it() {
    priority_queue< pair<long long, int> > PQ;
    PQ.push(make_pair(safety, 0));
    memset(best, 0xff, sizeof best);
    best[0] = -safety;
    while (!PQ.empty()) {
        long long cur_t = -PQ.top().first;
        int at = PQ.top().second;
        PQ.pop();
        if (cur_t > best[at]) {
            continue;
        }
        
        long long safe_time = cur_t + safety;
        if (safe_time > time_limit) {
            return false;
        }
        for (int next=0; next<n; ++next) {
            for (int i=0; i<(int)F[at][next].size(); ++i) {
                const int f = F[at][next][i];
                const int p = P[at][next][i];
                const int t = T[at][next][i];
                long long go_off_time;
                if (safe_time <= f) {
                    go_off_time = f;
                } else {
                    go_off_time = f + (safe_time-f+p-1)/p*p;
                }
                long long land_time = go_off_time + t;
                if (land_time > time_limit) {
                    continue;
                }
                if (next == n-1) {
                    return true;
                }
                if (best[next]==-1 || best[next]>land_time) {
                    best[next] = land_time;
                    PQ.push(make_pair(-land_time, next));
                }
            }
        }
    }
    
    return false;
}
class TheAirTripDivOne {
	public:
	int find(int n, vector <string> flights, int time) {
		string s = accumulate(flights.begin(), flights.end(), string());
        ::n = n;
        istringstream is(s);
        string tmp;
        time_limit = time;
        while (is >> tmp) {
            int a, b, f, t, p;
            sscanf(tmp.c_str(), "%d,%d,%d,%d,%d", &a, &b, &f, &t, &p);
            --a;
            --b;
            F[a][b].push_back(f);
            T[a][b].push_back(t);
            P[a][b].push_back(p);
        }
        
        safety = 1;
        if (!can_do_it()) {
            return -1;
        }
        
        int lo=1, hi=time;
        while (lo < hi) {
            safety = lo + (hi-lo+1)/2;
            if (can_do_it()) {
                lo = safety;
            } else {
                hi = safety-1;
            }
        }
        
        return lo;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"1,2,1,4,7 ", "2,3,9,1,10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; int Arg3 = 14; verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; string Arr1[] = {"1,2,1,1,1 2,3,2,1,98"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = -1; verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 477; string Arr1[] = {"47,74,1,1,1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; int Arg3 = -1; verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 7; string Arr1[] = {"1,3,15,17,11 1,3,14,16,14 5,7,12,18,18 1,6,13,1", 
 "6,12 1,2,18,14,13 5,6,10,10,18 3,1,10,10,10 1,3",
 ",17,16,10 2,3,16,18,16 6,1,15,12,10 2,1,15,18,1",
 "0 4,7,10,16,15 6,3,10,14,10 1,6,19,19,15 1,4,12",
 ",10,14 4,7,10,18,14 2,3,16,12,12 1,3,14,10,19 3",
 ",7,17,10,12 2,1,14,12,16 4,3,19,11,12 1,6,10,18",
 ",12 2,3,16,12,10 6,2,10,18,12 5,1,14,18,12 5,1,",
 "18,10,10 3,2,19,15,10 7,4,16,19,14 6,3,16,12,10",
 " 5,7,14,13,13 1,3,12,10,16 5,7,16,18,15 6,2,18,",
 "12,14 3,2,10,18,16 4,2,18,18,14 1,5,10,18,16 2,",
 "3,10,19,16 1,4,11,18,15 2,1,15,15,14 7,2,10,12,",
 "10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 74; int Arg3 = 33; verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 7; string Arr1[] = {"1,4,10,8,2 4,6,14,8,2 6,2,8,1",
 "0,1 2,7,19,5,1 ",
 "1,5,15,17,11 5,3,10,1",
 "0,18 3,7,12,18,18"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 147; int Arg3 = 35; verify_case(4, Arg3, find(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheAirTripDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
