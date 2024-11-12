#include <stdio.h>
#include <limits.h>

void print_optimal_parenthesis(int i, int j, int n, int s[n][n]) {
    if (i == j) {
        printf("M%d", i);
        return;
    }
    printf("(");
    print_optimal_parenthesis(i, s[i][j], n, s);
    print_optimal_parenthesis(s[i][j] + 1, j, n, s);
    printf(")");
}
void matrix_chain_order(int p[], int n) {
    int m[n][n];
    int s[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = 0;
            s[i][j] = 0;
        }
    }
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("\nCost Table (m):\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i > j) {
                printf("    - "); 
            } else {
                printf("%6d ", m[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nK Value Table (s):\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i >= j) {
                printf("    - ");
            } else {
                printf("%6d ", s[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nOptimal Parenthesization: ");
    print_optimal_parenthesis(1, n - 1, n, s);
    printf("\nMinimum number of multiplications: %d\n", m[1][n - 1]);
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];
    printf("Enter the dimensions of the matrices:\n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    matrix_chain_order(p, n + 1);

    return 0;
}