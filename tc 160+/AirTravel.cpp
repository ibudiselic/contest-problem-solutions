#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

//radius * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon1 - lon2))
double deg2rad(int x) {
	return x*M_PI/180.0;
}
double dist(int lat1_, int lon1_, int lat2_, int lon2_) {
	double lat1 = deg2rad(lat1_);
	double lon1 = deg2rad(lon1_);
	double lat2 = deg2rad(lat2_);
	double lon2 = deg2rad(lon2_);
	return 4000 * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon1 - lon2));
}
double D[20][20];
class AirTravel {
	public:
	double shortestTrip(vector <int> latitude, vector <int> longitude, vector <string> canTravel, int origin, int destination) {
		for (int i=0; i<20; ++i) {
			D[i][i] = 0.0;
			for (int j=i+1; j<20; ++j)
				D[i][j] = D[j][i] = 1e32;
		}

		int n = canTravel.size();
		for (int i=0; i<n; ++i) {
			istringstream is(canTravel[i]);
			int x;
			while (is >> x)
				D[i][x] = dist(latitude[i], longitude[i], latitude[x], longitude[x]);
		}

		for (int k=0; k<n; ++k)
			for (int i=0; i<n; ++i)
				for (int j=0; j<n; ++j)
					D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

		return D[origin][destination]<1e31 ? D[origin][destination] : -1.0;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 70}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {90, 0, 45}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2", "0 2", "0 1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arg4 = 1; double Arg5 = 10612.237799994255; verify_case(0, Arg5, shortestTrip(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {0, 0, 70}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {90, 0, 45}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 2", "0 2", "0 1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arg4 = 1; double Arg5 = 6283.185307179586; verify_case(1, Arg5, shortestTrip(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {0, 30, 60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {25, -130, 78}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 2", "0 2", "1 2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arg4 = 0; double Arg5 = 0.0; verify_case(2, Arg5, shortestTrip(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arr0[] = {0, 20, 55}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-20, 85, 42}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1", "0", "0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arg4 = 2; double Arg5 = -1.0; verify_case(3, Arg5, shortestTrip(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AirTravel ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
