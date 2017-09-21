#include <iostream>
#include <algorithm>
using namespace std;
string add(string str){
    string copy = str;
    reverse(copy.begin(), copy.end());
    int currentDigit;
    int plus = 0;
    string sum;
    for(int i = 0;;++i){
        if(i == str.size()){
            if(plus){
                sum += char(plus+48);
            }
            break;
        }
        else{
            currentDigit = (str[str.size() - 1 - i] - '0')+(copy[copy.size() - 1 - i] - '0')+plus;
            sum += char(currentDigit%10+48);
            plus = currentDigit / 10;
        }
    }
    reverse(sum.begin(), sum.end());
    return sum;
}
int main(){
    string str;
    int k;
    cin>>str>>k;
    string result = str;
    for(int i = 0;;++i){
        if(i == k){
            cout<<result<<endl;
            cout<<k<<endl;
            break;
        }
        else{
            string copy = result;
            reverse(copy.begin(), copy.end());
            if(copy == result){
                cout<<result<<endl;
                cout<<i<<endl;
                break;
            }
            string temp = add(result);
            result.clear();
            result = temp;
        }
    }
    return 0;
}