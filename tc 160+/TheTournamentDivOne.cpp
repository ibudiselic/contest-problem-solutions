#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;
vector<int> P;
int gcd(int m, int n) { return m==0 ? n : gcd(n%m, m); }

class TheTournamentDivOne {
	public:
	int find(vector <int> points, int w, int d) {
		P = points;
        int g = gcd(w, d);
        w /= g;
        d /= g;
        for (int i=0; i<(int)P.size(); ++i) {
            if (P[i]%g != 0) {
                return -1;
            }
            P[i] /= g;
        }
        
        
        vector<int> draw_count;
        if (2*d >= w) {
            // maximize draw count
            vector<int> maxdraw = P;
            for (int i=0; i<(int)maxdraw.size(); ++i) {
                while (maxdraw[i]>0 && maxdraw[i]%d!=0) {
                    maxdraw[i] -= w;
                }
                if (maxdraw[i] < 0) {
                    return -1;
                }
                
                maxdraw[i] /= d;
            }
            int maxi = 0;
            int total = accumulate(maxdraw.begin(), maxdraw.end(), 0);
            for (int i=1; i<(int)maxdraw.size(); ++i) {
                if (maxdraw[i] > maxdraw[maxi]) {
                    maxi = i;
                }
            }
            while ((total&1) || 2*maxdraw[maxi]>total) {
                maxdraw[maxi] -= w; // another d wins (score d*w => minus w draws) because maxdraw*d - x*w = k*d => minx = d
                if (maxdraw[maxi] < 0) {
                    return -1;
                }
                total -= w;
                for (int i=0; i<(int)maxdraw.size(); ++i) {
                    if (maxdraw[i] > maxdraw[maxi]) {
                        maxi = i;
                    }
                }
            }
            draw_count = maxdraw;
        } else {
            // maximize win count => minimize draw count
            vector<int> mindraw = P;
            for (int i=0; i<(int)mindraw.size(); ++i) {
                mindraw[i] = 0;
                while (P[i]>=mindraw[i] && (P[i]-mindraw[i])%w != 0) {
                    mindraw[i] += d;
                }
                if (mindraw[i] > P[i]) {
                    return -1;
                }
                mindraw[i] /= d;
            }
            
            int maxi = 0;
            int total = accumulate(mindraw.begin(), mindraw.end(), 0);
            for (int i=0; i<(int)mindraw.size(); ++i) {
                if (mindraw[i] > mindraw[maxi]) {
                    maxi = i;
                }
            }
            while ((total&1) || 2*mindraw[maxi]>total) {
                int add_to = -1; // one that can be increased
                for (int i=0; i<(int)mindraw.size(); ++i) {
                    if (i!=maxi && (mindraw[i]+w)*d<=P[i] && (add_to==-1 || mindraw[i]<mindraw[add_to])) {
                        add_to = i;
                    }
                }
                if (add_to == -1) {
                    return -1;
                }
                total += w;
                mindraw[add_to] += w;
                for (int i=0; i<(int)mindraw.size(); ++i) {
                    if (mindraw[i] > mindraw[maxi]) {
                        maxi = i;
                    }
                }
            }
            draw_count = mindraw;
        }
        
        int sol = accumulate(draw_count.begin(), draw_count.end(), 0)/2;
        for (int i=0; i<(int)P.size(); ++i) {
            cerr << draw_count[i] << ' ' << P[i]-draw_count[i]*d << '\n';
            sol += (P[i]-draw_count[i]*d)/w;
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; int Arg3 = 6; verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; int Arg3 = -1; verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 4, 0, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 1; int Arg3 = 3; verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {8, 3, 8, 5, 9, 2, 7, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; int Arg3 = 15; verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheTournamentDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
