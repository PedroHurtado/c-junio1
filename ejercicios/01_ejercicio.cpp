/*
Lee un número por teclado e indica si es divisible entre 2 (resto = 0). Si no lo es, 
también debemos indicarlo.
Codificar un programa que recibiendo un número por teclado devuelva si es primo o no.
Haz un programa que pida un número por pantalla. 
Posteriormente pida números hasta que se ponga el mismo número 
que se introdujo al principio. Si es distinto, ha de decir si el número escrito es mayor o menor
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Introduce un numero: ";
    cin >> n;
    if (n % 2 == 0)
        cout << n << " es divisible entre 2\n";
    else
        cout << n << " NO es divisible entre 2\n";
    return 0;
}

/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Introduce un numero: ";
    cin >> n;

    if (n < 2) {
        cout << n << " NO es primo\n";
        return 0;
    }

    bool primo = true;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            primo = false;
            break;
        }
    }

    cout << n << (primo ? " es primo\n" : " NO es primo\n");
    return 0;
}
*/

/*
#include <iostream>
using namespace std;

int main() {
    int objetivo, n;
    cout << "Introduce el numero objetivo: ";
    cin >> objetivo;

    do {
        cout << "Introduce un numero: ";
        cin >> n;
        if (n > objetivo)
            cout << "Mayor\n";
        else if (n < objetivo)
            cout << "Menor\n";
    } while (n != objetivo);

    cout << "Correcto!\n";
    return 0;
}
*/