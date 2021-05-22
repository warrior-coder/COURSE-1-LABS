#include <iostream>

using namespace std;

struct Node
{
    int inf;
    Node* next;
};
struct Stack
{
    Node* top = nullptr;

    void push_back(int inf)
    {
        Node* spt = new Node;
        spt->inf = inf;
        spt->next = top;
        top = spt;
    }
    void show()
    {
        Node* spt = top;
        while (spt)
        {
            cout << spt->inf << ' ';
            spt = spt->next;
        }
        cout << endl;
    }
    void clear()
    {
        Node* spt;
        while (top)
        {
            spt = top;
            top = top->next;
            delete spt;
        }
        top = nullptr;
    }
};

int main()
{
    int n;
    cout << "Enter stack  size: "; cin >> n;
    
    if (n > 0)
    {
        // create
        Stack s;
        for (int i = 0; i < n; i++)
            s.push_back(rand() % 101 - 50);

        cout << "Stack: ";
        s.show();

        // find
        Node* smax = s.top;
        for (Node* spt = s.top->next; spt != nullptr; spt = spt->next)
            if (smax->inf < spt->inf) smax = spt;

        cout << "Max element: " << smax->inf << endl;

        n = 0;
        for (Node* spt = s.top; spt != smax; spt = spt->next) n++;
        cout << "Elements before max: " << n << endl;

        // clear
        s.clear();
    }
    else cout << "Stack is empty" << endl;
    
    return 0;
}