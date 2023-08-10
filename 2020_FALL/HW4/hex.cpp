#include <iostream>
#include "hexgame.h"
using namespace std;

int main() {
	//I performed the menu operations in my main function and performed the operations according to the selections.
	int game;
	int menuChoice;
	cout << "MENU:\n";
	cout << "1- Start a new game\n";
	cout << "2- Select an active game\n";
	cout << "3- Compare two active game\n";
	cout << "4- Quit\nSelect:";
	cin >> menuChoice;
	if (menuChoice == 1) {
		Hex hex; //I created a new object with reference to the hex class in each new game.

		hex.playGame();
		hex.fillPath();
		hex.fillTable();
		hex.getCoordinate();
		activeGame.push_back(hex); //I'm adding the newly created game to the active games lineup.
		main();
	}
	if (menuChoice == 2) { //the condition I use to list active ones
		/*
		 * Here, unfinished games that can be continued to be played are listed.
		 * From here, the user can make a selection to continue the active game or
		 * view the information of the active games.	 */
		if (activeGame.size() > 0) {
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
		}
	}
	if (menuChoice == 4) { // Exit condition
		cout << "Bye\n";
		exit(1);
	}
	if (menuChoice == 3) {
		/* Function that counts non-empty cells of active games. Here I check all games.
		 * Then I send true to the most full game.	 */
		int game1, game2;
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
					;
				} else {
					cout << "There are more cells full in game 2" << endl;

				}
			}
		}
	}
}
void Hex::compareGame() {
	//the function counts the full cells in the active games tables and countcell obj is equal to count
	int count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (hexCells[i][j].getValue() == 120
					|| hexCells[i][j].getValue() == 111) {
				count++;
			}
		}
	}

	countcell = count;
}
//I compared the size and size between the count cell objects of two games with the overload operator.
bool operator >(const Hex &hex1, const Hex &hex2) {

	return (hex1.countcell > hex2.countcell);

}
int Hex::getSize() const {
	return size;
}
int Hex::Cell::getValue() {
	return value;
}
int Hex::getUser() const {
	return userOrder;
}
int Hex::getType() const{
	return selectType;
}
int Hex::setSize(int a) {
	size = a;
	return size;
}
int Hex::setUser(int a) {
	userOrder = a;
	return userOrder;
}
int Hex::setType(int a) {
	selectType = a;
	return selectType;
}
int Hex::Cell::setValue(int b) {
	value = b;
	return value;
}

int Hex::getCoordinate() {
	//here is the function where the game is played.
	//Here the game is played according to the user and user status.
	//The cellPtr dynamic array that I have defined keeps the entered coordinate information in the array.
	printTable();

	auto check = 0, resultBoard = 0, result = 0;
	string column, path;
	if (getType() == 1) {
		if (getUser() == 1) {
			cout << "1.User Move:";
			cin >> column;
			if (column == "SAVE") {
				cin >> path; //I read the file extension by reading it in the second string.
				cout << "GAME SAVED..\n";
				saveFile(path);
				getCoordinate();
			} else if (column == "LOAD") {
				cin >> path; //I read the file extension by reading it in the second string.
				cout << "GAME İS LOADED..\n";
				loadFile(path);
				getCoordinate();

			} else if (column == "UNDO") {
				//When UNDO command is entered - operator will run
				--*this;
				printTable();
				getCoordinate();
			} else if (column == "QUIT") {
				return 0;
			} else {
				for (int t = 0; t < getSize(); t++) {
					if (char('A' + t) == column[0]
							&& hexCells[int(column[1] - 49)][t].getValue()
									== 46) {
						play(int(column[1] - 49), t);
						//I have performed the step deletion by adding the entered coordinates to the cell Part array consecutively.
						//I have made the necessary assignments and increments.
						cellPtr[countptr] = new int[2];
						cellPtr[countptr][1] = t;
						cellPtr[countptr][0] = column[1] - 49;
						countptr = countptr + 1;
						check = 1;
					}
				}
				if (check != 1) {
					cerr << "Try again..\n";
					getCoordinate();
				} else {
					score = 0;
					for (int i = 0; i < getSize(); i++) {
						if (hexCells[i][0].getValue() == 120 && hexCells[i][getSize()-1].getValue() == 120) {
							findPath(i, 0);
						}
					}
					setUser(2);
					getCoordinate();
				}
			}
		} else if (getUser() == 2) {
			cout << "2.User Move:";
			cin >> column;
			if (column == "SAVE") {
				cin >> path; //I read the file extension by reading it in the second string.
				cout << "GAME SAVED..\n";
				saveFile(path);
				getCoordinate();
			} else if (column == "LOAD") {
				cin >> path; //I read the file extension by reading it in the second string.
				cout << "GAME İS LOADED..\n";
				loadFile(path);
				getCoordinate();
			} else if (column == "UNDO") {
				--*this;
				printTable();
				getCoordinate();
			} else if (column == "QUIT") {
				return 0;
			} else {
				for (int t = 0; t < getSize(); t++) {
					if (char('A' + t) == column[0]
							&& hexCells[int(column[1] - 49)][t].getValue()
									== 46) {
						play(int(column[1] - 49), t);
						//I have performed the step deletion by adding the entered coordinates to the cell Part array consecutively.
						//I have made the necessary assignments and increments.
						cellPtr[countptr] = new int[2];
						cellPtr[countptr][1] = t;
						cellPtr[countptr][0] = column[1] - 49;
						countptr = countptr + 1;
						check = 1;
					}
				}
				if (check != 1) {
					cerr << "Try again..\n";
					getCoordinate();
				} else {
					score = 0;
					setUser(1);
					for (int i = 0; i < getSize(); i++) {
						if (hexCells[0][i].getValue() == 111) {
							findPath(0, i);
						}
					}
					setUser(1);
					getCoordinate();
				}
			}
		}
	} else if (getType() == 2) {
		cout << "1.User Move:";
		cin >> column;
		if (column == "SAVE") {
			cin >> path; //I read the file extension by reading it in the second string.
			cout << "GAME SAVED..\n";
			saveFile(path);
			getCoordinate();
		} else if (column == "LOAD") {
			cin >> path; //I read the file extension by reading it in the second string.
			cout << "GAME İS LOADED..\n";
			loadFile(path);
			getCoordinate();
		} else if (column == "UNDO") {
			--*this;
			printTable();
			getCoordinate();
		} else if (column == "QUIT") {
			return 0;
		} else {
			for (int t = 0; t < getSize(); t++) {
				if (char('A' + t) == column[0]
						&& hexCells[int(column[1] - 49)][t].getValue() == 46) {
					play(int(column[1] - 49), t);
					//I have performed the step deletion by adding the entered coordinates to the cell Part array consecutively.
					//I have made the necessary assignments and increments.
					cellPtr[countptr] = new int[2];
					cellPtr[countptr][1] = t;
					cellPtr[countptr][0] = column[1] - 49;
					countptr = countptr + 1;
					check = 1;
				}
			}
			if (check != 1) {
				cerr << "Try again..\n";
				getCoordinate();
			} else {
				score = 0;
				setUser(1);
				for (int i = 0; i < getSize(); i++) {
					if (hexCells[i][0].getValue() == 120) {
						findPath(i, 0);
					}
				}
				setUser(2);
				play();
				getCoordinate();
			}
		}
	}

}
void Hex::printTable() {
	//I defined the << operator to print the table on the screen.
	cout << *this;
}
void Hex::playGame() {
	//I have defined the necessary variables.
	//I have written my if conditions according to the user response.*/
	//The user can play the game by entering a value such as A1 B5 C5.*/
	int type, user, size;
	cout << "Please enter board size :";
	cin >> size;
	setSize(size);
	if (size >= 5) {
		cout << "Please Select Game Mode\n\n";
		cout << "1-UservsUser \n2-User vs Computer\nSelect:";
		cin >> type;
		if (type == 1) {
			setType(type);
			cout << "\n1-UservsUser Selected\n";
			user = 1;
			setUser(user);

		} else if (type == 2) {
			setType(type);
			cout << "\n1-UservsComputer Selected\n";
			user = 1;
			setUser(user);

		} else {
			cerr << "Wrong Selection.\n" << endl;
			exit(1);
		}
	} else {
		cerr << "BoardSize must be greater than 5.\n" << endl;
		exit(1);
	}
}
void Hex::play(int x, int y) {
	//I implemented the condition which user will write which value to that cell.
	if (getUser() == 1) {
		hexCells[x][y].setValue(120);
	} else {
		hexCells[x][y].setValue(111);
	}

}
void Hex::controlBoard(int *x) {
	/*In this function, whether the hex table is full or not, depending on the situation, parameter by reference and a
	 I am sending it back to the function with a pointer using constant parameter by reference.  */
	auto countSize = 0, boardsize = 0;
	boardsize = getSize();
	for (int i = 0; i < getSize(); i++) {
		for (int j = 0; j < getSize(); j++) {
			if (hexCells[i][j].getValue() == 120
					|| hexCells[i][j].getValue() == 111) {
				countSize++;
			}
		}
	}
	if (countSize == (boardsize * boardsize))
		*x = 1;
	else
		*x = 0;
}
void Hex::play() {
	/*The function that I randomly take from empty cells for computer cellPtrs,
	 save 2 cells to the table for the computer to play, and print it on the screen.
	 */
	int resultBoard = 0;
	int row = rand() % getSize();
	int column = rand() % getSize();
	if (hexCells[row][column].getValue() == 46) {
		hexCells[row][column].setValue(111);
		controlBoard(&resultBoard);
		/* In this function, whether the hex table is full or not, depending on the situation, parameter by reference
		 I am sending it back to the function with a pointer using constant parameter by reference.  */
		if (resultBoard != 1) {
			setUser(2);
			setType(2);
			for (int i = 0; i < getSize(); i++) {
				if (hexCells[0][i].getValue() == 120) {
					score = 0;
					findPath(i, 0);

				}
			}
			cout << "Computer Score :" << score << endl;
			setUser(1);
			getCoordinate();
		}
	} else {
		play();
	}
}
void Hex::fillTable() {
	/*First of all, I created the vector array in order to make a
	 condition according to the letters I will press on the screen and the location the user will enter.*/
	int size = getSize();
	hexCells = new Cell*[size];
	for (int i = 0; i < size; i++) {
		hexCells[i] = new Cell[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			hexCells[i][j].setValue(46);

		}
	}
}
void Hex::fillPath() {
	////In order to be able to use backtracking, I find out where my reference table, which I have defined, is going by keeping 1 and 0 from here.
	//Before using the vector array, I write 0 to all its cells.
	vector<int> v1;
	for (int i = 0; i < getSize(); i++) {
		for (int j = 0; j < getSize(); j++) {
			v1.push_back(0);
		}
		newPath.push_back(v1);

	}
}
ostream& operator <<(std::ostream &out, const Hex &hex) {
	//I moved the table print operation commands I made in the printable function to << operator overloading here and made the necessary corrections.
	int tempSize = hex.size;

	for (int i = 97; i < 123 && tempSize != 0; i++) {
		out << "  " << char(i);
		tempSize--;
	}
	out << "\n";

	for (int i = 0; i < hex.size; i++) {
		out << i + 1;
		for (int k = 0; k < i + 1; k++) {
			out << "  ";
		}
		for (int j = 0; j < hex.size; j++) {
			out << char(hex.hexCells[i][j].getValue()) << "  ";
		}
		out << "\n";
	}
	out << "\n";

	return out;
}
int Hex::findPath(int x, int y) {

	/*First of all, in this function,
	 * I checked that the y value I send in the first condition is not less than boardSize.
	 * If the value of y is equal to the value of boardSize, my condition will be met and return will return 1.
	 * Later, in my second condition, I used the condition according to whether the value is 'X' or 'Y'.
	 *  Thinking that there are different cases since they will start from the left and from the top. */
	////
	/*First, I created a vector array, to check
	 * where it is going through this array, to check if user 1 has taken the necessary cellPtrs to win the game.
	 *I check that he can reach the end of the game from the locations
	 *I he went to, if I wrote 1 in the reference table I just created to the
	 *I  regions he went to, in order not to pass the places he went to.
	 *it progresses by finding the X value in different locations,
	 *I reach the result by visiting the places that are X and 0 in the reference table.
	 *I have checked the positions using labyrinth recursion.
	 *I If the position is full, it returns to the starting point
	 *I by cellPtrping back if there is no end of the position.
	 *I I tried to determine the winner by trying any path again	 */
	int returnvalue = 0;
	if (getUser() == 1) {
		if (y < (getSize()) - 1) {
			score = score + 10;
			if (hexCells[x][y].getValue() == 120) {
				newPath[x][y] = 1;
				if (hexCells[x][y + 1].getValue() == 120
						&& newPath[x][y + 1] == 0) {
					newPath[x][y + 1] = 1;
					findPath(x, y + 1);
				} else if (x > 0 && hexCells[x - 1][y].getValue() == 120
						&& newPath[x - 1][y] == 0) {
					newPath[x - 1][y] = 1;
					findPath(x - 1, y);
				} else if (x > 0 && hexCells[x - 1][y + 1].getValue() == 120
						&& newPath[x - 1][y + 1] == 0) {
					newPath[x - 1][y + 1] = 1;
					findPath(x - 1, y + 1);
				} else if (x < getSize() - 1
						&& hexCells[x + 1][y].getValue() == 120
						&& newPath[x + 1][y] == 0) {
					newPath[x + 1][y] = 1;
					findPath(x + 1, y);
				} else if (x < getSize() - 1
						&& hexCells[x + 1][y - 1].getValue() == 120
						&& newPath[x + 1][y - 1] == 0) {
					newPath[x + 1][y - 1] = 1;
					findPath(x + 1, y - 1);
				} else if (Hex::hexCells[x][y - 1].getValue() == 120
						&& newPath[x][y - 1] == 0) {
					newPath[x][y - 1] = 1;
					findPath(x, y - 1);
				} else
					newPath[x][y] = 0;
				for (int j = 0; j < getSize(); j++) {
					for (int k = 0; k < getSize(); k++) {
						newPath[j][k] = 0;
					}
				}
			}
		} else {
			returnvalue = 1;

		} //By returning 1, I am sending that user 1 won the game
	}
	if (getUser() == 2) {
		if (x < getSize() - 1) {
			score = score + 10;
			if (hexCells[x][y].getValue() == 111) {
				newPath[x][y] = 1;
				if (hexCells[x + 1][y].getValue() == 111
						&& newPath[x + 1][y] == 0) {
					newPath[x + 1][y] = 1;
					findPath(x + 1, y);
				} else if (y > 0 && hexCells[x][y + 1].getValue() == 111
						&& newPath[x][y + 1] == 0) {
					newPath[x][y + 1] = 1;
					findPath(x, y + 1);
				} else if (y > 0 && x < getSize() - 1
						&& hexCells[x + 1][y - 1].getValue() == 111
						&& newPath[x + 1][y - 1] == 0) {
					newPath[x + 1][y - 1] = 1;
					findPath(x + 1, y - 1);
				} else if (x > 0 && y < getSize() - 1
						&& hexCells[x - 1][y + 1].getValue() == 111
						&& newPath[x - 1][y + 1] == 0) {
					newPath[x - 1][y + 1] = 1;
					findPath(x - 1, y + 1);
				} else if (y < getSize() - 1
						&& hexCells[x][y - 1].getValue() == 111
						&& newPath[x][y - 1] == 0) {
					newPath[x][y - 1] = 1;
					findPath(x, y - 1);
				} else if (x > 0 && hexCells[x - 1][y].getValue() == 111
						&& newPath[x - 1][y] == 0) {
					newPath[x][y] = 1;
					findPath(x - 1, y);
				}
				for (int j = 0; j < getSize(); j++) {
					for (int k = 0; k < getSize(); k++) {
						newPath[j][k] = 0;
					}
				}
			}
		} else {
			returnvalue = 2;
			score = score + 10;
		} //By returning 2, I am sending that user 2 won the game
	}
	if (returnvalue == 1) {
		system("clear");
		score = score + 10;
		cout << "1.USER SCORE :" << score << endl;
		cout << "GAME OVER   1.USER WON\n";
		finalUpper(1);
		main();
	} else if (returnvalue == 2) {
		system("clear");
		score = score + 10;
		cout << "2.USER SCORE :" << score << endl;
		cout << "GAME OVER   2.USER WON\n";
		finalUpper(2);
		main();
	}
}
void Hex::finalUpper(int winner) {
	////As x or o, whichever won the game, I enlarge the variables in the way they won and clarify the path.
	for (int i = 0; i < getSize(); i++) {
		for (int j = 0; j < getSize(); j++) {
			if (winner == 1) {
				if (newPath[i][j] == 1) {
					hexCells[i][j].setValue(88); //if x wins the game
				}
			} else {
				if (newPath[i][j] == 1) {
					hexCells[i][j].setValue(79); //if o wins the game
				}
			}
		}
	}
	printTable();
}
ofstream& operator <<(ofstream& out, Hex &hex) {
	//I moved my commands for saving the file I made in the saveFile function to << operator overloading here and made the necessary corrections.
	out << hex.getType() << "\n" << hex.getUser() << "\n" << hex.getSize()
			<< "\n";
	for (int i = 0; i < hex.getSize(); i++) {
		for (int j = 0; j < hex.getSize(); j++) {
			out << char(hex.hexCells[i][j].getValue());
		}
	}
	return out;
}
void Hex::loadFile(string input) {
	//This function loads the saved game. While I was saving in the file,
	//I printed the game type (uservsuser or uservscomputer) on the first line, and then on the 2nd line,
	//I printed the table size on the 3rd line, which user belongs to.
	//I printed the output of the table on the 4th line.

	ifstream readFile(input);
	readFile >> *this;
	readFile.close();
	//play();
}
void Hex::saveFile(string path) {

	//In the file saving process,
	//I send the user who the user is, the table size and the game type to the function you want to save and save.

	ofstream saveFile(path); //To record ofstream, ifstream to read

	saveFile << *this;

	saveFile.close();
	getCoordinate();
}
Hex& Hex::operator --() {
	//In the operator - function, I get counted in the getcoordinate function and check the countptr object first.
	//Then I reduce its value twice because I did this since the current user's step was before 2.
	//then I have my object returned by converting the value in my cell array to a blank cell.
	int x, y;
	if (countptr > 0) {
		--countptr;
		--countptr;

		x = cellPtr[countptr][0];
		y = cellPtr[countptr][1];
		hexCells[x][y].setValue(46);
	} else {
		cerr << "Move not found.\n";
	}
	return *this;
}
ifstream& operator >>(ifstream& in, Hex &hex) {

	int bordersize, select, usernumber,count=0;
	string s;
	//First of all, I open my file and if the file is opened, I do the operations, if not, I give an error.
	if (in.is_open()) {

		//Then I take the first 3 lines one by one, here after taking them one by one,
		//I read them once in order not to get the \ n at the end of each line, then I switch to the 2nd line and reread.
		getline(in, s);
		select = int(s[0] - 48);
		hex.setType(select);
		getline(in, s);
		usernumber = int(s[0] - 48);
		hex.setUser(usernumber);
		getline(in, s);
		bordersize = int(s[0] - 48);
		hex.setSize(bordersize);

		int a;
		getline(in, s);
		hex.fillTable();
		for (int i = 0; i < bordersize; i++) {
			for (int j = 0; j < bordersize; j++) {

				hex.hexCells[i][j].setValue(int(s[count]));

				count++;
			}
		}

		return in;

	} else {
		cerr << "The file not  opened. " << endl;
	}
	return in;
}
bool operator==(const Hex &hex1, const Hex &hex2) {
	//The operator I use to compare two games. The countcell of the two games also checks the number of non-empty cells.
	return (hex1.countcell == hex2.countcell);

}
