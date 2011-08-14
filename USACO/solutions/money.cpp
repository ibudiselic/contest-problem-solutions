/*
ID: ivan.bu1
PROG: money
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

int main() {
	ifstream fin("money.in");
    int V, N;
    fin >> V >> N;
    vector<int> v;
    copy(istream_iterator<int>(fin), istream_iterator<int>(), back_inserter(v));
    fin.close();
    
    vector<long long> ways(N+1);
    ways[0] = 1;
    for (int i=0; i<V; ++i) {
        for (int j=v[i]; j<=N; ++j) {
            ways[j] += ways[j-v[i]];
        }
    }

    ofstream fout("money.out");
    fout << ways[N] << '\n';
    fout.close();

	return 0;
}
