#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int saver1 = 20;
const int savec1 = 50;
const int saver2 = 39;
const int savec2 = 99;
vector<int> sol;
int inside(int r, int c)
{
  return (r>=saver1 && r<=saver2 && c>=savec1 && c<=savec2);
}
class grafixClick {
   public:
   vector <int> checkSaveButton(vector <int> mouseRows, vector <int> mouseCols) {
     for (int i=0; i<mouseRows.size(); ++i)
       if (inside(mouseRows[i], mouseCols[i]))
         sol.push_back(i);
     return sol;    
   }







   
// BEGIN CUT HERE 
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {20, 39, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {99, 50, 200}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0,  1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, checkSaveButton(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 100, 399}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 200, 599}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, checkSaveButton(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {75}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, checkSaveButton(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {10, 20, 30, 30, 30, 30, 34, 35, 345}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 20, 30, 50, 60, 80, 34, 35, 345}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 3,  4,  5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, checkSaveButton(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {57, 28, 18, 25, 36, 12, 33, 44, 13, 32,
 32, 51, 11, 27, 8, 51, 17, 34, 10, 16,
 47, 57, 20, 57, 32, 14, 13, 37, 10, 16,
 49, 37, 52, 8, 18, 44, 50, 43, 11, 1,
 21, 22, 17, 35, 28, 53, 56, 16, 11, 44}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {146, 22, 41, 88, 123, 99, 43, 110, 25, 64,
 141, 110, 70, 34, 99, 103, 60, 64, 142, 109,
 133, 144, 72, 68, 25, 32, 21, 140, 30, 105,
 32, 72, 114, 97, 35, 131, 103, 110, 133, 81,
 125, 36, 76, 78, 77, 47, 50, 94, 22, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 3,  9,  17,  22,  31,  43,  44 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, checkSaveButton(Arg0, Arg1)); }

// END CUT HERE 
 
};

// BEGIN CUT HERE 
int main()
    {
    grafixClick ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE 
