//--------------------------------------------------------------------------------

#ifndef PERCEPTRON_LAYER_H
#define PERCEPTRON_LAYER_H

#include <vector>

#include "domain.h"
#include "perceptron.h"
#include "layer.h"

class PerceptronLayer : public Layer
{
public:
	PerceptronLayer(uint_32 aInputsNumber, uint_32 aNeuronsCount);
	~PerceptronLayer();

	virtual Args process (const Args &aInp);
	virtual Args correct (const Args &aInp);

	virtual uint_16 size() const;

	virtual const std::vector<double>& getPresentation(uint_32 aNeurin) const;

private:
	std::vector<Perceptron> mNeurons;
};

#endif // PERCEPTRON_LAYER_H

//--------------------------------------------------------------------------------