#include <iostream>
#include <string.h>
using namespace std;

struct Node
{
    char inf[20];
    Node* left;
    Node* right;
};
struct Tree
{
    Node* root = nullptr;

    void push(char* inf)
    {
        Node* pt = new Node;
        strcpy_s(pt->inf, inf);
        pt->left = pt->right = nullptr;

        if (root == nullptr)  root = pt;
        else
        {
            Node* r1, * r2;
            r1 = r2 = root;
            while (r1)
            {
                r2 = r1;
                if (strcmp(inf, r1->inf) == -1) r1 = r1->left;
                else r1 = r1->right;
            }
            if (strcmp(inf, r2->inf) == -1) r2->left = pt;
            else r2->right = pt;
        }
    }
    void show_grow(Node* p)
    {
        if (p == nullptr) return;
        show_grow(p->left);
        cout << p->inf << ' ';
        show_grow(p->right);
    }
    void show_direct(Node* p)
    {
        if (p == nullptr) return;
        cout << p->inf << ' ';
        show_direct(p->left);
        show_direct(p->right);
    }
    void show_reverse(Node* p)
    {
        if (p == nullptr) return;
        show_reverse(p->left);
        show_reverse(p->right);
        cout << p->inf << ' ';
    }
    void clear(Node* p)
    {
        if (p == nullptr) return;
        clear(p->left);
        clear(p->right);
        delete p;
        p = nullptr;
    }
    int str_len(Node* p)
    {
        if (p == nullptr) return 0;
        else return strlen(p->inf) + str_len(p->left) + str_len(p->right);
    }
};

int main()
{
    int n;
    cout << "Enter number of storkes: "; cin >> n;

    if (n > 0)
    {
        // create
        Tree t;
        char str[20];

        getchar();
        for (int i = 0; i < n; i++)
        {
            cout << i+1 << ": "; cin >> str;
            t.push(str);
        }
        cout << endl << "Tree (grow order): " << endl;
        t.show_grow(t.root);
        cout << endl << "Tree (direct order): " << endl;
        t.show_direct(t.root);
        cout << endl << "Tree (reverse order): " << endl;
        t.show_reverse(t.root);

        // count
        cout << endl << endl << "Number of chars: " << t.str_len(t.root) << endl;

        // clear
        t.clear(t.root);
    }
    else cout << "Tree is empty" << endl;
    
    return 0;
}