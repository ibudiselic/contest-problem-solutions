#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class PaperAndPaint {
	public:
	long long computeArea(int width, int height, vector <int> xfold, vector <int> cnt, vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2) {
		int n = (int)xfold.size();
        long long sol = 0;
        vector<int> X;
        X.push_back(0);
        X.push_back(width);
        
        for (int i=0; i<n; ++i) {
            X.push_back(xfold[i]);
            if (x1[i] < xfold[i]) {
                X.push_back(xfold[i] - x1[i]);
            }
            if (x2[i] < xfold[i]) {
                X.push_back(xfold[i] - x2[i]);
            }
            if (x1[i] < width-xfold[i]) {
                X.push_back(xfold[i] + x1[i]);
            }
            if (x2[i] < width-xfold[i]) {
                X.push_back(xfold[i] + x2[i]);
            }
        }
        sort(X.begin(), X.end());
        X.resize(unique(X.begin(), X.end()) - X.begin());
        
        for (int interval=1; interval<(int)X.size(); ++interval) {
            int minx = X[interval-1];
            int maxx = X[interval];
            vector< pair<int, int> > Q;
            for (int i=0; i<n; ++i) {
                int p1, p2;
                if (maxx <= xfold[i]) {
                    p1 = xfold[i] - maxx;
                    p2 = xfold[i] - minx;
                } else {
                    p1 = minx - xfold[i];
                    p2 = maxx - xfold[i];
                }
                
                if (x1[i]<=p1 && p2<=x2[i]) {
                    int h = height / (cnt[i] + 1);
                    for (int k=0; k<=cnt[i]; ++k) {
                        if (k&1) {
                            Q.push_back(make_pair(h*(k+1) - y2[i], h*(k+1) - y1[i]));
                        } else {
                            Q.push_back(make_pair(h*k + y1[i], h*k + y2[i]));
                        }
                    }
                }
            }
            
            sort(Q.begin(), Q.end());
            int last = -1;
            for (int i=0; i<(int)Q.size(); ++i) {
                if (Q[i].first > last) {
                    last = Q[i].first;
                }
                if (Q[i].second > last) {
                    sol += (long long)(maxx-minx)*(Q[i].second-last);
                    last = Q[i].second;
                }
            }
        }
        
        return (long long)height*width - sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 6; int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {1}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {3}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); int Arr7[] = {2}; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); long long Arg8 = 21LL; verify_case(0, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 4; int Arr2[] = {0, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 0}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {1, 1}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {2, 1}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); int Arr7[] = {2, 4}; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); long long Arg8 = 3LL; verify_case(1, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 6; int Arr2[] = {2, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 2}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {2, 0}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {3, 4}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); int Arr7[] = {3, 2}; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); long long Arg8 = 18LL; verify_case(2, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_3() { int Arg0 = 21; int Arg1 = 30; int Arr2[] = {3,21,7,11,13}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4,14,9,5,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {4,0,2,5,9}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {2,0,1,2,3}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {7,19,6,11,12}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); int Arr7[] = {5,2,2,4,5}; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); long long Arg8 = 27LL; verify_case(3, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_4() { int Arg0 = 30; int Arg1 = 42; int Arr2[] = {16, 24, 25, 21, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5, 1, 6, 13, 20}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {3, 1, 5, 8, 9}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {0, 1, 0, 0, 1}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {14, 22, 12, 18, 13}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); int Arr7[] = {2, 15, 1, 1, 2}; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); long long Arg8 = 336LL; verify_case(4, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_5() { int Arg0 = 26; int Arg1 = 60; int Arr2[] = {17, 17, 24, 4, 21}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4, 1, 11, 0, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {9, 1, 20, 18, 7}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {1, 3, 0, 45, 12}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {13, 4, 23, 19, 13}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); int Arr7[] = {3, 14, 1, 46, 14}; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); long long Arg8 = 1319LL; verify_case(5, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_6() { int Arg0 = 17; int Arg1 = 3; int Arr2[] = {17, 2, 10, 2, 10, 13}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 0, 0, 2, 0, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {7, 6, 4, 11, 0, 5}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {0, 0, 1, 0, 1, 1}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {12, 10, 6, 12, 4, 12}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); int Arr7[] = {1, 3, 2, 1, 2, 2}; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); long long Arg8 = 20LL; verify_case(6, Arg8, computeArea(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PaperAndPaint ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
