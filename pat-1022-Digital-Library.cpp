#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef struct Node{
  int id;
  char name[100];
  char author[100];
  char keyword[100];
  string keywords[5];
  int total;
  char publisher[100];
  int year;
}BookInfo;
vector<BookInfo> library;
bool cmp(BookInfo b1, BookInfo b2){
  return b1.id < b2.id;
}
void arrangeKeyword(BookInfo &b, string key){
  int pos = 0, prePos = 0;
  int count = 0;
  while(1){
    if(pos == key.size()){
      b.keywords[count++] = key.substr(prePos);
      break;
    }
    else if(key[pos] == ' '){
      b.keywords[count++] = key.substr(prePos, pos-prePos);
      prePos = pos+1;
    }
    ++pos;
  }
  b.total = count;
}
void search(string query){
  printf("%s\n",query.c_str());
  int type = query[0]-'0';
  string needle = query.substr(3);
  int sign = 0;
  switch(type){
    case 1: {
      for(auto book : library){
        if(strcmp(book.name, needle.c_str()) == 0){
          printf("%07d\n",book.id);
          sign = 1;
        }
      }
      break;
    }
    case 2: {
      for(auto book : library){
        if(strcmp(book.author, needle.c_str()) == 0){
          printf("%07d\n",book.id);
          sign = 1;
        }
      }
      break;
    }
    case 3: {
      for(auto book : library){
        for(int i = 0; i < book.total; ++i){
          if(strcmp(book.keywords[i].c_str(), needle.c_str()) == 0){
            printf("%07d\n",book.id);
            sign = 1;
            break;
          }
        }
      }
      break;
    }
    case 4: {
      for(auto book : library){
        if(strcmp(book.publisher, needle.c_str()) == 0){
          printf("%07d\n",book.id);
          sign = 1;
        }
      }
      break;
    }
    case 5: {
      int qYear = stoi(needle);
      for(auto book : library){
        if(book.year == qYear){
          printf("%07d\n",book.id);
          sign = 1;
        }
      }
      break;
    }
    default: break;
  }
  if(!sign) printf("Not Found\n");
}
int main(){
  int n,m;
  scanf("%d",&n);
  for(int i = 0; i < n; ++i){
    BookInfo tmp;
    scanf("%d",&(tmp.id));
    getchar();
    gets(tmp.name);
    gets(tmp.author);
    gets(tmp.keyword);
    gets(tmp.publisher);
    scanf("%d",&(tmp.year));
    getchar();
    arrangeKeyword(tmp, tmp.keyword);
    library.push_back(tmp);
  }
  sort(library.begin(), library.end(), cmp);
  scanf("%d",&m);
  getchar();
  for(int i = 0; i < m; ++i){
    char query[100];
    gets(query);
    search(query);
  }
  return 0;
}
