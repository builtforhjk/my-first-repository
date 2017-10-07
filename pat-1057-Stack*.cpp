#include <iostream>
#include <vector>
using namespace std;
void SortedInsert(vector<int> &sqList, int val){
    for(auto it = sqList.begin(); it != sqList.end(); ++it){
        if((*it) > val){
        sqList.insert(it,val);
        return;
        }
    }
    sqList.push_back(val);
}
void SortedDelete(vector<int> &sqList, int val){
    for(auto it = sqList.begin(); it != sqList.end(); ++it){
        if((*it) == val){
            sqList.erase(it);
            return;
        }
    }
}
int main(){
    char command[20];
    int n;
    scanf("%d",&n);
    getchar();
    vector<int> stack;
    vector<int> sqList;
    for(int i = 0; i < n; ++i){
        gets(command);
        switch(command[1]){
            case 'o':{
                if(stack.empty()) printf("Invalid\n");
                else{
                    SortedDelete(sqList, stack.back());
                    printf("%d\n",stack.back());
                    stack.pop_back();
                }
                break;
            }
            case 'u':{
                int val = atoi(command+5);
                SortedInsert(sqList, val);
                stack.push_back(val);
                break;
            }
            case 'e':{
                if(stack.empty()) printf("Invalid\n");
                else printf("%d\n",sqList[(sqList.size()-1)/2]);
                break;
            }
            default: break;    
        }
    }
    return  0;
}
