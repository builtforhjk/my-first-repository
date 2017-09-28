#include <stdio.h>
int main() {  
    int n;  
    scanf("%d",&n);  
    int i;  
    double in, sum = 0.0;
    for(i=0; i<n; i++){  
      scanf("%lf",&in);
      sum += in*(i+1)*(n-i);
    } 
    printf("%.2lf\n",sum);  
    return 0;  
}
