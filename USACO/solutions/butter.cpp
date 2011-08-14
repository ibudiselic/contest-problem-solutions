/*
ID: ivan.bu1
PROG: butter
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
#include <cassert>

using namespace std;

int cnt_cows_at[800];
int main() {
	ifstream fin("butter.in");
    int cnt_cows, cnt_pastures, cnt_edges;
    fin >> cnt_cows >> cnt_pastures >> cnt_edges;
    for (int i=0; i<cnt_cows; ++i) {
        int x;
        fin >> x;
        ++cnt_cows_at[x-1];
    }
    vector< vector< pair<int, int> > > edges(cnt_pastures);
    for (int i=0; i<cnt_edges; ++i) {
        int a, b, c;
        fin >> a >> b >> c;
        --a; --b;
        edges[a].push_back(make_pair(b, c));
        edges[b].push_back(make_pair(a, c));
    }
    fin.close();
    
    long long sol = 123456790123456789LL;
    for (int i=0; i<cnt_pastures; ++i) {
        priority_queue< pair<long long, int> > PQ;
        vector<int> dist(cnt_pastures, -1);
        vector<int> done(cnt_pastures, 0);
        dist[i] = 0;
        PQ.push(make_pair(0, i));
        long long cur = 0;
        while (!PQ.empty() && cur<sol) {
            pair<long long, int> t = PQ.top();
            PQ.pop();
            int u = t.second;
            if (done[u]) {
                continue;
            }
            done[u] = true;
            int cur_dist = -t.first;
            assert(cur_dist == dist[u]);
            cur += cnt_cows_at[u] * cur_dist;
            for (int j=0; j<(int)edges[u].size(); ++j) {
                const int v = edges[u][j].first;
                const long long d = edges[u][j].second;
                if (dist[v]==-1 || cur_dist+d<dist[v]) {
                    dist[v] = cur_dist + d;
                    PQ.push(make_pair(-dist[v], v));
                }
            }
        }
        sol = min(sol, cur);
    }
    ofstream fout("butter.out");
    fout << sol << '\n';
    fout.close();

	return 0;
}

