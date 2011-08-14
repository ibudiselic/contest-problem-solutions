#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <set>

using namespace std;

class InternetSecurity {
	public:
	vector <string> determineWebsite(vector <string> address, vector <string> keyword, vector <string> dangerous, int threshold) {
		map<string, set<string> > M;
        set<string> dang(dangerous.begin(), dangerous.end());
        vector< vector<string> > kws;
        for (int i=0; i<(int)address.size(); ++i) {
            kws.push_back(vector<string> ());
            istringstream is(keyword[i]);
            string s;
            while (is >> s) {
                kws.back().push_back(s);
            }
        }
        bool D[50] = {0};
        bool change = true;
        while (change) {
            change = false;
            for (int i=0; i<(int)address.size(); ++i) {
                if (!D[i]) {
                    int cnt = 0;
                    for (int j=0; j<(int)kws[i].size(); ++j) {
                        cnt += (dang.count(kws[i][j]) > 0);
                    }
                    if (cnt >= threshold) {
                        D[i] = true;
                        for (int j=0; j<(int)kws[i].size(); ++j) {
                            change |= dang.insert(kws[i][j]).second;
                        }
                    }
                }
            }
        }
        
        vector<string> sol;
        for (int i=0; i<(int)address.size(); ++i) {
            if (D[i]) {
                sol.push_back(address[i]);
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
	void test_case_0() { string Arr0[] = {"www.topcoder.com",
"www.sindicate_of_evil.com",
"www.happy_citizens.com"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"hack encryption decryption internet algorithm",
"signal interference evil snake poison algorithm",
"flower baloon topcoder blue sky sea"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"hack","encryption","decryption","interference","signal","internet"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; string Arr4[] = {"www.topcoder.com", "www.sindicate_of_evil.com" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, determineWebsite(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"brokenlink","flowerpower.net","purchasedomain.com"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"broken","rose tulips","cheap free domain biggest greatest"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"biggest","enemy","hideout"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; string Arr4[] = { }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, determineWebsite(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"a..a.ab.","...aa.b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a bc def","def ghij klmno"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"a","b","c","d","e"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; string Arr4[] = {"a..a.ab.", "...aa.b" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, determineWebsite(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"www.tsa.gov"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"information assurance signal intelligence research"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"signal","assurance","penguin"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; string Arr4[] = {"www.tsa.gov" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, determineWebsite(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    InternetSecurity ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
