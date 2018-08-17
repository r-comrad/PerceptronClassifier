#include "output_layer.h"

//--------------------------------------------------------------------------------
//							Output layer implementation							//
//--------------------------------------------------------------------------------

OutputLayer::OutputLayer(uint_8 aConnectionsCount) :
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
		if (aInp[i] > aInp[num])
		{
			num = i;
		}
	}
	return { double(num) };
}
//--------------------------------------------------------------------------------
Args
OutputLayer::correct(const Args &aInp)
{
	Args result(mConnectionsCount);
	result[aInp[0]] = 1;
	return result;
}
//--------------------------------------------------------------------------------