//--------------------------------------------------------------------------------

#ifndef NEURO_DATASET_H
#define NEURO_DATASET_H

#include "reader.h"

class NeuroTests : public TestGenerator
{
public:
	SumTests(uint_8 aFirstNumMax, uint_8 aSecondNumMax, uint_8 aMaxCicleCount);
	~SumTests();

	virtual void generate(uint_32 aCount = 1);

	virtual bool isEnd() const;

private:
	uint_8 mFirstNum;
	uint_8 mSecondNum;

	uint_8 mFirstNumMax;
	uint_8 mSecondNumMax;

	uint_8 mCicleCount;
	uint_8 mMaxCicleCount;
};

#endif // NEURO_DATASET_H

//--------------------------------------------------------------------------------