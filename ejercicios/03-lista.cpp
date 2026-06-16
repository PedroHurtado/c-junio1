#include <vector>
#include <algorithm>
#include <memory>

template <typename T>
class Node
{
public:
    T value;
    Node *parent = nullptr;
    std::vector<std::unique_ptr<Node>> children;

    explicit Node(T value) : value(std::move(value)) {}

    Node *addChild(T childValue)
    {
        auto child = std::make_unique<Node>(std::move(childValue));
        child->parent = this;
        children.push_back(std::move(child));
        return children.back().get();
    }

    void addChild(std::unique_ptr<Node> child)
    {
        child->parent = this;
        children.push_back(std::move(child));
    }

    // Elimina (destruye) un hijo concreto
    bool removeChild(Node *child)
    {
        auto it = std::find_if(children.begin(), children.end(),
                               [child](const std::unique_ptr<Node> &n)
                               { return n.get() == child; });
        if (it == children.end())
            return false;
        children.erase(it);
        return true;
    } 
    // Se elimina a sí mismo del padre (se autodestruye)
    void remove()
    {
        if (parent)
            parent->removeChild(this);
    }
};

int main()
{
    auto root = std::make_unique<Node<int>>(1);
    Node<int> *a = root->addChild(2);
    Node<int> *b = root->addChild(3);
    a->addChild(4);

    b->remove();                       // destruye b y sus hijos    
    return 0;
}

/*
                    ┌──────────┐
                    │  Node 1  │  (root)
                    │ parent=∅ │
                    └────┬─────┘
            children →   │
              ┌──────────┴──────────┐
              │                     │
        ┌─────▼─────┐         ┌─────▼─────┐
        │  Node 2   │         │  Node 3   │
        │ parent=1  │◄──┐     │ parent=1  │◄──┐
        └─────┬─────┘   │     └───────────┘   │
   children → │         │                     │
        ┌─────▼─────┐   │  parent              │  parent
        │  Node 4   │   │  apunta              │  apunta
        │ parent=2  │───┘  a Node 2            │  a Node 1
        └───────────┘                          │
              │                                │
              └── parent apunta a Node 2 ──────┘
*/