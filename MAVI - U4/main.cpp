#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
	Texture textureCrosshair;
	Sprite crosshair;

	textureCrosshair.loadFromFile("assets/crosshair.png");
	crosshair.setTexture(textureCrosshair);
	crosshair.setOrigin(64, 64);
	crosshair.setPosition(400, 300);

	/////Creamos la ventana//////
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Que ventana horrible");

	/////Loop principal//////
	while (App.isOpen())
	{
		Event evt;
		while (App.pollEvent(evt)) {
			/////Procesar eventos//////
			switch (evt.type)
			{
				/////Si se cerro la ventana//////
			case sf::Event::Closed:
				App.close();
				break;
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape) == true)
				App.close();
		}

		App.clear();

		App.draw(crosshair);

		App.display();
	}
	return 0;
}

