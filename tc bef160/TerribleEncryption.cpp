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

class TerribleEncryption {
	public:
	string decrypt(string pool, vector <int> data, vector <int> keys) {
		string sol;
		for (int i=0; i<(int)data.size(); ++i) {
			int k=1;
			for (; (data[i]*k)%keys[i] != 1; ++k)
				continue;
			sol += pool[k%pool.size()];
		}
		return sol;
			
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; int Arr1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {17,17,17,17,17,17,17,17,17,17,17,17,17,17,17}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "BJGNHDFPCMOKELI"; verify_case(0, Arg3, decrypt(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "AEIOUAEIOUaeiouaeiou"; int Arr1[] = {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,5,6,7,8,9,10,11,13,15,16,17,18}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "EIOUAEIOUaEOeoe"; verify_case(1, Arg3, decrypt(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "abcdeffedcbaABCDEFFEDCBA"; int Arr1[] = {10,10,10,10,10,10,10,10,10,10,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,7,11,13,17,19,23,29,31,37,41}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "bfbeAcedecB"; verify_case(2, Arg3, decrypt(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "abcdefghijklmnopqrstuvwxyz"; int Arr1[] = {11,11,11,11,11,11,11,11,11,11,11,11,11,11,11}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,5,6,7,8,9,10,12,13,14,15,16,17}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "bcdbfcdfblgjldo"; verify_case(3, Arg3, decrypt(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "HmmBlahHmmBlah"; int Arr1[] = {1,1,1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,9,8,7,6,5,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "mmmmmmm"; verify_case(4, Arg3, decrypt(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TerribleEncryption ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
