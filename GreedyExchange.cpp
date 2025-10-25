#include <iostream>
using namespace std;

int greedyChange(int coins[], int available[], int used[], int n, int amount) {
    int i, count;

    // Initialize all used coins to zero
    for (i = 0; i < n; i++)
        used[i] = 0;

    // Start from the largest denomination
    i = n - 1;

    while (amount > 0 && i >= 0) {
        count = amount / coins[i];              // maximum number of this coin we could use
        if (count > available[i])               // limit by available coins
            count = available[i];

        used[i] = count;
        amount -= count * coins[i];
        i--;                                    // move to next smaller denomination
    }

    if (amount == 0) {
        // update remaining coins
        for (i = 0; i < n; i++)
            available[i] -= used[i];
        return 1;   // success
    } else {
        return 0;   // cannot make exact change
    }
}

int main() {
    int coins[] = {1, 5, 10, 25};
    int available[] = {5, 2, 2, 1};  // available counts
    int used[4];
    int n = 4, amount = 48;

    if (greedyChange(coins, available, used, n, amount)) {
        cout<<"Change possible:\n";
        for (int i = 0; i < n; i++)
            cout<<"Coin"<<coins[i]<<":"<<" used:"<<used[i]<<"\n";			
    } else {
        cout<<"Cannot make exact change.\n";
    }
    return 0;
}
