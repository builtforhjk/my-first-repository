#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
void convert(string & s,int precision,int decimal){
    string a = "0.";
    int delta = 0;
    if(decimal <= 0){
        delta = 2 - decimal;
    }
    int i = 0;
    while(i < precision){
        if((i+delta) < s.size() && s[i+delta] != '.'){
            a = a + s[i+delta];
        }
        else if(s[i+delta] == '.'){
            ++precision;
        }
        else{
            a = a+'0';
        }
        ++i;
    }
    a = a + "*10^"+to_string(decimal);
    s = a;
}
int getDecimal(string s1){
    int decimal_1 = 0;
    if(s1[0] != '0'){
        if(s1.find(".") == string::npos) decimal_1 = s1.size();
        else decimal_1 = s1.find_first_of(".");
    }
    else {
        for(int i = 0; i < s1.size();++i){
            if(s1[i] != '0' && s1[i] != '.'){
                decimal_1 = 2 - i;
                break;
            }
        }
    }
    return decimal_1;
}
void simplify(string &s){
    if(s.find(".")==string::npos){
        int pos = 0;
        while(pos < s.size()){
            if(s[pos] != '0'){
                break;
            }
            ++pos;
        }
        if(pos == s.size()) s = "0";
        else s = s.substr(pos);
    }
}
bool isEqual(string & s1, string & s2, int precision){
    int decimal_1 = 0,decimal_2 = 0;
    simplify(s1);
    simplify(s2);
    decimal_1 = getDecimal(s1);
    decimal_2 = getDecimal(s2);
    convert(s1,precision,decimal_1);
    convert(s2,precision,decimal_2);
    return (strcmp(s1.c_str(),s2.c_str()) == 0);
}
int main(){
    string s1,s2;
    int n;
    cin>>n>>s1>>s2;
    if(isEqual(s1, s2, n)){
        cout<<"YES "<<s1<<endl;
    }
    else{
        cout<<"NO "<<s1<<" "<<s2<<endl;
    }
    return 0;
}
