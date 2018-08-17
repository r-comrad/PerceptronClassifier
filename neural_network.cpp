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
	Args answer{ double(aAns) };
	for (sint_16 i = mLayers.size() - 1; i >= 0; --i)
	{
		answer = (mLayers[i])->correct(answer);
	}
}
//--------------------------------------------------------------------------------
std::vector<std::vector<uint_8>>
NeuralNetwork::getPresentation(uint_32 aLayer, uint_32 aNeurin) const
{
	std::vector<std::vector<uint_8>> result(1);
	const std::vector<double>& temp = mLayers[aLayer]->getPresentation(aNeurin);

	double mn = *(std::min_element(temp.begin(), temp.end()));
	double mx = *(std::max_element(temp.begin(), temp.end()));

	for (const auto& i : temp)
	{
		result.back().emplace_back((i - mn) / (mx - mn) * 255);
		if (result.back().size() % uint_32(std::sqrt(temp.size())) == 0)
		{
			result.resize(result.size() + 1);
		}
	}
	return result;
}
//--------------------------------------------------------------------------------