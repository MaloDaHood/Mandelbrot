#include <SFML/Graphics.hpp>

constexpr int SCREEN_WIDTH = 1920;
constexpr int SCREEN_HEIGHT = 1080;

sf::Color linear_interpolation(const sf::Color& v, const sf::Color& u, double a)
{
	double const b {1-a};
	return sf::Color(b*v.r + a * u.r, b*v.g + a * u.g, b*v.b + a * u.b);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Mandelbrot");
	sf::Image image; 
    image.create(SCREEN_WIDTH, SCREEN_HEIGHT);
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Font font; 
    font.loadFromFile("assets/poppins.ttf");
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);

	int max_iter {128};
	double zoom {1.0};
	double min_re {-2.5}, max_re {1};
	double min_im {-1}, max_im {1};

	while(window.isOpen())
	{
		sf::Event e;
		while(window.pollEvent(e))
		{
			if(e.type==sf::Event::Closed)
                window.close();
			if(e.type==sf::Event::KeyPressed)
			{
				double w {(max_re-min_re)*0.3};
				double h {(max_im-min_im)*0.3};

				if(e.key.code==sf::Keyboard::Left)
                {
                    min_re-=w;
                    max_re-=w;
                }
				if(e.key.code==sf::Keyboard::Right)
                {
                    min_re+=w;
                    max_re+=w;
                }
				if(e.key.code==sf::Keyboard::Up)
                {
                    min_im-=h;
                    max_im-=h;
                }
				if(e.key.code==sf::Keyboard::Down)
                {
                    min_im+=h;
                    max_im+=h;
                }

			}
			// Set Iteration level by mouse wheel
			// The more iteration level the better image result
			if(e.type==sf::Event::MouseWheelScrolled)
			{

                if(e.mouseWheelScroll.wheel==sf::Mouse::VerticalWheel)
                {
                    if(e.mouseWheelScroll.delta>0)
                        max_iter*=2;
                    else 
                        max_iter/=2;
                    if(max_iter<1)
                        max_iter = 1;
                }
			}
			if (e.type==sf::Event::MouseButtonPressed)
			{
				auto zoom_x = [&](double z)
				{
					// Mouse point will be new center point
					double cr {min_re+(max_re-min_re)*e.mouseButton.x/SCREEN_WIDTH};
					double ci {min_im+(max_im-min_im)*e.mouseButton.y/SCREEN_HEIGHT};

					// Zoom
					double tminr {cr-(max_re-min_re)/2/z};
					max_re=cr+(max_re-min_re)/2/z;
					min_re=tminr;

					double tmini {ci-(max_im-min_im)/2/z};
					max_im=ci+(max_im-min_im)/2/z;
					min_im=tmini;
				};
				// Left Click to ZoomIn
				if(e.mouseButton.button==sf::Mouse::Left)
				{
					zoom_x(5);
					zoom*=5;
				}
				// Right Click to ZoomOut
				if(e.mouseButton.button==sf::Mouse::Right)
				{
					zoom_x(1.0/5);
					zoom/=5;
				}
			}
		}
		window.clear();

		for(int y {0}; y<SCREEN_HEIGHT; y++) for(int x {0}; x<SCREEN_WIDTH; x++)
		{
			double cr {min_re+(max_re-min_re)*x/SCREEN_WIDTH};
			double ci {min_im+(max_im-min_im)*y/SCREEN_HEIGHT};
			double re {0}, im {0};
			int iter;
			for(iter=0; iter<max_iter; iter++)
			{
				double tr {re*re-im*im+cr};
				im=2*re*im+ci;
				re=tr;
				if(re*re+im*im>2*2)
                    break;
			}
			
			static const std::vector<sf::Color> colors{
				{0,0,0},
				{213,67,31},
				{251,255,121},
				{62,223,89},
				{43,30,218},
				{0,255,247}
			};

			static const unsigned long max_color {colors.size()-1};
			if(iter==max_iter)
                iter=0;
			double mu {1.0*iter/max_iter};
			mu*=max_color;
			size_t i_mu {static_cast<size_t>(mu)};
			sf::Color color1 {colors[i_mu]};
			sf::Color color2 {colors[std::min(i_mu+1, max_color)]};
			sf::Color c {linear_interpolation(color1, color2, mu-i_mu)};

			image.setPixel(x, y, sf::Color(c));
		}
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		window.draw(sprite);
		char str[100];
		sprintf(str, "iterations : %d\nzoom : x%2.2lf", max_iter, zoom);
		text.setString(str);
		window.draw(text);

		window.display();
	}
	return 0;
}