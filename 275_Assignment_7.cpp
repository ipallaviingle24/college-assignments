/*Consider the Dictionary Implementations which allow for efficient storage and retrieval of key-value
pairs using binary search trees. Each node in the tree store (key, value) pair. The dictionary should
support the following operations efficiently:
a. Insert word (Handle insertion of duplicate entry)
b. Delete word
c. Search specific word
d. Display dictionary (Traversal)
e. Mirror image of dictionary
f. Create a copy of dictionary
g. Display dictionary level wise*/

#include<iostream>
#include <queue>
using namespace std;

struct node{
    string key;
    string value;
    node *left;
    node *right;

    node(string val1, string val2){
        key=val1;
        value=val2;
        left=right=NULL;
    }
};

class DICTIONARY{
    node *root;

    public:
    DICTIONARY(){
        root=NULL;
    }

    // Return root of the dictionary
    node* getRoot(){
        return root;
    }

    // Insert a new word into the BST
    void insert_word(string a, string b){
        node *newnode= new node(a,b);

        if(root==NULL){
            root=newnode;
            cout << "Word inserted!" << endl;
            return;
        }
        else{
            node *curr=root;

            while(true){

                if(a<curr->key){
                    if(curr->left==NULL){
                        curr->left=newnode;
                        cout<<"word Inserted!"<<endl;
                        return;
                    }
                    else{
                        curr=curr->left;
                    }
                }

                else if(a > curr->key){
                    if(curr->right==NULL){
                        curr->right=newnode;
                        cout<<"word inserted!"<<endl;
                        return;
                    }
                    else{
                        curr=curr->right;
                    }
                }

                // Duplicate word
                else{
                    cout<<"Duplicate!"<<endl;
                    delete newnode;
                    return;
                }
            }
        }
    }

    // Delete a word from the BST
    void delete_word(string a){
        if(root==NULL){
            cout<<"Nothing to delete!"<<endl;
            return;
        }
        else{
            node *curr=root;
            node *parent;

            // Search for the word
            while(curr!=NULL && curr->key!=a){
                parent=curr;

                if(a<curr->key){
                    curr=curr->left;
                }
                else{
                    curr=curr->right;
                }
            }

            if(curr==NULL){
                cout<<"word not found!"<<endl;
                return;
            }

            // Node has no children
            if(curr->left==NULL && curr->right==NULL){
                if(curr==root){
                    root=NULL;
                }
                else if (parent->left == curr) {
                    parent->left = NULL;
                }
                else {
                    parent->right = NULL;
                }

                delete curr;
            }

            // Node has only left child
            else if (curr->left != NULL && curr->right == NULL) {

                if (curr == root) {
                    root = curr->left;
                }
                else if (parent->left == curr) {
                    parent->left = curr->left;
                }
                else {
                    parent->right = curr->left;
                }

                delete curr;
            }

            // Node has only right child
            else if (curr->left == NULL && curr->right != NULL) {

                if (curr == root) {
                    root = curr->right;
                }
                else if (parent->left == curr) {
                    parent->left = curr->right;
                }
                else {
                    parent->right = curr->right;
                }

                delete curr;
            }

            // Node has two children
            else{
                node *succesor_p=curr;
                node *succesor=curr->right;

                // Find inorder successor
                while(succesor->left!=NULL){
                    succesor_p=succesor;
                    succesor=succesor->left;
                }

                // Copy successor data into current node
                curr->key=succesor->key;
                curr->value=succesor->value;

                // Remove successor from its original position
                if(succesor_p->left==succesor){
                    succesor_p->left=succesor->right;
                }
                else{
                    succesor_p->right=succesor->right;
                }

                delete succesor;
            }

            cout<<"Word deleted!"<<endl;
        }
    }

    // Search for a specific word
    void search_word(string a){
        if(root == NULL){
            cout << "Dictionary is empty!" << endl;
            return;
        }
        else{
            node *curr=root;

            while(curr!=NULL && curr->key!=a){
                if(a<curr->key){
                    curr=curr->left;
                }
                else{
                    curr=curr->right;
                }
            }

            if(curr==NULL){
                cout<<"word not found!"<<endl;
                return;
            }

            cout<<"word found!"<<endl;
            cout<<"key: "<<curr->key<<endl;
            cout<<"value: "<<curr->value<<endl;
        }
    }

    // Inorder: Left -> Root -> Right
    void inorder(node * p){
        if(p == NULL){
            return;
        }

        inorder(p->left);
        cout << p->key << ": " << p->value << endl;
        inorder(p->right);
    }

    // Preorder: Root -> Left -> Right
    void preorder(node *p){
        if(p == NULL){
            return;
        }

        cout << p->key << ": " << p->value << endl;
        preorder(p->left);
        preorder(p->right);
    }

    // Postorder: Left -> Right -> Root
    void postorder(node *p){
        if(p == NULL){
            return;
        }

        postorder(p->left);
        postorder(p->right);
        cout << p->key << ": " << p->value << endl;
    }

    // Create mirror image by swapping left and right subtrees
    void mirror(node *p){
        if(p == NULL){
            return;
        }

        node *temp = p->left;
        p->left = p->right;
        p->right = temp;

        mirror(p->left);
        mirror(p->right);
    }

    // Create a deep copy of the tree
    node* copy_tree(node *p){
        if(p == NULL){
            return NULL;
        }

        node *newnode = new node(p->key, p->value);

        newnode->left = copy_tree(p->left);
        newnode->right = copy_tree(p->right);

        return newnode;
    }

    // Display tree level by level using queue
    void display_level(node *p){
        if(p==NULL){
            return;
        }
        else{
            queue<node *>q;

            q.push(p);

            while(!q.empty()){
                node *curr=q.front();
                q.pop();

                cout << curr->key << ": " << curr->value << endl;

                // Add left child to queue
                if(curr->left!=NULL){
                    q.push(curr->left);
                }

                // Add right child to queue
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
        }
    }

};

int main(){
    DICTIONARY dict;

    int choice;
    string word, meaning;

    do{
        cout << "\n===== DICTIONARY =====" << endl;
        cout << "1. Insert Word" << endl;
        cout << "2. Delete Word" << endl;
        cout << "3. Search Word" << endl;
        cout << "4. Inorder Display" << endl;
        cout << "5. Preorder Display" << endl;
        cout << "6. Postorder Display" << endl;
        cout << "7. Mirror Dictionary" << endl;
        cout << "8. Create Copy" << endl;
        cout << "9. Level-wise Display" << endl;
        cout << "10. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){

            case 1:
                cout << "Enter word: ";
                cin >> word;

                cout << "Enter meaning: ";
                cin.ignore();
                getline(cin, meaning);

                dict.insert_word(word, meaning);
                break;

            case 2:
                cout << "Enter word to delete: ";
                cin >> word;

                dict.delete_word(word);
                break;

            case 3:
                cout << "Enter word to search: ";
                cin >> word;

                dict.search_word(word);
                break;

            case 4:
                cout << "\nInorder Traversal:" << endl;
                dict.inorder(dict.getRoot());
                break;

            case 5:
                cout << "\nPreorder Traversal:" << endl;
                dict.preorder(dict.getRoot());
                break;

            case 6:
                cout << "\nPostorder Traversal:" << endl;
                dict.postorder(dict.getRoot());
                break;

            case 7:
                dict.mirror(dict.getRoot());

                cout << "\nMirror Dictionary:" << endl;
                dict.inorder(dict.getRoot());
                break;

            case 8:
                cout << "\nCopy of Dictionary:" << endl;
                dict.inorder(dict.copy_tree(dict.getRoot()));
                break;

            case 9:
                cout << "\nLevel-wise Display:" << endl;
                dict.display_level(dict.getRoot());
                break;

            case 10:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    }while(choice != 10);

    return 0;
}