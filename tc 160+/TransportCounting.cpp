#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class TransportCounting {
	public:
	int countBuses(int speed, vector <int> positions, vector <int> velocities, int time) {
		int sol = 0;

		for (int i=0; i<(int)positions.size(); ++i)
			if (positions[i]==0 || (speed*time >= positions[i]+time*velocities[i]))
				++sol;

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arg4 = 1; verify_case(0, Arg4, countBuses(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {10, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 1; verify_case(1, Arg4, countBuses(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {10, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 2; verify_case(2, Arg4, countBuses(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 777; int Arr1[] = {10,20,30,40,50,60,70,80,90,100,
110,120,130,140,150,160,170,180,190,200,
210,220,230,240,250,260,270,280,290,300,
310,320,330,340,350,360,370,380,390,400,
410,420,430,440,450,460,470,480,490,500}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,20,30,40,50,60,70,80,90,100,
110,120,130,140,150,160,170,180,190,200,
210,220,230,240,250,260,270,280,290,300,
310,320,330,340,350,360,370,380,390,400,
410,420,430,440,450,460,470,480,490,500}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 333; int Arg4 = 50; verify_case(3, Arg4, countBuses(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = {0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,5,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; int Arg4 = 3; verify_case(4, Arg4, countBuses(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TransportCounting ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
