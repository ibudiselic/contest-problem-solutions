/*
ID: ivan.bu1
PROG: pprime
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

int A, B;
vector<int> sol;

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
int rev(int x) {
    int ret = 0;
    while (x > 0) {
        ret = 10*ret + x%10;
        x /= 10;
    }
    return ret;
}
void go(int cur, int p10) {
    if (cur > 0) {
        long long r = rev(cur);
        long long x = (long long)cur * p10;
        long long t = x + r;
        if (t > B) {
            return;
        }
        if (A<=t && t<=B && is_prime(t)) {
            sol.push_back(t);
        }
        for (int d=0; d<10; ++d) {
            t = x*10 + d*p10 + r;
            if (t > B) {
                return;
            }
            if (A<=t && t<=B && is_prime(t)) {
                sol.push_back(t);
            }
        }
    }
    p10 *= 10;
    for (int d=(cur==0); d<10; ++d) {
        go(cur*10 + d, p10);
    }
}
int main() {
	ifstream fin("pprime.in");
    fin >> A >> B;
    fin.close();

    if (A<=5 && 5<=B) {
        sol.push_back(5);
    }
    if (A<=7 && 7<=B) {
        sol.push_back(7);
    }
    go(0, 1);
    sort(sol.begin(), sol.end());

    ofstream fout("pprime.out");
    for (int i=0; i<(int)sol.size(); ++i) {
        fout << sol[i] << '\n';
    }
    fout.close();

	return 0;
}
