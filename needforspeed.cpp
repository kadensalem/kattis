#include<cstdio>
int main() {
    // All of the data that will be input
    int n, total_time;
    int distances[1000], speeds[1000];

    int min_speed = 1000; // Used for calculating lower bound

    // Read in the input
    scanf("%d %d", &n, &total_time);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &distances[i], &speeds[i]);
        if(speeds[i] < min_speed)
            min_speed = speeds[i];
    }

    // Generate bounds
    double lower_bound = -min_speed;
    double upper_bound = 1e9;
    double midpoint;

    // Keep guessing until our precision is at least 1e-6
    while(upper_bound - lower_bound > 1e-9) {
        // Our guess for c
        midpoint = (lower_bound + upper_bound) / 2;

        // Calculate our estimated final time
        double estimated_total_time = 0;
        for(int i = 0; i < n; i++) {
            estimated_total_time += (double)distances[i] / (midpoint + speeds[i]);
        }

        // Over or underestimate?
        if(estimated_total_time < total_time)
            upper_bound = midpoint;
        else
            lower_bound = midpoint;
    }

    // Print out the answer
    printf("%0.9lf", midpoint);
}
