#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}
void knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1));
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
    cout << K[n][W] << endl;

    cout << "Object(s): ";
    int arr[n]={0};
    int s=0;
    for (int i = n - 1; i > 0; i--)
    {
        if (K[i][W] != K[i - 1][W]){
            arr[s++] = i;
            W = W - wt[i - 1];
            }
    }
    reverse(arr, arr + s);
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] ;
        if(i!=s-1) cout << ", ";
    }
    cout << endl;
}
int main()
{
    int n, W;
    // cout << "Enter the number of items and the capacity of the knapsack: ";
    cin >> n >> W;

    // cout << "Enter the weight and value of each item: " << endl;
    int val[n] = {0};
    int wt[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> val[i] >> wt[i];
    }

    cout << "Maximum profit: ";
    knapSack(W, wt, val, n);
    return 0;
}

// report on this
//with example
// tables and code 
//  objective , decision ,code, visuals
//maximum output and used objects
// description,middle code explanation section by section, last full code

// everything hand written except code 