#ifndef Abstract
#define Abstract
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace HexGame
{
	class AbstractHex
	{
		public:

	           AbstractHex(void);
	           vector<vector<int> > newPath;
	           void fillTable();
	           bool controlBoard();
	           void fillPath();
	           void printTable() const;
	           int findPath(int x,int y);
	           void readFile(const string& filename);
	           void writeFile(const string& filename);
	           int play();
	           void finalUpper(int winner);
	           void playGame();
	           void reset();
	           void compareGame();
	           void  setType(const int& setType);
	           void  setUser(const int& user);
	           int getCoordinate();
	           int play(int x,int y);
	           bool isEnd(int result);
	           int get_x(void) const { return x; }
	           int get_y(void) const { return y; }
	           int getType(void) const { return selectType; }
	           int getUser(void) const { return user; }
	           virtual void setSize( const int& xSize , const int& ySize );
	           virtual int& operator()(int x , int y) = 0;
	           virtual const int& operator()(int x , int y) const = 0;
	           virtual ~AbstractHex();
	        private:
	            int x,y;
	            int selectType,user;
	            static int Number_Of_Hex;
	            char last_Movex;
	            int last_Movey;
	            int number_Of_Moves;
};

}

#endif
