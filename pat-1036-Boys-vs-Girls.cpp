#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;
struct Student{
  string name;
  string gender;
  string ID;
  int grade;
};
bool compare(Student s1, Student s2){
  if(s1.gender == s2.gender){
    return s1.grade < s2.grade;
  }
  else{
    return strcmp(s1.gender.c_str(), s2.gender.c_str()) < 0;
  }
}
int main(){
  int number = 0;
  cin>>number;
  vector <Student> students;
  for(int i = 0; i < number; ++i){
    Student temp;
    cin>>temp.name>>temp.gender>>temp.ID>>temp.grade;
    students.push_back(temp);
  }
  sort(students.begin(), students.end(), compare);
  int index = 0;
  while(index < students.size() && students[index].gender != "M"){
    ++index;
  }
  if(number == 0){
    cout<<"Absent"<<endl;
    cout<<"Absent"<<endl;
    cout<<"NA"<<endl;
    return 0;
  }
  if(index == 0){
    cout<<"Absent"<<endl;
    cout<<students[index].name<<" "<<students[index].ID<<endl;
    cout<<"NA"<<endl;
  }
  else if(index == students.size()){
    cout<<students[index-1].name<<" "<<students[index-1].ID<<endl;
    cout<<"Absent"<<endl;
    cout<<"NA"<<endl;
  }
  else{
    cout<<students[index-1].name<<" "<<students[index-1].ID<<endl;
    cout<<students[index].name<<" "<<students[index].ID<<endl;
    cout<<students[index-1].grade - students[index].grade<<endl;
  }
  return 0;
}