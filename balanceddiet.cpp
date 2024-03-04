#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

std::vector<int> v;

int find_closest(int start, int target) {
    // Base case
    if(start == v.size() - 1) {
        if(v[start] > target)
            return 0;
        return v[start];
    }

    // Go thru all subcases
    int closest = 0;
    for(int i = start; i < v.size(); i++) {
        if(v[i] > target)
            continue;
        int temp = v[i] + find_closest(i + 1, target - v[i]);
        if(temp > closest)
            closest = temp;
    }

    return closest;
}

int main() {
    while(1) {
        // Read input
        int n;
        scanf("%d", &n);
        if(n == 0)
            break;
        v.resize(n, 0);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            int t;
            scanf("%d", &t);
            v[i] = t;
            sum += t;
        }

        // Sort
        std::sort(v.begin(), v.end(), std::greater<int>());

        // Find second day
        int second = find_closest(0, sum / 2);

        // Print
        printf("%d %d\n", sum - second, second);
    }
}
