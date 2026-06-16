#include <iostream>

class Punto {
    int x, y;
public:
    Punto(int x = 0, int y = 0) : x(x), y(y) {}

    Punto operator+(const Punto& otro) const {
        return Punto(x + otro.x, y + otro.y);
    }

    Punto operator-(const Punto& otro) const {
        return Punto(x - otro.x, y - otro.y);
    }

    void mostrar() const {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

int main() {
    Punto p1(3, 5);
    Punto p2(1, 2);

    Punto suma = p1 + p2;
    Punto resta = p1 - p2;

    suma.mostrar();   // (4, 7)
    resta.mostrar();  // (2, 3)
}