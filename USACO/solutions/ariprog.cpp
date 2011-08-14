/*
ID: ivan.bu1
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <utility>

using namespace std;

bool have[125001];
int n, m;
bool ok(int start, int diff) {
    for (int i=0; i<n; ++i) {
        const int t = start + i*diff;
        if (t>125000 || !have[t]) {
            return false;
        }
    }
    return true;
}
int main() {
	ifstream fin("ariprog.in");
    fin >> n >> m;
    fin.close();
    vector<int> nums;
    for (int i=0; i<=m; ++i) {
        for (int j=0; j<=m; ++j) {
            nums.push_back(i*i + j*j);
        }
    }
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    for (int i=0; i<(int)nums.size(); ++i) {
        have[nums[i]] = true;
    }

    vector< pair<int, int> > v;
    for (int i=0; i<(int)nums.size(); ++i) {
        for (int j=i+1; j<(int)nums.size(); ++j) {
            const int diff = nums[j] - nums[i];
            if (nums[i] + (n-1)*diff > 125000) {
                break;
            }
            if (ok(nums[i], diff)) {
                v.push_back(make_pair(diff, nums[i]));
            }
        }
    }
    sort(v.begin(), v.end());
    ofstream fout("ariprog.out");
    if (v.size() == 0) {
        fout << "NONE\n";
    } else {
        for (int i=0; i<(int)v.size(); ++i) {
            fout << v[i].second << ' ' << v[i].first << '\n';
        }
    }
    fout.close();

	return 0;
}
