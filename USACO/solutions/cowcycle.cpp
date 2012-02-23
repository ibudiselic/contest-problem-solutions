/*
ID: ivan.bu1
PROG: cowcycle
LANG: C++
*/
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

int F, R;
int Flo, Fhi, Rlo, Rhi;

const long double EPS = 0.0;
long double my_abs(long double x) {
    return x < 0 ? -x : x;
}
long double f(const vector<int> &A, const vector<int> &B) {
    if (A.back()*B.back() < 3*A[0]*B[0]) {
        return 1e32;
    }
    vector<long double> V;
    for (int i=0; i<F; ++i) {
        for (int j=0; j<R; ++j) {
            V.push_back((long double)A[i] / B[j]);
        }
    }
    sort(V.begin(), V.end());
    
    for (int i=1; i<(int)V.size(); ++i) {
        V[i-1] = my_abs(V[i] - V[i-1]);
    }
    V.pop_back();
    
    long double x = 0.0;
    for (int i=0; i<(int)V.size(); ++i) {
        x += V[i];
    }
    x /= V.size();
    long double ret = 0.0;
    for (int i=0; i<(int)V.size(); ++i) {
        ret += (V[i]-x)*(V[i]-x);
    }
    ret /= V.size();
    
    return ret;
}

bool lt(const vector<int> &A, const vector<int> &B, const vector<int> &C, const vector<int> &D) {
    for (int i=0; i<(int)A.size(); ++i) {
        cerr << A[i] << ' ';
    }
    cerr << '\n';
    for (int i=0; i<(int)B.size(); ++i) {
        cerr << B[i] << ' ';
    }
    cerr << '\n';
    for (int i=0; i<(int)A.size(); ++i) {
        if (A[i] != C[i]) {
            return A[i] < C[i];
        }
    }
    for (int i=0; i<(int)B.size(); ++i) {
        if (B[i] != D[i]) {
            return B[i] < D[i];
        }
    }
    return false;
}
long double best = 1e32;
vector<int> solF, solR;
void solveB(int at, const vector<int> &A, vector<int> &B) {
    if (at == R) {
        long double cand = f(A, B);
        if (cand<best-EPS || cand<best+EPS && lt(A, B, solF, solR)) {
            solF = A;
            solR = B;
            best = cand;
        }
    } else {
        for (B[at]=(at==0 ? Rlo : B[at-1]+1); B[at]+(R-1-at)<=Rhi; ++B[at]) {
            solveB(at+1, A, B);
        }
    }
}
void solveA(int at, vector<int> &A, vector<int> &B) {
    if (at == F) {
        solveB(0, A, B);
    } else {
        for (A[at]=(at==0 ? Flo : A[at-1]+1); A[at]+(F-1-at)<=Fhi; ++A[at]) {
            solveA(at+1, A, B);
        }
    }
}
int main() {
	ifstream fin("cowcycle.in");
    fin >> F >> R;
    fin >> Flo >> Fhi >> Rlo >> Rhi;
    fin.close();
    
    vector<int> A(F, 0), B(R, 0);
    solveA(0, A, B);
    
    ofstream fout("cowcycle.out");
    for (int i=0; i<F; ++i) {
        if (i) fout << ' ';
        fout << solF[i];
    }
    fout << '\n';
    for (int i=0; i<R; ++i) {
        if (i) fout << ' ';
        fout << solR[i];
    }
    fout << '\n';
    fout.close();

	return 0;
}
