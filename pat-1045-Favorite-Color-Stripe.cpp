#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    int f[201];
    for(i = 1; i <= m; ++i){
        scanf("%d",f+i);
    }
    scanf("%d",&n);
    int st[10001];
    for(i = 1; i <= n; ++i){
        scanf("%d",st+i);
    }
    int dp[201][10001] = {{0}};
    int max_len = 0;
    for(i = 1; i <= m; ++i){
    	int j;
    	for(j = 1; j <= n; ++j){
    		dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    		if(st[j] == f[i]) ++dp[i][j];
    	}
    }
    for(i = 1; i <= n; ++i){
    	if(dp[m][i] > max_len) max_len = dp[m][i];
    }
    printf("%d\n",max_len);
    return 0;
}