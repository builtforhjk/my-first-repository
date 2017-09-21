#include <stdio.h>
#include <stdlib.h>
int n,k,*mice,*order,*r;
int main(){
    scanf("%d%d",&n,&k);
    int i;
    mice = (int *)malloc(sizeof(int)*n);
    order = (int *)malloc(sizeof(int)*n);
    r = (int *)malloc(sizeof(int)*n);
    for(i = 0; i < n; ++i){
        scanf("%d", mice+i);
    }
    for(i = 0; i < n; ++i){
        scanf("%d", order+i);
    }
    int remain = n;
    while(remain > 1){
        int num = 0;
        int le = remain/k+(remain%k==0?0:1);
        for(i = 0; i < remain; i += k){
            int j;
            int pos = order[i];
            int val = mice[pos];
            for(j = 1; j < k; ++j){
                if(i+j >= remain) break;
                if(mice[order[i+j]] > val){
                    val = mice[order[i+j]];
                    r[pos] = le+1;
                    pos = order[i+j];
                }
                else r[order[i+j]] = le+1;
            }
            order[num++] = pos;
        }
        remain = num;
    }
    r[order[0]] = 1;
    for(i = 0; i < n; ++i){
        if(i == (n-1)) printf("%d\n",r[i]);
        else printf("%d ",r[i]);
    }
    return 0;
}