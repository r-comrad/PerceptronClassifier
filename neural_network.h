//--------------------------------------------------------------------------------

#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <vector>
#include <list>

#include "domain.h"

#include "layer.h"
#include "perceptron_layer.h"
#include "normalize_layer.h"
#include "output_layer.h"

class NeuralNetwork
{
public:
	enum LayerType {NORMALIZE, PERCEPTRON, OUTPUT};

	NeuralNetwork(std::vector<LayerType> aLayersType, 
		std::list<std::pair<uint_32, uint_32>> aLayersConnexions);
	~NeuralNetwork();

	uint_32 process	(const Args &aInp);
	void	correct	(uint_32 aAns);

	std::vector<std::vector<uint_8>> 
		getPresentation(uint_32 aLayer, uint_32 aNeurin) const;

private:
	std::vector<Layer*> mLayers;
};

#endif // NEURAL_NETWORK_H

//--------------------------------------------------------------------------------