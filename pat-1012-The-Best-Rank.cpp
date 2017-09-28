#include <iostream>
#include <string.h>
using namespace std;
typedef struct{
    string id;
    int c;
    int m;
    int e;
    int a;
}StudentInfo;
int main(){
    int m,n;
    cin>>m>>n;
    StudentInfo * students = new StudentInfo[m];
    for(int i = 0; i < m; ++i){
        cin>>students[i].id>>students[i].c>>students[i].m>>students[i].e;
        students[i].a = (students[i].c+students[i].m+students[i].e)/3.0;
    }
    for(int i = 0; i < n; ++i){
        string query;
        cin>>query;
        StudentInfo temp;
        int flag = 0;
        for(int i = 0; i < m; ++i){
            if(strcmp(query.c_str(),students[i].id.c_str()) == 0){
                temp.id = students[i].id;
                temp.c = students[i].c;
                temp.m = students[i].m;
                temp.e = students[i].e;
                temp.a = students[i].a;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout<<"N/A"<<endl;
            continue;
        }
        int rank = 1;
        string subject = "C";
        for(int i = 0; i < m; ++i){
            if(students[i].c > temp.c) ++rank;
        }
        int pRank = 1;
        for(int i = 0; i < m; ++i){
            if(students[i].m > temp.m) ++pRank;
        }
        if(pRank < rank){
            subject = "M";
            rank = pRank;
        }
        pRank = 1;
        for(int i = 0; i < m; ++i){
            if(students[i].e > temp.e) ++pRank;
        }
        if(pRank < rank){
            subject = "E";
            rank = pRank;
        }
        pRank = 1;
        for(int i = 0; i < m; ++i){
            if(students[i].a > temp.a) ++pRank;
        }
        if(pRank <= rank){
            subject = "A";
            rank = pRank;
        }
        cout<<rank<<" "<<subject<<endl;
    }
    return 0;
}
