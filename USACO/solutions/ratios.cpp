/*
ID: ivan.bu1
PROG: ratios
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
#include <queue>

using namespace std;

int A[4][3];
/*struct S {
    int p[3];
    S(int a, int b, int c) {
        int arr[] = {a, b, c};
        S(arr);
    }
    S(int *p_) {
        for (int i=0; i<3; ++i) {
            p[i] = p_[i];
        }
    }
    int& operator[](int i) {
        return p[i];
    }
    bool is_final() const {
        int f = get_factor();
        for (int i=0; i<3; ++i) {
            if (A[0][i]*f != p[i]) {
                return false;
            }
        }
        return true;
    }
};*/
int choice[100][100][100];
int main() {
	ifstream fin("ratios.in");
    for (int i=0; i<4; ++i) {
        for (int j=0; j<3; ++j) {
            fin >> A[i][j];
        }
    }
    fin.close();
    
    /*memset(choice, 0xff, sizeof choice);
    queue<S> Q;
    Q.push(S(0, 0, 0));
    int steps = 0;
    int layer = 0;
    ofstream fout("ratios.out");

    while (!Q.empty()) {
        if (layer == 0) {
            layer = Q.size();
            ++steps;
        }
        --layer;
        S state = Q.front();
        Q.pop();
        
        for (int i=0; i<3; ++i) {
            S next = state;
            for (int j=0; j<3; ++j) {
                next[j] += A[i+1][j];        
                if (next[j] >= 100) {
                    continue;
                }
            }
            if (next.is_final()) {
                sol = next;
                goto SOLVED;
            }
        }
    }
    
    fout << "NONE\n";
SOLVED: ;
    fout.close();*/

    int sol = 301;
    int sola, solb, solc, solmul;
    int tmp[3], vals[3];
    for (tmp[0]=0; tmp[0]<100; ++tmp[0]) {
        for (tmp[1]=0; tmp[1]<100; ++tmp[1]) {
            for (tmp[2]=0; tmp[2]<100; ++tmp[2]) {
                bool ok = true;
                int total = 0;
                int factor = -1;
                for (int i=0; i<3; ++i) {
                    vals[i] = 0;
                    total += tmp[i];
                    for (int j=0; j<3; ++j) {
                        vals[i] += A[1+j][i] * tmp[j];
                    }
                    if (A[0][i] == 0) {
                        if (vals[i] != 0) {
                            ok = false;
                            break;
                        }
                    } else if (factor == -1) {
                        factor = vals[i]/A[0][i];
                        if (A[0][i]*factor != vals[i]) {
                            ok = false;
                            break;
                        }
                    } else if (A[0][i]*factor != vals[i]) {
                        ok = false;
                        break;
                    }
                }
                if (ok && total<sol && total>0) {
                    sol = total;
                    sola = tmp[0];
                    solb = tmp[1];
                    solc = tmp[2];
                    solmul = factor;
                    for (int i=0; i<3; ++i) {
                        cerr << vals[i] << ' ';
                    }
                    cerr << '\n';
                    cerr << sol << ' ' << sola << ' ' << solb << ' ' << solc << ' ' << solmul << '\n';
                }
            }
        }
    }
    ofstream fout("ratios.out");
    if (sol > 300) {
        fout << "NONE\n";
    } else {
        fout << sola << ' ' << solb << ' ' << solc << ' ' << solmul << '\n';
    }
    fout.close();

	return 0;
}
