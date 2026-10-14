/*Implement a checkout system for a supermarket to efficiently manage customer queues during peak
hours. The system should support the following operations using a circular queue data structure:
a. Customer arrival
b. Customer checkout
c. Close Checkout Counter
d. View customer
*/

#include<iostream>
using namespace std;

#define size 5

class Circularqueue{
public:
string cust[size];
int front,rear;

	// Constructor initializes an empty queue
	Circularqueue(){
		front=-1;
		rear=-1;
	}

	// Adds a new customer to the circular queue
void arrival(string a){
	// Check if the queue is full
	if((rear+1)%size==front){
		cout<<"Queue oveflow!!"<<endl;
		return;
	}

	// If queue is empty, initialize front and rear
	if(front==-1){
		front=rear=0;
	}
	else{
		// Move rear circularly to the next position
		rear=(rear+1)%size;
	}

	// Store the customer at the rear position
cust[rear]=a;
cout<<a<<" joined queue!"<<endl;
}

	// Removes the customer at the front after checkout
void checkout(){
	// Check if the queue is empty
	if(front==-1){
		cout<<"Queue underflow!!"<<endl;
	return;
	}

	// If only one customer is present, make the queue empty
	if(front==rear){
		front=rear=-1;
	}
	else{
		// Move front circularly to the next customer
		front=(front+1)%size;
	}

	cout<<"checkout is performed!!"<<endl;
	}

	// Displays all customers currently present in the queue
void view_customer(){
	// Check if the queue is empty
	if(front==-1){
		cout<<"Queue is empty!!"<<endl;
		return;
		}

	// Start traversing from the front of the queue
	int i=front;
	cout<<"The queue has: "<<endl;

	while(true){
		cout<<cust[i]<<endl;

		// Stop when the rear position is reached
		if(i==rear){
			break;
		}

		// Move to the next position circularly
		i=(i+1)%size;
		}
	
}

	// Provides service to all remaining customers and closes the counter
void close_counter(){
	// Check if the queue is already empty
	if(front==-1){
		cout<<"Queue is empty!!"<<endl;
		return;
		}
	else{
	// Serve customers one by one until the queue becomes empty
	while(front!=-1){
		cout<<cust[front]<<" is provided service"<<endl;
		
		// If the last customer is served, reset the queue
		if(front==rear){
		front=-1;
		rear=-1;
		}
		else{
		// Move front to the next customer
		front=(front+1)%size;
		}
		}
		
		cout<<"Counter closed!!"<<endl;
}
}
};

int main(){

Circularqueue q;
int choice;
string name;
 
do{
cout<<"Supermarket System"<<endl;
cout<<"1.Customer arrival"<<endl;
cout<<"2.Customer checkout"<<endl;
cout<<"3.Close Checkout Counter"<<endl;
cout<<"4. View customer"<<endl;
cout<<"5.Exit"<<endl;
cout<<"Enter choice: "<<endl;
cin>>choice;

switch(choice){
	case 1:
		cout<<"Enter Customer name: "<<endl;
		cin>>name;
		q.arrival(name);
		break;

	case 2:
		q.checkout();
		break;

	case 3:
		q.close_counter();
		break;

	case 4:
		 q.view_customer();
		 break;

	case 5:
		cout<<"Exiting..."<<endl;
		break;

	default:
		cout<<"Invalid choice!!"<<endl;
		}
	}
	while(choice!=5);

	return 0;
}