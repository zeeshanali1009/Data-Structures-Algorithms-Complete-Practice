#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> v = {
        {1, 2, 3},
        {4, 5},
        {6, 7, 8, 9}
    };

    cout << "Jagged 2D Vector: \n";
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
