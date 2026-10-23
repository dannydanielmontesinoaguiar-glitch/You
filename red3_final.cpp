#include <iostream>
using namespace std;

// Función para mostrar las ecuaciones
void mostrarEcuaciones(double a, double b, double c, double d, double e, double f, double g, double h) {
    cout << "\nSistema de ecuaciones:\n";
    cout << "x2 - x3 = " << b - a << endl;
    cout << "x1 - x2 = " << e - f << endl;
    cout << "x3 - x4 = " << d - c << endl;
    cout << "-x1 + x4 = " << h - g << endl;
}

// Función para mostrar la matriz
void mostrarMatriz(double M[4][5], string titulo) {
    cout << "\n" << titulo << "\n";
    for(int i=0; i<4; i++) {
        for(int j=0; j<5; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

// Función para calcular las soluciones
void calcularSoluciones(double a, double b, double e, double f, double g, double h, 
                        double &x1, double &x2, double &x3, double &x4) {
    x3 = 0;
    x2 = b - a;
    x1 = x2 + (e - f);
    x4 = x1 + (h - g);
}
void funcion_prueba(int prueba){
    prueba = 5;
}

int main() {
    double a, b, c, d, e, f, g, h;
    double x1, x2, x3, x4;
    int prueba;
    funcion_prueba(prueba);
    cout << prueba;

    // Entrada de datos
    cout << "Ingrese los flujos conocidos:\n";
    cin >> a >> b >> c >> d >> e >> f >> g >> h;

    // Mostrar ecuaciones
    mostrarEcuaciones(a, b, c, d, e, f, g, h);

    // Crear y mostrar matriz inicial
    double M[4][5] = {
        {0, 1, -1, 0, b - a},
        {1, -1, 0, 0, e - f},
        {0, 0, 1, -1, d - c},
        {-1, 0, 0, 1, h - g}
    };
    mostrarMatriz(M, "Matriz aumentada inicial:");
    M[3][0] += M[1][0];
    M[3][4] += M[1][4];
    mostrarMatriz(M, "Transformacion R4 = R4 + R2:");

    calcularSoluciones(a, b, e, f, g, h, x1, x2, x3, x4);
    cout << "\nSolucion:\n";
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x3 = " << x3 << endl;
    cout << "x4 = " << x4 << endl;

    cout << "\nFlujo minimo A -> B: " << x4 << endl;

    return 0;
}