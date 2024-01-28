#include <iostream>
#include <omp.h>

#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#endif

const int N = 1000; 

void llenarArreglo(int arreglo[]) {
    for (int i = 0; i < N; ++i) {
        arreglo[i] = rand() % 100; 
    }
}

void imprimirArreglo(const char* nombre, int arreglo[]) {
    std::cout << nombre << ": ";
    for (int i = 0; i < 20; ++i) { 
        std::cout << arreglo[i] << " ";
    }
    std::cout << "..." << std::endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int arregloA[N];
    int arregloB[N];
    int resultado[N];

    llenarArreglo(arregloA);
    llenarArreglo(arregloB);

    imprimirArreglo("Arreglo A", arregloA);
    imprimirArreglo("Arreglo B", arregloB);

#pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        resultado[i] = arregloA[i] + arregloB[i];
    }

    imprimirArreglo("Resultado", resultado);

    return 0;
}

