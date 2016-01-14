/*
 * HiFrequencySignal.cpp
 *
 *  Created on: 14 янв. 2016 г.
 *      Author: artemcherkasov
 */

#include "../Headers/HiFrequencySignal.h"

HiFrequencySignal::HiFrequencySignal(sf::RenderWindow *window, LowFrequencySignal *f){
	this->window = window;
	this->line_x[0] = sf::Vertex(sf::Vector2f(POSITION_X - 10, POSITION_Y));
	this->line_x[1] = sf::Vertex(sf::Vector2f(POSITION_X + WIDTH, POSITION_Y));
	this->line_x[0].color = sf::Color::Red;
	this->line_x[1].color = sf::Color::Red;

	this->line_y[0] = sf::Vertex(sf::Vector2f(POSITION_X, POSITION_Y + HIGHT));
	this->line_y[1] = sf::Vertex(sf::Vector2f(POSITION_X, POSITION_Y - HIGHT));
	this->line_y[0].color = sf::Color::Red;
	this->line_y[1].color = sf::Color::Red;
	this->f = f;

	this->generateSinus();
}

void HiFrequencySignal::drawDecartCoordinate(){
	this->window->draw(this->line_x, 2, sf::Lines);
	this->window->draw(this->line_y, 2, sf::Lines);
}

void HiFrequencySignal::drawSignal(){
	int count = this->points.size();
	for(int i = 1; i < count; ++i){
		sf::Vertex line_point[2];
		line_point[0] = sf::Vertex(sf::Vector2f(POSITION_X + DISCRET*(i - 1), this->points[i - 1] + POSITION_Y));
		line_point[1] = sf::Vertex(sf::Vector2f(POSITION_X + DISCRET*i, this->points[i] + POSITION_Y));
		line_point[0].color = sf::Color::Blue;
		line_point[1].color = sf::Color::Blue;
		//std::cout << this->points[i - 1] << std::endl;
		this->window->draw(line_point, 2, sf::Lines);
	}
}

void HiFrequencySignal::generateSinus(){
	int count = WIDTH / DISCRET;
	this->points.push_back(0);
	for (int i = 1; i < count; ++i){
		std::cout << this->f->getPoints()[i] << std::endl;
		this->points.push_back(this->f->getPoints()[i]*sin(i));
	}
}
