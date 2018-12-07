#include "analog_output_layer.h"

//--------------------------------------------------------------------------------
//						Analog output layer implementation						//
//--------------------------------------------------------------------------------

AnalogOutputLayer::AnalogOutputLayer(uint_16 aConnectionsCount) :
	OutputLayer		(aConnectionsCount)
{}
//--------------------------------------------------------------------------------
AnalogOutputLayer::~AnalogOutputLayer()
{}
//--------------------------------------------------------------------------------
Args
AnalogOutputLayer::process(const Args &aInp)
{
	uint_32 num = 0;
	for (uint_32 i = 1; i < aInp.size(); ++i)
	{
		if (std::abs(0.5 - aInp[i]) < std::abs(0.5 - aInp[num]))
		{
			num = i;
		}
	}
	return { double(num) };
}
//--------------------------------------------------------------------------------
Args
AnalogOutputLayer::correct(const Args &aInp)
{
	Args result(getConnectionsCount());
	for (uint_16 i = 0; i < result.size(); ++i)
	{
		result[i] = funktion((i - aInp[0]) / 500);
	}
	return result;
}
//--------------------------------------------------------------------------------
double
AnalogOutputLayer::funktion(double aS)
{
	return 1. / (1. + exp(-aS));
}
//--------------------------------------------------------------------------------