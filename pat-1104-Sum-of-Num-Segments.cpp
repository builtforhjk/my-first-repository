
#include <iostream>  
#include <string>  
#include <vector>  
#include <cmath>  
using namespace std;  
  
int main(int argc, char** argv) {  
    int n;  
    scanf("%d",&n);  
    int i;  
    double t, sum = 0;  
    vector<double> vec;  
    for(i=0; i<n; i++){  
        scanf("%lf",&t);  
        vec.push_back(t);  
    }  
   
    int len = vec.size();  
    for(i=0; i<vec.size(); i++){  
        sum += vec[i] * (i+1)*(len-i);  
    }  
    
    printf("%.2lf\n",sum);  
    return 0;  
} 
