#include <iostream>
using namespace std;

class Toyota {
private:
    int car;
    string model;
    string durability;
public:
    void setDetails(int c, string m, string d) {
        car = c;
        model = m;
        durability = d;
    }
    void showDetails() {
        cout << "Car ID: " << car << endl;
        cout << "Model: " << model << endl;
        cout << "Durability: " << durability << endl;
    }
};
int main() {
    Toyota C1;
    C1.setDetails(123, "Corolla", "High");
    C1.showDetails();
    return 0;
}
