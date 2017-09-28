#include <iostream>
#include <vector>
using namespace std;
vector<long long> getRSystem(long long m, long long b){
    vector <long long> con;
    while(m){
        con.push_back(m%b);
        m = m/b;
    }
    return con;
}
int main(){
    long long m,b;
    cin>>m>>b;
    if(m == 0){
        cout<<"Yes"<<endl<<0<<endl;
    }
    else{
        vector<long long> con_1 = getRSystem(m,b);
        vector<long long> con_2;
        for(auto it = con_1.rbegin(); it != con_1.rend(); ++it){
            con_2.push_back((*it));
        }
        int flag = 1;
        for(int i = 0; i < con_1.size(); ++i){
            if(con_1[i] != con_2[i]){
                flag = 0;
                break;
            }
        }
        if(flag == 0) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
        for(auto it = con_2.begin(); it != con_2.end(); ++it){
            cout<<(*it);
            if(it+1 != con_2.end()) cout<<" ";
            else cout<<endl;
        }
    }
    return 0;
}
