#include "cmath"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;


float addition = 0;
float xPosition = 0;
float xSpeed = 1;
float direction = 1;

class Segment {
private:
  float deg2rad(float deg) { return deg * M_PI / 180; }

public:
  void drawCircleSegment(sf::RenderWindow &view, sf::Vector2f radiusPos, float radius = 100, float userAngle = 90) {
    view.clear();

    float segmentAngle = deg2rad(userAngle);

    int circlePoints = 500;
    float angle = 0;

    sf::ConvexShape arr;
    arr.setPointCount(circlePoints);
    arr.setPoint(0, radiusPos);

    for (int i = 0; i < circlePoints; i++) {
      sf::Vector2f p(cos(angle + (addition - segmentAngle / 2)) * radius,
                     sin(angle + (addition - segmentAngle / 2)) * radius);

      addition += 0.0001;

      p += radiusPos;
      arr.setPoint(i, p);

      angle += segmentAngle / circlePoints;
    }

    arr.setPoint(circlePoints - 1, radiusPos);

    view.draw(arr);

    view.display();
  }
};

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 800), "sfmltest");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    Segment segment;
    sf::Vector2f position = window.getView().getCenter();
    float radius = 100;
    xPosition += xSpeed * direction;
    position.x += xPosition;
    if (position.x + radius > 800) {
        direction = -1; 
    }
    if (position.x - radius < 0) {
        direction = 1;
    }
    segment.drawCircleSegment(window, position, radius);
  }
  return 0;
}
