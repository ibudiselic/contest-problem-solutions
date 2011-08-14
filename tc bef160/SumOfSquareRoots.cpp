#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <map>
#include <sstream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

enum {
  MAXF = 32
};
vector <int> sol;
map<int, int> dict;
int sqr(int a)
{
  return a*a;
}
void ex_facts(int x)
{
  vector<int> found;
  bool flag=false;

  for (int i=MAXF; i>=2 && x>1; --i)
    while (x%sqr(i)==0) {
      found.push_back(i);
      x /= sqr(i);
    }
  for (int i=0; i<found.size(); ++i) {
    flag = true;
    dict[x] += found[i];
  }
  if (!flag)
    ++dict[x];
  
}
class SumOfSquareRoots {
  public:
  vector <int> shortestList(vector <int> A) {
    for (int i=0; i<A.size(); ++i) {
      ex_facts(A[i]);
    }
    for (map<int, int>::const_iterator i=dict.begin(); i!=dict.end(); ++i) {
      sol.push_back(i->first * sqr(i->second));
    }
    sort(sol.begin(), sol.end());
    return sol;
  }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {12, 48}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 108 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, shortestList(Arg0)); }
	void test_case_1() { int Arr0[] = {9, 16, 25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 144 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, shortestList(Arg0)); }
	void test_case_2() { int Arr0[] = {4, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 3,  4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, shortestList(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 1, 1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 9 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, shortestList(Arg0)); }
	void test_case_4() { int Arr0[] = {5, 3, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 3,  20 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, shortestList(Arg0)); }
	void test_case_5() { int Arr0[] = {1, 3, 5, 12, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  27,  45 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, shortestList(Arg0)); }
	void test_case_6() { int Arr0[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 961,  1922 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(6, Arg1, shortestList(Arg0)); }
	void test_case_7() { int Arr0[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
  11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
  21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
  31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
  41, 42, 43, 44, 45, 46, 47, 48, 49, 50 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 13,  14,  15,  17,  19,  21,  22,  23,  26,  29,  30,  31,  33,  34,  35,  37,  38,  39,  41,  42,  43,  46,  47,  54,  63,  90,  99,  180,  300,  450,  784 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(7, Arg1, shortestList(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SumOfSquareRoots ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
