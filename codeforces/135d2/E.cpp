#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

int inf = 987654321;
struct Node {
    int left_car, right_car, best_pos, best_dist, size;
    Node(): left_car(-inf), right_car(+inf), best_pos(0), best_dist(0), size(1) {}
    string str() const {
        ostringstream os;
        os << size << ' ' << left_car << ' ' << right_car << ' ' << best_pos << ' ' << best_dist;
        return os.str();
    }
};
Node join(const Node &a, const Node &b) {
    Node res;
    if (a.left_car != -inf) {
        res.left_car = a.left_car;
    } else if (b.left_car != -inf) {
        res.left_car = a.size + b.left_car;
    } else {
        res.left_car = -inf;
    }
    if (b.right_car != +inf) {
        res.right_car = a.size + b.right_car;
    } else if (a.right_car != +inf) {
        res.right_car = a.right_car;
    } else {
        res.right_car = +inf;
    }
    res.size = a.size + b.size;
    res.best_pos = a.best_pos;
    res.best_dist = a.best_dist;
    if (b.best_dist > res.best_dist) {
        res.best_pos = a.size + b.best_pos;
        res.best_dist = b.best_dist;
    }
    int center_dist, center_pos;
    if (a.right_car == inf) {
        if (b.left_car == -inf) { // no cars
            center_dist = (res.size-1)/2;
            center_pos = center_dist;
        } else {
            center_dist = (a.size + b.left_car - 1)/2;
            center_pos = center_dist;
        }
    } else if (b.left_car == -inf) {
        center_dist = (a.size-1-a.right_car+b.size - 1)/2;
        center_pos = a.right_car + 1 + center_dist;
    } else {
        center_dist = (a.size + b.left_car - a.right_car - 2);
        if (center_dist < 0) {
            center_pos = inf;
        } else {
            center_dist /= 2;
            center_pos = a.right_car + 1 + center_dist;
        }
    }
    if (center_dist>res.best_dist || (center_dist==res.best_dist && center_pos<res.best_pos)) {
        res.best_pos = center_pos;
        res.best_dist = center_dist;
    }

    //cerr << "joined " << a.str() << "\nand\n" << b.str() << "\ninto\n" << res.str() << '\n';
    return res;
}
class TournamentTree {
public:
    TournamentTree(int N) {
        n = 1;
        while (n < N) {
            n <<= 1;
        }
        T.assign(2*n, Node());
        for (int i=N; i<n; ++i) {
            T[n+i].size = 0;
        }
        for (int i=n-1; i>0; --i) {
            T[i] = join(T[2*i], T[2*i+1]);
        }
    }
    void set(int pos) {
        pos += n;
        T[pos].left_car = T[pos].right_car = 0;
        T[pos].best_dist = -1;
        fix_up(pos/2);
    }
    void clear(int pos) {
        pos += n;
        T[pos].left_car = -inf;
        T[pos].right_car = +inf;
        T[pos].best_dist = 0;
        fix_up(pos/2);
    }
    int query() const {
        const Node &x = T[1];
        //cerr << x.str() << '\n';
        int ret = x.best_pos;
        int best = x.best_dist;
        if (x.left_car == -inf) {
            assert(x.right_car == +inf);
            return 0;
        }
        assert(x.right_car < +inf);
        if (x.left_car-1 >= best) {
            ret = 0;
            best = x.left_car - 1;
        }
        if (x.size-x.right_car-2 > best) {
            ret = x.size - 1;
            best = x.size-x.right_car-2;
        }

        return ret;
    }
private:
    int n;
    vector<Node> T;

    void fix_up(int node) {
        while (node > 0) {
            T[node] = join(T[2*node], T[2*node+1]);
            node /= 2;
        }
    }
};
int pos[1000000];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    TournamentTree T(n);
    for (int i=0; i<m; ++i) {
        int type, k;
        scanf("%d %d", &type, &k);
        if (type == 1) {
            int sol = T.query();
            //cerr << "adding " << sol + 1 << '\n';
            T.set(sol);
            pos[k-1] = sol;
            printf("%d\n", sol + 1);
        } else {
            T.clear(pos[k-1]);
            //cerr << "removing " << pos[k-1] + 1 << '\n';
        }
    }
    return 0;
}
