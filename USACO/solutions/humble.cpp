/*
ID: ivan.bu1
PROG: humble
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
#include <set>

using namespace std;

int main() {
	ifstream fin("humble.in");
    int k, n;
    fin >> k >> n;
    vector<int> P;
    copy(istream_iterator<int>(fin), istream_iterator<int>(), back_inserter(P));
    fin.close();
    
    sort(P.begin(), P.end());
    
    set<long long> S;
    S.insert(1);
    while (n > 0) {
        long long x = *S.begin();
        S.erase(S.begin());
        for (int i=0; i<k; ++i) {
            long long next = x * P[i];
            if (S.size()>n && next>*S.rbegin()) {
                break;
            }
            S.insert(next);
        }
        --n;
    }
    
    ofstream fout("humble.out");
    fout << *S.begin() << '\n';
    fout.close();

	return 0;
}
