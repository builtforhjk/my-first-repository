#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
  int n;
  ios::sync_with_stdio(false);
  cin>>n;
  string earliest, latest, sign_in, sign_out;
  for(int i = 0; i < n; ++i){
    string id, in, out;
    cin>>id>>in>>out;
    if(i == 0){
      earliest = in;
      latest = out;
      sign_in = id;
      sign_out = id;
    }
    else{
      if(strcmp(in.c_str(), earliest.c_str()) < 0){
        earliest = in;
        sign_in = id;
      }
      if(strcmp(out.c_str(), latest.c_str()) > 0){
        latest = out;
        sign_out = id;
      }
    }
  }
  cout<<sign_in<<" "<<sign_out<<endl;
  return 0;
}
