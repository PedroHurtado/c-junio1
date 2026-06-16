#include <iostream>

class Punto {
   int x, y;
public:  

    /*int getX() const{
        return x;
    }
    int getY() const{
        return y;
    }*/
    Punto(int x = 0, int y = 0) : x(x), y(y) {}
    //RVO (Return Value Optimization) 

    /*
    Punto crear() {
        Punto temp(3, 5);
        return temp;   // NRVO: permitido, no garantizado, en cualquier estándar
    }
    */
    Punto operator+(const Punto& otro) const {
        return Punto(x + otro.x, y + otro.y);
    }

    Punto operator-(const Punto& otro) const {
        return Punto(x - otro.x, y - otro.y);
    }

     Punto operator*(const Punto& otro) const {
        return Punto(x * otro.x, y * otro.y);
    }
    void mostrar() const {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

/*Punto suma(const& Punto p1, const& Punto p2){
   return Punto(p1.getX() +p2.getX() ,p1.y+p2.y)
}*/

int main() {
    Punto p1(3, 5);
    Punto p2(1, 2);

    
    Punto suma = p1 + p2;
    Punto resta = p1 - p2; 
    Punto multiplicar = p1*p2;   

    suma.mostrar();   // (4, 7)
    resta.mostrar();  // (2, 3)
}