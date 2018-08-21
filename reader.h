//--------------------------------------------------------------------------------

#ifndef TEST_GENERATOR_H
#define TEST_GENERATOR_H

#include <vector>
#include <fstream>
#include <string>
#include <list>

#include "domain.h"

class TestGenerator
{
public:
	TestGenerator();
	~TestGenerator();

	virtual bool isEnd() const = 0;
	void next();

	virtual void generate(uint_32 aCount = 1) = 0;

	std::vector<uint_8> getTest() const;
	std::vector<std::vector<uint_8>> getMatrix(uint_8 aN, uint_8 aM) const;
	uint_16 getLabel() const;

protected:
	std::list<std::vector<uint_8>> mTestValues;
	std::list<uint_16> mLabelValues;
};

#endif // TEST_GENERATOR_H

//--------------------------------------------------------------------------------