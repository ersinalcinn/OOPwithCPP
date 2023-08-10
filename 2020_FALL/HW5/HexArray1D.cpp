#include "HexArray1D.h"

namespace HexGame {

HexArray1D::HexArray1D(int x, int y) :
	AbstractHex() {
	setSize(x, y);
}

HexArray1D::HexArray1D() {

}
void HexArray1D::setSize(const int& x, const int& y) {

	AbstractHex::setSize(x, y);
	hex = new int[x * y];
}

int& HexArray1D::operator()(int x, int y) {

	return hex[y * get_x() + x];
}
const int& HexArray1D::operator()(int x, int y) const {
	return hex[y * get_x() + x];
}
HexArray1D::~HexArray1D() {
	delete[] hex;

}
}
