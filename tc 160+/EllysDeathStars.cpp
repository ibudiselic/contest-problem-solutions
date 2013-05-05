#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>

using namespace std;

struct Ship {
    int sx, sy, ex, ey, speed, range, energy;
    Ship(const string &s) {
        istringstream is(s);
        is >> sx >> sy >> ex >> ey >> speed >> range >> energy;
    }
};

int X[20], Y[20];
const int NITER = 100;
const double EPS = 1e-12;
const double inf = 1e20;
double len(double x, double y) {
    return sqrt(x*x + y*y);
}
inline double sqr(double x) {
    return x*x;
}
double dist2(double x1, double y1, double x2, double y2) {
    return sqr(x2-x1) + sqr(y2-y1);
}
double dist(double x1, double y1, double x2, double y2) {
    return sqrt(dist2(x1, y1, x2, y2));
}

struct edge_t {
    int from, to, rev_idx;
    double cap;
    edge_t(int from_, int to_, int rev_idx_, double cap_): from(from_), to(to_), rev_idx(rev_idx_), cap(cap_) {}
};
class FlowNetwork {
public:
    FlowNetwork(): n(0) {}
    int add_node() {
        edges.push_back(vector<edge_t>());
        return n++;
    }
    int add_source() {
        source = add_node();
        return source;
    }
    int add_sink() {
        sink = add_node();
        return sink;
    }
    void add_edge(int from, int to, double cap) {
        edges[from].push_back(edge_t(from, to, int(edges[to].size()), cap));
        edges[to].push_back(edge_t(to, from, int(edges[from].size())-1, 0.0));
    }

    bool can_augment(vector<edge_t*> &P) {
        P.assign(n, (edge_t*)0);
        queue<int> Q;
        Q.push(source);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (int i=0; i<(int)edges[u].size(); ++i) {
                edge_t *e = &edges[u][i];
                if (e->to!=source && e->cap>EPS && !P[e->to]) {
                    P[e->to] = e;
                    if (e->to == sink) {
                        return true;
                    }
                    Q.push(e->to);
                }
            }
        }
        return false;
    }
    double max_flow() {
        double flow = 0.0;
        vector<edge_t*> P;
        while (can_augment(P)) {
            double by = inf;
            int u = sink;
            while (u != source) {
                edge_t *e = P[u];
                by = min(by, e->cap);
                u = e->from;
            }
            flow += by;
            u = sink;
            while (u != source) {
                edge_t *e = P[u];
                e->cap -= by;
                edges[e->to][e->rev_idx].cap += by;
                u = e->from;
            }
        }
        return flow;
    }

private:
    int n;
    int source, sink;
    vector< vector<edge_t> > edges;
};
class EllysDeathStars {
public:
    double getMax(vector <string> stars, vector <string> ships) {
        int nstars = stars.size();
        int nships = ships.size();
        for (int i=0; i<nstars; ++i) {
            sscanf(stars[i].c_str(), "%d %d", X+i, Y+i);
        }
        vector<Ship> V;
        for (int i=0; i<nships; ++i) {
            V.push_back(Ship(ships[i]));
        }

        FlowNetwork F;
        int source = F.add_source();
        int sink = F.add_sink();
        vector<int> ship_nodes;
        vector<pair<double, int> > events[20];
        for (int i=0; i<nships; ++i) {
            ship_nodes.push_back(F.add_node());
            if (V[i].ex==V[i].sx && V[i].ey==V[i].sy) {
                continue;
            }
            F.add_edge(source, ship_nodes.back(), V[i].energy);
            double dx = V[i].ex - V[i].sx;
            double dy = V[i].ey - V[i].sy;
            for (int j=0; j<nstars; ++j) {
                double lo = 0.0;
                double hi = 1.0;
                for (int iter=0; iter<NITER; ++iter) {
                    double m1 = lo + (hi-lo)/3;
                    double m2 = m1 + (hi-lo)/3;
                    if (dist2(V[i].sx+m1*dx, V[i].sy+m1*dy, X[j], Y[j]) < dist2(V[i].sx+m2*dx, V[i].sy+m2*dy, X[j], Y[j])) {
                        hi = m2;
                    } else {
                        lo = m1;
                    }
                }
                if (dist(V[i].sx+lo*dx, V[i].sy+lo*dy, X[j], Y[j]) >= V[i].range-EPS) {
                    continue;
                }
                double center = lo;
                lo = 0.0;
                hi = center;
                for (int iter=0; iter<NITER; ++iter) {
                    double mid = (lo+hi)/2;
                    if (dist(V[i].sx+mid*dx, V[i].sy+mid*dy, X[j], Y[j]) < V[i].range) {
                        hi = mid;
                    } else {
                        lo = mid;
                    }
                }
                double left = hi;
                lo = center;
                hi = 1.0;
                for (int iter=0; iter<NITER; ++iter) {
                    double mid = (lo+hi)/2;
                    if (dist(V[i].sx+mid*dx, V[i].sy+mid*dy, X[j], Y[j]) < V[i].range) {
                        lo = mid;
                    } else {
                        hi = mid;
                    }
                }
                double right = lo;
                events[j].push_back(make_pair(len(left*dx, left*dy)/V[i].speed, i));
                events[j].push_back(make_pair(len(right*dx, right*dy)/V[i].speed, i));
            }
        }

        for (int j=0; j<nstars; ++j) {
            sort(events[j].begin(), events[j].end());
            int in_range = 0;
            for (int i=0; i+1<(int)events[j].size(); ++i) {
                const pair<double, int> &e = events[j][i];
                double t = e.first;
                int ship = e.second;
                in_range ^= 1<<ship;
                if (in_range > 0) {
                    double event_duration = events[j][i+1].first - t;
                    if (event_duration < EPS) {
                        continue;
                    }
                    int event_node = F.add_node();
                    F.add_edge(event_node, sink, event_duration);
                    for (int k=0; k<nships; ++k) {
                        if (in_range & (1<<k)) {
                            F.add_edge(ship_nodes[k], event_node, inf);
                        }
                    }
                }
            }
        }

        return F.max_flow();
    }
};
