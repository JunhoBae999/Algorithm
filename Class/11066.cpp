#define MAX 1<<30
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<algorithm>


using namespace std;

int novel[500];
int p_sum[500];
int dp[500][500];

int main(void) {
    int T, m, i, j, k;
    scanf("%d", &T);
    for (m = 0; m < T; m++) {
        int K;
        scanf("%d", &K);
        for (i = 0; i < K; i++) {
            scanf("%d", &novel[i]);
            if (i == 0) p_sum[i] = novel[i];
            else p_sum[i] = p_sum[i - 1] + novel[i];        
        }
        for (i = 1; i < K; i++) {                            //���Ϸ��� ������ ���� = i
            for (j = 0; j + i < K; j++) {                        //������ ���� index = j
                dp[j][j + i] = MAX;
                for (k = j; k < j + i; k++) {
                    if (j == 0)    dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + p_sum[j + i]);
                    else dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + p_sum[j + i] - p_sum[j - 1]);
                }
            }
        }
        printf("%d\n", dp[0][K - 1]);
    }
}
