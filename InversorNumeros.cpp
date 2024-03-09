#include <iostream>
using namespace std;
int main() {
    int num, rev = 0, rem;
    cout << "Ingresa un numero: ";
    cin >> num;
    while(num != 0) {
        rem = num % 10;
        rev = rev * 10 + rem;
        num /= 10;
    }
    cout << "El numero invertido es: " << rev << endl;
    return 0;
}
