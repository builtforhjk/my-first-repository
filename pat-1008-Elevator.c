#include <stdio.h>
int N;
int list[101];
int total;
int calDuration(int next){
    if(next > N){
        return total;
    }
    int diff = list[next] - list[next-1];
    total += (diff > 0?diff*6:diff*(-4))+5;
    return calDuration(next+1);
}
int main(){
    scanf("%d",&N);
    list[0]=0;
    total=0;
    for(int i = 1; i <= N; ++i){
        scanf("%d",list+i);
    }
    printf("%d\n",calDuration(1));
    return 0;
}
