// now we will be checking the sequence of the constructors, destructor here as:
#include <iostream>
using namespace std;
class A{
    public:
    A(){
        cout << "Constructors" << endl;
    }
    ~A(){
        cout << "Destructors" << endl;
    }
};

int main(){
    if (true){
        static A obj;
    }
    cout << "End of the main Function" << endl;

    return 0;
}
// Constructors
// Destructors                                             this will be the sequence before static 
// End of the main Function



// Constructors
// End of the main Function
// Destructors                                             this will be the sequence after using static 
// so it has been proved that the object will remain till the lifetime of the program.
