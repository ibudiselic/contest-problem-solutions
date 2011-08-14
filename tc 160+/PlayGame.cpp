#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class PlayGame {
	public:
	int saveCreatures(vector <int> you, vector <int> computer) {
		sort(computer.begin(), computer.end());
		sort(you.begin(), you.end());
		vector<bool> used(you.size(), 0);

		int sum = 0;
		for (int i=(int)you.size()-1; i>=0; --i) {
			int j = (int)computer.size()-1;
			while (used[j])
				--j;

			if (you[i] <= computer[j])
				for (int k=j-1; k>=0; --k)
					if (!used[k] && you[i]>computer[k]) {
						j = k;
						break;
					}

			used[j] = 1;
			if (computer[j] < you[i])
				sum += you[i];
		}

		return sum;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 15, 100, 1, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 15, 100, 1, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 120; verify_case(0, Arg2, saveCreatures(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, saveCreatures(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 99; verify_case(2, Arg2, saveCreatures(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 65; verify_case(3, Arg2, saveCreatures(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {651, 321, 106, 503, 227, 290, 915, 549, 660, 115,
 491, 378, 495, 789, 507, 381, 685, 530, 603, 394,
 7, 704, 101, 620, 859, 490, 744, 495, 379, 781,
 550, 356, 950, 628, 177, 373, 132, 740, 946, 609,
 29, 329, 57, 636, 132, 843, 860, 594, 718, 849}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {16, 127, 704, 614, 218, 67, 169, 621, 340, 319,
 366, 658, 798, 803, 524, 608, 794, 896, 145, 627,
 401, 253, 137, 851, 67, 426, 571, 302, 546, 225,
 311, 111, 804, 135, 284, 784, 890, 786, 740, 612,
 360, 852, 228, 859, 229, 249, 540, 979, 55, 82}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25084; verify_case(4, Arg2, saveCreatures(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PlayGame ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
