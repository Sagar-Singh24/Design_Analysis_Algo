#include <stdio.h>

void fractionalKnapsack(int n, float weight[], float profit[], float capacity) {
    float x[20], total_profit = 0;
    int i, j;
    float temp;
    
    // Calculate profit/weight ratio
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if ((profit[i] / weight[i]) < (profit[j] / weight[j])) {
                // Swap weights
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
                
                // Swap profits
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    // Greedily select items
    for (i = 0; i < n; i++) {
        if (weight[i] > capacity)
            break;
        else {
            x[i] = 1.0;
            total_profit += profit[i];
            capacity -= weight[i];
        }
    }

    if (i < n) {
        x[i] = capacity / weight[i];
        total_profit += (x[i] * profit[i]);
    }

    printf("\nThe result vector (fraction of each item taken): ");
    for (i = 0; i < n; i++) {
        printf("%.2f ", x[i]);
    }

    printf("\nMaximum profit: %.2f\n", total_profit);
}

int main() {
    int n, i;
    float weight[20], profit[20], capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of the items:\n");
    for (i = 0; i < n; i++) {
        printf("Weight of item %d: ", i + 1);
        scanf("%f", &weight[i]);
    }

    printf("Enter the profits of the items:\n");
    for (i = 0; i < n; i++) {
        printf("Profit of item %d: ", i + 1);
        scanf("%f", &profit[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    fractionalKnapsack(n, weight, profit, capacity);

    return 0;
}