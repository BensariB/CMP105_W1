#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects
	rect[0].setSize(sf::Vector2f(50, 50));
	rect[0].setPosition(100, 100);
	rect[0].setFillColor(sf::Color::Red);

	rect[1].setSize(sf::Vector2f(35, 35));
	rect[1].setPosition(108, 108);
	rect[1].setFillColor(sf::Color::Green);

	rect[2].setSize(sf::Vector2f(20, 20));
	rect[2].setPosition(116, 116);
	rect[2].setFillColor(sf::Color::Blue);

	//circle:
	circle.setRadius(50);
	circle.setPosition(600, 337);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2.f);

	//text:
	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "Font error";
	}
	text.setFont(font);
	text.setString("Hello World");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold);
	text.setPosition(600, 0);

	//bottom left rectangle:
	myrect.setSize(sf::Vector2f(30, 60));
	myrect.setFillColor(sf::Color::Green);
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2u pos = window->getSize();
	int posx = pos.x - myrect.getSize().x;
	int posy = pos.y - myrect.getSize().y;
	myrect.setPosition(posx, posy);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(rect[0]);
	window->draw(rect[1]);
	window->draw(rect[2]);
	window->draw(circle);
	window->draw(text);
	window->draw(myrect);
	endDraw();
	
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}