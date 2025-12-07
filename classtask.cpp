#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class BankAccount{
   private:
    string OwnerName;
    int AccountNumber;
    double Balance;
   public:
    BankAccount(string ownername,int accountenumber,double balance) : OwnerName(ownername),AccountNumber(accountenumber),Balance(balance){}
    void deposit(){
      double depsum;
      cout <<"How many you want to put into your deposit account?\n";
      do {
       cin >> depsum;
       if (depsum> Balance){
        cout << "You current balanse is too low.\nbalance: "<<Balance<<endl<<"Write sum that is smaller then this.";
       }
      } while(depsum> Balance) ;
      Balance -=depsum;
    }
};
int main(){

}