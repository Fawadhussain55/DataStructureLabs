#include <iostream>
using namespace std;

int main() {
    int players;
    cout << "Enter number of players: ";
    cin >> players;

    int *scores = new int[players];

    for (int i = 0; i < players; i++) {
        cout << "Enter score for Player " << i + 1 << ": ";
        cin >> scores[i];
    }

    cout << "\n--- Tournament Scores ---\n";
    for (int i = 0; i < players; i++) {
        cout << "Player " << i + 1 << ": " << scores[i] << endl;
    }

    delete[] scores;
    return 0;
}
