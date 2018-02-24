#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  string sc_number;
  cin>>sc_number;
  auto pivot = sc_number.find_first_of('E');
  int exponent = stoi(sc_number.substr(pivot+1));
  if(sc_number[0] == '-') cout<<"-";
  string fraction = sc_number.substr(1, pivot-1);
  if(exponent < 0){
    cout<<"0.";
    for(int i = -1; i > exponent; --i) cout<<"0";
    cout<<fraction[0]<<fraction.substr(2,pivot-3)<<endl;
  }
  else if(exponent > 0){
    int diff = exponent - ((int)fraction.length()-2);
    if(diff > 0){
      cout<<fraction[0]<<fraction.substr(2,pivot-3);
      for(int i = 0; i < diff; ++i) cout<<"0";
    }
    else if(diff < 0){
      cout<<fraction[0]<<fraction.substr(2,exponent)<<"."<<fraction.substr(exponent+2);
    }
    else cout<<fraction[0]<<fraction.substr(2,pivot-3);
    cout<<endl;
  }
  else cout<<fraction<<endl;
  return 0;
}
