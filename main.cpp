#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<list>
#include<unistd.h>												   // for usleep(miliseconds);
#include<time.h>
#include<random>
#include <string>

#include "constants.h"
#include "rectangle.h"
#include "sort.h"

int main(){
	std::srand(time(NULL));									// Seed the random function
    sf::RenderWindow window(sf::VideoMode(windowWidth,windowHeight), "Graphical Sort Simulator");

	rectVec rects;
	
	for(int i=0; i<numBars; i++){
																   // For each bar in the graph,
		sf::Color col = randColor();							   // assign it a random color such
		if(i>0){												   // that no two adjacent bars match
			while(col == rects[i-1].getFillColor())
				col = randColor();
		}
		Rectangle r(col,(i+1)*windowWidth/numBars,windowHeight);   // Assign each bar a random height
		rects.push_back(r); 
	}

	bool sorting = true;
    while (window.isOpen() && sorting)
    {
		update(window,rects);
		sorts::bubbleSort(rects,window,sorting);
	}

	window.close();
    return 0;
}
