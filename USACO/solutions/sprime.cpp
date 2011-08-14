/*
ID: ivan.bu1
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>

using namespace std;

bool is_prime(int x) {
    if (!(x&1)) {
        return false;
    }
    for (int d=3; d*d<=x; d+=2) {
        if (x%d == 0) {
            return false;
        }
    }
    return true;
}
vector<int> sol, tmp;
int main() {
    int n;
	ifstream fin("sprime.in");
    fin >> n;
    fin.close();
    sol.push_back(2);
    sol.push_back(3);
    sol.push_back(5);
    sol.push_back(7);
    for (int i=2; i<=n; ++i) {
        for (int j=0; j<(int)sol.size(); ++j) {
            for (int d=0; d<10; ++d) {
                const int x = sol[j]*10 + d;
                if (is_prime(x)) {
                    tmp.push_back(x);
                }
            }
        }
        sol.swap(tmp);
        tmp.clear();
    }
    ofstream fout("sprime.out");
    for (int i=0; i<(int)sol.size(); ++i) {
        fout << sol[i] << '\n';
    }
    fout.close();

	return 0;
}
