#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// ============================================================================
// 4. REGISTROS (STRUCTS)
// Estructura heterogenea que agrupa diferentes tipos de datos bajo un nombre.
// ============================================================================
struct Estudiante {
    string nombre;
    int edad;
    float promedio;
};

// ============================================================================
// 3. FUNCIONES (MODULARIZACION)
// Bloques de codigo reutilizables para tareas especificas.
// ============================================================================

// Funcion con retorno de valor (paso por valor)
float calcularArea(float base, float altura) {
    return base * altura;
}

// Funcion sin retorno (void) y paso por valor para calcular el promedio de un vector
float calcularPromedioNotas(const int notas[], int tamano) {
    int suma = 0;
    for (int i = 0; i < tamano; i++) {
        suma += notas[i];
    }
    return static_cast<float>(suma) / tamano;
}

// Funcion con paso por referencia (&) para modificar directamente el registro original
void actualizarPromedio(Estudiante &est, float nuevoPromedio) {
    est.promedio = nuevoPromedio;
}

// Funcion void para mostrar la informacion de un registro
void mostrarEstudiante(const Estudiante &est) {
    cout << "Nombre:   " << est.nombre << endl;
    cout << "Edad:     " << est.edad << " anios" << endl;
    cout << "Promedio: " << fixed << setprecision(2) << est.promedio << endl;
}

int main() {
    cout << "=========================================================" << endl;
    cout << "  EJEMPLOS PRACTICOS: ARREGLOS, FUNCIONES Y REGISTROS    " << endl;
    cout << "=========================================================" << endl << endl;

    // ------------------------------------------------------------------------
    // 1. ARREGLOS UNIDIMENSIONALES (VECTORES)
    // Coleccion homogenea y de tamano fijo accesible mediante un indice [i]
    // ------------------------------------------------------------------------
    cout << "--- 1. ARREGLO UNIDIMENSIONAL (VECTOR) ---" << endl;
    const int NUM_NOTAS = 5;
    int notas[NUM_NOTAS] = {85, 90, 78, 95, 88};

    // Recorrido secuencial con un solo bucle for
    for (int i = 0; i < NUM_NOTAS; i++) {
        cout << "Nota en posicion [" << i << "]: " << notas[i] << endl;
    }
    cout << endl;

    // ------------------------------------------------------------------------
    // 2. ARREGLOS BIDIMENSIONALES (MATRICES)
    // Organizados en filas y columnas, accesibles mediante [fila][columna]
    // ------------------------------------------------------------------------
    cout << "--- 2. ARREGLO BIDIMENSIONAL (MATRIZ 3x3) ---" << endl;
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Recorrido de la matriz mediante bucles anidados
    for (int i = 0; i < 3; i++) {          // Recorre filas
        for (int j = 0; j < 3; j++) {      // Recorre columnas
            cout << "[" << i << "][" << j << "]=" << matriz[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;

    // ------------------------------------------------------------------------
    // 3. USO DE FUNCIONES (PASO POR VALOR Y RETORNO)
    // ------------------------------------------------------------------------
    cout << "--- 3. FUNCIONES (MODULARIZACION) ---" << endl;
    float base = 5.0f, altura = 3.0f;
    float area = calcularArea(base, altura);
    cout << "Area de rectangulo (" << base << " x " << altura << "): " << area << endl;

    float promedioNotas = calcularPromedioNotas(notas, NUM_NOTAS);
    cout << "Promedio calculado del vector de notas: " << promedioNotas << endl;
    cout << endl;

    // ------------------------------------------------------------------------
    // 4. USO DE REGISTROS (STRUCTS) Y PASO POR REFERENCIA
    // Acceso a campos mediante el operador punto (.)
    // ------------------------------------------------------------------------
    cout << "--- 4. REGISTROS (STRUCTS) ---" << endl;
    Estudiante e1;
    e1.nombre = "Diego Andres Espitia Rincon";
    e1.edad = 20;
    e1.promedio = 4.5f;

    cout << "Datos iniciales del estudiante:" << endl;
    mostrarEstudiante(e1);

    // Modificamos el registro original usando paso por referencia
    actualizarPromedio(e1, 4.8f);
    cout << "\nDatos tras actualizar promedio (paso por referencia):" << endl;
    mostrarEstudiante(e1);

    return 0;
}
