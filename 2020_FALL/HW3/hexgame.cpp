#include <iostream>
#include<vector>
#include<stdlib.h>
#include<random>
#include<fstream>
#include<string>
using namespace std;
class Hex {
public:
	void fillPath();
	void play();
	void finalUpper();
	void saveFile();
	void loadFile();
	void playGame();
	void printBoard();
	void finalUpper(int winner);
	void controlBoard(int *x);
	void findPath(int x, int y);
	void fillBoard(int boardSize);
	static void compareCellSize();
	static int compareGame(int gameNumber);
	int play(int userOrder, int selectType, int boardSize);
	vector<vector<int> > newPath;
	class Cell {
	public:
		bool returnVal;
		int cellCount;
		int rowNumber;
		int columnNumber;
		int boardSize;
		int selectType;
		int userOrder;
		string path;
		enum type {
			x = 120, o = 111, empty = 46
		};
		void countCell() {
			cellCount++;
		}
		int getRow(int row) {
			rowNumber = row;
			return rowNumber;
		}
		int getRow() {
			return rowNumber;
		}
		int getColumn(int column) {
			columnNumber = column;
			return columnNumber;
		}
		int getColumn() {
			return columnNumber;
		}
		string pathFile(string pathfile) {
			path = pathfile;
			return path;;
		}
		int getboardSize(int size) {
			boardSize = size;
			return boardSize;
		}
		int getboardSize() {
			return boardSize;
		}
		int getSelectType(int Type) {
			selectType = Type;
			return selectType;
		}
		int getSelectType() {
			return selectType;
		}
		int getUserOrder(int User) {
			userOrder = User;
			return userOrder;
		}
		int getUserOrder() {
			return userOrder;
		}
	};
	Cell cell;
private:
	vector<vector<int> > hexCells;
};
vector<Hex> activeGame;//I've created a vector array globally. This array will have a function that records active games
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
		Hex hex;//I created a new object with reference to the hex class in each new game.
		hex.playGame();
		hex.fillPath();
		hex.fillBoard(hex.cell.getboardSize());
		hex.play(hex.cell.userOrder, hex.cell.selectType, hex.cell.boardSize);
		activeGame.push_back(hex);//I'm adding the newly created game to the active games lineup.
		main();
	}
	if (menuChoice == 2) {//the condition I use to list active ones
		/*
		 * Here, unfinished games that can be continued to be played are listed.
		 * From here, the user can make a selection to continue the active game or
		 * view the information of the active games.	 */
		if (activeGame.size() > 0) {
			for (int i = 0; i < activeGame.size(); i++) {
				cout << i + 1 << "- Game Properties => BoardSize:["
						<< activeGame[i].cell.boardSize << "x"
						<< activeGame[i].cell.boardSize << "] ";
				if (activeGame[i].cell.selectType == 1) {
					cout << "Type: UservsUser\n";
				} else {
					cout << "Type: UservsComputer\n";
				}

			}
			cout << "Select:";
			cin >> game;
			activeGame[game - 1].play(activeGame[game - 1].cell.userOrder,activeGame[game - 1].cell.selectType,activeGame[game - 1].cell.boardSize);
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
		if (activeGame.size() < 1) {
			cerr << "No Active Games\n";
			main();
		}
		else {
			for (int i = 0; i < activeGame.size(); i++) {
				activeGame[i].cell.cellCount = Hex::compareGame(i);
			}
			Hex::compareCellSize();
		}
	}
	else{
			cerr << "Wrong Selection.\n";
		}
}
void Hex::compareCellSize() {
	/*In the static void function, I access the board size of the games
	 *  that are active with the for loop and count the non-empty cells in the hex board.
	 *  I'm sending true to the game with the highest cell number */
	int temp = 0, index = 0;
	for (int i = 0; i < activeGame.size(); i++) {
		activeGame[i].cell.returnVal = false;
		cout << i + 1 << ".Game NonEmpty Cells Size:"
				<< activeGame[i].cell.cellCount << "\n";
		if (activeGame[i].cell.cellCount > temp) {
			temp = activeGame[i].cell.cellCount;
			index = i + 1;
		}
	}
	activeGame[index].cell.returnVal = true;
	cout << "More Marked Cell  " << index << ".Game" << endl;
}
int Hex::compareGame(int gameNumber) {
	//The function that I have defined as a static int array counts the non-empty cells in the active games tables and returns them.
	int count = 0;
	for (int j = 0; j < activeGame[gameNumber].hexCells.size(); j++) {
		for (int k = 0; k < activeGame[gameNumber].hexCells.size(); k++) {
			if (activeGame[gameNumber].hexCells[j][k] == 120 || activeGame[gameNumber].hexCells[j][k] == 111) {
				count++;
			}
		}
	}
	return count;
}
void Hex::finalUpper(int winner) {
	////As x or o, whichever won the game, I enlarge the variables in the way they won and clarify the path.
	for (int i = 0; i < Hex::cell.boardSize; i++) {
		for (int j = 0; j < Hex::cell.boardSize; j++) {
			if (winner == 1) {
				if (newPath[i][j] == 1) {
					Hex::hexCells[i][j] = 88; //if x wins the game
				}
			} else {
				if (newPath[i][j] == 1) {
					Hex::hexCells[i][j] = 79; //if o wins the game
				}
			}
		}
	}
	Hex::printBoard();
}
void Hex::play() {
	/*The function that I randomly take from empty cells for computer steps,
	save 2 cells to the table for the computer to play, and print it on the screen.
	*/
	int resultBoard = 0;
	int row = rand() % Hex::cell.boardSize;
	int column = rand() % Hex::cell.boardSize;
	if (Hex::hexCells[row][column] == Hex::cell.empty) {
		Hex::hexCells[row][column] = Hex::cell.o;
		Hex::controlBoard(&resultBoard);
		/* In this function, whether the hex table is full or not, depending on the situation, parameter by reference
		I am sending it back to the function with a pointer using constant parameter by reference.  */
		if (resultBoard != 1) {
			Hex::cell.userOrder = 2;
			Hex::cell.selectType = 2;
			for (int i = 0; i < Hex::cell.boardSize; i++) {
				if (Hex::hexCells[0][i] == 120) {
					Hex::cell.getColumn(0);
					Hex::cell.getRow(i);
					Hex::findPath(Hex::cell.columnNumber, Hex::cell.rowNumber);
					Hex::cell.userOrder = 1;

				}
			}
			Hex::play(Hex::cell.userOrder, Hex::cell.selectType,Hex::cell.boardSize);
		}
	} else {
		Hex::play();
	}
}
void Hex::controlBoard(int *x) {
	/*In this function, whether the hex table is full or not, depending on the situation, parameter by reference and a
	 I am sending it back to the function with a pointer using constant parameter by reference.  */
	auto countSize = 0, boardsize = 0;
	boardsize = hexCells.size();
	for (int i = 0; i < Hex::hexCells.size(); i++) {
		for (int j = 0; j < Hex::hexCells.size(); j++) {
			if (Hex::hexCells[i][j] == Hex::cell.x
					|| Hex::hexCells[i][j] == Hex::cell.o) {
				countSize++;
			}
		}
	}
	Hex::findPath(Hex::cell.columnNumber, Hex::cell.rowNumber);

	if (countSize == (boardsize * boardsize)) *x = 1;
	else *x = 0;
}
void Hex::loadFile() {
	/*First, I pull the file path from the function. Then I used the lineCount variable to read the file line by line.
		 *By reading char by char I read it whenever "\ n" is not equal and assign these values ​​to the necessary variables.
		 *In the last row, I created an array with size  pull the hex table (for the max value). I cast every char data I read into int and synchronized it to my array.
		 *In this function I used auto type variables and decltype..
		 */
	Hex hexLoad;
	char line;
	int lineCount = 0, akt, counter = 0, selectType, user, boardsize, count = 0;
	int loadArray[(hexLoad.cell.boardSize*hexLoad.cell.boardSize)];
	ifstream input(Hex::cell.path);
	if (input.is_open()) {
		while (input.get(line)) {
			if (line != '\n') {
				if (lineCount == 0) {
					if (line == '1')
						selectType = 1;
					else
						selectType = 2;
					hexLoad.cell.getSelectType(selectType);
				} else if (lineCount == 1) {
					if (line == '1')
						user = 1;
					else
						user = 2;
					hexLoad.cell.getUserOrder(user);
				} else if (lineCount == 2) {
					boardsize = (line - 48);
					hexLoad.cell.getboardSize(boardsize);
				} else {
					loadArray[counter] = int(line);
					counter++;

				}
			} else
				lineCount++;
		}
		//I am saving to loadArray vector array using vector array.
		vector<int> temp;
		for (int j = 0; j < counter; j++) {
			temp.push_back(loadArray[j]);
			count++;
			if (count == boardsize) {
				count = 0;
				hexLoad.hexCells.push_back(temp);
				temp.clear();
			}
		}
	}
	activeGame.push_back(hexLoad);
	hexLoad.play(hexLoad.cell.userOrder, hexLoad.cell.selectType,hexLoad.cell.boardSize);
	input.close();
}
void Hex::saveFile() {
	/*saveFile. This function works if the user wants to save the game. So if the user specifies "save" tag and "path" tag.
		 *If the game is uservsuser, it will print 1 if not 2 on the first line.
		 *If  the user who wants to save the game is the 1st user, 1 will write 2 if not the author.
		 *Line 3 shows the length of the game's boardSize.
		 *In the last line, it writes the hex table completely and writes to the specified txt file.
		 *I used default argument and const variable in this function
		 */
	ofstream output(Hex::cell.path);
	output << Hex::cell.selectType << "\n";
	output << Hex::cell.userOrder << "\n";
	output << Hex::cell.boardSize << "\n";
	for (int i = 0; i < hexCells.size(); i++) {
		for (int k = 0; k < hexCells.size(); k++) {
			output << char(hexCells[i][k]);
		}
	}
}
void Hex::printBoard() {
	//The function defined to print the table on the screen. This kind of refreshing the table.
	cout << "  ";
	for (int i = 0; i < hexCells.size(); i++) {
		cout << char('A' + i) << "  ";
	}
	cout << "\n";
	for (int i = 0; i < hexCells.size(); i++) {
		for (int j = 0; j < hexCells.size(); j++) {
			if (j == 0) {
				cout << i + 1 << "  ";
				for (int k = 0; k < i; k++) {
					cout << "  ";
				}
			}
			cout << char(hexCells[i][j]) << "  ";
		}
		cout << "\n";
	}
}
void Hex::fillBoard(int boardSize) {
	/*First of all, I created the vector array in order to make a
		condition according to the letters I will press on the screen and the location the user will enter.*/
	for (int i = 0; i < boardSize; i++) {
		vector<int> temp;
		for (int j = 0; j < boardSize; j++)
		{
			temp.push_back(Cell::empty);
		}
		hexCells.push_back(temp);
	}
}
void Hex::fillPath() {
	////In order to be able to use backtracking, I find out where my reference table, which I have defined, is going by keeping 1 and 0 from here.
	//Before using the vector array, I write 0 to all its cells.
	for (int i = 0; i < Hex::cell.boardSize; i++) {
		vector<int> temp;
		for (int j = 0; j < Hex::cell.boardSize; j++) {
			temp.push_back(0);
		}
		newPath.push_back(temp);
	}
}
int Hex::play(int userOrder, int selectType, int boardSize) {
	Hex::printBoard();
	auto check = 0, resultBoard = 0, result = 0;
	//cout << boardSize << ":" << selectType << ":" << userOrder;
	string column, path;
	if (selectType == 1) {
		if (userOrder == 1) {
			cout << "1.User Move:";
			cin >> column;
			if (column == "SAVE") {
				cin >> path; //I read the file extension by reading it in the second string.
				cout << "GAME SAVED..\n";
				Hex::cell.pathFile(path);
				saveFile();
				Hex::play(Hex::cell.userOrder, Hex::cell.selectType,Hex::cell.boardSize);
			} else if (column == "LOAD") {
				cin >> path; //I read the file extension by reading it in the second string.
				cout << "GAME İS LOADED..\n";
				Hex::cell.pathFile(path);
				Hex::loadFile();

			} else if (column == "QUİT") {
				userOrder = 1;
				Hex::cell.getUserOrder(userOrder);
				return 0;
			} else {
				for (int t = 0; t < hexCells.size(); t++) {
					if (char('A' + t) == column[0]
							&& hexCells[int(column[1] - 49)][t] == 46) {
						hexCells[int(column[1] - 49)][t] = 120;
						check = 1;
					}
				}
				if (check != 1) {
					cerr << "Try again..\n";
					Hex::play(Hex::cell.userOrder, Hex::cell.selectType,
							Hex::cell.boardSize);
				} else {
					Hex::cell.userOrder = 1;
					for (int i = 0; i < boardSize; i++) {
						if (Hex::hexCells[i][0] == Hex::cell.x) {
							Hex::cell.getColumn(i);
							Hex::cell.getRow(0);
							Hex::findPath(Hex::cell.columnNumber,Hex::cell.rowNumber);
						}
					}
					if (result == 1)
					{

					}
					else {
						Hex::controlBoard(&resultBoard);
						if (resultBoard != 1) {
							if (selectType == 1)
								Hex::cell.userOrder = 2;
							Hex::play(Hex::cell.userOrder, Hex::cell.selectType,Hex::cell.boardSize);
						}
					}
				}
			}
		} else if (userOrder == 2) {
			cout << "2.User Move:";
			cin >> column;
			if (column == "SAVE") {
				cin >> path; //I read the file extension by reading it in the second string.
				cout << "GAME SAVED..\n";
				Hex::cell.pathFile(path);
				saveFile();
				Hex::play(Hex::cell.userOrder, Hex::cell.selectType,Hex::cell.boardSize);
			} else if (column == "LOAD") {
				cin >> path; //I read the file extension by reading it in the second string.
				cout << "GAME İS LOADED..\n";
				Hex::cell.pathFile(path);
				Hex::loadFile();
				//loadFile(hex_Board,boardSize,selectType,path);
			} else if (column == "QUİT") {
				userOrder = 2;
				Hex::cell.getUserOrder(userOrder);
				return 0;
			} else
			{
				for (int t = 0; t < hexCells.size(); t++) {
					if (char('A' + t) == column[0]
							&& hexCells[int(column[1] - 49)][t] == 46) {
						hexCells[int(column[1] - 49)][t] = 111;
						check = 1;
					}
				}
				if (check != 1) {
					cerr << "Try again..\n";
					Hex::play(Hex::cell.userOrder, Hex::cell.selectType,
							Hex::cell.boardSize);
				} else {
					Hex::cell.userOrder = 2;
					for (int i = 0; i < boardSize; i++) {
						if (Hex::hexCells[0][i] == Hex::cell.o) {
							Hex::cell.getColumn(0);
							Hex::cell.getRow(i);
							Hex::findPath(Hex::cell.columnNumber,Hex::cell.rowNumber);
						}
					}
					if (result == 1) //If the value returned from the Findpath function is 1, I indicate that the 1st user won the game
					{	}
					else {
						Hex::controlBoard(&resultBoard);
						if (resultBoard != 1) {
							if (selectType == 1)
								Hex::cell.userOrder = 1;
							Hex::play(Hex::cell.userOrder, Hex::cell.selectType,Hex::cell.boardSize);
						}
					}
				}
			}
		}
	} else if (selectType == 2) {
		cout << "1.User Move:";
		cin >> column;
		if (column == "SAVE") {
			cin >> path; //I read the file extension by reading it in the second string.
			cout << "GAME SAVED..\n";
			Hex::cell.pathFile(path);
			saveFile();
			Hex::play(Hex::cell.userOrder, Hex::cell.selectType,Hex::cell.boardSize);
		} else if (column == "LOAD") {
			cin >> path; //I read the file extension by reading it in the second string.
			cout << "GAME İS LOADED..\n";
			Hex::cell.pathFile(path);
			Hex::loadFile();
		} else if (column == "QUİT") {
			userOrder = 1;
			Hex::cell.getUserOrder(userOrder);
			return 0;
		} else {

			for (int t = 0; t < hexCells.size(); t++) {
				if (char('A' + t) == column[0]
						&& hexCells[int(column[1] - 49)][t] == 46) {
					hexCells[int(column[1] - 49)][t] = 120;
					check = 1;
				}
			}
			if (check != 1) {
				cerr << "Try again..\n";
				Hex::play(Hex::cell.userOrder, Hex::cell.selectType,
						Hex::cell.boardSize);
			} else {
				Hex::cell.userOrder = 2;
				for (int i = 0; i < boardSize; i++) {
					if (Hex::hexCells[i][0] == Hex::cell.x) {
						Hex::cell.getColumn(i);
						Hex::cell.getRow(0);
						Hex::findPath(Hex::cell.columnNumber,Hex::cell.rowNumber);
					}
				}
				if (result == 1) //If the value returned from the Findpath function is 1, I indicate that the 1st user won the game
				{

				} else {
					Hex::controlBoard(&resultBoard);
					if (resultBoard != 1) {
						if (selectType == 2)
						{

							Hex::play();
						}
					}
				}
			}
		}
	}
}
void Hex::playGame() {
	 //I have defined the necessary variables.
	//I have written my if conditions according to the user response.*/
	//The user can play the game by entering a value such as A1 B5 C5.*/
	int type, user, size;
	cout << "Please enter board size :";
	cin >> size;
	cell.getboardSize(size);
	if (size >= 5) {
		cout << "Please Select Game Mode\n\n";
		cout << "1-UservsUser \n2-User vs Computer\nSelect:";
		cin >> type;
		if (type == 1) {
			cell.getSelectType(type);
			cout << "\n1-UservsUser Selected\n";
			user = 1;
			cell.getUserOrder(user);

		} else if (type == 2) {
			cell.getSelectType(type);
			cout << "\n1-UservsComputer Selected\n";
			user = 1;
			cell.getUserOrder(user);
		} else {
			cerr << "Wrong Selection.\n" << endl;
			exit(1);
		}
	} else
	{
		cerr << "BoardSize must be greater than 5.\n" << endl;
		exit(1);
	}
}
void Hex::findPath(int x, int y) {

	/*First of all, in this function,
		 * I checked that the y value I send in the first condition is not less than boardSize.
		 * If the value of y is equal to the value of boardSize, my condition will be met and return will return 1.
		 * Later, in my second condition, I used the condition according to whether the value is 'X' or 'Y'.
		 *  Thinking that there are different cases since they will start from the left and from the top. */
	////
	/*First, I created a vector array, to check
			 * where it is going through this array, to check if user 1 has taken the necessary steps to win the game.
			 *I check that he can reach the end of the game from the locations
			 *I he went to, if I wrote 1 in the reference table I just created to the
			 *I  regions he went to, in order not to pass the places he went to.
			 *it progresses by finding the X value in different locations,
			 *I reach the result by visiting the places that are X and 0 in the reference table.
			 *I have checked the positions using labyrinth recursion.
			 *I If the position is full, it returns to the starting point
			 *I by stepping back if there is no end of the position.
			 *I I tried to determine the winner by trying any path again	 */
	int returnvalue = 0;
	if (Hex::cell.userOrder == 1) {
		if (y < (Hex::cell.boardSize) - 1) {
			if (Hex::hexCells[x][y] == Hex::cell.x) {
				Hex::newPath[x][y] = 1;
				if (Hex::hexCells[x][y + 1] == Hex::cell.x && Hex::newPath[x][y + 1] == 0) {
					Hex::newPath[x][y + 1] = 1;
					Hex::findPath(x, y + 1);
				} else if (x > 0 && Hex::hexCells[x - 1][y] == Hex::cell.x && Hex::newPath[x - 1][y] == 0) {
					Hex::newPath[x - 1][y] = 1;
					Hex::findPath(x - 1, y);
				} else if (x > 0 && Hex::hexCells[x - 1][y + 1] == Hex::cell.x && Hex::newPath[x - 1][y + 1] == 0) {
					Hex::newPath[x - 1][y + 1] = 1;
					Hex::findPath(x - 1, y + 1);
				} else if (x < Hex::cell.boardSize - 1 && Hex::hexCells[x + 1][y] == Hex::cell.x && Hex::newPath[x + 1][y] == 0) {
					Hex::newPath[x + 1][y] = 1;
					Hex::findPath(x + 1, y);
				} else if (x < Hex::cell.boardSize - 1 && Hex::hexCells[x + 1][y - 1] == Hex::cell.x && Hex::newPath[x + 1][y - 1] == 0) {
					Hex::newPath[x + 1][y - 1] = 1;
					Hex::findPath(x + 1, y - 1);
				} else if (Hex::hexCells[x][y - 1] == Hex::cell.x && Hex::newPath[x][y - 1] == 0) {
					Hex::newPath[x][y - 1] = 1;
					Hex::findPath(x, y - 1);
				} else
					Hex::newPath[x][y] = 0;
				for (int j = 0; j < Hex::cell.boardSize; j++) {
					for (int k = 0; k < Hex::cell.boardSize; k++) {
						Hex::newPath[j][k] = 0;
					}
				}
			}
		}else returnvalue = 1;//By returning 1, I am sending that user 1 won the game
	}
	if (Hex::cell.userOrder == 2) {
		if (x < Hex::cell.boardSize - 1) {
			if (Hex::hexCells[x][y] == Hex::cell.o) {
				newPath[x][y] = 1;
				if (Hex::hexCells[x + 1][y] == Hex::cell.o && Hex::newPath[x + 1][y] == 0) {
					Hex::newPath[x + 1][y] = 1;
					Hex::findPath(x + 1, y);
				} else if (y > 0 && Hex::hexCells[x][y + 1] == Hex::cell.o && Hex::newPath[x][y + 1] == 0) {
					Hex::newPath[x][y + 1] = 1;
					Hex::findPath(x, y + 1);
				} else if (y > 0 && x < Hex::cell.boardSize - 1 && Hex::hexCells[x + 1][y - 1] == Hex::cell.o && Hex::newPath[x + 1][y - 1] == 0) {
					Hex::newPath[x + 1][y - 1] = 1;
					Hex::findPath(x + 1, y - 1);
				} else if (x > 0 && y < Hex::cell.boardSize - 1 && Hex::hexCells[x - 1][y + 1] == Hex::cell.o && Hex::newPath[x - 1][y + 1] == 0) {
					Hex::newPath[x - 1][y + 1] = 1;
					Hex::findPath(x - 1, y + 1);
				} else if (y < Hex::cell.boardSize - 1 && Hex::hexCells[x][y - 1] == Hex::cell.o && Hex::newPath[x][y - 1] == 0) {
					Hex::newPath[x][y - 1] = 1;
					Hex::findPath(x, y - 1);
				} else if (x > 0 && Hex::hexCells[x - 1][y] == Hex::cell.o && Hex::newPath[x - 1][y] == 0) {
					Hex::newPath[x][y] = 1;
					Hex::findPath(x - 1, y);
				}
				for (int j = 0; j < Hex::cell.boardSize; j++) {
					for (int k = 0; k < Hex::cell.boardSize; k++) {
						Hex::newPath[j][k] = 0;
					}
				}
			}
		} else returnvalue = 2; //By returning 2, I am sending that user 2 won the game
	}
	if (returnvalue == 1) {
		system("clear");
		cout << "GAME OVER   1.USER WON\n";
		Hex::finalUpper(1);
		main();
	} else if (returnvalue == 2) {
		system("clear");
		cout << "GAME OVER   2.USER WON\n";
		Hex::finalUpper(2);
		main();
	}
}
