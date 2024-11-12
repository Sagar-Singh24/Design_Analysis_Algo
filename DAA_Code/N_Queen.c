#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void back_track(int nq, int arr[nq][nq], int i, int j, int);
int main()
{
    int nq;
    printf("Enter number of queens : ");
    scanf("%d", &nq);

    int arr[nq][nq];
    for(int i=0; i<nq; i++) {
        for(int j=0; j<nq; j++) {
            arr[i][j] = 0;
        }
    }

    int arr1[nq];
    for(int i=0; i<nq; i++) arr1[1] = 0;

    for(int i=0; i<nq; i++) { 
        for(int k=0; k<nq; k++) {
            for(int j=0; j<nq; j++) {
                arr[k][j] = 0;
            }
        }

        back_track(nq, arr, 0, i, 0);

        int count1 = 0;
        for(int i=0; i<nq; i++) {
            for(int j=0; j<nq; j++) {
                if(arr[i][j] == 1) {
                    count1++;
                    arr1[i] = j+1; 
                }
            }
        }

        if( count1 == nq ){
            for(int i=0; i<nq; i++) {
                for(int j=0; j<nq; j++) {
                    printf("%d  ",arr[i][j]);
                }
                printf("\n");
            }
            printf("\nSolution :\n");
            for(int j=0; j<nq; j++) {
                printf("%d  ",arr1[j]);
            }
            printf("\n\n");
        }

    }
    return 0;
}

void back_track(int nq, int arr[nq][nq], int i, int j, int p) {
    if( i == nq || j == nq ) return;
    int count = 0;
    int k, l;
    for(k=0; k<nq; k++) {
        for(l=0; l<nq; l++) {
            if( arr[k][j] == 1 || arr[i][l] == 1) count++;
            else if( arr[k][l] == 1 && abs(i-k) == abs(j-l)) count++;
        }
    }

    if( count == 0 ) {
        arr[i][j] = 1;
        for(int m=0; m<nq; m++)
            back_track(nq, arr, i+1, m, p+1);
    }
    else {
        for(int m=0; m<nq; m++)
        back_track(nq, arr, i, j+1, p);
    }

    return;    
}