#include <iostream>
#include <map>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
    map <int , double>polynomials;
    int A_number = 0;
    int B_number = 0;
    cin>>A_number;
    for(int i = 0; i < A_number; ++i){
        int exponent;
        double coefficient;
        cin>>exponent>>coefficient;
        if(fabs(coefficient - 0) > 1e-5){
            polynomials[exponent] = coefficient;
        }
    }
    cin>>B_number;
    for(int i = 0; i < B_number; ++i){
        int exponent;
        double coefficient;
        cin>>exponent>>coefficient;
        polynomials[exponent] += coefficient;
        if(fabs(polynomials[exponent] - 0) < 1e-5){
            polynomials.erase(exponent);
        }
    }
    cout<<polynomials.size();
    map <int , double>::reverse_iterator it = polynomials.rbegin();
    while(it != polynomials.rend()){
        cout<<" "<<it->first<<" "<<fixed<<setprecision(1)<<it->second;
        ++it;
    }
    cout<<endl;
    return 0;
}
