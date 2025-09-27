#include <iostream>
using namespace std;

int main() {
    float espresso = 200, latte = 250, cappuccino = 300;
    float *pEspresso = &espresso, *pLatte = &latte, *pCappuccino = &cappuccino;

    int qEspresso, qLatte, qCappuccino;
    int *pqEspresso = &qEspresso, *pqLatte = &qLatte, *pqCappuccino = &qCappuccino;

    cout << "Enter Espresso Quantity: ";
    cin >> *pqEspresso;
    cout << "Enter Latte Quantity: ";
    cin >> *pqLatte;
    cout << "Enter Cappuccino Quantity: ";
    cin >> *pqCappuccino;

    float subEspresso = (*pEspresso) * (*pqEspresso);
    float subLatte = (*pLatte) * (*pqLatte);
    float subCappuccino = (*pCappuccino) * (*pqCappuccino);

    float totalBill;
    float *pTotal = &totalBill;
    *pTotal = subEspresso + subLatte + subCappuccino;

    cout << "\n------ Cafe Bill ------\n";
    cout << "Espresso   (" << *pqEspresso << " x " << *pEspresso << ") = " << subEspresso << endl;
    cout << "Latte      (" << *pqLatte << " x " << *pLatte << ") = " << subLatte << endl;
    cout << "Cappuccino (" << *pqCappuccino << " x " << *pCappuccino << ") = " << subCappuccino << endl;
    cout << "-----------------------\n";
    cout << "TOTAL BILL: " << *pTotal << endl;

    return 0;
}
