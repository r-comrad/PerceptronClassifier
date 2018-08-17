#include "normalize_layer.h"

//--------------------------------------------------------------------------------
//						Normalize layer implementation							//
//--------------------------------------------------------------------------------

NormalizeLayer::NormalizeLayer(uint_32 aNormalizeValue) :
	mNormalizeValue		(aNormalizeValue)
{}
//--------------------------------------------------------------------------------
NormalizeLayer::~NormalizeLayer()
{}
//--------------------------------------------------------------------------------
Args
NormalizeLayer::process(const Args &aInp)
{
	Args resilt;
	for (auto& i : aInp)
	{
		resilt.emplace_back(i / mNormalizeValue);
	}
	return resilt;
}
//--------------------------------------------------------------------------------
Args
NormalizeLayer::correct(const Args &aInp)
{
	return aInp;
}
//--------------------------------------------------------------------------------