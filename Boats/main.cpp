#include "Boat.h"
#include "Animation.h"
#include <SFML/Graphics.hpp>

void PollEvent(Animation& test);
void Render(Animation& test);

sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
Boat myboat;
sf::Sprite background;

int main()
{
	myboat.SetPosition(sf::Vector2f(500, 500));
	myboat.SetVelocity(sf::Vector2f(0, 0));
	myboat.SetTexture("ship_large_body.png");
	myboat.SetMoveDrag(0.05);
	myboat.SetTurnDrag(0.5);
	myboat.SetVelocity(sf::Vector2f(0.001, 0.001));

	sf::View myview;
	myview.reset(sf::FloatRect(0, 0, 1920 * 3, 1080 * 3));
	window.setView(myview);

	sf::Texture backgroundtext;
	backgroundtext.loadFromFile("water.png");
	backgroundtext.setRepeated(true);
	background.setTexture(backgroundtext);
	background.setTextureRect(sf::IntRect(0, 0, window.getSize().x * 3, window.getSize().y * 3));
	background.setPosition(0, 0);

	sf::Texture AnimationTexture;
	AnimationTexture.loadFromFile("PirateAnimation.png"); 

	Animation myAnimation(AnimationTexture, sf::Vector2f(80, 96));
	myAnimation.setPosition(sf::Vector2f(250, 250));

	myAnimation.SetAnimatonFPS(1);
	myAnimation.setPosition(sf::Vector2f(100, 100));

	while (window.isOpen())
	{
		PollEvent(myAnimation);
		Render(myAnimation);
	}
}

void PollEvent(Animation& test)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}

	myboat.Update(0.1);
	test.Update(0.01);
}

void Render(Animation& test)
{
	window.clear();
	
	window.draw(background);
	window.draw(myboat);
	//window.draw(test);

	window.display();
}