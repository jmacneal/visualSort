#ifndef sorts
#define sorts

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<unistd.h>												   // for usleep(miliseconds);
#include<unistd.h>

using namespace sf;

namespace sorts{

typedef std::vector<Rectangle> rectVec;


void drawRects(const rectVec &rects, sf::RenderWindow &window){
	window.clear(sf::Color::Black);
	for(unsigned int i=0; i<rects.size(); i++)
		window.draw(rects[i]);
	
	window.display();
}

void swapRect(rectVec &rects, int a, int b){
	Rectangle temp = rects[a];
	rects[a] = rects[b];
	rects[b] = temp;

	float temppos = rects[a].getPos();
	rects[a].setPos(rects[b].getPos());
	rects[b].setPos(temppos);
}


void update(sf::RenderWindow &window, rectVec &rects){
	sf::Event event;
	while (window.pollEvent(event))							   // Polls the window to see if
	{														   // closed.
		if(event.type == sf::Event::Closed)
			window.close();
		if(event.type == sf::Event::Resized){
			float tempX = (float)windowWidth;
			float tempY = (float)windowHeight;
			constants::windowWidth = window.getSize().x;
			constants::windowHeight = window.getSize().y;
			for(unsigned int i=0;i<numBars;i++)
				rects[i].setScale(windowWidth/tempX,windowHeight/tempY);
		}
	}

	// Pause/unpause if space pressed
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
		usleep(100000);
		while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
			usleep(10000);

		usleep(100000);
	}
	// Check if escape pressed (exits)
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		window.close();

}

	bool bubbleSort(rectVec &rects, sf::RenderWindow &window, bool &sorting){				   
	sf::SoundBuffer soundBuffer;											   
	if(!soundBuffer.loadFromFile("c-tone.wav"))
		return false;														   

	sf::Sound sound;														   
	sound.setBuffer(soundBuffer);											   
																			   
	while(sorting){															   
		sorting = false;			   		 
		for(unsigned int i=0; i<rects.size()-1; i++){								   
			if(rects[i] > rects[i+1]){
				update(window,rects);
				swapRect(rects,i,i+1);										   
				drawRects(rects,window);									   
				sound.setPitch(rects[i].getSize().y / windowHeight * 2);	   
				sound.play();												   
				sorting = true;												   
			}																   
		}																	   
	}																		   
																			   
	return sorting;															   
}

}

#endif
