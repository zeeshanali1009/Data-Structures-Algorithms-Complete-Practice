#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int totalGas = 0, totalCost = 0;

    for (int i = 0; i < n; i++) {
        totalGas += gas[i];
        totalCost += cost[i];
    }

    // If total fuel is less than total cost, impossible
    if (totalGas < totalCost) return -1;

    int currGas = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {
        currGas += gas[i] - cost[i];
        if (currGas < 0) {
            // can't reach i+1 from current start
            start = i + 1;
            currGas = 0;
        }
    }

    return start;
}

// Driver
int main() {
    vector<int> gas  = {1, 2, 4, 5, 2};
    vector<int> cost = {3, 4, 1, 1, 9};

    int start = canCompleteCircuit(gas, cost);

    if (start != -1)
        cout << "Start at station: " << start << endl;
    else
        cout << "No solution possible" << endl;

    return 0;
}
