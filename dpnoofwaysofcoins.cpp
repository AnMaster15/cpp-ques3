#include <iostream>
#include <vector>

using namespace std;

long getNumberOfWays(long N, vector<long>& Coins) {
    vector<long> ways(N + 1, 0);
    ways[0] = 1;

    for (int i = 0; i < Coins.size(); i++) {
        for (int j = Coins[i]; j <= N; j++) {
            ways[j] += ways[j - Coins[i]];
        }
    }

    return ways[N];
}

int main() {
    vector<long> Coins = {1, 5, 10};
    cout << "No of ways: - " << getNumberOfWays(12, Coins) << endl;
    return 0;
}
