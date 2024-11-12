#include<stdio.h>
int main(){
    int n;
    printf("Enter the total no of activities = ");
    scanf("%d",&n);

     int start[n];
     printf("Enter the start time for each time activity = ");

     for(int i=0; i<n; i++)
     {
        scanf("%d", &start[n]);
     }

     int finish[n];
     printf("Enter the finish time for each time avtivity = ");
    
    for(int i=0; i<n; i++)
    {
        scanf("%d",&finish[n]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (finish[i] > finish[j])
            {
                int temp = start[i];
                start[i] = start[j];
                start[j] = temp;

                temp = finish[i];
                finish[i] = finish[j];
                finish[j] = temp;
            }
        }
    }
    printf("Selected activities: ");
    printf("(%d, %d) ", start[0], finish[0]);

    int last = finish[0];
    for (int i = 1; i < n; i++)
    {
        if (start[i] >= last)
        {
            printf("(%d, %d) ", start[i], finish[i]);
            last = finish[i];
        }
    }
    printf("\n");
    return 0;
}


