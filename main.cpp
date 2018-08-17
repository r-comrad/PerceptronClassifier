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

enum programmState {NON, PAUSE, LEARN, TEST};

void MNISTLearn()
{

}

int main()
{
	bool flag = true;
	GUI gui;

	PerceptronLayer layer(28*28, 10);
	MNISTReader mnistLearn(PROJECT_RESOURSES_PATH "MNIST/train_images",
		PROJECT_RESOURSES_PATH "MNIST/train_labels");
	MNISTReader mnistTest(PROJECT_RESOURSES_PATH "MNIST/train_images",
		PROJECT_RESOURSES_PATH "MNIST/train_labels");

	NeuralNetwork network
	(
		{ NeuralNetwork::LayerType::NORMALIZE,
		NeuralNetwork::LayerType::PERCEPTRON,
		NeuralNetwork::LayerType::OUTPUT
		},
		{ std::make_pair(784, 10) }
	);

	MNISTReader mnist(PROJECT_RESOURSES_PATH "MNIST/train_images",
		PROJECT_RESOURSES_PATH "MNIST/train_labels");

	programmState state = NON;
	for(uint_32 cicleCount = 0;; ++cicleCount)
	{
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

		if (state == PAUSE) continue;
		else if (state == LEARN)
		{
			mnistLearn.read();
			std::vector<uint_8> test = mnistLearn.getTest();
			uint_8 lab = mnistLearn.getLabel();
			//network.process(test);
		}
		//flag = false;

		mnist.read();
		std::vector<uint_8> test = mnist.getTest();
		uint_8 lab = mnist.getLabel();


		std::vector<double> inp;
		for (auto& i : test) inp.emplace_back(i /255);

		std::vector<double> out(10);
		out[lab] = 1;
			
		std::vector<double> res = layer.process(inp);
		layer.correct(out);

		double s = 0;
		int mx = 0;
		for (int i = 0; i < 10; ++i)
		{
			s += (out[i] - res[i])*(out[i] - res[i]);
			if (res[mx] < res[i]) mx = i;
		}

		cout << "#" << cicleCount << " in:" << char(lab + '0') << " out:" << char(mx + '0') 
			<< " corr" << ((mx == lab) ? "YES" : "NO ") << " error:" << s << "\n";

		//gui.draw(mnist.getMatrix(28, 28));
		//cout << char(mnist.getLabel() + '0') << "\n";

		mnist.pop();
	}

	return 0;
}