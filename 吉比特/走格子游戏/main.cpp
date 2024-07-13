#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    vector<vector<int>> grid(M, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(M, vector<int>(N, 0));

    dp[M-1][N-1] = max(1, 1 - grid[M-1][N-1]);

    for (int i = M - 2; i >= 0; --i) {
        dp[i][N-1] = max(1, dp[i+1][N-1] - grid[i][N-1]);
    }

    for (int j = N - 2; j >= 0; --j) {
        dp[M-1][j] = max(1, dp[M-1][j+1] - grid[M-1][j]);
    }

    for (int i = M - 2; i >= 0; --i) {
        for (int j = N - 2; j >= 0; --j) {
            int min_hp_on_exit = min(dp[i+1][j], dp[i][j+1]);
            dp[i][j] = max(1, min_hp_on_exit - grid[i][j]);
        }
    }

    cout << dp[0][0] << endl;
    return 0;
}
