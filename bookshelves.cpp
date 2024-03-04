#include <cstdio>
#include <climits>
#include <vector>

int w;
std::vector<std::vector<std::vector<std::vector<int> > > > data;

int solve(int s, int m, int l, int u) {
    if(s == 0 && m == 0 && l == 0)
        return u != w;

    if(data[s][m][l][u] != -1)
        return data[s][m][l][u];

    int shelves = INT_MAX;
    if(s) {
        if(u - 1 >= 0)
            shelves = std::min(shelves, solve(s - 1, m, l, u - 1));
        else
            shelves = std::min(shelves, 1 + solve(s - 1, m, l, w - 1));
    }
    if(m) {
        if(u - 2 >= 0)
            shelves = std::min(shelves, solve(s, m - 1, l, u - 2));
        else
            shelves = std::min(shelves, 1 + solve(s, m - 1, l, w - 2));
    }
    if(l) {
        if(u - 3 >= 0)
            shelves = std::min(shelves, solve(s, m, l - 1, u - 3));
        else
            shelves = std::min(shelves, 1 + solve(s, m, l - 1, w - 3));
    }

    data[s][m][l][u] = shelves;
    return shelves;
}

int main() {
    int s, m, l;
    scanf("%d %d %d %d", &s, &m, &l, &w);
    data.assign(s + 1, std::vector<std::vector<std::vector<int>>>(
                           m + 1, std::vector<std::vector<int>>(
                                          l + 1, std::vector<int>(w + 1, -1))));
    int ans = solve(s, m, l, w);
    printf("%d\n", ans);
}
