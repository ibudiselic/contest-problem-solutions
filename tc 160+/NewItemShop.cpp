#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

int P[24], nP[24], C[24], idx[24], start[24], end[24], active[24];
int ncustomers;
int nswords;
int ndays;

int pack(int day, int mask) { // generate a mask that only contains bits for the active customers on that day
    int ret = 0;
    int n = 0;
    int active_mask = active[day];
    for (int i=0; i<ncustomers; ++i) {
        if (active_mask & (1<<i)) {
            if (mask & (1<<i)) {
                ret |= (1<<n);
            }
            ++n;
        }
    }
    assert(n <= 12);
    return ret;
} 
bool done[24][24][1<<12];
double dp[24][24][1<<12];

double go(int day, int swords_left, int visited_mask) {
    if (day==ndays || swords_left<0) {
        return 0.0;
    }
    int packed_mask = pack(day, visited_mask);
    double &ret = dp[day][swords_left][packed_mask];
    if (done[day][swords_left][packed_mask]) {
        return ret;
    }
    done[day][swords_left][packed_mask] = 1;
    
    int c = idx[day];
    if (visited_mask & (1<<c)) {
        ret = go(day+1, swords_left, visited_mask);
    } else {
        ret = P[day]*max(go(day+1, swords_left-1, visited_mask | (1<<c)) + C[day], // sell if he visits
                         go(day+1, swords_left, visited_mask | (1<<c))) // don't sell if he visits
              + nP[day]*go(day+1, swords_left, visited_mask);
        ret /= nP[day] + P[day];
    }
    return ret;
}
class NewItemShop {
	public:
	double getMaximum(int swords, vector <string> customers) {
        nswords = swords;
        ncustomers = (int)customers.size();
		fill(idx, idx+24, -1);
        for (int i=0; i<ncustomers; ++i) {
            vector<string> tmp;
            istringstream is(customers[i]);
            copy(istream_iterator<string>(is), istream_iterator<string>(), back_inserter(tmp));
            int t, c, p;
            int pleft = 100;
            for (int j=0; j<(int)tmp.size(); ++j) {
                sscanf(tmp[j].c_str(), "%d,%d,%d", &t, &c, &p);
                idx[t] = i;
                C[t] = c;
                P[t] = p;
                pleft -= P[t];
                nP[t] = pleft;
            }
        }
        
        for (int i=23; i>=0; --i) {
            if (idx[i] == -1) {
                for (int j=i+1; j<24; ++j) {
                    idx[j-1] = idx[j];
                    C[j-1] = C[j];
                    P[j-1] = P[j];
                    nP[j-1] = nP[j];
                }
                idx[23] = -1;
            }
        }
        for (ndays=0; ndays<24 && idx[ndays]!=-1; ++ndays)
            ;
        
        fill(start, start+ncustomers, -1);
        for (int i=0; i<ndays; ++i) {
            if (start[idx[i]] == -1) {
                start[idx[i]] = i;
            }
        }
        fill(end, end+ncustomers, -1);
        for (int i=ndays-1; i>=0; --i) {
            if (end[idx[i]] == -1) {
                end[idx[i]] = i;
            }
        }
        
        for (int i=0; i<ndays; ++i) {
            int active_mask = 0;
            for (int j=0; j<ncustomers; ++j) {
                if (start[j]<i && i<=end[j]) {
                    active_mask |= (1<<j);
                }
            }
            active[i] = active_mask;
        }

        memset(done, 0, sizeof done);
        return go(0, nswords-1, 0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arr1[] = { "8,1,80 16,100,11", "12,10,100" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 19.0; verify_case(0, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = { "8,1,80 16,100,11", "12,10,100" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 21.8; verify_case(1, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; string Arr1[] = { "0,90,25 2,90,25 4,90,25 6,90,25", "7,100,80" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 90.0; verify_case(2, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; string Arr1[] = { "17,31,41 20,59,26 23,53,5", "19,89,79", "16,32,38 22,46,26", "18,43,38 21,32,7" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 135.5121414; verify_case(3, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; string Arr1[] = { "1,1,10", "2,2,9", "3,3,8", "4,4,7", "5,5,6", "6,6,5", "7,7,4", "8,8,3", "9,9,2", "10,10,1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.1999744634845344; verify_case(4, Arg2, getMaximum(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NewItemShop ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
