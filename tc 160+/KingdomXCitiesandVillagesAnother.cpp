#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

long long best[50];
inline long long sqr(long long x) { return x*x; }
long long dist2(long long x1, long long y1, long long x2, long long y2) {
    return sqr(x2-x1) + sqr(y2-y1);
}
bool done[50];
const long long inf = 12345678901234567LL;
class KingdomXCitiesandVillagesAnother {
	public:
	double determineLength(vector <int> cX, vector <int> cY, vector <int> vX, vector <int> vY) {
		int C = cX.size();
        int V = vX.size();
        
        priority_queue< pair<long long, int> > PQ;
        memset(done, 0, sizeof done);
        for (int i=0; i<V; ++i) {
            best[i] = inf;
            for (int j=0; j<C; ++j) {
                best[i] = min(best[i], dist2(vX[i], vY[i], cX[j], cY[j]));
            }
            PQ.push(make_pair(-best[i], i));
        }
        
        double sol = 0.0;
        int cnt_done = 0;
        while (cnt_done < V) {
            assert(PQ.size() > 0);
            pair<long long, int> tmp = PQ.top();
            PQ.pop();
            long long d = -tmp.first;
            int i = tmp.second;
            if (done[i]) {
                continue;
            }
            ++cnt_done;
            done[i] = true;
            sol += sqrt(d);
            
            for (int j=0; j<V; ++j) {
                if (j!=i && !done[j]) {
                    d = dist2(vX[i], vY[i], vX[j], vY[j]);
                    if (d < best[j]) {
                        best[j] = d;
                        PQ.push(make_pair(-d, j));
                    }
                }
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 2.0; verify_case(0, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 2.0; verify_case(1, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 2.8284271247461903; verify_case(2, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    KingdomXCitiesandVillagesAnother ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
