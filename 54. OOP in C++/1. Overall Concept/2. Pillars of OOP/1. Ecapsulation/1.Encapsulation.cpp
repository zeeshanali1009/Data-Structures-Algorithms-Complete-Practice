// 1. Encapsulation:
// It is the process of wrapping up the data members and member functions in a single unit class.
// Data Properties    +    Member Functions    = Class
// Uses:
// Data Hiding (Used to improve the security)
// It is the process of making the sensitive member/member function private/protected.
#include <iostream>
using namespace std;
class BankAccount {
private:
    int balance;  // private data member
public:
    // Constructor to initialize balance
    BankAccount(int initialBalance) {
        if (initialBalance >= 0)
            balance = initialBalance;
        else
            balance = 0;
    }
    // Public method to deposit money
    void deposit(int amount) {
        if (amount > 0)
            balance += amount;
    }
    // Public method to get balance
    int getBalance() {
        return balance;
    }
};

int main() {
    BankAccount acc(1000);  // Create account with balance 1000
    acc.deposit(500);  // Deposit 500
    cout << "Current Balance: " << acc.getBalance() << endl;  // Output: 1500
    // acc.balance = 5000; // Error! Cannot access private member directly
    return 0;
}
