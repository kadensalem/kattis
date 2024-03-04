#include <vector>
#include <cstdio>
#include <queue>
#include <unordered_set>
using namespace std;

class Stick {
    public:
    unordered_set<int> parents;
    unordered_set<int> children;
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<Stick> sticks(n+1);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        sticks[a].children.insert(b);
        sticks[b].parents.insert(a);
    }

    int count = 0;
    queue<int> q;
    for(int i = 1; i < sticks.size(); i++) {
        Stick s = sticks[i];
        if(s.parents.size() == 0)
            q.push(i);
    }

    queue<int> print;

    while(!q.empty()) {
        int curr = q.front();
        count++;
        print.push(curr);
        q.pop();
        for(int child : sticks[curr].children) {
            sticks[child].parents.erase(curr);
            if(sticks[child].parents.size() == 0)
                q.push(child);
        }
    }

    if(count != n) {
        printf("IMPOSSIBLE\n");
    }   
    else {
        while(!print.empty()) {
            printf("%d\n", print.front());
            print.pop();
        }
    } 
}
