// name: Xinrui Yi
// Link: https://leetcode.com/problems/perfect-squares/

int numSquares(int n)
{
    int dp[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int j = 1; j < n + 1; j++)
    {
        for (int i = 1; i * i <= j; i++)
        {
            dp[j] = fmin(dp[j], dp[j - i * i] + 1);
        }
    }
    return dp[n];
}