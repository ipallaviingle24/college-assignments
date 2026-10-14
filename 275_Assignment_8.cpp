#include <iostream>
using namespace std;

struct node
{
    string title;
    int id;
    node *left, *right;
    int lth, rth;
    node(int value, string a)
    {
        id = value;
        title = a;
        left = right = NULL;
        lth = rth = 1;
    }
};

class Library
{
    node *head;

public:
    Library()
    {
        head = NULL;
    }

    void insert(int key, string b)
    {
        node *temp = head;
        node *parent = NULL;

        while (temp != NULL)
        {
            if (key == temp->id)
            {
                cout << "Duplicate!" << endl;
                return;
            }
            parent = temp;
            if (key < temp->id)
            {
                if (temp->lth == 0)
                {
                    temp = temp->left;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (temp->rth == 0)
                {
                    temp = temp->right;
                }
                else
                {
                    break;
                }
            }
        }
        node *newnode = new node(key, b);

        if (head == NULL)
        {
            head = newnode;
        }
        else if (key < parent->id)
        {
            newnode->left = parent->left;
            parent->left = newnode;
            parent->lth = 0;
            newnode->right = parent;
        }
        else
        {
            newnode->left = parent;
            newnode->right = parent->right;
            parent->right = newnode;
            parent->rth = 0;
        }
    }

    void inorder()
    {
        if (head == NULL)
        {
            cout << "Library is empty!";
            return;
        }
        node *curr = head;
        // First move to the left most node;
        while (curr->lth == 0)
        {
            curr = curr->left;
        }
        //
        while (curr != NULL)
        {
            // print the left most node
            cout << curr->id << ": " << curr->title << "    ";
            // if right thread exist, follow that thread
            if (curr->rth == 1)
            {
                curr = curr->right;
            }
            // if right thread not exist, move to the next right child and then move
            //  to its leftmost child and repeat till curr reaches NULL
            else
            {
                curr = curr->right;
                while (curr != NULL && curr->lth == 0)
                {
                    curr = curr->left;
                }
            }
        }
    }
};

int main()
{
    Library book;
    int choice, id;
    string title;

    do
    {
        cout << "\n\n----- LIBRARY MENU -----";
        cout << "\n1. Insert Book";
        cout << "\n2. Inorder Traversal";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;

            cout << "Enter Book Title: ";
            cin.ignore();
            getline(cin, title);

            book.insert(id, title);
            break;

        case 2:
            cout << "\nBooks in Inorder:\n";
            book.inorder();
            break;

        case 3:
            cout << "Exiting...";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (choice != 3);

    return 0;
}