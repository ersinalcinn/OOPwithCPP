#include "AbstractHex.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

namespace HexGame {

AbstractHex::AbstractHex(void) {

}

void AbstractHex::readFile(const string& filename) {
	ifstream readFile(filename);
	int bordersize, select, usernumber;

	int count = 0;

	string s;
	//First of all, I open my file and if the file is opened, I do the operations, if not, I give an error.
	if (readFile.is_open()) {

		//Then I take the first 3 lines one by one, here after taking them one by one,
		//I read them once in order not to get the \ n at the end of each line, then I switch to the 2nd line and reread.
		getline(readFile, s);
		select = int(s[0] - 48);
		this->setType(select);
		getline(readFile, s);
		usernumber = int(s[0] - 48);
		this->setUser(usernumber);
		getline(readFile, s);
		bordersize = int(s[0] - 48);
		this->setSize(bordersize, bordersize);
		this->fillTable();

		getline(readFile, s);

		for (int i = 0; i < bordersize; i++) {
			for (int j = 0; j < bordersize; j++) {

				this->operator ()(i, j) = int(s[count]);

				count++;
			}
		}

	} else {
		cerr << "The file could not be opened. " << endl;
	}

}
void AbstractHex::writeFile(const string& filename) {
	ofstream saveFile(filename);
	saveFile << this->getType() << "\n" << this->getType() << "\n"
			<< this->get_x() << "\n";
	for (int i = 0; i < get_x(); i++) {
		for (int j = 0; j < get_y(); j++) {
			saveFile << char(this->operator ()(i, j));
		}
	}

}

void AbstractHex::fillTable() {

	for (int i = 0; i < get_x(); i++) {
		for (int j = 0; j < get_y(); j++) {
			this->operator()(i, j) = 46;

		}
	}

}
void AbstractHex::printTable() const {

	//I moved the table print operation commands I made in the printable function to << operator overloading here and made the necessary corrections.
	int tempSize = this->get_x();

	for (int i = 97; i < 123 && tempSize != 0; i++) {
		cout << "  " << char(i);
		tempSize--;
	}
	cout << "\n";

	for (int i = 0; i < this->get_x(); i++) {
		cout << i + 1;
		for (int k = 0; k < i + 1; k++) {
			cout << "  ";
		}
		for (int j = 0; j < this->get_x(); j++) {
			cout << char(this->operator()(i, j)) << "  ";
		}
		cout << "\n";
	}
	cout << "\n";

}

void AbstractHex::setSize(const int& x, const int& y) {
	if (x <= 1 || y <= 1) {
		cerr << endl << "Invalid size for argument ! " << endl << endl;

	}

	this->x = x;
	this->y = y;

}
void AbstractHex::setType(const int& setType) {

	this->selectType = setType;

}
int AbstractHex::findPath(int x, int y) {
	if (getUser() == 1) {

		if (y == get_y() - 1 && this->operator()(x, y) == 120) {
			newPath[x][y] = 1;
			isEnd(1);
			return 1;

		}

		else {

			//score=score+10;
			/*In this function, I need to check the places I go. For this, I create a 2-dimensional array again and mark the place
			 I go to as 1 and put that array in the if condition in order not to go to where I go. In this way, I record my steps.*/
			newPath[x][y] = 1;

			/*Since we have 6 cases, I check these cases with if conditions. In this if condition,
			 I check where I go and check whether I am going. If I have gone, I am considering another direction.*/
			if (y < get_y() && this->operator()(x, y + 1) == 120
					&& newPath[x][y + 1] == 0) {
				return findPath(x, y + 1);
			} else if (x > 0 && y < get_y()
					&& this->operator()(x - 1, y + 1) == 120
					&& newPath[x - 1][y + 1] == 0) {

				return findPath(x - 1, y + 1);
			} else if (x < get_x() - 1 && this->operator()(x + 1, y) == 120
					&& newPath[x + 1][y] == 0) {

				return findPath(x + 1, y);
			} else if (x < get_x() - 1 && y > 0
					&& this->operator()(x + 1, y - 1) == 120
					&& newPath[x + 1][y - 1] == 0) {

				return findPath(x + 1, y - 1);
			} else if (x > 0 && this->operator()(x - 1, y) == 120
					&& newPath[x - 1][y] == 0) {

				return findPath(x - 1, y);
			} else if (y > 0 && this->operator()(x, y - 1) == 120
					&& newPath[x][y - 1] == 0) {

				return findPath(x, y - 1);
			} else {
				newPath[x][y] = 0;

			}
		}
		return 0;
	}
	if (getUser() == 2) {

		if (x == get_x() - 1 && this->operator()(x, y) == 111) {
			newPath[x][y] = 1;
			isEnd(2);

		}

		else {
			//score=score+10;
			cout << x << y;
			/*In this function, I need to check the places I go. For this, I create a 2-dimensional array again and mark the place
			 I go to as 1 and put that array in the if condition in order not to go to where I go. In this way, I record my steps.*/
			newPath[x][y] = 1;

			/*Since we have 6 cases, I check these cases with if conditions. In this if condition,
			 I check where I go and check whether I am going. If I have gone, I am considering another direction.*/
			if (this->operator()(x + 1, y) == 111 && newPath[x + 1][y] == 0) {
				return findPath(x + 1, y);
			} else if (x > 0 && y < get_y()
					&& this->operator()(x - 1, y + 1) == 111
					&& newPath[x - 1][y + 1] == 0) {

				return findPath(x - 1, y + 1);
			} else if (y > 0 && x < get_x()
					&& this->operator()(x + 1, y - 1) == 111
					&& newPath[x + 1][y - 1] == 0) {

				return findPath(x + 1, y - 1);
			} else if (y > 0 && x < get_x()
					&& this->operator()(x + 1, y - 1) == 111
					&& newPath[x + 1][y - 1] == 0) {

				return findPath(x, y + 1);
			} else if (y < get_y() && this->operator()(x, y + 1) == 111
					&& newPath[x][y + 1] == 0) {

				return findPath(x - 1, y);
			} else if (y > 0 && this->operator()(x, y - 1) == 111
					&& newPath[x][y - 1] == 0) {

				return findPath(x, y - 1);
			} else {
				newPath[x][y] = 0;

			}

		}

	}

}
void AbstractHex::fillPath() {

	////In order to be able to use backtracking, I find out where my reference table, which I have defined, is going by keeping 1 and 0 from here.
	//Before using the vector array, I write 0 to all its cells.
	vector<int> v1;
	for (int i = 0; i < get_x(); i++) {
		for (int j = 0; j < get_y(); j++) {
			v1.push_back(0);
		}
		newPath.push_back(v1);

	}
}
bool AbstractHex::controlBoard() {
	/*In this function, whether the hex table is full or not, depending on the situation, parameter by reference and a
	 I am sending it back to the function with a pointer using constant parameter by reference.  */
	auto countSize = 0;

	for (int i = 0; i < get_x(); i++) {
		for (int j = 0; j < get_y(); j++) {
			if (this->operator()(i, j) == 120
					&& this->operator()(i, j) == 111) {
				countSize++;
			}
		}
	}
	if (countSize == (get_x() * get_y()))
		return true;
	else
		return false;
}
void AbstractHex::finalUpper(int winner) {
	////As x or o, whichever won the game, I enlarge the variables in the way they won and clarify the path.
	for (int i = 0; i < get_x(); i++) {
		for (int j = 0; j < get_y(); j++) {
			if (winner == 1) {
				if (newPath[i][j] == 1) {
					this->operator()(i, j) = 88; //if x wins the game
				}
			} else {
				if (newPath[i][j] == 1) {
					this->operator()(i, j) = 79; //if o wins the game
				}
			}
		}
	}
	printTable();
}
bool AbstractHex::isEnd(int result) {

	if (result == 1) {
		system("clear");
		cout << "GAME OVER   1.USER WON\n";
		finalUpper(1);
		exit(1);

	}
	if (result == 2) {
		system("clear");
		cout << "GAME OVER   2.USER WON\n";
		finalUpper(2);
		exit(1);
	} else if (controlBoard() == true) {
		cout << "Table is full.\n";
		exit(1);
	}
}
void AbstractHex::playGame() {
	//I have defined the necessary variables.
	//I have written my if conditions according to the user response.*/
	//The user can play the game by entering a value such as A1 B5 C5.*/
	int type, user;

	cout << "Please Select Game Mode\n\n";
	cout << "1-UservsUser \n2-User vs Computer\nSelect:";
	cin >> type;
	if (type == 1) {
		this->setType(type);
		cout << "\n1-UservsUser Selected\n";
		user = 1;
		this->setUser(user);
		this->getCoordinate();

	} else if (type == 2) {
		this->setType(type);
		cout << "\n1-UservsComputer Selected\n";
		user = 1;
		this->setUser(user);
		this->getCoordinate();

	} else {
		cerr << "Wrong Selection.\n" << endl;
		exit(1);
	}

}
int AbstractHex::play(int x, int y) {

//I implemented the condition which user will write which value to that cell.
	if (getUser() == 1) {
		this->operator()(x, y) = 120;
	} else {
		this->operator()(x, y) = 111;

	}
	last_Movex = char(x + 97);
	last_Movey = y + 1;

}
void AbstractHex::setUser(const int& a) {
	this->user = a;
}
int AbstractHex::getCoordinate() {
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
				writeFile(path);
				getCoordinate();
			} else if (column == "LOAD") {
				cin >> path; //I read the file extension by reading it in the second string.
				cout << "GAME İS LOADED..\n";
				readFile(path);
				getCoordinate();

			} else if (column == "QUIT") {
				return 0;
			} else {
				for (int t = 0; t < get_x(); t++) {
					if (char('A' + t) == column[0]
							&& this->operator()(int(column[1] - 49), t) == 46) {
						play(int(column[1] - 49), t);
						//I have performed the step deletion by adding the entered coordinates to the cell Part array consecutively.
						//I have made the necessary assignments and increments.
						check = 1;
					}
				}
				if (check != 1) {
					cerr << "Try again..\n";
					getCoordinate();
				} else {

					for (int i = 0; i < get_x(); i++) {
						if (this->operator()(i, 0) == 120) {
							for (int j = 0; j < get_x(); ++j) {
								for (int k = 0; k < get_y(); ++k) {

									newPath[k][j] = 0;

								}
							}
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
				writeFile(path);
				getCoordinate();
			} else if (column == "LOAD") {
				cin >> path; //I read the file extension by reading it in the second string.
				cout << "GAME İS LOADED..\n";
				readFile(path);
				getCoordinate();
			} else if (column == "LASTMOVE") {
				cout << last_Movex;
				cout << last_Movey << " " << "Value  : ";
				cout
						<< char(
								this->operator ()((int(last_Movex) - 97),
										last_Movey - 1));
				cout << endl;
				getCoordinate();
			} else if (column == "QUIT") {
				exit(1);
			} else {
				for (int t = 0; t < get_x(); t++) {
					if (char('A' + t) == column[0]
							&& this->operator()(int(column[1] - 49), t) == 46) {
						play(int(column[1] - 49), t);
						//I have performed the step deletion by adding the entered coordinates to the cell Part array consecutively.
						//I have made the necessary assignments and increments.
						check = 1;
					}
				}
				if (check != 1) {
					cerr << "Try again..\n";
					getCoordinate();
				} else {

					for (int i = 0; i < get_x(); i++) {
						if (this->operator()(0, i) == 111) {
							for (int j = 0; j < get_x(); ++j) {
								for (int k = 0; k < get_y(); ++k) {

									newPath[k][j] = 0;

								}
							}
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
			writeFile(path);
			getCoordinate();
		} else if (column == "LOAD") {
			cin >> path; //I read the file extension by reading it in the second string.
			cout << "GAME İS LOADED..\n";
			readFile(path);
			getCoordinate();
		} else if (column == "QUIT") {
			return 0;
		} else {
			for (int t = 0; t < get_x(); t++) {
				if (char('A' + t) == column[0]
						&& this->operator()(int(column[1] - 49), t) == 46) {
					play(int(column[1] - 49), t);
					//I have performed the step deletion by adding the entered coordinates to the cell Part array consecutively.
					//I have made the necessary assignments and increments.

					check = 1;
				}
			}
			if (check != 1) {
				cerr << "Try again..\n";
				getCoordinate();
			} else {

				for (int i = 0; i < get_x(); i++) {
					if (this->operator()(i, 0) == 120) {
						for (int j = 0; j < get_x(); ++j) {
							for (int k = 0; k < get_y(); ++k) {

								newPath[k][j] = 0;

							}
						}
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
int AbstractHex::play() {
	/*The function that I randomly take from empty cells for computer cellPtrs,
	 save 2 cells to the table for the computer to play, and print it on the screen.
	 */
	int resultBoard = 0;
	int row = rand() % get_x();
	int column = rand() % get_y();
	if (this->operator ()(row, column) == 46) {
		this->operator ()(row, column) = 111;

		/* In this function, whether the hex table is full or not, depending on the situation, parameter by reference
		 I am sending it back to the function with a pointer using constant parameter by reference.  */
		if (controlBoard() == false) {
			setUser(2);
			setType(2);
			for (int i = 0; i < get_x(); i++) {
				if (this->operator ()(0, i) == 120) {

					findPath(i, 0);

				}
			}

			setUser(1);
			getCoordinate();
		}
	} else {
		play();
	}
}
void AbstractHex::reset() {
	for (int j = 0; j < get_x(); ++j) {
		for (int i = 0; i < get_y(); ++i) {

			this->operator()(i, j) = '\0';

		}
	}
}

AbstractHex::~AbstractHex() {
}

}

