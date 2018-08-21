//--------------------------------------------------------------------------------

#ifndef MNIST_READER_H
#define MNIST_READER_H

#include "reader.h"

class MNISTReader : public TestGenerator
{
public:
	MNISTReader(std::string aTestFileName, std::string aLabelFileName);
	~MNISTReader();

	virtual void generate(uint_32 aCount = 1);

	virtual bool isEnd() const;

private:
	std::ifstream mTestsFile, mLabelsFile;

	uint_32 mTestMagicNumber;
	uint_32 mTestNumberOfImages;
	uint_32 mTestRows;
	uint_32 mTestColumns;

	uint_32 mLabelMagicNumber;
	uint_32 mLabelNumberOfImages;

	uint_32 mReadCount;

	uint_32 reverseInt(uint_32 aNum);
};

#endif // MNIST_READER_H

//--------------------------------------------------------------------------------