#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iomanip>
using namespace std;
struct PhoneRecords{
	string name;
	string time;
	string status;
	PhoneRecords(string name, string time, string status){
		this->name = name;
		this->time = time;
		this->status = status;
	}
	PhoneRecords & operator=(PhoneRecords PR){
		this->name = PR.name;
		this->time = PR.time;
		this->status = PR.status;
		return *this;
	}
};
struct Pairs{
	string name;
	int begin;
	int end;
	Pairs(int begin, int end, string name){
		this->begin = begin;
		this->end = end;
		this->name = name;
	}
};
bool compare(PhoneRecords pr1, PhoneRecords pr2){
	if(strcmp(pr1.name.c_str(), pr2.name.c_str()) == 0){
		return strcmp(pr1.time.c_str(), pr2.time.c_str()) < 0;
	}
	else{
		return strcmp(pr1.name.c_str(), pr2.name.c_str()) < 0;
	}
}
int getPerPairDuration(const string on_line,const string off_line){
	int Days = stoi(off_line.substr(3,2)) - stoi(on_line.substr(3,2));
	int beginHours = stoi(on_line.substr(6,2));
	int beginMinutes = stoi(on_line.substr(9,2));
	int endHours = stoi(off_line.substr(6,2)) + Days * 24;
	int endMinutes = stoi(off_line.substr(9,2));
	return ((endHours - beginHours) * 60 + endMinutes - beginMinutes);
}
double getPerPairBills(const string on_line,const string off_line, const int * rate){
	int Days = stoi(off_line.substr(3,2)) - stoi(on_line.substr(3,2));
	int beginHours = stoi(on_line.substr(6,2));
	int beginMinutes = stoi(on_line.substr(9,2));
	int endHours = stoi(off_line.substr(6,2)) + Days * 24;
	int endMinutes = stoi(off_line.substr(9,2));
	int sum = 0;
	for(int i = beginHours; i <= endHours; i++){
		if(i == beginHours){
			if(beginHours == endHours){
				sum += (endMinutes - beginMinutes) * rate[i];
				break;
			}
			sum += rate[i] * (60-beginMinutes);
		}
		else if(i == endHours){
			sum += rate[i%24] * endMinutes;
		}
		else{
			sum += rate[i%24] * 60;
		}
	}
	double total = ((double)sum) / 100;
	return total;
}
int main(){
	int rateStructure[24];
	int n = 0;
	vector <PhoneRecords> phoneRecords;
	vector <Pairs> pair;
	for(int i = 0; i < 24; i++){
		cin>>rateStructure[i];
	}
	cin>>n;
	for(int i = 0; i < n; i++){
		string inputName;
		string inputTime,inputStatus;
		cin>>inputName>>inputTime>>inputStatus;
		PhoneRecords temp(inputName,inputTime,inputStatus);
		phoneRecords.push_back(temp);
	}
	sort(phoneRecords.begin(), phoneRecords.end(), compare);
	int pair_begin = -1;
	string pair_name = "__none__";
	for(int i = 0; i < phoneRecords.size(); i++){
		if(strcmp(phoneRecords[i].status.c_str(), "on-line") == 0){
			pair_begin = i;
			pair_name = phoneRecords[i].name;
		}
		else if(strcmp(phoneRecords[i].status.c_str(), "off-line") == 0){
			if(pair_begin != -1 && 
				strcmp(pair_name.c_str(), phoneRecords[i].name.c_str()) == 0){
				Pairs temp(pair_begin, i, pair_name);
				pair.push_back(temp);
				pair_begin = -1;
			}
		}
	}
	const string month = phoneRecords[0].time.substr(0,2);
	double total = 0;
	string person;
	person.clear();
	for(int i = 0; i < pair.size(); i++){
		if(person.empty()){
			person = pair[i].name;
			cout<<person<<" "<<month<<endl;
		}
		else if(strcmp(person.c_str(), pair[i].name.c_str()) != 0){
			cout<<"Total amount: $"<<total<<endl;
			person = pair[i].name;
			total = 0;
			cout<<person<<" "<<month<<endl;
		}
		double sum = getPerPairBills(phoneRecords[pair[i].begin].time,
			phoneRecords[pair[i].end].time, rateStructure);
		int duration = getPerPairDuration(phoneRecords[pair[i].begin].time,
			phoneRecords[pair[i].end].time);
		cout<<phoneRecords[pair[i].begin].time.substr(3)<<" "
		<<phoneRecords[pair[i].end].time.substr(3)<<" "<<duration<<" $"
		<<fixed<<setprecision(2)<<sum<<endl;
		total += sum;
		if(i == (pair.size() - 1)){
			cout<<"Total amount: $"<<fixed<<setprecision(2)<<total<<endl;
		}
	}
	return 0;
}