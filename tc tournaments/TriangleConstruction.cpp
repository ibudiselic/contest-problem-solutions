#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class TriangleConstruction {
	public:
	int greatestPerimeter(vector <int> lengths) {
		sort(lengths.begin(), lengths.end());

		int sol = -1;
		for (int i=0; i<(int)lengths.size(); ++i)
			for (int j=i+1; j<(int)lengths.size(); ++j)
				for (int k=j+1; k<(int)lengths.size(); ++k)
					if (lengths[i] + lengths[j] > lengths[k])
						sol = max(sol, lengths[i] + lengths[j] + lengths[k]);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, greatestPerimeter(Arg0)); }
	void test_case_1() { int Arr0[] = {2,3,2,3,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(1, Arg1, greatestPerimeter(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, greatestPerimeter(Arg0)); }
	void test_case_3() { int Arr0[] = {4, 5, 6, 7, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; verify_case(3, Arg1, greatestPerimeter(Arg0)); }
	void test_case_4() { int Arr0[] = {214, 108, 273, 467, 991, 434, 767, 659}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2417; verify_case(4, Arg1, greatestPerimeter(Arg0)); }
	void test_case_5() { int Arr0[] = {116, 373, 471, 540, 350, 318, 804, 561, 428, 915, 64, 853, 498, 600, 439, 732, 139, 497, 512, 510, 796}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2572; verify_case(5, Arg1, greatestPerimeter(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TriangleConstruction ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
