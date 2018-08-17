//--------------------------------------------------------------------------------

#ifndef OUTPUT_LAYER_H
#define OUTPUT_LAYER_H

#include <vector>

#include "domain.h"
#include "perceptron.h"
#include "layer.h"

class OutputLayer : public Layer
{
public:
	OutputLayer(uint_8 aConnectionsCount = 10);
	~OutputLayer();

	virtual Args process (const Args &aInp);
	virtual Args correct (const Args &aInp);

private:
	uint_8 mConnectionsCount;
};

#endif // OUTPUT_LAYER_H

//--------------------------------------------------------------------------------