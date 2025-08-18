// Variables declared as static in a function are created & initialized once for the lifetime of the program. (In function)
// Static variables in a class are created & initialized once. They are shared by all the objects of the class.
 
#include <iostream>
using namespace std;
void func(){
    static int x =0 ;      // it will be called for only one time 
    cout << x << endl;
    x++;
}

int main(){
    func();
    func();
    func();
    func();
    return 0;
}