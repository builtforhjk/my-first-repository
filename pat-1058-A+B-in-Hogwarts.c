#include <stdio.h>
int main(){
    int g1,g2,s1,s2,k1,k2,g3,s3,k3;
    scanf("%d.%d.%d",&g1,&s1,&k1);
    scanf("%d.%d.%d",&g2,&s2,&k2);
    int deltaK = (k1+k2)/29;
    k3 = (k1+k2)%29;
    int deltaS = (s1+s2+deltaK)/17;
    s3 = (s1+s2+deltaK)%17;
    g3 = g1+g2+deltaS;
    printf("%d.%d.%d\n",g3,s3,k3);
    return 0;
}
