#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct{
    int hh;
    int mm;
    int ss;
    int wait;
}Time;
bool compare(Time t1, Time t2){
    if(t1.hh == t2.hh){
        if(t1.mm == t2.mm) return t1.ss < t2.ss;
        else return t1.mm < t2.mm;
    }
    return t1.hh < t2.hh;
}
int main(){
    vector <Time> arrivals;
    int n,k;
    cin>>n>>k;
    for(int i = 0; i < n; ++i){
        Time t;
        string s;
        cin>>s;
        t.hh = stoi(s);
        t.mm = stoi(s.substr(3));
        t.ss = stoi(s.substr(6));
        cin>>t.wait;
        arrivals.push_back(t);
    }
    sort(arrivals.begin(), arrivals.end(), compare);
    int sum = 0;
    int queue = 0;
    int * onWait = new int[k];
    for(int i = 0; i < k; ++i){
        onWait[i] = 8*3600;
    }
    for(auto item : arrivals){
        int con = item.hh*3600+item.mm*60+item.ss;
        if(con > 17 * 3600) break;
        ++queue;
        int pos= 0;
        int standby = onWait[0];
        for(int i = 1; i < k; ++i){
            if(onWait[i] < standby){
                standby = onWait[i];
                pos = i;
            }
        }
        if(con < standby){
            sum += standby - con;
            onWait[pos] = standby+item.wait*60;
        }
        else{
            onWait[pos] = con+item.wait*60;
        }
    }
    if(!queue) cout<<0.0<<endl;
    else printf("%.1f\n",(double)sum/(queue*60));
    return 0;
}
