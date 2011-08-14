#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <utility>

using namespace std;

class BatchSystem {
	public:
	vector <int> schedule(vector <int> duration, vector <string> user) {
		map<string, vector<int> > tmp;
        int n = duration.size();
        for (int i=0; i<n; ++i) {
            tmp[user[i]].push_back(i);
        }
        
        vector< pair<long long, vector<int> > > V;
        for (map<string, vector<int> >::const_iterator it=tmp.begin(); it!=tmp.end(); ++it) {
            long long sum = 0;
            const vector<int> &v = it->second;
            for (int i=0; i<(int)v.size(); ++i) {
                sum += duration[v[i]];
            }
            V.push_back(make_pair(sum, v));
        }
        
        sort(V.begin(), V.end());
        
        vector<int> sol;
        for (int i=0; i<(int)V.size(); ++i) {
            for (int j=0; j<(int)V[i].second.size(); ++j) {
                sol.push_back(V[i].second[j]);
            }
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {400, 100, 100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Danny Messer", "Stella Bonasera", "Stella Bonasera", "Mac Taylor"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 1, 2, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, schedule(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {200, 200, 200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Gil", "Sarah", "Warrick"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, schedule(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {100, 200, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Horatio Caine", "horatio caine", "YEAAAAAAH"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 0, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, schedule(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BatchSystem ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
