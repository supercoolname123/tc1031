#include <iostream>

//Gerardo Alberto Garay - A01564643


int sumaIterativa(int n)
{ // Esta funcion es O(n), incluye un ciclo for de n repeticiones.
    int suma = 0;
    for (int i = 1; i <= n; i++)
    {
        suma += i;
    }
    return suma;
}

int sumaRecursiva(int n)
{
    // Esta funcion es O(n), ya que se realizan n llamadas recursivas para llegar al resultado
    return n > 1 ? n + sumaRecursiva(n - 1) : 1;
}

int sumaDirecta(int n)
{
    // Esta funcion es O(1), siempre se realiza el mismo numero de operaciones sin importar n.
    return n * (n + 1) / 2;
}

int main()
{
    int pruebas[4] = { 1, 5, 10, 20 };
    int resultados[4] = { 1, 15, 55, 210 };

    for (int i = 0; i < 4; i++)
    {
        int iterativa = sumaIterativa(pruebas[i]);
        int recursiva = sumaRecursiva(pruebas[i]);
        int directa = sumaDirecta(pruebas[i]);

        std::cout << "Caso " << i + 1 << ", n = " << pruebas[i] << "\n";
        std::cout << "Suma Iterativa: " << iterativa << (iterativa == resultados[i] ? " Correcto" : " Incorrecto") << "\n";
        std::cout << "Suma Recursiva: " << recursiva << (recursiva == resultados[i] ? " Correcto" : " Incorrecto") << "\n";
        std::cout << "Suma Directa: " << directa << (directa == resultados[i] ? " Correcto" : " Incorrecto") << "\n";
        std::cout << "\n";
    }

    return 0;
}
