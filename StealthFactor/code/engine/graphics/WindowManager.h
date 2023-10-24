#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>

class WindowManager {
public:
    WindowManager();
    ~WindowManager();

    sf::RenderWindow& getWindow() { return window; }
    void setView(sf::View viewP) { view = viewP; }
    const sf::View& getView() const { return view; }
    sf::Vector2f getEdges() {
        return sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT);
    }

    bool hasFocus();

private:
    sf::RenderWindow window;
    sf::View view;

    static const sf::Int16 WINDOW_WIDTH = 800;
    static const sf::Int16 WINDOW_HEIGHT = 600;
};