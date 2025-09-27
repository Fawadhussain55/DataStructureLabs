#include <iostream>
using namespace std;

int main() {
    int participants;
    cout << "Enter number of participants: ";
    cin >> participants;

    int *attendance = new int[participants];
    for (int i = 0; i < participants; i++) {
        attendance[i] = 0;
    }

    int present;
    cout << "Enter number of present participants: ";
    cin >> present;

    for (int i = 0; i < present; i++) {
        int roll;
        cout << "Enter participant number (1-" << participants << "): ";
        cin >> roll;
        if (roll >= 1 && roll <= participants) {
            attendance[roll - 1] = 1;
        }
    }

    cout << "\n--- Attendance List ---\n";
    for (int i = 0; i < participants; i++) {
        cout << "Participant " << i + 1 << ": " 
             << (attendance[i] == 1 ? "Present" : "Absent") << endl;
    }

    delete[] attendance;
    return 0;
}
