#include <iostream>

using namespace std;

const int N = 4;

// Mostrar matriz aumentada
void mostrarMatriz(int m[N][N + 1]) {
    cout << "\nMatriz del sistema:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + 1; j++)
            cout << m[i][j] << "\t";
        cout << endl;
    }
}

// Resolver sistema por Gauss 
void resolverSistema(int m[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        int pivote = m[i][i];

        for (int j = 0; j < N + 1; j++)
            m[i][j] /= pivote;

        for (int k = 0; k < N; k++) {
            if (k != i) {
                int factor = m[k][i];
                for (int j = 0; j < N + 1; j++)
                    m[k][j] -= factor * m[i][j];
            }
        }
    }
}

// Mostrar solución
void mostrarSolucion(int m[N][N + 1]) {
    cout << "\nFlujos desconocidos:\n";
    for (int i = 0; i < N; i++)
        cout << "x" << i + 1 << " = " << m[i][N] << endl;
}

// Hallar flujo mínimo A -> B
void hallarFlujoMinimo(int m[N][N + 1]) {
    int minimo = m[0][N];

    for (int i = 1; i < N; i++) {
        if (m[i][N] < minimo)
            minimo = m[i][N];
    }

    cout << "\nFlujo minimo necesario para mantener el trafico: "
         << minimo << " autos/hora\n";
}

int main() {
    int matriz[N][N + 1];

    cout << "Ingrese la matriz aumentada del sistema:\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N + 1; j++)
            cin >> matriz[i][j];

    mostrarMatriz(matriz);

    resolverSistema(matriz);

    mostrarSolucion(matriz);

    hallarFlujoMinimo(matriz);

    return 0;
}