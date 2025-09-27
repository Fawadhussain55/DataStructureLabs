
#include <iostream>
using namespace std;

int generateCode(int n) {
    if (n == 0) return 1;
    int product = 1;
    for (int i = n; i >= 1; i--) {
        product *= i;
    }
    return product;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int (*codePtr)(int) = generateCode;
    int secret = codePtr(num);

    cout << "Your secret code is: " << secret << endl;
    return 0;
}
