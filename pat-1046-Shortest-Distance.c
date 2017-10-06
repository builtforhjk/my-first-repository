#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int *pre = (int*)malloc(sizeof(int)*(n+1));
    int i;
    pre[0] = 0;
    for(i = 1; i <= n; ++i){
        scanf("%d",pre+i);
        pre[i] += pre[i-1];
    }
    int query;
    scanf("%d",&query);
    for(i = 0; i < query; ++i){
        int st, ta;
        scanf("%d %d",&st,&ta);
        int p = abs(pre[ta-1] - pre[st-1]);
        int q = pre[n]-p;
        int res = (p<q?p:q);
        printf("%d\n",res);
    }
    return 0;
}
