#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long dist2(long long x1, long long y1, long long x2, long long y2) {
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}
class KingdomXCitiesandVillages {
	public:
	double determineLength(vector <int> cityX, vector <int> cityY, vector <int> villageX, vector <int> villageY) {
	    int C = cityX.size();
        int V = villageX.size();
        double sol = 0.0;
        for (int i=0; i<V; ++i) {
            vector< pair<long long, int> > cands;
            for (int j=0; j<C; ++j) {
                cands.push_back(make_pair(dist2(cityX[j], cityY[j], villageX[i], villageY[i]), 0));
            }
            for (int j=0; j<V; ++j) {
                if (j != i) {
                    cands.push_back(make_pair(dist2(villageX[j], villageY[j], villageX[i], villageY[i]), 1));
                }
            }
            sort(cands.begin(), cands.end());
            int j = 0;
            double p = 0.0;
            while (cands[j].second == 1) {
                sol += sqrt(cands[j].first)/(j+1)/(j+2);
                p += 1.0/(j+1)/(j+2);
                ++j;
            }
            sol += (1.0-p) * sqrt(cands[j].first);
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 2.5; verify_case(0, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1,4,7,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,5,5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,4,7,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4,4,4,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 4.0; verify_case(1, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,4,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,5,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4,4,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 4.166666666666667; verify_case(2, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    KingdomXCitiesandVillages ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
