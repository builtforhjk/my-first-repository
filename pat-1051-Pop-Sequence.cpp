#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<int>popList, int M){
    vector <int> stack;
    int index = 0;
    for(int i = 0; i < popList.size(); ++i){
        stack.push_back(i+1);
        if(stack.size() > M) return false;
        while(stack.size() && stack.back() == popList[index]){
            stack.pop_back();
            ++index;
        }
    }
    return stack.empty();
}
int main(){
    int N,M,K;
    vector <vector<int> >sqPop;
    cin>>M>>N>>K;
    for(int i = 0; i < K; ++i){
        vector<int> temp;
        for(int j = 0; j < N; ++j){
            int t;
            cin>>t;
            temp.push_back(t);
        }
        sqPop.push_back(temp);
    }
    for(auto item:sqPop){
        if(isValid(item,M)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
