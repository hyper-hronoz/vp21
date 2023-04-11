#include "cmath"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

float deg2rad(float deg) { return deg * M_PI / 180; }

void drawCircleSegment(sf::RenderWindow &view) {
  sf::ConvexShape arr;


  float segmentAngle = deg2rad(180);
  float radius = 200;
  sf::Vector2f radiusPos = view.getView().getCenter();

  int circlePoints = 1000;
  arr.setPointCount(circlePoints);
  float angle = 0;

  arr.setPoint(0, radiusPos);

  for (int i = 0; i < circlePoints; i++) {
    sf::Vector2f p(cos(angle + (segmentAngle / 2)) * radius,
                   sin(angle + (segmentAngle / 2)) * radius);

    p += radiusPos;
    arr.setPoint(i, p);

    angle += segmentAngle / circlePoints;
  }

  // arr.setPoint(circlePoints - 1, radiusPos);

  view.draw(arr);

  view.display();
}

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
    drawCircleSegment(window);
    // window.clear();
    // window.draw(shape);
    // window.display();
  }
  return 0;
}
