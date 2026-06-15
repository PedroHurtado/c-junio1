#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numeros;
    int numero;

    do
    {
        std::cout << "Introduce un número (0 para terminar): ";
        std::cin >> numero;

        if (numero != 0)
            numeros.push_back(numero);

    } while (numero != 0);

    std::cout << "\nNúmeros introducidos:\n";
    for (int n : numeros)
        std::cout << n << '\n';

    return 0;
}

/*
#include <iostream>

int main()
{
    int capacidad = 4;
    int tam = 0;
    int* numeros = new int[capacidad];
    int numero;

    do
    {
        std::cout << "Introduce un número (0 para terminar): ";
        std::cin >> numero;

        if (numero != 0)
        {
            if (tam == capacidad)
            {
                capacidad *= 2;
                int* nuevo = new int[capacidad];
                for (int i = 0; i < tam; ++i)
                    nuevo[i] = numeros[i];
                delete[] numeros;
                numeros = nuevo;
            }
            numeros[tam++] = numero;
        }

    } while (numero != 0);

    std::cout << "\nNúmeros introducidos:\n";
    for (int i = 0; i < tam; ++i)
        std::cout << numeros[i] << '\n';

    delete[] numeros;
    return 0;
}
*/

/*
#include <iostream>
#include <cstdlib>

int main()
{
    int capacidad = 4;
    int tam = 0;
    int* numeros = static_cast<int*>(std::malloc(capacidad * sizeof(int)));
    int numero;

    do
    {
        std::cout << "Introduce un número (0 para terminar): ";
        std::cin >> numero;

        if (numero != 0)
        {
            if (tam == capacidad)
            {
                capacidad *= 2;
                numeros = static_cast<int*>(std::realloc(numeros, capacidad * sizeof(int)));
            }
            numeros[tam++] = numero;
        }

    } while (numero != 0);

    std::cout << "\nNúmeros introducidos:\n";
    for (int i = 0; i < tam; ++i)
        std::cout << numeros[i] << '\n';

    std::free(numeros);
    return 0;
}
*/