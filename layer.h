//--------------------------------------------------------------------------------

#ifndef LAYER_H
#define LAYER_H

#include <vector>

#include "domain.h"

class Layer
{
public:
	Layer() {}
	~Layer() {}

	virtual Args process (const Args &aInp) = 0;
	virtual Args correct (const Args &aInp) = 0;

	virtual const std::vector<double>& getPresentation(uint_32 aNeurin) const 
	{
		return {};
	}
};

#endif // LAYER_H

//--------------------------------------------------------------------------------