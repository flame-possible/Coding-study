#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define len 100000

using namespace std;

int N, K;
int w[101] = { 0 }, v[101] = { 0 };
int dp[101][100001] = { 0 };

int main(void)
{
        cin.tie(NULL);
        ios::sync_with_stdio(false);

        cin >> N >> K;
        for (int i = 1; i <= N; i++)
                cin >> w[i] >> v[i];

        for (int i = 1; i <= N; i++)
        {
                for (int j = 1; j <= K; j++)
                {
                        if (j >= w[i])
                                dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
                        else dp[i][j] = dp[i - 1][j];
                }
        }

        cout << dp[N][K] << '\n';

        return 0;
}
