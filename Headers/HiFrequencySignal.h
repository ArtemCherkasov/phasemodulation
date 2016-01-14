/*
 * HiFrequencySignal.h
 *
 *  Created on: 14 янв. 2016 г.
 *      Author: artemcherkasov
 */

#ifndef HEADERS_HIFREQUENCYSIGNAL_H_
#define HEADERS_HIFREQUENCYSIGNAL_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <math.h>
#include "LowFrequencySignal.h"

#define POSITION_X 20
#define WIDTH 1600
#define HIGHT 100
#define POSITION_Y 520
#define DISCRET 5
#define NOICE 20

class HiFrequencySignal{
private:
	sf::RenderWindow *window;
	sf::Vertex line_x[2];
	sf::Vertex line_y[2];
	std::vector<int> points;
	LowFrequencySignal *f;

public:
	HiFrequencySignal(sf::RenderWindow *window, LowFrequencySignal *f);
	void drawDecartCoordinate();
	void generateSinus();
	void drawSignal();
};

#endif /* HEADERS_HIFREQUENCYSIGNAL_H_ */
