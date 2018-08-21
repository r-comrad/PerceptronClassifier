#include "mnist_reader.h"

//--------------------------------------------------------------------------------
//							MNIST reader implementation							//
//--------------------------------------------------------------------------------

MNISTReader::MNISTReader(std::string aTestFileName, std::string aLabelFileName) :
	mTestsFile		(aTestFileName, std::ios::binary),
	mLabelsFile		(aLabelFileName, std::ios::binary),
	mReadCount		(0)
{
	if (!mTestsFile.is_open())
	{
		cout << "ERROR #F1: tests file doesn't open!\n";
		cout << "Path: " << aTestFileName << "\n";
	}
	if (!mLabelsFile.is_open())
	{
		cout << "ERROR #F2: label file doesn't open!\n";
		cout << "Path: " << aLabelFileName << "\n";
	}

	uint_32* testVariables[] = { &mTestMagicNumber,  &mTestNumberOfImages,
		&mTestRows, &mTestColumns };
	for (uint_8 i = 0; i < 4; ++i)
	{
		mTestsFile.read((char*)testVariables[i], sizeof(*(testVariables[i])));
		*(testVariables[i]) = reverseInt(*(testVariables[i]));
	}

	if (mTestMagicNumber != 2051)
	{
		cout << "ERROR #C1: wrong test magic number!\n";
		cout << "Magic number: " << mTestMagicNumber << " (correct: 2051)\n";
	}

	uint_32* labelVariables[] = { &mLabelMagicNumber,  &mLabelNumberOfImages };
	for (uint_8 i = 0; i < 2; ++i)
	{
		mLabelsFile.read((char*)labelVariables[i], sizeof(*(labelVariables[i])));
		*(labelVariables[i]) = reverseInt(*(labelVariables[i]));
	}

	if (mLabelMagicNumber != 2049)
	{
		cout << "ERROR #C2: wrong label magic number!\n";
		cout << "Magic number: " << mLabelMagicNumber << " (correct: 2049)\n";
	}
}
//--------------------------------------------------------------------------------
MNISTReader::~MNISTReader()
{
	mTestsFile.close();
	mLabelsFile.close();
}
//--------------------------------------------------------------------------------
void
MNISTReader::generate(uint_32 aCount)
{
	//if (aCount > mNumberOfImages - mReadCount)
	//	aCount = mNumberOfImages - mReadCount;

	for (uint_32 i = 0; i < aCount; ++i)
	{
		mTestValues.emplace_back(std::vector<uint_8 >(0));
		mReadCount++;
		unsigned char temp;

		for (uint_32 i = 0; i < mTestRows; ++i)
		{
			for (uint_32 j = 0; j < mTestColumns; ++j)
			{
				mTestsFile.read((char*)&temp, sizeof(temp));
				mTestValues.back().emplace_back(temp);
			}
		}

		mLabelsFile.read((char*)&temp, sizeof(temp));
		mLabelValues.emplace_back(temp);
	}
}
//--------------------------------------------------------------------------------
bool
MNISTReader::isEnd() const
{
	return mTestNumberOfImages <= mReadCount;
}
//--------------------------------------------------------------------------------
uint_32
MNISTReader::reverseInt(uint_32 aNum)
{
	int result = 0;
	for (uint_8 i = 0; i < 4; ++i)
	{
		result <<= 8;
		result += aNum & 255;
		aNum >>= 8;
	}
	return result;
}
//--------------------------------------------------------------------------------