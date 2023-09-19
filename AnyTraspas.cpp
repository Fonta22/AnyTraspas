/*
Assigna a una variable booleana l'expressió booleana que calcula si un any és o no de traspàs:
"és de traspàs cada any múltiple de quatre, excepte els múltiples de cent, que no ho són, i excepte els múltiples de 400, que sí que ho són"

Any de traspàs:
    - múltiple de 4
    - múltiple de 4, 100 i 400

No any de traspàs:
    - no múltiple de 4
    - múltiple de 4, 100 i no 400
*/

#include <iostream>

using namespace std;

// Algorisme vell, menys eficient.
bool comprovarTraspas_old(int any) {
    bool traspas = false;

    if (any % 4 == 0) {
        if (any % 100 == 0) {
            if (any % 400 == 0) {
                traspas = true;
            }
            else {
                traspas = false;
            }
        }
        else {
            traspas = true;
        }
    }

    return traspas;
}

bool comprovarTraspas(int any) {
    return any % 4 == 0 && (any % 100 != 0 || any % 400 == 0);
}

void seleccionarAny() {
    int any;

    cout << "Any: ";
    cin >> any;

    bool traspas = comprovarTraspas(any);

    if (traspas) cout << "El " << any << " es un any de traspas." << endl;
    else cout << "El " << any << " no es un any de traspas." << endl;
}

void imprimirAnys() {
    int inici, fi;

    cout << "Introdueix l'interval (limits inclosos)" << endl;
    cout << "Inici: ";
    cin >> inici;
    cout << "Fi: ";
    cin >> fi;
    cout << "[" << inici << ", " << fi << "]" << endl;

    bool traspas;

    for (int i = inici; i <= fi; i++) {
        traspas = comprovarTraspas(i);

        if (traspas) {
            cout << i << " " << "TRASPAS" << endl;
        }
        else {
            cout << i << endl;
        }
    }
}

int main() {
    // Determina si l'any introduït és de traspàs o no.
    seleccionarAny();

    // Imprimeix tots els anys en l'interval especificat (límits inclosos) i indica quin d'aquests és de traspàs.
    imprimirAnys();

    return 0;
}
