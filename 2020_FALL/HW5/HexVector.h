#ifndef HexVector_H
#define HexVector_H
#include <vector>
#include "AbstractHex.h"

namespace HexGame {
using namespace std;

class HexVector: public AbstractHex {
public:
	HexVector();
	HexVector(int);
	HexVector(int xSize, int ySize);
	HexVector(const HexVector& other);
	virtual void setSize(const int& xSize, const int& ySize);
	virtual int& operator()(int x, int y);
	virtual const int& operator()(int x, int y) const;

	HexVector& operator=(const HexVector& other);

	~HexVector();

private:

	std::vector<std::vector<int>> hex;
};
}

#endif
