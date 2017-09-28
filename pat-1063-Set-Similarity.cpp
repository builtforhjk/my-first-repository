#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
set<int> stat[51];
double similarity(int t1, int t2){
    int count = 0;
    auto iter1 = stat[t1-1].begin();
    auto iter2 = stat[t2-1].begin();
    for(;(iter1!=stat[t1-1].end() && iter2!=stat[t2-1].end());){
        if(*iter1 == *iter2){
            ++count;
            ++iter1;
            ++iter2;
        }
        else if(*iter1 > *iter2){
            ++iter2;
        }
        else ++iter1;
    }
    return (double)count/(double)(stat[t1-1].size()+stat[t2-1].size()-count);
}
int main(){
    int n;
    scanf("%d",&n);
    int i;
    for(i = 0; i < n; ++i){
        int m;
        scanf("%d",&m);
        int j;
        for(j = 0; j < m; ++j){
            int t;
            scanf("%d",&t);
            stat[i].insert(t);
        }
    }
    int m;
    scanf("%d",&m);
    for(i = 0; i < m; ++i){
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        printf("%.1lf",((double)similarity(t1,t2)*100));
        cout<<'%'<<endl;
    }
    return 0;
}
