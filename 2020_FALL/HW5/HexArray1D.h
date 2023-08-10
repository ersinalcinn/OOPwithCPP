#ifndef BOARDARRAY1D_H
#define BOARDARRAY1D_H

#include "AbstractHex.h"
using namespace std;
namespace HexGame {

class HexArray1D: public AbstractHex {
public:
	HexArray1D();
	HexArray1D(int x, int y);
	virtual void setSize(const int& x, const int& y);
	virtual int& operator()(int x, int y);
	virtual const int& operator()(int x, int y) const;
	~HexArray1D();

private:
	int* hex;
};
}

#endif
