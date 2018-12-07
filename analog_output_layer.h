//--------------------------------------------------------------------------------

#ifndef ANALOG_OUTPUT_LAYER_H
#define ANALOG_OUTPUT_LAYER_H

#include "output_layer.h"

class AnalogOutputLayer : public OutputLayer
{
public:
	AnalogOutputLayer (uint_16 aConnectionsCount);
	~AnalogOutputLayer();

	virtual Args process(const Args &aInp);
	virtual Args correct(const Args &aInp);

private:
	double funktion(double aS);
};

#endif // ANALOG_OUTPUT_LAYER_H

//--------------------------------------------------------------------------------