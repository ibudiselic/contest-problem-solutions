/*
ID: ivan.bu1
PROG: fence8
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
#include <numeric>

using namespace std;

enum {
    MAX_BOARDS = 50,
    MAX_RAILS = 1023,
};
int boards[MAX_BOARDS+1];
int rails[MAX_RAILS+1];
int nboards, nrails;
bool can_make(int r, int board_hint) {
    if (r == nrails) {
        return true;
    }
    
    int board_start = (rails[r]==rails[r-1] ? board_hint : 1);
    for (int i=board_start; i<nboards; ++i) {
        if (boards[i]>=rails[r] && boards[i]!=boards[i-1]) {
            boards[i] -= rails[r];
            bool can = can_make(r+1, i);
            boards[i] += rails[r];
            if (can) {
                return true;
            }
        }
        if (boards[i] == rails[r]) {
            break;
        }
    }
    return false;
}
int main() {
	ifstream fin("fence8.in");
    boards[0] = rails[0] = -1;
    fin >> nboards;
    ++nboards;
    for (int i=1; i<nboards; ++i) {
        fin >> boards[i];
    }
    fin >> nrails;
    ++nrails;
    for (int i=1; i<nrails; ++i) {
        fin >> rails[i];
    }
    fin.close();
    
    sort(boards+1, boards+nboards);
    long long total_boards = accumulate(boards+1, boards+nboards, 0LL);
    sort(rails+1, rails+nrails);
    
    int i = 1;
    long long rail_sum = 0;
    while (i<nrails && rail_sum+rails[i]<=total_boards && rails[i]<=boards[nboards-1]) {
        rail_sum += rails[i++];
    }
    nrails = i;
    reverse(rails+1, rails+nrails);

    int lo = 1;
    int hi = nrails;
    while (lo < hi) {
        int mid = lo + (hi-lo)/2;
        if (can_make(mid, 1)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    ofstream fout("fence8.out");
    fout << nrails-lo << '\n';
    fout.close();

	return 0;
}
