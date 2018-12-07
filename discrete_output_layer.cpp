#include "discrete_output_layer.h"

//--------------------------------------------------------------------------------
//					Discrete output layer implementation						//
//--------------------------------------------------------------------------------

DiscreteOutputLayer::DiscreteOutputLayer(uint_16 aConnectionsCount) :
	OutputLayer		(aConnectionsCount)
{}
//--------------------------------------------------------------------------------
DiscreteOutputLayer::~DiscreteOutputLayer()
{}
//--------------------------------------------------------------------------------
Args
DiscreteOutputLayer::process(const Args &aInp)
{
	return { double( 
		std::distance(
			aInp.begin(), std::max_element(aInp.begin(), aInp.end())
		)
	)};
}
//--------------------------------------------------------------------------------
Args
DiscreteOutputLayer::correct(const Args &aInp)
{
	Args result(getConnectionsCount());
	result[aInp[0]] = 1;
	return result;
}
//--------------------------------------------------------------------------------