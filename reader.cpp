#include "reader.h"

//--------------------------------------------------------------------------------
//							Test generator implementation						//
//--------------------------------------------------------------------------------

TestGenerator::TestGenerator()
{}
//--------------------------------------------------------------------------------
TestGenerator::~TestGenerator()
{}
//--------------------------------------------------------------------------------
//bool
//Reader::eof() const
//{
//	return mInput.eof();
//}
//--------------------------------------------------------------------------------
void
TestGenerator::next()
{
	mTestValues.pop_front();
	mLabelValues.pop_front();
}
//--------------------------------------------------------------------------------
std::vector<uint_8>
TestGenerator::getTest() const
{
	return mTestValues.front();
}
//--------------------------------------------------------------------------------
std::vector<std::vector<uint_8>>
TestGenerator::getMatrix(uint_8 aN, uint_8 aM) const
{
	std::vector<std::vector<uint_8>> result;

	const std::vector<uint_8>& val = mTestValues.front();
	for (uint_8 i = 0; i < aM; ++i)
	{
		result.emplace_back(val.begin() + aN * i, val.begin() + aN * (i + 1));
	}

	return result;
}
//--------------------------------------------------------------------------------
uint_16
TestGenerator::getLabel() const
{
	return mLabelValues.front();
}
//--------------------------------------------------------------------------------