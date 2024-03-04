#include<cstdio>
#include<unordered_map>
#include<vector>
#include<stack>
int main() {
    // Scan params
    int c, p, x, l;
    scanf("%d %d %d %d", &c, &p, &x, &l);

    // Scan all partnerships
    std::unordered_map<int, std::vector<int>> map;
    std::vector<int> np(c + 1, 0);
    for(int i = 0; i < p; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a].push_back(b);
        np[a]++;
        map[b].push_back(a);
        np[b]++;
    }

    // Country leaves
    std::vector<int> status(c + 1, 0); // 0 means stay, 1 means leave
    status[l] = 1;
    for(int i : map[l])
        np[i]--;
    std::stack<int> stack;
    stack.push(l);

    // Iterate thru the graph
    while(!stack.empty()) {
        int curr = stack.top();
        stack.pop();

        // Iterate thru each partnership
        for(int i : map[curr]) {
            if(status[i] == 1)
                continue; // i has already left
            if(np[i] * 2 <= map[i].size()) { // Should country leave?
                status[i] = 1;
                for(int j : map[i])
                    np[j]--;
                stack.push(i);
            }
        }
    }

    // Print status of x
    if(status[x] == 0)
        printf("%s", "stay");
    else
        printf("%s", "leave");
}
