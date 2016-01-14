/*
 * LowFrequencySignal.cpp
 *
 *  Created on: 14 янв. 2016 г.
 *      Author: artemcherkasov
 */

#include "../Headers/LowFrequencySignal.h"

LowFrequencySignal::LowFrequencySignal(sf::RenderWindow *window){
	this->window = window;
	this->line_x[0] = sf::Vertex(sf::Vector2f(POSITION_X - 10, POSITION_Y));
	this->line_x[1] = sf::Vertex(sf::Vector2f(POSITION_X + WIDTH, POSITION_Y));
	this->line_x[0].color = sf::Color::Red;
	this->line_x[1].color = sf::Color::Red;

	this->line_y[0] = sf::Vertex(sf::Vector2f(POSITION_X, POSITION_Y + HIGHT));
	this->line_y[1] = sf::Vertex(sf::Vector2f(POSITION_X, POSITION_Y - HIGHT));
	this->line_y[0].color = sf::Color::Red;
	this->line_y[1].color = sf::Color::Red;
	this->generatePoint();
}

void LowFrequencySignal::drawDecartCoordinate(){
	this->window->draw(this->line_x, 2, sf::Lines);
	this->window->draw(this->line_y, 2, sf::Lines);
}

void LowFrequencySignal::drawSignal(){
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

void LowFrequencySignal::generatePoint(){
	int count = WIDTH / DISCRET;
	int range_top = -HIGHT;
	int range_bottom = HIGHT;
	int last_position = 0;
	this->points.push_back(0);

	for (int i = 1; i < count; ++i){
		int current_position;
		double d = 0.01*(rand()%100);
		std::cout << d << last_position << std::endl;

		if (d > 0.5) {
			if (current_position < range_top){
				current_position = last_position + rand()%NOICE;
			} else {
				current_position = last_position - rand()%NOICE;
			}
		} else {
			if (current_position > range_bottom){
				current_position = last_position - rand()%NOICE;
			} else {
				current_position = last_position + rand()%NOICE;
			}
		}
		this->points.push_back(current_position);
		last_position = current_position;
	}
}

std::vector<int> LowFrequencySignal::getPoints(){
	return this->points;
}
