#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class BankAccount{
   private:
   int createAcNum(){
       int num = rand() % 100000;
       return num;
   }
    string OwnerName;
    int AccountNumber= createAcNum();
    double Balance;
   public:
     BankAccount(string ownername, double balance)
         : OwnerName(ownername), Balance(balance) {}
     void withdraw() {
         double depsum;
         cout << "How many you want to put into your deposit account?\n";
         do {
             cin >> depsum;
             if (depsum > Balance) {
                 cout << "You current balanse is too low.\nbalance: " << Balance << endl
                      << "Write sum that is smaller then this.";
             }
         } while (depsum > Balance);
         Balance -= depsum;
     }
     void deposit() { 
        double dep;
        cout << "Write deposite number you want : ";
        cin >> dep;
        Balance += dep;
     }
     void display(){
         cout << "The name of an owner is : " << OwnerName << endl << "Your balance is:" << Balance << endl;
         printf("Your account number is %6d", AccountNumber);
     }
};
int main(){
    srand(time(0));
    BankAccount Mine("V.C", 123);
}