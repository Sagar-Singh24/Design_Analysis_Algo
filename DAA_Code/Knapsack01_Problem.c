#include <stdio.h>

void knapSack(int W, int wt[], int val[], int n) {
    int i, j;
    int T[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                T[i][j] = 0;
            } else if (wt[i] <= j) {
                T[i][j] = (T[i - 1][j] > (val[i] + T[i - 1][j - wt[i]])) ? T[i - 1][j] : (val[i] + T[i - 1][j - wt[i]]);
            } else {
                T[i][j] = T[i - 1][j];
            }
        }
    }

    printf("Knapsack Table:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            printf("%d\t", T[i][j]);
        }
        printf("\n");
    }
    printf("\nMaximum profit: %d\n", T[n][W]);
    int max_profit = T[n][W];
    printf("Items included to achieve the maximum profit:\n");
    j = W;
    for (i = n; i > 0 && max_profit > 0; i--) {
        if (max_profit != T[i - 1][j]) {
            printf("Item %d (Value: %d, Weight: %d)\n", i, val[i], wt[i]);
            max_profit -= val[i];
            j -= wt[i];
        }
    }
}
int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int val[n + 1], wt[n + 1];
    for (int i = 1; i <= n; i++) {
        printf("Enter value and weight for item %d: ", i);
        scanf("%d %d", &val[i], &wt[i]);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    knapSack(W, wt, val, n);

    return 0;
}