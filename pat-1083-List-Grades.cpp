#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector <string> name;
vector <string> ID;
vector <int> grade;
void QuickSort(int left, int right){
    if (right > left) {
        int pivpos = left;
        int pivot = grade[left];
        string namePivot = name[left];
        string IDPivot = ID[left];
        for (int i = left + 1; i <= right; i++) {
            if (grade[i] > pivot) {
                pivpos++;
                if (pivpos != i) {
                    int temp = grade[pivpos];
                    grade[pivpos] = grade[i];
                    grade[i] = temp;
                    string nameTemp = name[pivpos];
                    name[pivpos] = name[i];
                    name[i] = nameTemp;
                    string IDTemp = ID[pivpos];
                    ID[pivpos] = ID[i];
                    ID[i] = IDTemp;
                }
            }
        }
        grade[left] = grade[pivpos];
        name[left] = name[pivpos];
        ID[left] = ID[pivpos];
        grade[pivpos] = pivot;
        name[pivpos] = namePivot;
        ID[pivpos] = IDPivot;
        QuickSort(left, pivpos - 1);
        QuickSort(pivpos + 1, right);
    }
}
int main(){
	int N = 0;
	cin>>N;
	for(int i = 0; i < N; ++i){
		string temp1;
		string temp2;
		int temp3;
		cin>>temp1>>temp2>>temp3;
		name.push_back(temp1);
		ID.push_back(temp2);
		grade.push_back(temp3);
	}
	int interval_lower = 0;
	int interval_higher = 100;
	cin>>interval_lower>>interval_higher;
	QuickSort(0, grade.size() - 1);
	int count = 0;
	bool isValid = false;
	while(count < grade.size()){
		if(grade[count] >= interval_lower && grade[count] <= interval_higher){
			cout<<name[count]<<" "<<ID[count]<<endl;
			isValid = true;
		}
		count += 1;
	}
	if(!isValid){
		cout<<"NONE"<<endl;
	}
	return 0;
}