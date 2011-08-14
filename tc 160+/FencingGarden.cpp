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

long long temp[1<<20];
long long ctz[1<<20]; // count of trailing zeros

// computes all posible subset sums of v and sorts them
vector<long long> compute(const vector<int> &v) {
    const int n = v.size();
    vector<long long> ret;
    temp[0] = 0;
    ret.push_back(0);
    for (unsigned i=1; i<(1u<<n); ++i) {
        temp[i] = temp[i ^ (i&(-i))] + v[ctz[i]];
        ret.push_back(temp[i]);
    }
    
    sort(ret.begin(), ret.end());
    ret.resize(unique(ret.begin(), ret.end()) - ret.begin());
    return ret;
}

// maximal value of x = a[i]+b[j] such that x <= T/factor
long long max_calc(const vector<long long> &a, const vector<long long> &b, long long factor, long long T) {
    long long ret = 0;
    int aa = 0;
    int bb = (int)b.size()-1;
    
    while (aa<(int)a.size() && bb>=0) {
        const long long cur = a[aa] + b[bb];
        if (factor*cur <= T) {
            ret = max(ret, cur);
            ++aa;
        } else {
            --bb;
        }
    }
    return ret;
}
// minimal value of x = a[i]+b[j] such that x >= T/factor
long long min_calc(const vector<long long> &a, const vector<long long> &b, long long factor, long long T) {
    long long ret = a.back() + b.back();
    if (ret*factor < T) {
        return 0;
    }
    int aa = 0;
    int bb = (int)b.size()-1;
    
    while (aa<(int)a.size() && bb>=0) {
        const long long cur = a[aa] + b[bb];
        if (factor*cur >= T) {
            ret = min(ret, cur);
            --bb;
        } else {
            ++aa;
        }
    }
    return ret;
}
// x is the |_____| vertical part of the fence
void upd_vert(long long &sol, long long &area, long long T, long long x) {
    const long long new_area = 2*x*(T-2*x);
    if (new_area>area || new_area==area && (T-2*x)>sol) {
        area = new_area;
        sol = T - 2*x;
    }
}
// x is the |_____| horizontal part of the fence
void upd_horiz(long long &sol, long long &area, long long T, long long y) {
    const long long new_area = y*(T-y);
    if (new_area>area || new_area==area && y>sol) {
        area = new_area;
        sol = y;
    }
}
    
class FencingGarden {
	public:
	long long computeWidth(vector <int> segment) {
        for (int i=(1<<20)-1; i>0; --i) {
            ctz[i] = (i&1) ? 0 : ctz[i | ((i & (-i))>>1)] + 1;
        }
        // key observation: one of the 3 fence segments is made up of only whole segment elements (because cutting produces 2 pieces)
        // area is v*(T-2*v) if v is the length of the vertical part => max value is achieved at v = T/4 and h = T/2
        const int n = segment.size();
        const long long T = accumulate(segment.begin(), segment.end(), 0LL);
		vector<long long> a = compute(vector<int>(segment.begin(), segment.begin() + n/2));
        vector<long long> b = compute(vector<int>(segment.begin()+n/2, segment.end()));
        
        long long sol = 0;
        long long area = 0;
        // assume a vertical part is made up of whole segment elements
        // find a subset sum for v (near T/4 - either above or below)
        upd_vert(sol, area, T, max_calc(a, b, 4, T));
        upd_vert(sol, area, T, min_calc(a, b, 4, T));
        // assume the horizontal part is made up of whole segment elements
        // find a subset sum for h (near T/2 - either above or below)
        upd_horiz(sol, area, T, max_calc(a, b, 2, T));
        upd_horiz(sol, area, T, min_calc(a, b, 2, T));
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1,1,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 8LL; verify_case(0, Arg1, computeWidth(Arg0)); }
	void test_case_1() { int Arr0[] = {50,25,25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 50LL; verify_case(1, Arg1, computeWidth(Arg0)); }
	void test_case_2() { int Arr0[] = {5,7,9,13,21,581,1848,1058,57172,58281,612,528}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 60078LL; verify_case(2, Arg1, computeWidth(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FencingGarden ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
