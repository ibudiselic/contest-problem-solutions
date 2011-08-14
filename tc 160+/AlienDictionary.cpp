#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool F[1<<17];
int dp[52][1<<17];
int n, f;
int ACTIVE;

void go(int p, int m, const string &s) {
    if (p == (int)s.size()) {
        F[m] = 1;
    } else {
        if (s[p] != 'B') {
            go(p+1, m<<1, s);
        }
        if (s[p] != 'A') {
            go(p+1, (m<<1)|1, s);
        }
    }
}

const int INF = 1000000001;
int cnt(int p, int m) {
    int &ret = dp[p][m];
    if (ret != -1) {
        return ret;
    }

    if (p>=f && F[m]) {
        return (ret = 0);
    }

    if (p == n) {
        return (ret = 1);
    }

    m = (m & ACTIVE) << 1;
    return (ret = min(INF, cnt(p+1, m) + cnt(p+1, m|1)));
}

class AlienDictionary {
	public:
	vector <string> getWords(int wordLength, vector <string> forbiddenSubstrings, vector <int> wordNumbers) {
	     n = wordLength;
         f = (forbiddenSubstrings.size()>0 ? forbiddenSubstrings[0].size() : 1);
         ACTIVE = (1<<(f-1)) - 1;
         memset(F, 0, sizeof F);

         for (vector<string>::const_iterator it=forbiddenSubstrings.begin(); it!=forbiddenSubstrings.end(); ++it) {
             go(0, 0, *it);
         }

         vector<string> sol;
         sol.reserve(wordNumbers.size());
         memset(dp, 0xff, sizeof dp);
         for (int i=0; i<(int)wordNumbers.size(); ++i) {
             int x = wordNumbers[i];
             if (cnt(0, 0) <= x) {
                 sol.push_back("NO PAGE");
             } else {
                 string s;
                 int m = 0;
                 for (int j=0; j<n; ++j) {
                     m = (m & ACTIVE) << 1;
                     if (cnt(j+1, m) > x) {
                         s += 'A';
                     } else {
                         x -= cnt(j+1, m);
                         m |= 1;
                         s += 'B';
                     }
                 }
                 sol.push_back(s);
             }
         }

         return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; string Arr1[] = {"?AA","ABB"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,12,0,6,9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"BBBAB", "NO PAGE", "AABAB", "BBBBB", "NO PAGE" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, getWords(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,4,7,5,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"AAB", "BAA", "BBB", "BAB", "AAB" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, getWords(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; string Arr1[] = {"AA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,6,11,4,8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"ABBB", "BBBA", "NO PAGE", "BABB", "NO PAGE" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, getWords(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10; string Arr1[] = {"BABB?","??A?B","A?AAA","A??AB","?A??A"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"AABBBABABA", "AABBBBABAB" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, getWords(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    AlienDictionary ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
