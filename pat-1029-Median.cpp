#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int main(){
    int s1_length = 0;
    int s2_length = 0;
    vector <long int> s1;
    vector <long int> s2;
    scanf("%d",&s1_length);
    for(int i = 0; i < s1_length; ++i){
        long int temp;
        scanf("%ld",&temp);
        s1.push_back(temp);
    }
   scanf("%d",&s2_length);
    for(int i = 0; i < s2_length; ++i){
        long int temp;
        scanf("%ld",&temp);
        s2.push_back(temp);
    }
    s2.insert(s2.end(),s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    printf("%ld\n",s2[(s2.size()-1)/2]);
    return 0;
}
