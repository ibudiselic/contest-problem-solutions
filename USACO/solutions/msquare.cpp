/*
ID: ivan.bu1
PROG: msquare
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
#include <map>
#include <queue>

using namespace std;

void doA(vector<int> &v) {
    for (int i=0; i<4; ++i) {
        swap(v[i], v[7-i]);
    }
}
void doB(vector<int> &v) {
    int t = v[3];
    for (int i=3; i>0; --i) {
        v[i] = v[i-1];
    }
    v[0] = t;
    t = v[4];
    for (int i=4; i<7; ++i) {
        v[i] = v[i+1];
    }
    v[7] = t;
}
void doC(vector<int> &v) {
    swap(v[2], v[1]);
    swap(v[1], v[6]);
    swap(v[6], v[5]);
}
int main() {
	ifstream fin("msquare.in");
    vector<int> v;
    copy(istream_iterator<int>(fin), istream_iterator<int>(), back_inserter(v));
    fin.close();
    vector<int> orig;
    for (int i=0; i<8; ++i) {
        orig.push_back(i+1);
    }
    vector<int> final = v;
    map< vector<int>, pair<char, vector<int> > > M;
    queue< vector<int> > Q;
    Q.push(orig);
    while (!Q.empty()) {
        v = Q.front();
        Q.pop();
        if (v == final) {
            break;
        }
        vector<int> tmp;
        tmp = v;
        doA(tmp);
        if (M.count(tmp) == 0) {
            M[tmp] = make_pair('A', v);
            Q.push(tmp);
        }
        tmp = v;
        doB(tmp);
        if (M.count(tmp) == 0) {
            M[tmp] = make_pair('B', v);
            Q.push(tmp);
        }
        tmp = v;
        doC(tmp);
        if (M.count(tmp) == 0) {
            M[tmp] = make_pair('C', v);
            Q.push(tmp);
        }
    }
    
    string sol;
    while (final != orig) {
        const pair<char, vector<int> > &tmp = M[final];
        sol += tmp.first;
        final = tmp.second;
    }
    
    reverse(sol.begin(), sol.end());
    ofstream fout("msquare.out");
    fout << sol.size() << '\n' << sol << '\n';
    fout.close();

	return 0;
}
