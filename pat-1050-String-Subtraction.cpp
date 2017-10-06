#include <iostream>
using namespace std;
int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    string s3;
    int pos = 0;
    while(s1.find_first_not_of(s2,pos) != string::npos){
        pos = s1.find_first_not_of(s2,pos);
        s3 += s1[pos];
        ++pos;
        if(pos >= s1.size()) break;
    }
    cout<<s3<<endl;
    return 0;
}
