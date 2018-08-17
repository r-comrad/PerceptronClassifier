#include "perceptron_layer.h"

//--------------------------------------------------------------------------------
//						Perceptron layer implementation							//
//--------------------------------------------------------------------------------

PerceptronLayer::PerceptronLayer(uint_32 aInputsNumber, uint_32 aNeuronsCount) :
	mNeurons		(aNeuronsCount, Perceptron(aInputsNumber))
{

}
//--------------------------------------------------------------------------------
PerceptronLayer::~PerceptronLayer()
{

}
//--------------------------------------------------------------------------------
Args
PerceptronLayer::process(const Args &aInp)
{
	Args resilt;
	for (auto& i : mNeurons)
	{
		double cur = i.process(aInp);
		resilt.emplace_back(cur);
	}
	return resilt;
}
//--------------------------------------------------------------------------------
Args
PerceptronLayer::correct(const Args &aInp)
{
	for (int i = 0; i < mNeurons.size(); ++i)
	{
		mNeurons[i].changeWeights(aInp[i]);
	}

	// TODO:
	return {};
}
//--------------------------------------------------------------------------------
const std::vector<double>&
PerceptronLayer::getPresentation(uint_32 aNeurin) const
{
	return mNeurons[aNeurin].getPresentation();
}
//--------------------------------------------------------------------------------