#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool beats(int a, int b, bool advLeft) {
	if (a>=90 && b<=90)
		return false;
	else if (a>=90 && b>90)
		return b > a;
	else if (a<90 && b<=90)
		return false;
	else
		return a > 180-b || (advLeft && a==180-b);
}
bool loses(int a, int b, bool advLeft) {
	if (a>=90 && b<=90)
		return false;
	else if (a>=90 && b>90)
		return false;
	else if (a<90 && b<=90)
		return a < b;
	else
		return a < 180-b || (!advLeft && a==180-b);
}

class Crossings {
	public:
	vector <int> getOut(vector <int> positions, vector <int> angles) {
		vector<int> orig;
		for (int i=0; i<(int)positions.size(); ++i)
			orig.push_back(i);

		for (int i=0; i<(int)positions.size()-1; ++i)
			for (int j=i+1; j<(int)positions.size(); ++j)
				if (positions[i] > positions[j]) {
					swap(positions[i], positions[j]);
					swap(angles[i], angles[j]);
					swap(orig[i], orig[j]);
				}

		vector<int> cars;
		for (int i=0; i<(int)angles.size(); ++i)
			cars.push_back(i);

		for (int dist=0; dist<=1000000; ++dist) {
		int cnt = cars.size()+1;
		while (cnt--)
		for (int i=0; i<(int)cars.size()-1; ++i)
		if (abs(positions[cars[i+1]]-positions[cars[i]]) == dist)
			if (beats(angles[cars[i]], angles[cars[i+1]], (orig[cars[i]] < orig[cars[i+1]]))) {
				cars.erase(cars.begin()+i+1);
			} else if (loses(angles[cars[i]], angles[cars[i+1]], (orig[cars[i]] < orig[cars[i+1]]))) {
				cars.erase(cars.begin()+i);
				--i;
			}
		}

		vector<int> sol;
		for (int i=0; i<(int)cars.size(); ++i)
			sol.push_back(orig[cars[i]]);

		sort(sol.begin(), sol.end());
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {0, 40, 20, 10, 30, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {105, 40, 30, 75, 135, 75}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0,  3,  5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getOut(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 40, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {40, 40, 140}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0,  1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getOut(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {89, 91}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getOut(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Crossings ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
