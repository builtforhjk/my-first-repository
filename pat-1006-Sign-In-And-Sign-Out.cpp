#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
struct Record{
    string ID;
    string sign_in;
    string sign_out;
    Record(string a, string b, string c):ID(a),sign_in(b),sign_out(c){};
};
int main(){
    int m;
    cin>>m;
    vector<Record> records;
    for(int i = 0; i < m; ++i){
        string a,b,c;
        cin>>a>>b>>c;
        records.push_back(Record(a,b,c));
    }
    string unlockID;
    string unlockTime = "24:00:00";
    auto findUnlock = [&](const Record re){
        if(strcmp(re.sign_in.c_str(),unlockTime.c_str()) < 0){
            unlockID = re.ID;
            unlockTime = re.sign_in;
        }
    };
    string lockID;
    string lockTime = "00:00:00";
    auto findLock = [&](const Record re){
        if(strcmp(re.sign_out.c_str(),lockTime.c_str()) > 0){
            lockID = re.ID;
            lockTime = re.sign_out;
        }
    };
    for_each(records.begin(), records.end(), findUnlock);
    for_each(records.begin(), records.end(), findLock);
    cout<<unlockID<<" "<<lockID<<endl;
    return 0;
}