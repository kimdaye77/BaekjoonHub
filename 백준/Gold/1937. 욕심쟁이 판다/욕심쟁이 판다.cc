#include <bits/stdc++.h>
#define FASTIO cin.tie(NULL), cout.tie(NULL), ios_base::sync_with_stdio(false);

using namespace std;

int dp[500][500];
int a[500][500];
int N;
int d[4][2] = { { 0, -1 }, { 0, +1 }, { -1, 0 }, { +1, 0 } };

bool chk(int col, int row)
{
    if (col == N || col < 0 || row == N || row < 0)
        return false;
    return true;
}

int dfs(int x, int y)
{
    if (dp[x][y] != -1)
        return dp[x][y];

    int result = 1;
    for (int i = 0; i < 4; i++) {
        int X = x + d[i][0];
        int Y = y + d[i][1];
        if (chk(X, Y) && a[x][y] < a[X][Y]) {
            result = max(result, 1 + dfs(X, Y));
        }
    }

    dp[x][y] = result;
    return result;
}

int main()
{
    FASTIO;
    cin >> N;
    memset(dp, -1, sizeof(int) * 500 * 500);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int n;
            cin >> n;
            a[i][j] = n;
        }
    }

    int res = -1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res = max(res, dfs(i, j));
        }
    }

    cout << res << "\n";

    return 0;
}
