#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template<class T>
vector<T> tokenize(string s, const string &delim=" ")
{
    vector<T> ret_val;
    string::size_type i=0;
    string::size_type len = delim.length();
    if (delim != " ")
        while ((i=s.find(delim)) != string::npos)
            s.replace(i, len, " ");

    istringstream is(s);
    T val;

    while (is >> val)
        ret_val.push_back(val);
    return ret_val;
}
template<class T>
string to_str(T x)
{
    string ret;
    ostringstream os(ret);

    os << x;
    return os.str();
}

/*** real code starts here ***/

class FolderSize {
    public:
    vector <int> calculateWaste(vector <string> files, int folderCount, int cs) {
        vector<int> sol(folderCount);
      
        for (int i=0; i<(int)files.size(); ++i) {
        	istringstream is(files[i]);
        	int f, s;
        	
        	is >> f >> s;
        	sol[f] += s%cs ? cs - s%cs : 0;
        }
        return sol;
    }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"0 55", "0 47", "1 86"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 50; int Arr3[] = { 48,  14,  0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, calculateWaste(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"0 123", "2 456", "4 789", "6 012", "8 345"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 98; int Arr3[] = { 73,  0,  34,  0,  93,  0,  86,  0,  47,  0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, calculateWaste(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 100; int Arr3[] = { 0,  0,  0,  0,  0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, calculateWaste(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"0 93842", "1 493784", "2 43212", "3 99327", "4 456209",
"5 947243", "6 59348", "7 58237", "8 5834", "9 492384",
"0 58342", "3 538432", "6 1432", "9 453983", "2 4321",
"4 583729", "6 6974", "8 9864", "4 43211", "8 38437"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 22485; int Arr3[] = { 27696,  886,  19922,  14306,  18616,  19612,  44671,  9218,  35805,  20488 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, calculateWaste(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FolderSize ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
