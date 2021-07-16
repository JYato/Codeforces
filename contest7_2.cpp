#include <bits/stdc++.h>

#define N 61
#define INF 10000000

using namespace std;

int main()
{
    int dp[N][N][N];
    int temp[N][N][N];
    int n,m,r; cin >> n >> m >> r;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                cin >> temp[i][j][k];
            }
        }
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                for(int l = 1; l <= n; l++){
                    temp[i][k][l] = min(temp[i][k][l], temp[i][k][j] + temp[i][j][l]);
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                dp[i][j][k] = INF;
            }
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                for(int l = 1; l <= n; l++){
                    dp[0][k][l] = min(dp[0][k][l], temp[i][k][l]);
                }
            }
        }
    }
    for(int a = 1; a < n-1; a++){
        for(int b = 1; b <= n; b++){
            for(int c = 1; c <= n; c++){
                for(int d = 1; d <= n; d++){
                    dp[a][c][d] = min(dp[a][c][d], dp[a-1][c][b] + dp[0][b][d]);
                }
            }
        }
    }
    while(r--){
        int s,t,k; cin >> s >> t >> k;
        int res = INF; k = min(k,n-2);
        for(int i = 0; i <= k; i++){
            res = min(res, dp[i][s][t]);
        }
        cout << res << endl;
    }

    return 0;
}
