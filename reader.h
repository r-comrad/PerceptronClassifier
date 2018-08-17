//--------------------------------------------------------------------------------

#ifndef READER_H
#define READER_H

#include <vector>
#include <fstream>
#include <string>
#include <list>

#include "domain.h"

class Reader
{
public:
	Reader();
	~Reader();

	virtual bool isEnd() const = 0;
	void pop();

	virtual void read(uint_32 aCount = 1) = 0;

	std::vector<uint_8> getTest() const;
	std::vector<std::vector<uint_8>> getMatrix(uint_8 aN, uint_8 aM) const;
	uint_8 getLabel() const;

protected:
	std::list<std::vector<uint_8>> mTestValues;
	std::list<uint_8> mLabelValues;
};

#endif // READER_H

//--------------------------------------------------------------------------------