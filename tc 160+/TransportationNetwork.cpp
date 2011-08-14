#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

bool done[150];
double RC[150][150];
double C[150];
vector<int> X, Y;
int N;
double calc2(double ac) {
    memset(done, 0, sizeof done);
    int n = N;
    done[0] = 1;
    priority_queue< pair<double, int> > PQ;
    for (int i=1; i<n; ++i) {
        C[i] = RC[0][i];
        PQ.push(make_pair(-C[i], i));
    }
    
    --n;
    double cost = ac;
    while (n > 0) {
        double d = -PQ.top().first;
        int p = PQ.top().second;
        PQ.pop();
        if (done[p]) {
            continue;
        }
        cost += min(d, ac);
        done[p] = 1;
        --n;
        for (int i=1; i<N; ++i) {
            if (!done[i] && RC[p][i]<C[i]) {
                C[i] = RC[p][i];
                PQ.push(make_pair(-C[i], i));
            }
        }
    }
    return cost;
}
double calc(double ac) {
    memset(done, 0, sizeof done);
    int n = N;
    done[0] = 1;
    priority_queue< pair<double, int> > PQ;
    for (int i=1; i<n; ++i) {
        C[i] = RC[0][i];
        PQ.push(make_pair(-C[i], i));
    }
    
    --n;
    double roads = 0.0;
    while (n > 0) {
        double d = -PQ.top().first;
        int p = PQ.top().second;
        PQ.pop();
        if (done[p]) {
            continue;
        }
        roads += d;
        done[p] = 1;
        --n;
        for (int i=1; i<N; ++i) {
            if (!done[i] && RC[p][i]<C[i]) {
                C[i] = RC[p][i];
                PQ.push(make_pair(-C[i], i));
            }
        }
    }
    return min(roads, calc2(ac));
}
double dist(int a, int b, int c, int d) {
    return sqrt(double(a-c)*(a-c) + double(b-d)*(b-d));
}

class TransportationNetwork {
	public:
	double minCost(vector <int> cityX, vector <int> cityY, double roadCost, double airportCost) {
        X = cityX;
        Y = cityY;
        N = cityX.size();
        for (int i=0; i<N; ++i) {
            for (int j=i+1; j<N; ++j) {
                RC[i][j] = RC[j][i] = dist(cityX[i], cityY[i], cityX[j], cityY[j]) * roadCost;
            }
        }
        
        return calc(airportCost);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 400, 400}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 100, 0, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; double Arg3 = 150.0; double Arg4 = 500.0; verify_case(0, Arg4, minCost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0, 0, 400, 400, 2000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 100, 0, 100, 2000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; double Arg3 = 500; double Arg4 = 1600.0; verify_case(1, Arg4, minCost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0, 100, 200, 300, 400,2000,2100,2200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 100, 200, 300, 400,2000,2100,2200}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.5; double Arg3 = 200; double Arg4 = 824.2640687119285; verify_case(2, Arg4, minCost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {798, 915, 797, 463, 895, 523, 959, 702, 235, 523}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {126, 25, 402, 45, 841, 762, 982, 605, 616, 78}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.66; double Arg3 = 300; double Arg4 = 2727.2895312339606; verify_case(3, Arg4, minCost(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TransportationNetwork ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
