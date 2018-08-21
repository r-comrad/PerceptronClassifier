#include "output_layer.h"

//--------------------------------------------------------------------------------
//							Output layer implementation							//
//--------------------------------------------------------------------------------

OutputLayer::OutputLayer(uint_16 aConnectionsCount) :
	mConnectionsCount		(aConnectionsCount)
{}
//--------------------------------------------------------------------------------
OutputLayer::~OutputLayer()
{}
//--------------------------------------------------------------------------------
Args
OutputLayer::process(const Args &aInp)
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
double activationFunction(double aS) 
{
	return 1. / (1. + exp(-aS));
}
Args
OutputLayer::correct(const Args &aInp)
{
	//Args result(mConnectionsCount);
	//result[aInp[0]] = 1;
	Args result(mConnectionsCount);
	for (uint_16 i = 0; i < result.size(); ++i)
	{
		result[i] = activationFunction((i - aInp[0]) / 500);
	}
	return result;
}
//--------------------------------------------------------------------------------
uint_16
OutputLayer::size() const
{
	return 1;
}
//--------------------------------------------------------------------------------