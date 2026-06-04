#include <cstdio>

struct IDraw { virtual void draw() = 0; virtual ~IDraw() = default; };
struct ISave { virtual void save() = 0; virtual ~ISave() = default; };

struct Widget : IDraw, ISave {
    int data = 42;
    void draw() override {}
    void save() override {}
};

int main() {
    Widget w;
    Widget* pw = &w;
    IDraw*  pd = &w;
    ISave*  ps = &w;

    printf("Widget* = %p\n", (void*)pw);
    printf("IDraw*  = %p\n", (void*)pd);
    printf("ISave*  = %p  (+%td bytes)\n", (void*)ps, (char*)ps - (char*)pw);
}