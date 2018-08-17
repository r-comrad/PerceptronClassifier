#include "neural_network.h"

//--------------------------------------------------------------------------------
//							Neural network implementation						//
//--------------------------------------------------------------------------------

NeuralNetwork::NeuralNetwork(std::vector<LayerType> aLayersType,
	std::list<std::pair<uint_32, uint_32>> aLayersConnexions)
{
	for (const auto& i : aLayersType)
	{
		if (i == NORMALIZE)
		{
			mLayers.emplace_back(new NormalizeLayer());
		}
		else if (i == PERCEPTRON)
		{
			std::pair<uint_32, uint_32> settings = aLayersConnexions.front();
			aLayersConnexions.pop_front();
			
			mLayers.emplace_back(
				new PerceptronLayer(settings.first, settings.second));
		}
		else if (i == OUTPUT)
		{
			mLayers.emplace_back(new OutputLayer());
		}
	}
}
//--------------------------------------------------------------------------------
NeuralNetwork::~NeuralNetwork()
{
	for (auto& i : mLayers)
	{
		delete(i);
	}
}
//--------------------------------------------------------------------------------
uint_32
NeuralNetwork::process(const Args &aInp)
{
	Args input = aInp;
	for (auto& i : mLayers)
	{
		input = i->process(input);
	}
	return input[0];
}
//--------------------------------------------------------------------------------
void
NeuralNetwork::correct(uint_32 aAns)
{
	Args answer = { double(aAns) };
	for (uint_16 i = mLayers.size() - 1; i >= 0; --i)
	{
		Args answer = (mLayers[i])->correct(answer);
	}
}
//--------------------------------------------------------------------------------
std::vector<std::vector<uint_8>>
NeuralNetwork::getPresentation(uint_32 aLayer, uint_32 aNeurin) const
{
	std::vector<std::vector<uint_8>> result;
	const std::vector<double>& temp = mLayers[aLayer]->getPresentation(aNeurin);
	for (const auto& i : temp)
	{
		result.emplace_back(i * 255);
	}
	return result;
}
//--------------------------------------------------------------------------------