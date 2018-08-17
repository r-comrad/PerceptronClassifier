#include "gui.h"

//--------------------------------------------------------------------------------
//								Draw implementation								//
//--------------------------------------------------------------------------------

GUI::GUI() :
		mWindow				(sf::VideoMode(700, 700), "Matrix"), 

		mDX					(30),
		mDY					(30),

		mRectLength			(20),
		mRectWidth			(20),

		mDistanceLength		(2),
		mDistanceWidth		(2)		
{
	mRectangle.setSize(sf::Vector2f(mRectLength, mRectWidth));
}
//--------------------------------------------------------------------------------
GUI::~GUI()
{}
//--------------------------------------------------------------------------------
void
GUI::draw(std::vector<std::vector<uint_8>> aMatrix)
{
	//sf::RectangleShape rect(sf::Vector2f(20, 20));

	mWindow.clear(sf::Color(50, 50, 125, 125));

	for (uint_8 i = 0; i < aMatrix.size(); ++i)
	{
		for (uint_8 j = 0; j < aMatrix[i].size(); ++j)
		{
			mRectangle.setPosition(
				sf::Vector2f(mDX + j * (mRectLength + mDistanceLength),
					mDY + i * (mRectWidth + mDistanceWidth)));
			//mRectangle.setFillColor(
			//sf::Color(aMatrix[i][j], 25, 255 - aMatrix[i][j], 255));
			mRectangle.setFillColor(
				sf::Color(aMatrix[i][j], aMatrix[i][j], aMatrix[i][j], 255));
			mWindow.draw(mRectangle);
		}
	}

	mWindow.display();
}
//--------------------------------------------------------------------------------
GUI::EventTypes
GUI::getEvents()
{
	GUI::EventTypes result = GUI::EventTypes::NON;

	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			mWindow.close();
			result = GUI::EventTypes::CLOSE;
			return result;
		}
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Tab)
			{
				result = GUI::EventTypes::PAUSE;
				return result;
			}
			if (event.key.code == sf::Keyboard::X)
			{
				mWindow.close();
				result = GUI::EventTypes::CLOSE;
				return result;
			}
		}
	}

	return result;
}
//--------------------------------------------------------------------------------