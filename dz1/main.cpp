#include <SFML/Graphics.hpp>
#include<iostream>
#include <math.h>

class Segment {
private:
  float deg2rad(float deg) { return deg * M_PI / 180; }

public:
  void drawCircleSegment(sf::RenderWindow &view) {
    sf::VertexArray arr(sf::LinesStrip);

    float segmentAngle = deg2rad(180);
    float radius = 200;
    sf::Vector2f radiusPos = view.getView().getCenter();

    int circlePoints = 1000;
    float angle = 0;

    arr.append(radiusPos);

    while (angle <= segmentAngle) {
      sf::Vector2f p(cos(angle + (segmentAngle / 2)) * radius,
                     sin(angle + (segmentAngle / 2)) * radius);

      p += radiusPos;
      arr.append(p);

      angle += segmentAngle / circlePoints;
    }

    arr.append(radiusPos);

    view.draw(arr);

    view.display();
  }
};

int main() {
  sf::RenderWindow gameWindow(sf::VideoMode(800, 800), "circle");
  gameWindow.setFramerateLimit(60);

  Segment segment;

  while (gameWindow.isOpen()) {
    sf::Event event;
    while (gameWindow.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        gameWindow.close();
      }
    }

    segment.fuckMyBrain();
    // segment.drawCircleSegment(gameWindow);
  }
}
