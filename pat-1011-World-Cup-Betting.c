#include <stdio.h>
#include <math.h>
int main(){
    double odds[3][3];
    int i, j;
    for(i = 0; i < 3; ++i){
        for(j = 0; j < 3; ++j) scanf("%lf",&odds[i][j]);
    }
    double sum = 1;
    int result[3] = {0,0,0};
    for(i = 0; i < 3; ++i){
        double m = odds[i][0];
        for(j = 1; j < 3; ++j){
            if(odds[i][j] > m){
                m = odds[i][j];
                result[i] = j;
            }
        }
        sum *= m;
    }
    sum = (sum*0.65-1)*2;
    for(i = 0; i < 3; ++i){
        switch(result[i]){
            case 0:
                printf("W ");
                break;
            case 1:
                printf("T ");
                break;
            case 2:
                printf("L ");
                break;
            default:
                break;
        }
    }
    int st = sum*1000;
    if(st%10 > 4) sum = (st+10-st%10)/1000.0;
    printf("%.2lf\n",sum);
    return 0;
}
