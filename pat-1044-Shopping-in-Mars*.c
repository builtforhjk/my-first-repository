#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int total;
    scanf("%d",&total);
    int *preSum = (int*)malloc(sizeof(int)*(n+1));
    preSum[0] = 0;
    int i;
    for(i = 1; i <= n; ++i){
        scanf("%d",preSum+i);
        preSum[i] += preSum[i-1];
    }
    int have = 0;
    int diff = 10000000;
    int count = 0;
    int st[100000];
    int ta[100000];
    for(int i = 0; i < n; ++i){
        int j = i+1;
        for(; j <= n; ++j){
            if(preSum[j]-preSum[i] == total){
                have = 1;
                printf("%d-%d\n",i+1,j);
            }
            else if(preSum[j]-preSum[i] > total){
                if(have) break;
                else{
                    if(preSum[j]-preSum[i]-total < diff){
                        diff = preSum[j]-preSum[i]-total;
                        count = 0;
                        st[count] = i+1;
                        ta[count] = j;
                        ++count;
                    }
                    else if(preSum[j]-preSum[i]-total == diff){
                        st[count] = i+1;
                        ta[count] = j;
                        ++count;
                    }
                    else break;
                }
            }
        }
    }
    if(!have){
        for(i = 0; i < count; ++i){
            printf("%d-%d\n",st[i],ta[i]);
        }
    }
    return 0;
}
