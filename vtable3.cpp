struct IDraw { virtual void draw() = 0; virtual ~IDraw() = default; };
struct ISave { virtual void save() = 0; virtual ~ISave() = default; };

struct Widget : IDraw, ISave {
    int data = 42;
    void draw() override { data++; }
    void save() override { data--; }
};

Widget w;
IDraw* pd = &w;
ISave* ps = &w;