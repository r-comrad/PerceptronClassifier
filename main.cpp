//#include <SFML/Graphics.hpp>
//
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//	sf::CircleShape shape(100.f);
//	shape.setFillColor(sf::Color::Green);
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		window.clear();
//		window.draw(shape);
//		window.display();
//	}
//
//	return 0;
//}

#include "gui.h"
#include "mnist_reader.h"
//#include "perceptron_layer.h"
#include "neural_network.h"
#include "sum_tests.h"

enum programmState {NON, PAUSE, LEARN, TEST};

int main()
{
	bool flag = true;
	GUI gui;

	PerceptronLayer layer(28*28, 10);
	MNISTReader mnistLearn(PROJECT_RESOURSES_PATH "MNIST/train_images",
		PROJECT_RESOURSES_PATH "MNIST/train_labels");
	MNISTReader mnistTest(PROJECT_RESOURSES_PATH "MNIST/test_images",
		PROJECT_RESOURSES_PATH "MNIST/test_labels");

	NeuralNetwork network
	(
		{ NeuralNetwork::LayerType::NORMALIZE,
		NeuralNetwork::LayerType::PERCEPTRON,
		NeuralNetwork::LayerType::DISCRETE_OUTPUT
		},
		{ std::make_pair(784, 10) }
	);
	int cor = 0, err = 0;
	sint_8 drawClaaNumber = -1;
	programmState state = NON, pausedState = NON;
	for(uint_32 cicleCount = 0;; ++cicleCount)
	{
		uint_8 ans = -1, res = -1;
		GUI::EventTypes myEvent = gui.getEvents();
		if (myEvent == GUI::EventTypes::PAUSE)
		{
			if (state != PAUSE)
			{
				pausedState = state;
				state = PAUSE;
			}
			else
			{
				state = pausedState;
			}
		}
		else if (myEvent == GUI::EventTypes::CLOSE)
		{
			return 0;
		}
		else if (myEvent == GUI::EventTypes::CLASS_DRAW)
		{
			sint_16 num = gui.getClassNumber();
			if (num == -200)
			{
				drawClaaNumber = -1;
			}
			else if (num == -100)
			{
				--drawClaaNumber;
				if (drawClaaNumber < 0) drawClaaNumber = 9;
			}
			else if (num == 100)
			{
				++drawClaaNumber;
				if (drawClaaNumber > 9) drawClaaNumber = 0;
			}
			else
			{
				drawClaaNumber = num - 1;
			}
		}
		else if (myEvent == GUI::EventTypes::LEARN)
		{
			state = LEARN;
		}
		else if (myEvent == GUI::EventTypes::TEST)
		{
			state = TEST;
		}

		if (drawClaaNumber != -1)
		{
			gui.draw(network.getPresentation(1, drawClaaNumber));
		}

		if (state == PAUSE)
		{
			--cicleCount;
			continue;
		}
		else if (state == LEARN)
		{
			if (mnistLearn.isEnd())
			{
				state == NON;
				continue;
			}

			mnistLearn.generate();
			std::vector<uint_8> test = mnistLearn.getTest();
			uint_8 lab = mnistLearn.getLabel();

			res = network.process(Args(test.begin(), test.end()));
			ans = lab;
			network.correct(lab);
		}
		else if (state == TEST)
		{
			if (mnistTest.isEnd())
			{
				state == NON;
				continue;
			}

			mnistTest.generate();
			std::vector<uint_8> test = mnistTest.getTest();
			uint_8 lab = mnistTest.getLabel();

			res = network.process(Args(test.begin(), test.end()));
			ans = lab;
		}

		if (state == LEARN)
		{
			cout << "#" << cicleCount << " ans:" << char(ans + '0') << " res:" << char(res + '0')
				<< " corr:" << ((ans == res) ? "YES" : "NO ") << "\n";
		}
		else if (state == TEST)
		{
			if (ans == res) ++cor;
			else ++err;
			cout << "#" << cicleCount << " ans:" << char(ans + '0') << " res:" << char(res + '0')
				<< " corr" << ((ans == res) ? "YES" : "NO ") << " " << cor << "-" << err << "\n";
		}
		else
		{
			cicleCount--;
		}
	}

	return 0;
}

int mainn()
{
	//freopen("output", "w", stdout);

	bool flag = true;
	GUI gui;

	SumTests sumLearn(250, 250, 10);
	SumTests sumTest(250, 250, 1);

	NeuralNetwork network
	(
		{ NeuralNetwork::LayerType::NORMALIZE,
		NeuralNetwork::LayerType::PERCEPTRON,
		NeuralNetwork::LayerType::ANALOG_OUTPUT
		},
		{ std::make_pair(2, 500) }
	);
	int cor = 0, err = 0;
	sint_8 drawClaaNumber = -1;
	programmState state = NON;
	for(uint_32 cicleCount = 0;; ++cicleCount)
	{
		uint_16 ans = -1, res = -1;
		GUI::EventTypes myEvent = gui.getEvents();
		if (myEvent == GUI::EventTypes::PAUSE)
		{
			if (state != PAUSE)
			{
				state = PAUSE;
			}
			else
			{
				state = NON;
			}
		}
		else if (myEvent == GUI::EventTypes::CLOSE)
		{
			return 0;
		}
		else if (myEvent == GUI::EventTypes::CLASS_DRAW)
		{
			sint_16 num = gui.getClassNumber();
			if (num == -200)
			{
				drawClaaNumber = -1;
			}
			else if (num == -100)
			{
				--drawClaaNumber;
				if (drawClaaNumber < 0) drawClaaNumber = 9;
			}
			else if (num == 100)
			{
				++drawClaaNumber;
				if (drawClaaNumber > 9) drawClaaNumber = 0;
			}
			else
			{
				drawClaaNumber = num - 1;
			}
		}
		else if (myEvent == GUI::EventTypes::LEARN)
		{
			state = LEARN;
		}
		else if (myEvent == GUI::EventTypes::TEST)
		{
			state = TEST;
		}

		if (state == PAUSE)
		{
			--cicleCount;
			continue;
		}
		else if (state == LEARN)
		{
			if (sumLearn.isEnd())
			{
				state == NON;
				continue;
			}

			sumLearn.generate();
			std::vector<uint_8> test = sumLearn.getTest();
			uint_16 lab = sumLearn.getLabel();

			res = network.process(Args(test.begin(), test.end()));
			ans = lab;
			network.correct(lab);

			sumLearn.next();

			cout << "#" << cicleCount << " fir: " << int(test[0]) << " sec: " << int(test[1]) <<
				" ans:" << int(ans) << " res:" << int(res)
				<< " corr:" << ((ans == res) ? "YES" : "NO ")  << endl;
		}
		else if (state == TEST)
		{
			if (sumTest.isEnd())
			{
				state == NON;
				continue;
			}

			sumTest.generate();
			std::vector<uint_8> test = sumTest.getTest();
			uint_16 lab = sumTest.getLabel();

			res = network.process(Args(test.begin(), test.end()));
			ans = lab;
			network.correct(lab);

			sumTest.next();

			//uint_8 firstNum, secondNum, answer;
			//std::cin >> firstNum >> secondNum >> answer;
			//std::vector<uint_8> test({ firstNum , secondNum });
			//uint_8 lab = answer;

			//res = network.process(Args(test.begin(), test.end()));
			//ans = lab;

			cout << "#" << cicleCount << " fir: " << int(test[0]) << " sec: " << int(test[1]) <<
				" ans:" << int(ans) << " res:" << int(res)
				<< " corr:" << ((ans == res) ? "YES" : "NO ") << " " << cor << "-" << err << endl;

			if (ans == res) ++cor;
			else ++err;
		}

		if (drawClaaNumber != -1)
		{
			gui.draw(network.getPresentation(1, drawClaaNumber));
		}

		if (state == LEARN)
		{
			/*cout << "#" << cicleCount << " ans:" << int(ans) << " res:" << int(res)
				<< " corr:" << ((ans == res) ? "YES" : "NO ") << "\n";*/
		}
		else if (state == TEST)
		{
			//if (ans == res) ++cor;
			//else ++err;
			//cout << "#" << cicleCount << " ans:" << int(ans) << " res:" << int(res)
			//	<< " corr" << ((ans == res) ? "YES" : "NO ") << " " << cor << "-" << err << "\n";
		}
		else
		{
			cicleCount--;
		}
	}

	return 0;
}

int mannn()
{

}