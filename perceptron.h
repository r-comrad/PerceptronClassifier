//--------------------------------------------------------------------------------

#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <vector>
#include <cstdlib>

#include "domain.h"

class Perceptron
{
public:
	Perceptron(int aDimension, double aLearningRate = 0.3);

	double	process			(const Args &aInp);
	double	getOutput		() const;
	void	changeWeights	(double aAnswer);

	const std::vector<double>& getPresentation() const;

private:
	double mSumm;
	double mOutput;
	double mLearningRate;

	double mOffset;
	std::vector<double> mWeights;

	Args inputs;

	double activationFunction	(double aS) const;
	double dActivationFunction	(double aS) const;
};

#endif // PERCEPTRON_H

//--------------------------------------------------------------------------------