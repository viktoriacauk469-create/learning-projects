#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;
class BankAccount{
private:
    string OwnerName;
    int AccountNumber;
    double Balance;
    int createAcNum(){
       int num = rand() % 100000;
       return num;
   }
public:
     BankAccount(string ownername, double balance)
         : OwnerName(ownername), Balance(balance) {
         AccountNumber = createAcNum();
     }
     void withdraw() {
         double depsum;
         cout << "How much do you want to withdraw?\n";
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
         cout << "Your account number is " << setw(5) << setfill('0') << AccountNumber << endl;
     }
};
int main() {
    srand(time(0));
    BankAccount mine("V.C", 123);
    mine.display();
    mine.deposit();
    mine.withdraw();
    mine.display();
    return 0;
}