#include <iostream>
#include <string>
using namespace std;
struct node
{
	string data;
	node *next, *prev;
	node(string a)
	{
		data = a;
		next = prev = NULL;
	}
};

class list
{
	node *head, *tail;

public:
	list()
	{
		head = tail = NULL;
	}
	void insert_text_back(string a)
	{
		node *newnode = new node(a);
		if (head == NULL)
		{
			head = tail = newnode;
		}
		else
		{
			tail->next = newnode;
			newnode->prev = tail;
			tail = newnode;
		}
		cout << "Text added at back!" << endl;
	}

	void insert_text_front(string a)
	{
		node *newnode = new node(a);
		if (head == NULL)
		{
			head = tail = newnode;
		}
		else
		{
			head->prev = newnode;
			newnode->next = head;
			head = newnode;
		}
		cout << "Text added at front!" << endl;
	}

	void insert_text_after(string after, string a)
	{
		if (head == NULL)
		{
			head = tail = new node(a);
			cout << "Editor was empty. Text added as first node!" << endl;
			return;
		}
		else
		{
			node *temp = head;
			while (temp != NULL && temp->data != after)
			{
				temp = temp->next;
			}
			if (temp == NULL)
			{
				cout << "Text: " << after << " not found!" << endl;
				return;
			}

			else if (temp == tail)
			{
				node *newnode = new node(a);

				newnode->prev = tail;
				tail->next = newnode;
				tail = newnode;
			}
			else
			{
				node *newnode = new node(a);

				newnode->next = temp->next;
				newnode->prev = temp;
				temp->next = newnode;
				newnode->next->prev = newnode;
			}
		}
	}

	void delete_back()
	{
		if (head == NULL)
		{
			cout << "Editor is empty.";
			return;
		}
		else
		{
			node *temp = tail;
			if (head == tail)
			{
				head = tail = NULL;
			}
			else
			{
				tail = tail->prev;
				tail->next = NULL;
			}
			delete temp;
			cout << "Text deleted from back!" << endl;
		}
	}

	void delete_front()
	{
		if (head == NULL)
		{
			cout << "Editor is empty." << endl;
			return;
		}
		else
		{
			node *temp = head;
			if (head->next == NULL)
			{
				head = tail = NULL;
			}
			else
			{
				head = head->next;
				head->prev = NULL;
			}
			delete temp;
		}

		cout << "Text deleted from front!" << endl;
	}
	void delete_specific(string a)
	{
		if (head == NULL)
		{
			cout << "Editor is empty." << endl;
		}
		else
		{
			node *temp = head;
			while (temp != NULL && temp->data != a)
			{
				temp = temp->next;
			}

			if (temp == NULL)
			{
				cout << "Text not found!" << endl;
				return;
			}
			if (head == tail)
			{
				head = tail = NULL;
			}

			else if (temp == tail)
			{
				tail->prev->next = NULL;
				tail = tail->prev;
			}
			else if (temp == head)
			{
				head->next->prev = NULL;
				head = head->next;
			}
			else
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}

			delete temp;
			cout << "Text is deleted!" << endl;
		}
	}

	void display()
	{
		cout << "The data in the text editor is: " << endl;
		node *temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void search_text(string a)
	{
		node *temp = head;
		while (temp != NULL && temp->data != a)
		{
			temp = temp->next;
		}
		if (temp == NULL)
		{
			cout << "Text not found!" << endl;
		}
		else
		{
			cout << "Text found!" << endl;
		}
	}

	void reverse_text()
	{
		node *temp = NULL;
		node *curr = head;
		node *nextnode;
		while (curr != NULL)
		{
			temp = curr->prev;
			curr->prev = curr->next;
			curr->next = temp;
			curr = curr->prev;
		}
		if (temp != NULL)
		{
			tail = head;
			head = temp->prev;
			cout << "Text reversed!" << endl;
		}
	}
};

int main()
{
	list editor;
	int choice;
	string text, target;

	do
	{

		cout << "          TEXT EDITOR MENU            " << endl;
		cout << " 1. Insert at Front" << endl;
		cout << " 2. Insert at Back" << endl;
		cout << " 3. Insert After Specific Word" << endl;
		cout << " 4. Delete from Front" << endl;
		cout << " 5. Delete from Back" << endl;
		cout << " 6. Delete Specific Word" << endl;
		cout << " 7. Search Word" << endl;
		cout << " 8. Reverse Text" << endl;
		cout << " 9. Display Editor Content" << endl;
		cout << " 0. Exit" << endl;

		cout << "Enter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter text to insert at front: ";
			cin >> text;
			editor.insert_text_front(text);
			break;
		case 2:
			cout << "Enter text to insert at back: ";
			cin >> text;
			editor.insert_text_back(text);
			break;
		case 3:
			cout << "Enter target word to insert after: ";
			cin >> target;
			cout << "Enter new text to insert: ";
			cin >> text;
			editor.insert_text_after(target, text);
			break;
		case 4:
			editor.delete_front();
			break;
		case 5:
			editor.delete_back();
			break;
		case 6:
			cout << "Enter word to delete: ";
			cin >> text;
			editor.delete_specific(text);
			break;
		case 7:
			cout << "Enter word to search: ";
			cin >> text;
			editor.search_text(text);
			break;
		case 8:
			editor.reverse_text();
			break;
		case 9:
			editor.display();
			break;
		case 0:
			cout << "Exiting Text Editor. Goodbye!" << endl;
			break;
		default:
			cout << "Invalid choice! Please try again." << endl;
		}
	} while (choice != 0);

	return 0;
}