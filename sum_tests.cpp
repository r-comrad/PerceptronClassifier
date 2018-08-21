#include "sum_tests.h"

//--------------------------------------------------------------------------------
//								Sum test implementation							//
//--------------------------------------------------------------------------------

SumTests::SumTests(uint_8 aFirstNumMax, uint_8 aSecondNumMax, 
	uint_8 aMaxCicleCount) :
	mFirstNum			(0),
	mSecondNum			(0),

	mFirstNumMax		(aFirstNumMax),
	mSecondNumMax		(aSecondNumMax),

	mCicleCount			(0),
	mMaxCicleCount		(aMaxCicleCount)
{}
//--------------------------------------------------------------------------------
SumTests::~SumTests()
{}
//--------------------------------------------------------------------------------
void
SumTests::generate(uint_32 aCount)
{
	mTestValues.emplace_back(std::vector<uint_8>{ mFirstNum, mSecondNum });
	mLabelValues.emplace_back(uint_16(mFirstNum) + mSecondNum);

	++mFirstNum;
	if (mFirstNum > mFirstNumMax)
	{
		mFirstNum = 0;
		++mSecondNum;
		if (mSecondNum > mSecondNumMax)
		{
			mSecondNum = 0;
			++mCicleCount;
		}
	}
}
//--------------------------------------------------------------------------------
bool
SumTests::isEnd() const
{
	return mCicleCount >= mMaxCicleCount;
}
//--------------------------------------------------------------------------------