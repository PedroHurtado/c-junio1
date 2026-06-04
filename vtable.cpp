#include <cstdio>

struct IDraw  { virtual void draw()  = 0; virtual ~IDraw()  = default; };
struct ISave  { virtual void save()  = 0; virtual ~ISave()  = default; };
struct IClick { virtual void click() = 0; virtual ~IClick() = default; };

struct W0 { int data; };

struct W1 : IDraw {
    int data;
    void draw() override {}
};

struct W2 : IDraw, ISave {
    int data;
    void draw() override {}
    void save() override {}
};

struct W3 : IDraw, ISave, IClick {
    int data;
    void draw()  override {}
    void save()  override {}
    void click() override {}
};

int main() {
    printf("sizeof(int)            = %zu\n", sizeof(int));
    printf("W0 (sin interfaces)    = %zu\n", sizeof(W0));
    printf("W1 (1 interfaz)        = %zu\n", sizeof(W1));
    printf("W2 (2 interfaces)      = %zu\n", sizeof(W2));
    printf("W3 (3 interfaces)      = %zu\n", sizeof(W3));
}