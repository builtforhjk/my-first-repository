#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Account{
	string username;
	string password;
	bool isModified;
};
int main(){
	int number = 0;
	cin>>number;
	vector <Account> accounts;
	for(int i = 0; i < number; ++i){
		Account temp;
		cin>>temp.username>>temp.password;
		temp.isModified = false;
		accounts.push_back(temp);
	}
	int count = 0;
	for(int i = 0; i < accounts.size(); ++i){
		bool ischanged = false;
		for(int j = 0; j < accounts[i].password.length(); ++j){
			switch(accounts[i].password[j]){
				case '1':
					accounts[i].password[j] = '@';
					ischanged = true;
					break;
				case '0':
					accounts[i].password[j] = '%';
					ischanged = true;
					break;
				case 'l':
					accounts[i].password[j] = 'L';
					ischanged = true;
					break;
				case 'O':
					accounts[i].password[j] = 'o';
					ischanged = true;
					break;
				default:
					break;
			}
		}
		if(ischanged){
			++count;
			accounts[i].isModified = true;
		}
	}
	if(count == 0){
		if(number == 1){
			cout<<"There is 1 account and no account is modified"<<endl;
		}
		else{
			cout<<"There are "<<number<<" accounts and no account is modified"<<endl;
		}
	}
	else{
		cout<<count<<endl;
		for(int i = 0; i < accounts.size(); ++i){
			if(accounts[i].isModified){
				cout<<accounts[i].username<<" "<<accounts[i].password<<endl;
			}
		}
	}
	return 0;
}