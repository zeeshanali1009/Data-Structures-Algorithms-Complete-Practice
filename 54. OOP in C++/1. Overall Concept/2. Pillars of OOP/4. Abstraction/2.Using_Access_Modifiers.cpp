#include <iostream>
using namespace std;
class Account {
private:
    double balance;
public:
    void setBalance(double b) {
        if (b >= 0)
            balance = b;
    }
    double getBalance() {
        return balance;
    }
};
int main() {
    Account acc;
    acc.setBalance(1000.50);
    cout << "Balance: " << acc.getBalance() << endl;
    return 0;
}
