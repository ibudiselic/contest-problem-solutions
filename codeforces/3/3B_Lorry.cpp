#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

struct vehicle {
    int ind;
    int cap;
    vehicle(int ind_, int cap_): ind(ind_), cap(cap_) {}
};
bool operator<(const vehicle &a, const vehicle &b) {
    if (a.cap != b.cap) {
        return a.cap > b.cap;
    } else {
        return a.ind < b.ind;
    }
}
int sum[100001];
int main() {
    int n, V;
    cin >> n >> V;
    
    vector<vehicle> A, B;
    for (int i=0; i<n; ++i) {
        int type, cap;
        cin >> type >> cap;
        if (type == 1) {
            B.push_back(vehicle(i+1, cap));
        } else {
            A.push_back(vehicle(i+1, cap));
        }
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sum[0] = 0;
    for (int i=1; i<=(int)B.size(); ++i) {
        sum[i] = sum[i-1] + B[i-1].cap;
    }
    
    int best = 0;
    int besti = -1;
    int sumA = 0;
    A.push_back(vehicle(0, 0));
    for (int i=0; i<(int)A.size() && 2*i<=V; ++i) {
        int rem = min((int)B.size(), V-2*i);
        int val = sumA + sum[rem];
        if (val > best) {
            best = val;
            besti = i;
        }
        sumA += A[i].cap;
    }

    cout << best << '\n';
    bool space = false;
    for (int i=0; i<besti; ++i) {
        if (space) cout << ' ';
        cout << A[i].ind;
        space = true;
    }
    for (int i=0; i<(int)B.size() && i<V-2*besti; ++i) {
        if (space) cout << ' ';
        cout << B[i].ind;
        space = true;
    }
    cout << '\n';

    return 0;
}
