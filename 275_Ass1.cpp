#include <iostream>

using namespace std;

// Structure to store song details
struct song
{
	string song_name;
	string artist;
	float time;
	song *next;

	// Constructor to initialize a song
	song(string a, string b, float c)
	{
		song_name = a;
		artist = b;
		time = c;
		next = NULL;
	}
};

// Playlist class using Singly Linked List
class Playlist
{
public:
	song *first;

	// Constructor
	Playlist()
	{
		first = NULL;
	}

	// Add song at the beginning
	void push_front(string a, string b, float c)
	{
		song *newsong = new song(a, b, c);
		if (first == NULL)
		{
			first = newsong;
		}
		else
		{
			newsong->next = first;
			first = newsong;
		}
		cout<<newsong->song_name<<" added to the front in the playlist!"<<endl;
	}

	// Add song at the end
	void push_back(string a, string b, float c)
	{
		song *newsong = new song(a, b, c);
		if (first == NULL)
		{
			first = newsong;
		}
		else
		{
			song *temp = first;
			while (temp->next != 0)
			{
				temp = temp->next;
			}
			temp->next = newsong;
		}
		cout<<newsong->song_name<<" added to the end in the playlist!"<<endl;
	}

	// Add song at a specific position
	void push_at_specific(string a, string b, float c, int n)
	{
		song *newsong = new song(a, b, c);
		if (first == NULL)
		{
			first = newsong;
		}
		else
		{
			int i = 0;
			song *temp = first;

			while (i != n - 2)
			{
				temp = temp->next;
				i++;
			}

			newsong->next = temp->next;
			temp->next = newsong;
		}

		cout<<newsong->song_name<<" added to the "<<n<<"th position in the playlist!"<<endl;
	}

	// Delete first song
	void pop_front()
	{
		if (first == NULL)
		{
			cout << "Playlist is empty!" << endl;
		}
		else
		{
			song *temp = first;
			first = temp->next;
			temp->next = NULL;
			cout<<temp->song_name<<" is deleted from the playlist!"<<endl;
			delete temp;
		}
	}

	// Delete last song
	void pop_back()
	{
		if (first == NULL)
		{
			cout << "Playlist is empty!" << endl;
		}
		else
		{
			song *temp = first;
			while (temp->next->next != NULL)
			{
				temp = temp->next;
			}

			song *last = temp->next;
			temp->next = NULL;
			cout<<last->song_name<<" is deleted from the playlist!"<<endl;
			delete last;
		}
	}

	// Delete a specific song by name
	void pop_at_specific(string a)
	{
		if (first == NULL)
		{
			cout << "Playlist is empty!" << endl;
		}
		else
		{
			song *temp = first;

			if (temp->song_name == a)
			{
				song *nodeToDelete = temp;
				first = first->next;
				cout<<nodeToDelete->song_name<<" is deleted from the playlist!"<<endl;
				delete nodeToDelete;
				return;
			}

			while (temp->next != NULL && temp->next->song_name != a)
			{
				temp = temp->next;
			}

			if (temp->next != nullptr)
			{
				song *p = temp->next;
				temp->next = p->next;
				cout<<p->song_name<<" is deleted from the playlist!"<<endl;
				delete p;
			}

			if (temp == NULL)
			{
				cout << "Song not found!" << endl;
			}
		}
	}

	// Display all songs
	void display()
	{
		cout << "Your playlist: " << endl;
		song *temp = first;

		while (temp != NULL)
		{
			cout << "Song name: " << temp->song_name << endl;
			cout << "Artist: " << temp->artist << endl;
			cout << "Song time: " << temp->time << " min" << endl << endl;
			temp = temp->next;
		}
	}

	// Play a specific song
	void play_specific(string n)
	{
		song *temp = first;

		if (first == NULL)
		{
			cout << "Playlist is empty!" << endl;
		}

		while (temp->song_name != n)
		{
			temp = temp->next;
		}

		cout << "Playing: " << temp->song_name << endl;
		cout << "Artist: " << temp->artist << endl;
		cout << "Duration: " << temp->time << endl;
	}

	// Find the song with maximum duration
	void max_duration_song()
	{
		float max = 0;
		song *temp = first;
		song *maxtemp = first;

		if (first == NULL)
		{
			cout << "Playlist is empty!" << endl;
		}

		while (temp != NULL)
		{
			if (temp->time > max)
			{
				max = temp->time;
				maxtemp = temp;
			}
			temp = temp->next;
		}

		cout << "Song with maximum duration: " << maxtemp->song_name << endl;
		cout << "Artist: " << maxtemp->artist << endl;
		cout << "Maximum Duration: " << max << endl;
	}

	// Delete all songs of a specific artist
	void pop_songs_of_artist(string b)
	{
		if (first == NULL)
		{
			cout << "Playlist is empty!" << endl;
		}

		song *temp = first;

		while (temp != NULL)
		{
			song *nextsong = temp->next;

			if (temp->artist == b)
			{
				pop_at_specific(temp->song_name);
			}

			temp = nextsong;
		}
	}
};

int main()
{
	Playlist Myplaylist;
	int pos, n;
	float dur;
	string sn, ar;

	// Menu-driven program
	do
	{
		cout<<"Menu: "<<endl;
		cout<<"1.Add song at beginning "<<endl;
		cout<<"2.Add song in the end "<<endl;
		cout<<"3.Add song at specific position "<<endl;
		cout<<"4.Delete song in the beginning "<<endl;
		cout<<"5.Delete song in the end "<<endl;
		cout<<"6.Delete song from specific position "<<endl;
		cout<<"7.Find song with maximum duration "<<endl;
		cout<<"8.Delete song of specific artist "<<endl;
		cout<<"9. Play specific song"<<endl;
		cout<<"10.Display "<<endl;
		cout<<"11. Exit "<<endl;
		cin>>n;

		switch(n)
		{
			case 1:
				cout<<"Enter song name: "<<endl;
				cin.ignore();
				getline(cin,sn);

				cout<<"Enter Artist name: "<<endl;
				cin.ignore();
				getline(cin,ar);

				cout<<"Enter duration of song: "<<endl;
				cin>>dur;

				Myplaylist.push_front(sn,ar,dur);
				break;

			case 2:
				cout<<"Enter song name: "<<endl;
				cin.ignore();
				getline(cin,sn);

				cout<<"Enter Artist name: "<<endl;
				cin.ignore();
				getline(cin,ar);

				cout<<"Enter duration of song: "<<endl;
				cin>>dur;

				Myplaylist.push_back(sn,ar,dur);
				break;

			case 3:
				cout<<"Enter song name: "<<endl;
				cin.ignore();
				getline(cin,sn);

				cout<<"Enter Artist name: "<<endl;
				cin.ignore();
				getline(cin,ar);

				cout<<"Enter duration of song: "<<endl;
				cin>>dur;

				cout<<"Enter the position to add this song at: "<<endl;
				cin>>pos;

				Myplaylist.push_at_specific(sn,ar,dur,pos);
				break;

			case 4:
				Myplaylist.pop_front();
				break;

			case 5:
				Myplaylist.pop_back();
				break;

			case 6:
				cout<<"Enter song name: "<<endl;
				cin.ignore();
				getline(cin,sn);

				Myplaylist.pop_at_specific(sn);
				break;

			case 7:
				Myplaylist.max_duration_song();
				break;

			case 8:
				cout<<"Enter Artist name: "<<endl;
				cin.ignore();
				getline(cin,ar);

				Myplaylist.pop_songs_of_artist(ar);
				break;

			case 9:
				cout<<"Enter song name: "<<endl;
				cin.ignore();
				getline(cin,sn);

				Myplaylist.play_specific(sn);
				break;

			case 10:
				Myplaylist.display();
				break;

			case 11:
				cout<<"Thankyou for using playlist!"<<endl;
				break;

			default:
				cout<<"Invalid choice!"<<endl;
		}
	}
	while(n!=11);

	return 0;
}