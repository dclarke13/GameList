#include <iostream>
#include <vector>
#include <string>

using namespace std;

//prototype functions
void listAll();
int printMenu();
void runMenu();
void addNew();
void removeGame();


//create list and iterator
vector<string> gameList;
vector<string>::const_iterator iter;

int main()
{
	//add game to list
	gameList.push_back("Dark Souls");
	runMenu();

	return 0;
}



int printMenu() 
{
	int option;
	cout << "-----Game List-----" << endl;
	cout << "--- 1) List All Games---" << endl;
	cout << "--- 2) Add a Game---" << endl;
	cout << "--- 3) Remove a Game---" << endl;
	cout << "--- 0) Exit---" << endl;

	cin >> option;
	return option;

}

void runMenu() 
{
	int option = printMenu();
	while (option != 0)
	{

		switch (option)
		{
			
		case 1:  
			listAll();
			break;
		//add
		case 2:    
			addNew();
			break;
		//remove
		case 3:    
			removeGame();
			break;
		default:    cout << "invalid option entered: " << option << endl;
			break;
		}

		system("pause");


		option = printMenu();
	}


}

void listAll()
{
	int i = 1;
	cout << endl;
	for (iter = gameList.begin(); iter != gameList.end(); ++iter)
	{
		cout << i << "- " << *iter << endl;
		i++;
	}
	cout << endl;

}

void addNew()
{
	
	cout << "please enter new game title" << endl;
	string newGame = " ";
	cin.ignore();
	getline(cin, newGame);
	cout << newGame << " added to list" << endl;
	gameList.push_back(newGame);
	cout << endl;

}

void removeGame()
{

	cout << "Please choose no. of game to remove: \n" << endl;
	listAll();
	cout << endl;
	int id = 0;
	cin >> id;
	gameList.erase(gameList.begin() + (id -1));
	cout << "Game Removed" << endl;
	cout << endl;

}