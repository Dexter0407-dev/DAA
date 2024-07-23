#include<stdio.h>


int max(int a, int b) { return (a > b) ? a : b; }


void knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];
   
   
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
   
    
    printf("Maximum value that can be put into the knapsack: %d\n", K[n][W]);
   
    
    int res = K[n][W];
    w = W;
    printf("Items included in the knapsack:\n");
    for (i = n; i > 0 && res > 0; i--)
    {
        if (res == K[i - 1][w])
            continue;
        else
        {
            printf("Item %d (weight = %d, Profit = %d) is included\n", i, wt[i - 1], val[i - 1]);
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
}

int main()
{
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
   
    int val[n], wt[n];
    printf("Enter weight and profit of items:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &wt[i], &val[i]);
    }
   
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);
   
    knapsack(W, wt, val, n);
   
    return 0;
}

