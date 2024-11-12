#include <stdio.h>
#include <string.h>

void search(char p[], char t[]);

int main() {
    char p[100], t[100];

    printf("Enter the main string (pattern): ");
    scanf("%s", p);

    printf("Enter the substring to search (text): ");
    scanf("%s", t);

    search(p, t);

    return 0;
}

void search(char p[], char t[]) {
    int pattern = strlen(p);
    int text = strlen(t);
    for (int i = 0; i <= pattern - text; i++) {
        int j;
        for (j = 0; j < text; j++) {
            if (p[i + j] != t[j]) {
                break;
            }
        }
        if (j == text) {
            printf("Index found: %d\n", i);
        }
    }
}
