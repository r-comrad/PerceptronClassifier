//--------------------------------------------------------------------------------

#ifndef DISCRETE_OUTPUT_LAYER_H
#define DISCRETE_OUTPUT_LAYER_H

#include <algorithm>

#include "output_layer.h"

class DiscreteOutputLayer : public OutputLayer
{
public:
	DiscreteOutputLayer	(uint_16 aConnectionsCount);
	~DiscreteOutputLayer();

	virtual Args process(const Args &aInp);
	virtual Args correct(const Args &aInp);
};

#endif // DISCRETE_OUTPUT_LAYER_H

//--------------------------------------------------------------------------------