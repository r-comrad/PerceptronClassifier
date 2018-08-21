#include "perceptron.h"

//--------------------------------------------------------------------------------
//							Perceptron implementation							//
//--------------------------------------------------------------------------------

Perceptron::Perceptron(int aDimension, double aLearningRate) :
	mSumm				(0),
	mWeights			(aDimension),
	mLearningRate		(aLearningRate)
{
	//srand(time(0));

	for (auto& i : mWeights)
	{
		i = (rand() % 1000 - 500) / 1000.;
		//i = 0;
	}
	mOffset = (rand() % 1000 - 500) / 1000.;
	//mOffset = 0;
}
//--------------------------------------------------------------------------------
double
Perceptron::process(const Args &aInp)
{
	inputs = aInp;

	mSumm = 0;
	for (int i = 0; i < mWeights.size(); ++i)
	{
		mSumm += mWeights[i] * (inputs)[i];
	}
	mSumm += mOffset;

	mOutput = activationFunction(mSumm);
	return mOutput;
}
//--------------------------------------------------------------------------------
double
Perceptron::getOutput() const
{
	return mOutput;
}
//--------------------------------------------------------------------------------
void
Perceptron::changeWeights(double aAnswer)
{
	double error = aAnswer - mOutput;
	double teta = error * dActivationFunction(mSumm);

	for (int i = 0; i < mWeights.size(); ++i)
	{
		mWeights[i] += mLearningRate * teta*(inputs)[i];
	}
	mOffset += mLearningRate * teta;
}
//--------------------------------------------------------------------------------
double
Perceptron::activationFunction(double aS) const
{
	return 1. / (1. + exp(-aS));
}
//--------------------------------------------------------------------------------
double
Perceptron::dActivationFunction(double aS) const
{
	return activationFunction(aS) * (1. - activationFunction(aS));
}
//--------------------------------------------------------------------------------
const std::vector<double>&
Perceptron::getPresentation() const
{
	return mWeights;
}
//--------------------------------------------------------------------------------