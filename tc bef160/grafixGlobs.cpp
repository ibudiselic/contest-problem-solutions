#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<int, vector<int> > dict;
enum {
  arc, circ, poly
};

int get_next(void)
{
  int i;
  
  for (i=0; dict.find(i) != dict.end(); ++i)
    ;
  return i;
} 
class grafixGlobs {
   public:
   vector <int> execute(vector <string> a, int b) {
     
     for (int i=0; i<a.size(); ++i) {
       istringstream is(a[i]);
       string s;
       is >> s;
       if (s == "make") {
         vector<int> tmp(3);
         is >> s;
         if (s == "arc") {
           tmp[arc] = 1;
         }
         else if (s == "circle") {
           tmp[circ] = 1;
         }
         else if (s == "polygon") {
           tmp[poly] = 1;
         }
         dict[get_next()] = tmp;
       }
       else if (s == "delete") {
         int t;
         is >> t;
         dict.erase(t);
       }
       else if (s == "merge") {
         int t, v;
         is >> t >> v;
         for (int j=0; j<3; ++j)
           dict[t][j] += dict[v][j];
         dict.erase(v);
       }
       else if (s == "split") {
         int t;
         is >> t;
         vector<int> tmp(3);
         tmp = dict[t];
         dict.erase(t);
         for (int j=0; j<3; ++j) {
           vector<int> hmz(3);
           hmz[j] = 1;
           for (; tmp[j]; --tmp[j])
             dict[get_next()] = hmz;
         }
       } else assert(0);
     }
     return dict[b];   
   }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"make polygon", "make circle", "make polygon", "merge 0 1", "merge 2 0", "split 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arr2[] = { 0,  1,  0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, execute(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"make circle", "make circle", "make arc", "merge 2 1", "delete 0",
 "split 2", "delete 0", "make polygon"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arr2[] = { 0,  0,  1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, execute(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"make circle", "make circle", "make arc", "merge 2 1", "delete 0",
 "split 2", "delete 0", "make polygon"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, execute(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"make arc"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 999; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, execute(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"make polygon", "make polygon", "make arc", "make circle",
 "make circle", "delete 3", "make polygon", "make arc",
 "make arc", "merge 1 3", "merge 1 4", "merge 2 1", "make arc",
 "make arc", "make circle", "make circle", "merge 6 5",
 "split 6", "merge 2 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arr2[] = { 2,  1,  2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, execute(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    grafixGlobs ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
