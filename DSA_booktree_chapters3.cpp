//DSA_ASSIGNMENT3
#include <iostream>
#include <string>
using namespace std;

struct node {
    string label;
    int count;
    node* child[10];
};

class g_tree {
public:
    node* root;
    void create();
    void display();

    g_tree() : root(NULL) {}
};

void g_tree::create() {
    root = new node();
    cout << "\nEnter the name of the book: ";
    cin >> root->label;
    cout << "Enter the number of chapters: ";
    cin >> root->count;

    for (int i = 0; i < root->count; i++) {
        root->child[i] = new node;
        cout << "\nEnter the chapter name: ";
        cin >> root->child[i]->label;
        cout << "Enter the number of sections: ";
        cin >> root->child[i]->count;

        for (int j = 0; j < root->child[i]->count; j++) {
            root->child[i]->child[j] = new node;
            cout << "\nEnter the section name: ";
            cin >> root->child[i]->child[j]->label;
            cout << "Enter the number of subsections: ";
            cin >> root->child[i]->child[j]->count;

            for (int k = 0; k < root->child[i]->child[j]->count; k++) {
                root->child[i]->child[j]->child[k] = new node;
                cout << "\nEnter the subsection name: ";
                cin >> root->child[i]->child[j]->child[k]->label;
            }
        }
    }
}

void g_tree::display() {
    cout << "\nBook Tree:\n";
    if (root != NULL) {
        cout << "\nTitle of the Tree: " << root->label;
    }
    for (int i = 0; i < root->count; i++) {
        cout << "\n\tChapter: " << root->child[i]->label;
        for (int j = 0; j < root->child[i]->count; j++) {
            cout << "\n\t\tSection: " << root->child[i]->child[j]->label;
            for (int k = 0; k < root->child[i]->child[j]->count; k++) {
                cout << "\n\t\t\tSubsection: " << root->child[i]->child[j]->child[k]->label;
            }
        }
    }
}

int main() {
    int ch;
    char cd;
    g_tree g;
    while (1) {
        cout << "\n1. Create New Book Record";
        cout << "\n2. Display Book Record";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                g.create();
                break;
            case 2:
                g.display();
                break;
            case 3:
                cout << "\nWrong Choice";
                break;
        }
        cout << "\nDo you want to continue (y/n): ";
        cin >> cd;
        if (cd != 'y' && cd != 'Y')
            break;
    }
    return 0;
}