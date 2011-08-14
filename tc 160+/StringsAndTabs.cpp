#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

int to_int(char c) {
    if (c>='0' && c<='9') {
        return c-'0';
    } else {
        return 10 + (c-'A');
    }
}
char to_char(int x) {
    if (x < 10) {
        return char(x + '0');
    } else {
        return char(x-10 + 'A');
    }
}

class StringsAndTabs {
	public:
	vector <string> transformTab(vector <string> tab, vector <int> stringsA, vector <int> stringsB, int d) {
        vector< pair<int, int> > b;
        for (int i=0; i<(int)stringsB.size(); ++i) {
            b.push_back(make_pair(stringsB[i], i));
        }
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());
        vector<int> ob;
        for (int i=0; i<(int)b.size(); ++i) {
            ob.push_back(b[i].second);
        }
	    int n = tab[0].size();
        vector<string> sol(stringsB.size(), string(n, '-'));
        for (int i=0; i<n; ++i) {
            vector<int> p;
            for (int j=0; j<(int)tab.size(); ++j) {
                if (tab[j][i] != '-') {
                    p.push_back(stringsA[j] + to_int(tab[j][i]));
                }
            }
            if (p.size() == 0) {
                continue;
            }
            sort(p.begin(), p.end());
            reverse(p.begin(), p.end());

            bool ok = true;
            vector<bool> used(stringsB.size(), false);
            for (int j=0; j<(int)p.size(); ++j) {
                int pitch = p[j] + d;
                bool found = false;
                for (int k=0; k<(int)ob.size(); ++k) {
                    if (!used[ob[k]] && (stringsB[ob[k]]<=pitch && pitch<=stringsB[ob[k]]+35)) {
                        used[ob[k]] = 1;
                        sol[ob[k]][i]= to_char(pitch-stringsB[ob[k]]);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                for (int j=0; j<(int)stringsB.size(); ++j) {
                    sol[j][i] = 'x';
                }
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"-----------------",
 "-------------0-1-",
 "---------0-2-----",
 "---0-2-3---------",
 "-3---------------",
 "-----------------"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {28,23,19,14,9,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; string Arr4[] = {"-3-5-7-8-A-C-E-F-" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, transformTab(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"-4457754-20024422-4457754-20024200-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {28,23,19,14,9,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; string Arr4[] = {"-----------------------------------", "-----------------------------------", "----00---------------00------------", "-223--32-0--02200-223--32-0--020---", "----------33---------------33---33-", "-----------------------------------" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, transformTab(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"-----------------------------------",
 "-----------------------------------",
 "----00---------------00------------",
 "-223--32-0--02200-223--32-0--020---",
 "----------33---------------33---33-",
 "-----------------------------------"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {28,23,19,14,9,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {33,28,24,31}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; string Arr4[] = {"-----------------------------------", "-001--10-----00---001--10-----0----", "---------2002--22---------2002-200-", "----00---------------00------------" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, transformTab(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"-----0------2-2222--0-------0-",
 "----0------2---222---5-----55-",
 "---0------2-----22----9---999-",
 "--0------2-------2-----E-EEEE-",
 "-0------2---------------------",
 "0------2----------------------"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {28,23,19,14,9,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {33,28,28}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; string Arr4[] = {"xxx-27-xx-049-999x--7777-777x-", "xxx----xx-------5x---------Cx-", "xxx3---xx0-----99x--------CCx-" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, transformTab(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"012345---------",
 "---------UVWXYZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; string Arr4[] = {"xx0123---WXYZxx" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, transformTab(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { string Arr0[] = {"0220----02--",
 "75--75----57",
 "------B9B9B9",
 "--242424----"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {33,28,24,31}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {33,28,28}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; string Arr4[] = {"222222222222", "------------", "555555555555" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(5, Arg4, transformTab(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    StringsAndTabs ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
