#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

bool done[50];
int out[50];
int bc(long long x) {
    int ret = 0;
    while (x > 0) {
        ++ret;
        x &= x-1;
    }
    return ret;
}
class ImportsList {
	public:
	vector <int> importsCount(vector <string> requires) {
	    vector<long long> mask;
        int n = requires.size();
        memset(out, 0, sizeof out);
        priority_queue< pair<int, int> > PQ;
        for (int i=0; i<n; ++i) {
            long long t = 0;
            for (int j=0; j<n; ++j) {
                if (requires[i][j] == 'Y') {
                    t |= (1LL << j);
                }
            }
            mask.push_back(t);
            out[i] = bc(t);
            PQ.push(make_pair(-out[i], i));
        }
        
        memset(done, 0, sizeof done);
        vector<int> sol(n, 0);
        while (!PQ.empty()) {
            int o = -PQ.top().first;
            int x = PQ.top().second;
            PQ.pop();
            if (o != 0) {
                break;
            }
            
            long long donemask = 0;
            for (int y=0; y<n; ++y) {
                if (requires[x][y] == 'Y') {
                    assert(done[y]);
                    donemask |= mask[y];
                }
            }
            long long needmask = mask[x] ^ (mask[x] & donemask);
            sol[x] = bc(needmask);
            for (int y=0; y<n; ++y) {
                if (requires[y][x] == 'Y') {
                    assert(!done[y]);
                    PQ.push(make_pair(-(--out[y]), y));
                }
            }
            done[x] = true;
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"NNN"
,"NNN"
,"NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, importsCount(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYYY"
,"NNYY"
,"NNNY"
,"NNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, importsCount(Arg0)); }
	void test_case_2() { string Arr0[] = {"NNNNY"
,"NNNNY"
,"YNNNY"
,"NNNNN"
,"NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, importsCount(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYYNYNYYYNYYNYNN"
,"NNNNNNNNNNNNNNNN"
,"NNNNNNNNNNYNNNNN"
,"NNNNNNNNNYNNYNNN"
,"NYNNNNYNNNYYNNNN"
,"NYNNYNYNYNYYNNNN"
,"NNNNNNNNNNYNNNNN"
,"NNYNNNYNYNYNNNNN"
,"NNNNNNYNNNYNNNNN"
,"NNNNNNNNNNNNYNNN"
,"NNNNNNNNNNNNNNNN"
,"NNNNNNNNNNNNNNNN"
,"NNNNNNNNNNNNNNNN"
,"NNNNNNYNNNYNNNNN"
,"YYYYYNYYYYYYYYNY"
,"NYYYNNYNNYYNYYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 0, 1, 1, 3, 2, 1, 2, 1, 1, 0, 0, 0, 1, 2, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, importsCount(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ImportsList ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
