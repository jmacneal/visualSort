#ifndef constants
#define constants

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<random>


using namespace sf;

namespace constants{

int windowWidth = 1600;
int windowHeight = 900;
const int numBars = 50;

const std::vector<sf::Color> barColors {sf::Color::Red, sf::Color::Blue, sf::Color::Yellow,sf::Color::Magenta, sf::Color::Cyan, sf::Color::Green};


inline sf::Color randColor(){
	int r = random() % (barColors.size());
	sf::Color l = barColors[r];
	return l;
}

}

#endif
