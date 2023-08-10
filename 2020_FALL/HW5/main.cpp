#include "HexArray1D.h"
#include "AbstractHex.h"
#include "HexVector.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
using namespace HexGame;
void printDetails(const AbstractHex*);
void testHexArray1D();
void testHexVector();
vector<AbstractHex> activeGame;
void printDetails(const AbstractHex* hex)
{
	cout << "Row : " << hex->get_x() << endl;
	cout << "Column : " << hex->get_y() << endl;

}
/*TEST FUNCTIONS */
void testHexVector() {
	cout << "_________________HexVector Testing_____________\n";
		HexVector arr1D_3(8, 8);
		arr1D_3.fillTable();
		arr1D_3.printTable();
		cout << "_______________  Print function testing  _______________\n";
		arr1D_3.printTable();
		HexVector arr1D_2(5, 5);
		cout << "_______________  SetUser and SetSelection function testing  _______________\n";
		arr1D_3.setUser(1);
		arr1D_3.printTable();
		cout << "_______________  Play function testing  _______________\n";
		arr1D_3.play(6, 6);
		cout << "_________________  writeFile function testing  _________________\n";
		cout << "Writing test HexVector.txt\n";
		arr1D_3.writeFile("HexVector.txt");
		cout << "_________________  readFile function testing  _________________\n";
		cout << "Writing test HexVector.txt\n";
		arr1D_3.readFile("HexVector.txt");
		arr1D_3.printTable();
		cout << "_______________  Reset function testing  _______________\n";
		arr1D_3.reset();
		arr1D_3.printTable();
		cout << "___________________  setSize function testing  ___________________\n";
		cout << "Before setSize function : \n";
		printDetails(&arr1D_3);
		cout << "\nAfter setSize function : \n";
		arr1D_3.setSize(7, 7);
		printDetails(&arr1D_3);
}

void testHexArray1D() {
	cout << "_________________HexArray1D Testing_____________\n";
	HexArray1D arr1D_3(8, 8);
	arr1D_3.fillTable();
	cout << "_______________  Print function testing  _______________\n";
	arr1D_3.printTable();
	HexArray1D arr1D_2(5, 5);
	cout << "_______________  SetUser and SetSelection function testing  _______________\n";
	arr1D_3.setUser(1);
	arr1D_3.printTable();
	cout << "_______________  Play function testing  _______________\n";
	arr1D_3.play(6, 6);
	cout << "_________________  writeFile function testing  _________________\n";
	cout << "Writing test HexVector1D.txt\n";
	arr1D_3.writeFile("HexVector1D.txt");
	cout << "_________________  readFile function testing  _________________\n";
	cout << "Writing test HexVector.txt\n";
	arr1D_3.readFile("HexVector1D.txt");
	arr1D_3.printTable();
	cout << "_______________  Reset function testing  _______________\n";
	arr1D_3.reset();
	arr1D_3.printTable();
	cout << "___________________  setSize function testing  ___________________\n";
	cout << "Before setSize function : \n";
	printDetails(&arr1D_3);
	cout << "\nAfter setSize function : \n";
	arr1D_3.setSize(7, 7);
	printDetails(&arr1D_3);
}

int main() {
	testHexArray1D();
	testHexVector();
	//I performed the menu operations in my main function and performed the operations according to the selections.
	int game, menuChoice, gametype;
	cout << "___________________________\n";
	cout << "1- Start game with HexArray1D\n";
	cout << "2- Start game with HexVector\n";
	cout << "Select :";
	cin >> gametype;
	cout << "MENU:\n";
	cout << "1- Start a new game\n";
	cout << "2- Select an active game\n";
	cout << "3- Compare two active game\n";
	cout << "4- Quit\nSelect:";
	cin >> menuChoice;
	if (menuChoice == 1) {
		//I have defined the necessary variables.
		//I have written my if conditions according to the user response.*/
		//The user can play the game by entering a value such as A1 B5 C5.*/
		int type, user, size;
		cout << "Please enter board size :";
		cin >> size;
		if (gametype == 1) {

			HexArray1D hex;
			hex.setSize(size, size);
			if (size >= 5) {

				//I created a new object with reference to the hex class in each new game.

				hex.fillPath();
				hex.fillTable();
				hex.playGame();

				//activeGame.push_back(hex); //I'm adding the newly created game to the active games lineup.
				//main();

			} else {
				cerr << "BoardSize must be greater than 5.\n" << endl;
				exit(1);
			}

		} else if (gametype == 2) {
			HexVector hex2;
			hex2.setSize(size, size);
			if (size >= 5) {

				//I created a new object with reference to the hex class in each new game.

				hex2.fillPath();
				hex2.fillTable();
				hex2.playGame();

				//activeGame.push_back(hex); //I'm adding the newly created game to the active games lineup.
				//main();

			} else {
				cerr << "BoardSize must be greater than 5.\n" << endl;
				exit(1);
			}
		} else {

		}

	}
	if (menuChoice == 2) { //the condition I use to list active ones
		/*
		 * Here, unfinished games that can be continued to be played are listed.
		 * From here, the user can make a selection to continue the active game or
		 * view the information of the active games.	 */
		/*if (activeGame.size() > 0) {
			for (int i = 0; i < activeGame.size(); i++) {
				cout << i + 1 << "- Game Properties => BoardSize:["
						<< activeGame[i].getSize() << "x"
						<< activeGame[i].getSize() << "] ";
				if (activeGame[i].getType() == 1) {
					cout << "Type: UservsUser\n";
				} else {
					cout << "Type: UservsComputer\n";
				}

			}
			cout << "Select:";
			cin >> game;
			activeGame[game - 1].getCoordinate();
		} else {
			cerr << "No Active Games\n";
			main();
		}*/
	}
	if (menuChoice == 4) { // Exit condition
		cout << "Bye\n";
		exit(1);
	}
	if (menuChoice == 3) {
		/* Function that counts non-empty cells of active games. Here I check all games.
		 * Then I send true to the most full game.	 */
		/*int game1, game2;
		cout << activeGame.size();
		if (activeGame.size() >= 2) {
			for (int i = 0; i < activeGame.size(); i++) {
				cout << "--->" << i + 1 << ".Game Properties --> Size :"
						<< activeGame[i].getSize() << "  Selection :"
						<< activeGame[i].getType() << "  User :"
						<< activeGame[i].getUser();
				cout << endl;
			}
			cout << "Please select two games  :";
			cin >> game1 >> game2;
			//I created 2 new hex objects and transferred the selected 2 active games to the objects and made comparisons.
			activeGame[game1 - 1].compareGame();
			activeGame[game2 - 1].compareGame();
			if (activeGame[game1 - 1] == activeGame[game2 - 1]) {
				cout << "Full-cell numbers are equal.\n";
			} else {
				cout << "Full-cell cell numbers are not equal.\n";
				if (activeGame[game1 - 1] > activeGame[game2 - 1]) {
					cout << "There are more cells full in game 1" << endl;

				} else {
					cout << "There are more cells full in game 2" << endl;

				}
			}
		}*/
	}

}
