#include <vector>
#include <queue>
#include <cstdio>
#include <climits>
#include <float.h>

int n, m, x; // # cities, # roads, % of min distance
std::vector<std::vector<std::pair<int, double> > > g; // graph
std::vector<double> d; // distances
std::vector<int> p; // parents
int max_length = INT_MAX;

double dijkstra() {
    std::fill(d.begin(), d.end(), DBL_MAX);
    std::fill(p.begin(), p.end(), -1);
    std::priority_queue<int, std::vector<int>, std::greater<int> > q;
    d[1] = 0;
    q.push(1);

    while(!q.empty()) {
        int curr = q.top();
        q.pop();

        for(std::pair<int, double> i : g[curr]) {
            int adj = i.first;
            double edg = i.second;
            if(edg + d[curr] < d[adj] && edg < max_length) {
                p[adj] = curr;
                d[adj] = edg + d[curr];
                q.push(adj);
            }
        }
    }

    return d[n];
}

int main() {
    // Scan inputs
    scanf("%d %d %d", &n, &m, &x);
    g.resize(n + 1);
    d.resize(n + 1);
    p.resize(n + 1);
    for(int i = 0; i < m; i++) {
        int c1, c2;
        double t;
        scanf("%d %d %lf", &c1, &c2, &t);
        g[c1].push_back(std::pair<int, double>(c2, t));
        g[c2].push_back(std::pair<int, double>(c1, t));
    }

    double recent_path = dijkstra();
    double max_path = recent_path + (recent_path * (x / 100.0));

    while(recent_path <= max_path) {
        int curr = n;
        double longest_length = -1;
        if(p[curr] == -1)
            break;
        while(p[curr] != -1) {
            longest_length = std::max(longest_length, d[curr] - d[p[curr]]);
            curr = p[curr];
        }
        max_length = longest_length;
        recent_path = dijkstra();
    }

    printf("%d", max_length);
}
