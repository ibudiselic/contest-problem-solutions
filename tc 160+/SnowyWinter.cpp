#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

class SnowyWinter {
	public:
	int snowyHighwayLength(vector <int> a, vector <int> b) {
	    map<int, int> M;
        for (int i=0; i<(int)a.size(); ++i) {
            ++M[a[i]];
            --M[b[i]];
        }

        int x = 0;
        int last = 0;
        int sol = 0;
        for (map<int, int>::const_iterator it=M.begin(); it!=M.end(); ++it) {
            bool u = (x > 0);
            x += it->second;
            bool v = (x > 0);

            if (!u && v) {
                last = it->first;
            } else if (u && !v) {
                sol += it->first - last;
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {17,85,57}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {33,86,84}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 44; verify_case(0, Arg2, snowyHighwayLength(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {45,100,125,10,15,35,30,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {46,200,175,20,25,45,40,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 132; verify_case(1, Arg2, snowyHighwayLength(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4387,711,2510,1001,4687,3400,5254,584,284,1423,3755,929,2154,5719,1326,2368,554}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7890,5075,2600,6867,7860,9789,6422,5002,4180,7086,8615,9832,4169,7188,9975,8690,1423}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9691; verify_case(2, Arg2, snowyHighwayLength(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {4906,5601,5087,1020,4362,2657,6257,5509,5107,5315,277,6801,2136,2921,5233,5082,497,8250,3956,5720}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4930,9130,9366,2322,4687,4848,8856,6302,5496,5438,829,9053,4233,4119,9781,8034,3956,9939,4908,5928}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9510; verify_case(3, Arg2, snowyHighwayLength(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {51,807,943,4313,8319,3644,481,220,2161,448,465,1657,6290,22,6152,647,3185,4474,2168}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1182,912,1832,7754,9557,7980,4144,3194,7129,5535,1172,2043,6437,7252,9508,4745,8313,8020,4017}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9535; verify_case(4, Arg2, snowyHighwayLength(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {8786,7391,201,4414,5822,5872,157,1832,7487,7518,2267,1763,3984,3102,7627,4099,524,1543,1022,3060}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9905,7957,3625,6475,9314,9332,4370,8068,8295,8177,7772,2668,7191,8480,9211,4802,2625,1924,9970,4180}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9813; verify_case(5, Arg2, snowyHighwayLength(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SnowyWinter ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
