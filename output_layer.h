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
	OutputLayer(uint_16 aConnectionsCount);
	~OutputLayer();

	virtual Args process (const Args &aInp) = 0;
	virtual Args correct (const Args &aInp) = 0;

	virtual uint_16 size() const;

protected:
	uint_16 getConnectionsCount();

private:
	uint_16 mConnectionsCount;
};

#endif // OUTPUT_LAYER_H

//--------------------------------------------------------------------------------