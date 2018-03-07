#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  for(int i = 0; i < n; ++i){
    string tmp;
    cin>>tmp;
    long long origin = stoll(tmp),higher = stoll(tmp.substr(0,(int)tmp.size()/2)),lower =stoll(tmp.substr((int)tmp.size()/2));
    if(higher*lower==0 || origin%(higher*lower)) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
  }
  return 0;
}
