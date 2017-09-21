#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define dataType int
int main(){
    int couponNumber = 0;
    int productNumber = 0;
    vector <dataType> coupon;
    vector <dataType> product;
    cin>>couponNumber;
    for(int i = 0; i < couponNumber; ++i){
        dataType temp;
        cin>>temp;
        coupon.push_back(temp);
    }
    cin>>productNumber;
    for(int i = 0; i < productNumber; ++i){
        dataType temp;
        cin>>temp;
        product.push_back(temp);
    }
    sort(coupon.begin(),coupon.end());
    sort(product.begin(),product.end());
    dataType sum = 0;
    int i = 0;
    int j = 0;
    for(;;){
        if(i == coupon.size() || j == product.size()){
            break;
        }
        if(coupon[i] < 0 && product[j] < 0){
            sum += coupon[i] * product[j];
            ++i;
            ++j;
        }
        else {
            for(i = coupon.size() - 1, j = product.size() - 1;;){
                if(i < 0 || j < 0){
                    break;
                }
                if(coupon[i] > 0 && product[j] > 0){
                    sum += coupon[i] * product[j];
                    --i;
                    --j;
                }
                else {
                    break;
                }
            }
            break;
        }
    }
    cout<<sum<<endl;
}