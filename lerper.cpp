#include "lerper.hpp"
#include "GLOBALS.hpp"

Lerper::Lerper(sf::Color color, sf::Vector2f pos, sf::Vector2f size){
	self.setFillColor(color);
	self.setPosition(pos);
	self.setSize(size);


	startPos = pos;
	startSize = size;
	startColor = color;

	posState.timeScale 			= 5;
	sizeState.timeScale 		= 3;
	colorState.timeScale 		= 5;

	posState.lerpPosition.x 	= 0;
	posState.lerpPosition.y 	= 0;
	sizeState.lerpPosition.x 	= 0;
	sizeState.lerpPosition.y 	= 0;
	colorState.lerpPosition.x 	= 0;
	colorState.lerpPosition.y 	= 0;
	colorState.lerpPosition.z 	= 0;

	// for testing
	targetPos = sf::Vector2f(WINDOW_X-size.x, WINDOW_Y-size.y);
	targetSize = sf::Vector2f(size.x * 2, size.y * 2);
	targetColor = sf::Color::White;
}



void Lerper::lerpPos(){
	float newX = lerp(startPos.x, targetPos.x, posState.lerpPosition.x + deltaTime/posState.timeScale);
	float newY = lerp(startPos.y, targetPos.y, posState.lerpPosition.y + deltaTime/posState.timeScale);

	if(newX > 0 && newY > 0){
		sf::Vector2f newPos = sf::Vector2f(newX, newY);
		self.setPosition(newPos);
		posState.lerpPosition.x += deltaTime/posState.timeScale;
		posState.lerpPosition.y += deltaTime/posState.timeScale;
	}
}

void Lerper::lerpSize(){
	float newX = lerp(startSize.x, targetSize.x, sizeState.lerpPosition.x + deltaTime/sizeState.timeScale);
	float newY = lerp(startSize.y, targetSize.y, sizeState.lerpPosition.y + deltaTime/sizeState.timeScale);

	if(newX > 0 && newY > 0){
		sf::Vector2f newSize = sf::Vector2f(newX, newY);
		self.setSize(newSize);
		sizeState.lerpPosition.x += deltaTime/sizeState.timeScale;
		sizeState.lerpPosition.y += deltaTime/sizeState.timeScale;
	}
}

void Lerper::lerpColor(){
	float newR = lerp(startColor.r, targetColor.r, colorState.lerpPosition.x + deltaTime/colorState.timeScale);
	float newG = lerp(startColor.g, targetColor.g, colorState.lerpPosition.y + deltaTime/colorState.timeScale);
	float newB = lerp(startColor.b, targetColor.b, colorState.lerpPosition.z + deltaTime/colorState.timeScale);

	if(newR >= 0 && newG >= 0 && newB >= 0 &&
		newR <= 255 && newG <= 255 && newB <= 255){
		sf::Color newColor = sf::Color(newR, newG, newB);
		self.setFillColor(newColor);
		colorState.lerpPosition.x += deltaTime/colorState.timeScale;
		colorState.lerpPosition.y += deltaTime/colorState.timeScale;
		colorState.lerpPosition.z += deltaTime/colorState.timeScale;
	}
}

void Lerper::setTimeScale(lerpType t, float timeScale){


}

void Lerper::update(float newDeltaTime){
	deltaTime = newDeltaTime;
	lerpPos();
	lerpSize();
	lerpColor();
}

void Lerper::draw(sf::RenderWindow& w){
	w.draw(self);
}

/*
	Precise method, which guarantees v = v1 when t = 1.
	source: https://en.wikipedia.org/wiki/Linear_interpolation#Programming_language_support
*/
float Lerper::lerp(float v0, float v1, float t) {
	if(t <= 1 && t >= 0){
  		return (1 - t) * v0 + t * v1;
  	}
	return -1;
}
