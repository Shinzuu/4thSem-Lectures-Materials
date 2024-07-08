#include <iostream>
#include <climits>
using namespace std;

void matrixChainOrder(int arr[], int n)
{
    int dp[n + 1][n + 1];
    int K[n + 1][n + 1];

    // Initialize dp[i][i] to 0 and dp[i][i+1] to 0
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
        if (i < n)
            dp[i][i + 1] = 0;
    }

    // Compute minimum multiplications needed and optimal split points for each chain length
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                    K[i][j] = k; // Store optimal split point
                }
            }
        }
    }

    cout << "Minimum multiplication needed is " << dp[1][n] << endl;

    cout << "M matrix" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j < i)
            {
                cout << "0\t"; // Print 0 for lower triangle
            }
            else
            {
                cout << dp[i][j] << "\t";
            }
        }
        cout << endl;
    }
    cout << endl;

    cout << "K matrix" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j <= i)
            {
                cout << "0\t"; // Print 0 for lower triangle
            }
            else
            {
                cout << K[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n + 1];
    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }

    matrixChainOrder(arr, n);

    return 0;
}
