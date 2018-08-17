//--------------------------------------------------------------------------------

#ifndef DRAW_H
#define DRAW_H

#include <SFML/Graphics.hpp>

#include "domain.h"

class GUI
{
public:
	GUI();
	~GUI();

	void draw(std::vector<std::vector<uint_8>> aMatrix);
	
	enum EventTypes { NON, PAUSE, CLOSE, LEARN, TEST, CLASS_DRAW };
	EventTypes getEvents();

	sint_16 getClassNumber();

private:
	sf::RenderWindow mWindow;
	sf::RectangleShape mRectangle;

	uint_8 mDX;
	uint_8 mDY;

	uint_8 mRectLength;
	uint_8 mRectWidth;

	uint_8 mDistanceLength;
	uint_8 mDistanceWidth;

	sint_16 mCurrentClass;
};

#endif // READER_H

//--------------------------------------------------------------------------------