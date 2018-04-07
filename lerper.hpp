#pragma once

#include <SFML/Graphics.hpp>
#include "GLOBALS.hpp"

struct LerpState {
	sf::Vector3f lerpPosition;
	float timeScale;
};

class Lerper{
public:
	Lerper(sf::Color color, sf::Vector2f pos, sf::Vector2f size);
	void lerpPos();
	void lerpSize();
	void lerpColor();
	void setTimeScale(lerpType t, float timeScale);
	void update(float newDeltaTime);
	void draw(sf::RenderWindow& w);
	float lerp(float v0, float v1, float t);

private:

	float deltaTime;
	sf::Color targetColor;
	sf::Color startColor;
	sf::Vector2f targetPos;
	sf::Vector2f targetSize;
	sf::Vector2f startPos;
	sf::Vector2f startSize;
	sf::RectangleShape self;

	LerpState posState;
	LerpState sizeState;
	LerpState colorState;


};
