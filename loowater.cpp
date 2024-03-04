#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
    // Scan input into heads and knights
    int h, k;

    Loop:
    while(1) {
        scanf("%d %d", &h, &k);
        if(h == 0 && k == 0)
            break;
        
        std::vector<int> hv(h);
        for(int i = 0; i < h; i++) {
            int t;
            scanf("%d", &t);
            hv[i] = t;
        }

        std::vector<int> kv(k);
        for(int i = 0; i < k; i++) {
            int t;
            scanf("%d", &t);
            kv[i] = t;
        }

        if(h > k) {
            printf("Loowater is doomed!\n");
            goto Loop;
        }

        // Sort both lists
        std::sort(hv.begin(), hv.end());
        std::sort(kv.begin(), kv.end());

        // keep track of height sum
        int sum = 0;
        int kp = 0;
        for(int i = 0; i < h; i++) {
            if(kp >= k) {
                printf("Loowater is doomed!\n");
                goto Loop;
            }
            int curr_head = hv[i];
            while(kv[kp] < curr_head) {
                kp++;
                if(kp >= k) {
                    printf("Loowater is doomed!\n");
                    goto Loop;
                }
            }
            sum += kv[kp];
            kp++;
        }

        printf("%d\n", sum);
    }
}
