#include <SFML/Graphics.hpp>
#include <iostream>

void selectionSort(int array[], int size, sf::RenderWindow& window);
int main()
{
    int array[25];
    for (int i = 0; i < 25; i++)
    {
        array[i] = rand() % 25 + 1;
    }
    sf::RenderWindow window(sf::VideoMode(800, 800), "Test");

    selectionSort(array, 25, window);

    return 0;
}

void selectionSort(int array[], int size, sf::RenderWindow& window) {
    sf::RectangleShape bars[25];
    for (int i = 0; i < size; ++i) {
        bars[i].setSize(sf::Vector2f(20, array[i] * 30));
        bars[i].setFillColor(sf::Color::Blue);
        bars[i].setPosition(i * 25, 800 - bars[i].getSize().y);
    }

    window.clear();

    for (int i = 0; i < size; ++i) {
        window.draw(bars[i]);
    }

    window.display();

    for (int i = 0; i < size - 1; i++)
    {
        int minloc = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[minloc] > array[j])
            {
                minloc = j;
            }
        }
        std::swap(array[i], array[minloc]);

        window.clear();
        for (int k = 0; k < size; ++k) {
            bars[k].setSize(sf::Vector2f(20, array[k] * 30));
            bars[k].setPosition(k * 25, 800 - bars[k].getSize().y);
            window.draw(bars[k]);
        }
        window.display();
        sf::sleep(sf::seconds(0.5));
    }
}
