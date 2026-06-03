#include <iostream>
#include <set>

class Item {
public:
    int id;
    Item(int id) : id(id) {}

    bool operator<(const Item& other) const {
        return id < other.id;
    }
};

int main() {
    std::set<Item> s;

    Item m(1);
    Item m1(1);

    s.insert(m);
    s.insert(m1);

    std::cout << s.size() << '\n'; // 1

    return 0;
}