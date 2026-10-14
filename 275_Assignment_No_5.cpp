#include<iostream>
#include"qu.h"
using namespace std;
class Restaurentwaitlist{
Queue<string>waitlist;
int currfulltable;
int MAXtable;
int count=0;

public:

Restaurentwaitlist(int a,int b){
	MAXtable=a;
	currfulltable=b;
	}
	
void add(string a){
if(currfulltable==MAXtable){
	if(count!=10){
	waitlist.enqueue(a);
		count++;
		}
	else{
		cout<<"Waitlist is Full!"<<endl;
		return;
		}
	}
	
else{
	cout<<"Seat available in restuarent! No need to add to the waiting list!"<<endl;
	currfulltable++;
	return;
	}
}
	
void Remove(){
currfulltable--;
if(!waitlist.isempty()){
	waitlist.dequeue();
	currfulltable++;
	count--;
	cout<<"Got a Table!Removed from waitlist!"<<endl;
	}
else{
	 cout<<"waitlist is empty!"<<endl;
	}
}

void display_waitlist(){
	waitlist.display();
}
};
int main() {
    int max, current;
    
    cout << "Enter maximum number of tables: ";
    cin >> max;

    cout << "Enter number of currently occupied tables: ";
    cin >> current;

    Restaurentwaitlist r(max, current);

    int choice;
    string name;

    do {
        cout << "\n\n--- Restaurant Waitlist ---";
        cout << "\n1. Add customer";
        cout << "\n2. Remove customer";
        cout << "\n3. Display waitlist";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Enter customer name: ";
                cin >> name;
                r.add(name);
                break;

            case 2:
                r.Remove();
                break;

            case 3:
                cout << "Waiting List: ";
                r.display_waitlist();
                cout << endl;
                break;

            case 4:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 4);

    return 0;
}