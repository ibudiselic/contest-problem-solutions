#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool is_prime(int n) {
    if (n < 2) {
        return false;
    } else if (n == 2) {
        return true;
    } else if ((n&1) == 0) {
        return false;
    } else {
        int d = 3;
        while (d*d <= n) {
            if (n%d == 0) {
                return false;
            }
            d += 2;
        }
    }
    return true;
}
int can_do[51][170];
class ColorfulCards {
	public:
	vector <int> theCards(int N, string colors) {
		int cnt = 0;
        vector<int> primes;
        vector<int> sizes;
        for (int i=1; i<=N; ++i) {
            if (is_prime(i)) {
                sizes.push_back(cnt);
                primes.push_back(i);
                cnt = 0;
            } else {
                ++cnt;
            }
        }
        sizes.push_back(cnt);

        memset(can_do, 0, sizeof can_do);
        for (int i=0; i<170; ++i) {
            can_do[colors.size()][i] = true;
        }

        cnt = 0;
        for (int i=(int)colors.size()-1; i>=0; --i) {
            if (colors[i] == 'R') {
                for (int j=(int)primes.size()-1; j>=0; --j) {
                    int nonprimes = sizes[j+1];
                    int k = j+1;
                    while (k+1<(int)sizes.size() && nonprimes<cnt) {
                        nonprimes += sizes[++k];
                    }
                    if (nonprimes < cnt) {
                        can_do[i][j] = false;
                    } else {
                        int l = i+1;
                        while (l<(int)colors.size() && colors[l]!='R') {
                            ++l;
                        }
                        while (k<(int)sizes.size() && !can_do[l][k]) {
                            ++k;
                        }
                        can_do[i][j] = can_do[l][k];
                    }
                }
                cnt = 0;
            } else {
                ++cnt;
            }
        }
        
        vector<int> sol(colors.size(), -1);
        cnt = 0;
        int last_prime = -1;
        for (int i=0; i<(int)colors.size(); ++i) {
            if (colors[i] == 'B') {
                ++cnt;
            } else {
                int nonprimes = sizes[last_prime + 1];
                int j = last_prime + 1;
                while (j+1<(int)sizes.size() && nonprimes<cnt) {
                    nonprimes += sizes[++j];
                }
                while (j+1<(int)sizes.size() && !can_do[i][j]) {
                    nonprimes += sizes[++j];
                }
                assert(can_do[i][j]);
                sol[i] = can_do[i][j+1] ? -1 : primes[j];
                if ((sol[i]==-1 && (primes[j]>2 || can_do[i][2])) || nonprimes>cnt) {
                    for (int k=0; k<cnt; ++k) {
                        sol[i-1-k] = -1;
                    }
                } else {
                    int num = primes[j] - 1;
                    for (int k=0; k<cnt; ++k) {
                        while (is_prime(num)) {
                            --num;
                        }
                        sol[i-1-k] = num--;
                    }
                }
                cnt = 0;
                last_prime = j;
            }
        }
        if (cnt > 0) {
            int nonprimes = 0;
            int j = last_prime + 1;
            while (j < (int)sizes.size()) {
                nonprimes += sizes[j++];
            }
            if (nonprimes > cnt) {
                for (int k=0; k<cnt; ++k) {
                    sol[(int)sol.size()-1-k] = -1;
                }
            } else {
                int num = N;
                for (int k=0; k<cnt; ++k) {
                    while (is_prime(num)) {
                        --num;
                    }
                    sol[(int)sol.size()-1-k] = num--;
                }
            }
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; string Arg1 = "RRR"; int Arr2[] = {2, 3, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, theCards(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; string Arg1 = "BBB"; int Arr2[] = {1, 4, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, theCards(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; string Arg1 = "RBR"; int Arr2[] = {-1, 4, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, theCards(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 58; string Arg1 = "RBRRBRBBRBRRBBRRBBBRRBBBRR"; int Arr2[] = {-1, -1, -1, -1, -1, -1, -1, -1, 17, 18, 19, 23, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 47, 53 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, theCards(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 495; string Arg1 = "RBRRBRBBRBRRBBRRBBBRRBBBRR"; int Arr2[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, theCards(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ColorfulCards ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
