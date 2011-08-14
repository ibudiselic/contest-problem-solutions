#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

vector<string> cutUp(const string &s, const string &delim=" ") {
	int lastPos = 0, pos = 0;
	vector<string> ret;

	while (pos+delim.size() <= s.size()) {
		if (s.substr(pos, delim.size()) == delim) {
			ret.push_back(s.substr(lastPos, pos-lastPos));

			pos += (int)delim.size()-1;
			lastPos = pos+1;
		}
		++pos;
	}

	if (lastPos < (int)s.size())
		ret.push_back(s.substr(lastPos));

	return ret;
}

long long M = 1000000001LL;
map<string, long long> cur;
class MakingPotions {
	public:
	int getCost(vector <string> marketGoods, vector <int> cost, vector <string> recipes) {
        cur.clear();
        for (int i=0; i<(int)cost.size(); ++i) {
            cur[marketGoods[i]] = cost[i];
        }
        
        if (!cur.count("LOVE")) {
            cur["LOVE"] = -1;
        }
        
        vector<string> names;
        vector< vector<string> > ings;
        vector< vector<int> > cnt;
        for (int i=0; i<(int)recipes.size(); ++i) {
            vector<string> t = cutUp(recipes[i], "=");
            names.push_back(t[0]);
            if (!cur.count(names.back())) {
                cur[names.back()] = -1;
            }
            ings.push_back(vector<string>());
            cnt.push_back(vector<int>());
            t = cutUp(t[1], "+");
            for (int j=0; j<(int)t.size(); ++j) {
                cnt.back().push_back(t[j][0]-'0');
                ings.back().push_back(t[j].substr(1));
                if (!cur.count(ings.back().back())) {
                    cur[ings.back().back()] = -1;
                }
            }
        }
        
        while (1) {
            bool changed = false;
            
            for (int i=0; i<(int)names.size(); ++i) {
                long long t = 0;
                for (int j=0; j<(int)cnt[i].size(); ++j) {
                    const string &n = ings[i][j];
                    const int c = cnt[i][j];
                    if (cur[n] == -1) {
                        t = -1;
                        break;
                    } else {
                        t = min(M, t + c*cur[n]);
                    }
                }
                if (t == -1) {
                    continue;
                }
                const long long x = cur[names[i]];
                if (x==-1 || t<x) {
                    cur[names[i]] = t;
                    changed = true;
                    break;
                }
            }
            
            if (!changed) {
                break;
            }
        }
        
        return cur["LOVE"];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"LOVE", "WATER", "HONEY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100, 1, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"LOVE=5WATER+3HONEY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 95; verify_case(0, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"WATER", "HONEY", "HOP"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 6, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"LOVE=2WATER+4HONEY+2BEER", "BEER=1HOP+3WATER+1HOP"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 76; verify_case(1, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"ORANGEJUICE", "APPLEJUICE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"JUICEMIX=1ORANGEJUICE+1APPLEJUICE"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(2, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"WATER", "HONEY", "HOP"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,22,17}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"LOVE=7WATER+3HONEY", "LOVE=2HONEY+2HOP"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 73; verify_case(3, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"OIL", "WATER"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {60, 70}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"FIRSTPOTION=1OIL+1SECONDPOTION", "SECONDPOTION=4WATER+1FIRSTPOTION", "LOVE=1FIRSTPOTION+1SECONDPOTION"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(4, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"HONEYBIT"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"LOVE=6HONEYMEGABYTE","HONEYMEGABYTE=2HONEYFIFTYTWELVEKBYTES",
"HONEYFIFTYTWELVEKBYTES=8HONEYSIXTYFOURKBYTES","HONEYSIXTYFOURKBYTES=8HONEYEIGHTKBYTES",
"HONEYEIGHTKBYTES=8HONEYKBYTE","HONEYKBYTE=2EIGHTBYEIGHTWORDS","EIGHTBYEIGHTWORDS=8EIGHTWORDS",
"EIGHTWORDS=8HONEYWORD","HONEYWORD=8HONEYBYTE","HONEYBYTE=8HONEYBIT"}
; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1000000001; verify_case(5, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arr0[] = {"WATER"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"LOVE=1LOVE"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(6, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_7() { string Arr0[] = {"MILK","WATER","HOP"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6,1,14}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NECTAR=4HOP+2MILK","LOVE=5MILK+3BEER","LOVE=2WATER+1LOVE","LOVE=2MIX+1NECTAR",
"MIX=1MILK+1WATER+1HOP","BEER=5WATER+2HOP","LOVE=1NECTAR+3WATER+3HOP","NECTAR=3BEER+1MILK+2MILK"}
; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 110; verify_case(7, Arg3, getCost(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MakingPotions ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
