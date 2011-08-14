#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <set>

using namespace std;

const long long oo = 100000000000LL; // 10^11
void gen_sums(int p, long long cur, const vector<int> &v, vector<long long> &sums) {
    if (p == (int)v.size()) {
        sums.push_back(cur);
    } else {
        gen_sums(p+1, cur-v[p], v, sums);
        gen_sums(p+1, cur     , v, sums);
        gen_sums(p+1, cur+v[p], v, sums);
    }
}
void gen_cands(int p, vector<int> &v, vector< vector<int> > &cands) {
    if (p == (int)v.size()) {
        cands.push_back(v);
    } else {
        v[p] -= 4;
        for (int i=0; i<9; ++i) {
            if (1<=v[p] && v[p]<=100000000) {
                gen_cands(p+1, v, cands);
            }
            ++v[p];
        }
        v[p] -= 5;
    }
}
class BalancingAct {
	public:
	vector <string> recover(vector <int> labeled, vector <int> unlabeled) {
	    vector<int> a, b;
        for (int i=0; i<(int)labeled.size(); ++i) {
            if (i&1) {
                b.push_back(labeled[i]);
            } else {
                a.push_back(labeled[i]);
            }
        }
        vector<long long> aa, bb;
        gen_sums(0, 0, a, aa);
        gen_sums(0, 0, b, bb);
        bb.push_back(-oo);
        bb.push_back(oo);
        sort(aa.begin(), aa.end());
        sort(bb.begin(), bb.end());
        aa.resize(unique(aa.begin(), aa.end()) - aa.begin());
        bb.resize(unique(bb.begin(), bb.end()) - bb.begin());
        
        vector<long long> L;
        gen_sums(0, 0, unlabeled, L);
        int n = L.size();
        vector< pair<long long, long long> > bounds; // inclusive
        for (int i=0; i<n; ++i) {
            pair<long long, long long> tmp(-oo, oo);
            for (int j=0; j<(int)aa.size(); ++j) {
                vector<long long>::iterator it = lower_bound(bb.begin(), bb.end(), L[i] - aa[j]);
                if (aa[j] + *it == L[i]) {
                    tmp.first = tmp.second = L[i];
                    break;
                } else {
                    tmp.second = min(tmp.second, aa[j]+*it-1);
                    --it;
                    tmp.first = max(tmp.first, aa[j]+*it+1);
                }
            }
            bounds.push_back(tmp);
        }
        
        vector< vector<int> > candidates;
        gen_cands(0, unlabeled, candidates);
        vector< set<int> > possible_values(unlabeled.size());
        for (int i=0; i<(int)candidates.size(); ++i) {
            vector<long long> tmp;
            gen_sums(0, 0, candidates[i], tmp);
            assert(tmp.size() == n);
            bool valid = true;
            for (int j=0; j<n; ++j) {
                if (!(bounds[j].first<=tmp[j] && tmp[j]<=bounds[j].second)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                for (int j=0; j<(int)unlabeled.size(); ++j) {
                    possible_values[j].insert(candidates[i][j]);
                }
            }
        }
        
        vector<string> sol;
        for (int i=0; i<(int)unlabeled.size(); ++i) {
            sol.push_back(possible_values[i].size()==1 ? "yes" : "no");
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {9,13,15,16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {19}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"yes" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, recover(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"yes", "yes" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, recover(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {33333332,33333334}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {33333333,73,100000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"yes", "no", "yes" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, recover(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"yes", "yes", "yes", "yes" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, recover(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {31415926,5358979,32384626,43383279,50288419,
71693993,75105820,9749445,92307816,40628620,
89986280,34825342,11706798,21480865,13282306}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {64709384,46095505,82231725,35940812}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"no", "no", "no", "no" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, recover(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BalancingAct ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
