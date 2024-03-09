#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main() {
    const int num_personas =2;

    string nombres[num_personas];
    string apellidos[num_personas];
    string ciudades_nacimiento[num_personas];
    int fechas_nacimiento[num_personas][3];

    time_t t = time(0);
    tm* now = localtime(&t);
    int anio_actual = now->tm_year + 1900;
    int mes_actual = now->tm_mon + 1;
    int dia_actual = now->tm_mday;

    for (int i = 0; i < num_personas; ++i) {
        cout << "Persona " << i + 1 << ":" << endl;
        cout << "Nombre completo: ";
        getline(cin, nombres[i]);
        cout << "Apellido: ";
        getline(cin, apellidos[i]);
        cout << "Ciudad de nacimiento: ";
        getline(cin, ciudades_nacimiento[i]);
        cout << "Fecha de nacimiento (ano mes dia): ";
        cin >> fechas_nacimiento[i][0] >> fechas_nacimiento[i][1] >> fechas_nacimiento[i][2];
        cin.ignore();
    }

    for (int i = 0; i < num_personas; ++i) {
        cout << "\nPersona " << i + 1 << ":" << endl;
        cout << "Nombre completo: " << nombres[i] << endl;
        cout << "Apellido: " << apellidos[i] << endl;
        cout << "Ciudad de nacimiento: " << ciudades_nacimiento[i] << endl;
        cout << "Fecha de nacimiento: " << fechas_nacimiento[i][0] << "-" << fechas_nacimiento[i][1] << "-" << fechas_nacimiento[i][2] << endl;

        int edad = anio_actual - fechas_nacimiento[i][0];
        if (mes_actual < fechas_nacimiento[i][1] || (mes_actual == fechas_nacimiento[i][1] && dia_actual < fechas_nacimiento[i][2]))
            edad--;

        if (edad >= 18)
            cout << "Es mayor de edad." << endl;
        else
            cout << "Es menor de edad." << endl;
    }

    return 0;
}

