/*
Assigna a una variable booleana l'expressi� booleana que calcula si un any �s o no de trasp�s:
"�s de trasp�s cada any m�ltiple de quatre, excepte els m�ltiples de cent, que no ho s�n, i excepte els m�ltiples de 400, que s� que ho s�n"

Any de trasp�s:
    - m�ltiple de 4
    - m�ltiple de 4, 100 i 400

No any de trasp�s:
    - no m�ltiple de 4
    - m�ltiple de 4, 100 i no 400
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
    // Determina si l'any introdu�t �s de trasp�s o no.
    seleccionarAny();

    // Imprimeix tots els anys en l'interval especificat (l�mits inclosos) i indica quin d'aquests �s de trasp�s.
    imprimirAnys();

    return 0;
}
