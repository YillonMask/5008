// name: Xinrui Yi
// link: https://leetcode.com/problems/cheapest-flights-within-k-stops/

int findCheapestPrice(int n, int **flights, int flightsSize, int *flightsColSize, int src, int dst, int k)
{
    // initialize dp
    int dp[n][k + 2];
    int i, j, max = 10e6;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k + 1; j++)
        {
            if (i == src)
            {
                // price to get src is 0
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = max;
            }
        }
    }
    // iterate all the flights k + 1times and update dp
    for (int i = 1; i <= k + 1; i++)
    {
        for (int j = 0; j < flightsSize; j++)
        {
            int from = flights[j][0];
            int to = flights[j][1];
            int price = flights[j][2];
            if (dp[from][i - 1] < max)
            {
                dp[to][i] = fmin(dp[to][i], dp[from][i - 1] + price);
            }
        }
    }
    return (dp[dst][k + 1] == max) ? -1 : dp[dst][k + 1];
}