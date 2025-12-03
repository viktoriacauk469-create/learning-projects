#include <iostream>
using namespace std;
class cat{
  public:
  string name;
  string breed;
  int age;
  bool rescued;
  int mood;
  int hunger;
  cat(string n,string b,int a,bool r,int m,int h){
    name=n;
    breed=b;
    age=a;
    rescued=r;
    mood=m;
    hunger=h;
  }
  int feed(){
    if (hunger>0){
      return hunger--;
    }else return hunger;
  }
  int play(){
    if (mood<10){
      return mood++;
    }else return mood;
  }
    
  void status(){
    if (rescued) cout<<"rescued ";
    cout<<breed<<" "<<name<< " age: "<<age<<" condition: mood "<<mood<<" hunger: "<<hunger<<endl;
    
  }
};
int main() {
  cat one("Maggy","unknown",7,true,3,8);
  cat onew("Tom","white",2,false,9,1);
  one.play();
  onew.feed();
  one.status();
  onew.status();
}