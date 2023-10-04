#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ho {
private:
	struct node {
		int roomnum;
		string guestname, roomtype, date;
		node* next;
	};

public:
	node* head = NULL;

	void insert();
	void search();
	void delet();
	void update();

	void menu();
	void show();
};

void ho::insert() {
	node* new_node = new node;
	cout << "\t Enter room number!" << endl;
	cin >> new_node->roomnum;
	cout << endl;
	cout << "\t Enter booking date!" << endl;
	cin >> new_node->date;
	cout << endl;
	cout << "\t Enter your name!" << endl;
	cin >> new_node->guestname;
	cout << endl;
	cout << "\t Enter room type you prefer ('single', 'double', 'triple')" << endl;
	cin >> new_node->roomtype;
	cout << endl;

	if (head == NULL) {
		head = new_node;
		cout << "Congrats, you have booked with Rero_Hotel!" << endl;
		cout << "----------------------------------------------" << endl;
	}
	else {
		node* ptr = head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = new_node;
		cout << "Congrats, you have booked with Rero_Hotel!" << endl;
		cout << "----------------------------------------------" << endl;
	}
}

void ho::search() {
	int roomn;
	if (head == NULL) {
		cout << "No booked rooms!" << endl;
	}
	else {
		cout << "\t Enter room number: ";
		cin >> roomn;
		node* ptr = head;
		while (ptr != NULL) {
			if (roomn == ptr->roomnum) {
				cout << "Guest Name: " << ptr->guestname << endl;
				cout << "Room Type: " << ptr->roomtype << endl;
				cout << "Room Number: " << ptr->roomnum << endl;
				cout << "Booking Date: " << ptr->date << endl;
				return;
			}
			ptr = ptr->next;
		}
		cout << "Room not found!" << endl;
	}
}

void ho::update() {
	int roomn;
	if (head == NULL) {
		cout << "No booked rooms!" << endl;
		insert(); // Prompt for booking if no rooms are booked
	}
	else {
		cout << "\t Enter room number: ";
		cin >> roomn;
		node* ptr = head;
		while (ptr != NULL) {
			if (roomn == ptr->roomnum) {
				cout << "\t You can update now." << endl;
				cout << "Guest Name: ";
				cin >> ptr->guestname;
				cout << "Room Type: ";
				cin >> ptr->roomtype;
				cout << "Room Number: ";
				cin >> ptr->roomnum;
				cout << "Booking Date: ";
				cin >> ptr->date;
				cout << "Booking updated successfully!" << endl;
				break;
			}
		}
	}
}
void ho::delet() {
	int roomn;

	if (head == NULL) {
		cout << "No booked rooms!" << endl;

	}
	else {
		cout << "\t Enter room number: ";
		cin >> roomn;


		if (head->roomnum == roomn) {
			// delete head node
			node* temp = head;
			head = head->next;
			delete temp;

		}
		else {
			node* prev = head;
			node* curr = head->next;

			// traverse list to find matching node
			while (curr != NULL) {
				if (curr->roomnum == roomn) {
					// delete node
					prev->next = curr->next;
					delete curr;
					return;
				}
				prev = curr;
				curr = curr->next;
			}
		}

		cout << "Room not found!" << endl;
	}
}



void ho::show() {
	node* ptr = head;

	while (ptr != NULL) {
		cout << "first node";
		// Print room number
		cout << "Room num: " << ptr->roomnum << endl;

		// Print other details
		cout << "Guest name: " << ptr->guestname << endl;
		cout << "Room type: " << ptr->roomtype << endl;
		cout << "Date: " << ptr->date << endl;
		cout << "Next node";

		ptr = ptr->next;
	}
}




int main()
{
	ho hotel; // object of ho class

	while (true)
	{

		cout << "Hello,Rero Hotel" << endl;
		cout << "Enter num of proceess to continue" << endl;
		char choice;
		cin >> choice;

		switch (choice)
		{
		case '1':
			hotel.insert(); // book room
			break;

		case '2':
			hotel.search(); // search booking
			cout << "----------------------------------------------" << endl;
			break;

		case '3':
			hotel.update(); // update booking
			cout << "----------------------------------------------" << endl;
			break;

		case '4':
			hotel.delet(); // cancel booking 
			cout << "----------------------------------------------" << endl;
			break;



		case '5':
			hotel.show(); // show all bookings 
			cout << "----------------------------------------------" << endl;
			break;

		case '6':
			cout << "Bye,Bye";
			return 0; // exit

		default:
			cout << "Invalid Choice" << endl;
		}
	}


}