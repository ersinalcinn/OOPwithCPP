#include <iostream>
#include "HexVector.h"
#include "HexVector.h"

namespace HexGame {
using namespace std;

HexVector::HexVector() {

}
HexVector::HexVector(int s) {

}
HexVector::HexVector(int xSize, int ySize) :
		AbstractHex() {
	setSize(xSize, ySize);
}

HexVector::HexVector(const HexVector& other) :
		AbstractHex(other) {

	setSize(get_x(), get_y());
	for (int j = 0; j < get_y(); ++j)
		for (int i = 0; i < get_x(); ++i)
			hex[i][j] = other.hex[i][j];
}

void HexVector::setSize(const int& xSize, const int& ySize) {
	if (!hex.empty())
		hex.clear();
	AbstractHex::setSize(xSize, ySize);
	hex.resize(xSize, std::vector<int>(ySize, -1));
}
int& HexVector::operator()(int x, int y) {
	if ((x < 0 || x > (get_x() - 1)) || (y < 0 || y > (get_y() - 1))) {
		cerr << endl << "Invalid argument ! Error , operator() " << endl
				<< endl;
	}
	return hex[x][y];
}
const int& HexVector::operator()(int x, int y) const {
	if ((x < 0 || x > (get_x() - 1)) || (y < 0 || y > (get_y() - 1))) {
		cerr << endl << "Invalid argument ! Error , operator() " << endl
				<< endl;
	}
	return hex[x][y];
}

HexVector::~HexVector() {
	hex.clear();
}
}
