/*
 * LowFrequencySignal.h
 *
 *  Created on: 14 янв. 2016 г.
 *      Author: artemcherkasov
 */

#ifndef HEADERS_LOWFREQUENCYSIGNAL_H_
#define HEADERS_LOWFREQUENCYSIGNAL_H_


#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#define POSITION_X 20
#define WIDTH 1600
#define HIGHT 100
#define POSITION_Y 120
#define DISCRET 5
#define NOICE 20

class LowFrequencySignal{

private:
	sf::RenderWindow *window;
	sf::Vertex line_x[2];
	sf::Vertex line_y[2];
	std::vector<int> points;

public:
	LowFrequencySignal(sf::RenderWindow *window);
	void drawDecartCoordinate();
	void drawSignal();
	void generatePoint();
	std::vector<int> getPoints();
};


#endif /* HEADERS_LOWFREQUENCYSIGNAL_H_ */
