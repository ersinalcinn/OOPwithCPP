#ifndef hex_GAME
#define hex_GAME
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;
class Hex {

public:
	int quit_check=0,countptr=0,countcell,score=0;
	explicit Hex(){}
	void printTable();
	int getType() const;
	int setType(int a);
	int getSize() const;
	int getUser() const;
	int setUser(int a);
	int setSize(int a);
	void playGame();
	void loadFile(string input);
	void fillTable();
	void compareGame();
	void fillPath();
	void play(int x, int y);
	void controlBoard(int *x);
	void saveFile(string path);
	void finalUpper(int winner);
	int findPath(int x, int y);
	void play();
	int quit();
	int getCoordinate();
	vector<vector<int> > newPath;
	int **cellPtr=new int*[30];
	Hex& operator--();
	friend ostream& operator<< (std::ostream &out, const Hex &hex);
	friend ofstream& operator << (ofstream& in, Hex &hex);
	friend ifstream& operator >>(ifstream& in,Hex &hex);
	friend bool operator==(const Hex &hex1,const Hex &hex2);
	friend bool operator >(const Hex &hex1,const Hex &hex2);
	class Cell {
	private:
		int row, column, value;
	public:
		int getRow();
		int getColumn();
		int getValue();
		int setRow(int r);
		int setColumn(int c);
		int setValue(int b);
	};

private:
	int selectType, size, userOrder;
	Cell ** hexCells;
};
vector<Hex> activeGame;


#endif

