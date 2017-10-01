#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int i;
    for(i = 0; i < n; ++i){
        long long a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        printf("Case #%d: ",i+1);
        long long add = a+b;
        if(a>0 && b>0 &&  ((add>0 && add>c) || add<=0)) printf("true\n");
        else if(a<0 && b<0 && add<0 && add>c) printf("true\n");
        else if(((a<=0 && b>=0) || (a>=0 && b<=0)) && add>c) printf("true\n");
        else printf("false\n");
    }
    return 0;
}
