//--------------------------------------------------------------------------------

#ifndef NORMALIZE_LAYER_H
#define NORMALIZE_LAYER_H

#include <vector>

#include "domain.h"
#include "perceptron.h"
#include "layer.h"

class NormalizeLayer : public Layer
{
public:
	NormalizeLayer(uint_32 aNormalizeValue = 255);
	~NormalizeLayer();

	virtual Args process (const Args &aInp);
	virtual Args correct (const Args &aInp);

	virtual uint_16 size() const;

private:
	double mNormalizeValue;
};

#endif // NORMALIZE_LAYER_H

//--------------------------------------------------------------------------------