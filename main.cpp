#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <random>
#include <chrono>

int main() {

    sf::Texture dollar; // Dollar sign that shows up next to the amount of credits
    dollar.loadFromFile("../numbers/dollar.png");
    sf::Sprite dollarSpr(dollar);
    dollarSpr.setOrigin(70,70);
    dollarSpr.setPosition(115,125);
    dollarSpr.setScale(0.7, 0.7);

    sf::RectangleShape dollarBG; // Background for amount of credits
    dollarBG.setSize(sf::Vector2f(330, 120));
    dollarBG.setOrigin(dollarBG.getSize().x/2, dollarBG.getSize().y/2);
    dollarBG.setPosition(230, 125);
    dollarBG.setFillColor(sf::Color(255,200,0,255));

    sf::RectangleShape textBG; // Background for slot spinner text
    textBG.setSize(sf::Vector2f(805, 120));
    textBG.setOrigin(textBG.getSize().x/2, textBG.getSize().y/2);
    textBG.setPosition(810, 125);
    textBG.setFillColor(sf::Color(255,200,0,255));

    sf::Texture slotspinner; // numbers used to display shit
    slotspinner.loadFromFile("../images/slotspinner.png");
    sf::Sprite slotspinnerSpr(slotspinner);
    slotspinnerSpr.setOrigin(402.5,60);
    slotspinnerSpr.setPosition(810, 125);



    sf::Font font; // sets the usable font
    font.loadFromFile("../fonts/BOD_R.TTF");

    sf::Text money; // defines the money text variable
    money.setFont(font);
    money.setString("0");
    money.setCharacterSize(120);
    money.setFillColor(sf::Color(255,132,39,255));
    money.setPosition(150,40);

    sf::Texture nan; // empty sprite

    sf::Texture zero; // numbers used to display shit
    zero.loadFromFile("../numbers/0.png");
    sf::Sprite zeroSpr(zero);
    zeroSpr.setOrigin(70,130);

    sf::Texture one;
    one.loadFromFile("../numbers/1.png");
    sf::Sprite oneSpr(one);
    oneSpr.setOrigin(70,130);

    sf::Texture two;
    two.loadFromFile("../numbers/2.png");
    sf::Sprite twoSpr(two);
    twoSpr.setOrigin(70,130);

    sf::Texture three;
    three.loadFromFile("../numbers/3.png");
    sf::Sprite threeSpr(three);
    threeSpr.setOrigin(70,130);

    sf::Texture four;
    four.loadFromFile("../numbers/4.png");
    sf::Sprite fourSpr(four);
    fourSpr.setOrigin(70,130);

    sf::Texture five;
    five.loadFromFile("../numbers/5.png");
    sf::Sprite fiveSpr(five);
    fiveSpr.setOrigin(70,130);

    sf::Texture six;
    six.loadFromFile("../numbers/6.png");
    sf::Sprite sixSpr(six);
    sixSpr.setOrigin(70,130);

    sf::Texture seven;
    seven.loadFromFile("../numbers/7.png");
    sf::Sprite sevenSpr(seven);
    sevenSpr.setOrigin(70,130);

    sf::Texture eight;
    eight.loadFromFile("../numbers/8.png");
    sf::Sprite eightSpr(eight);
    eightSpr.setOrigin(70,130);

    sf::Texture nine;
    nine.loadFromFile("../numbers/9.png");
    sf::Sprite nineSpr(nine);
    nineSpr.setOrigin(70,130);

    int credits = 0;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Slot Spinner");
    window.setFramerateLimit(60);
    sf::RectangleShape canvas;
    canvas.setSize(sf::Vector2f(window.getSize().x-100, window.getSize().y-100));

    sf::Image icon; // program icon
    icon.loadFromFile("../images/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    canvas.setOrigin(canvas.getSize().x/2, canvas.getSize().y/2);
    canvas.setFillColor(sf::Color(117, 187, 167));
    canvas.setPosition(window.getSize().x/2, window.getSize().y/2);

    sf::RectangleShape numberBG; // background for the slots
    numberBG.setSize(sf::Vector2f(600.f,280.f));
    numberBG.setOrigin(numberBG.getSize().x/2, numberBG.getSize().y/2);
    numberBG.setPosition(window.getSize().x/2, window.getSize().y/2);
    numberBG.setFillColor(sf::Color(255,200,0,255));

    sf::RectangleShape slot1;
    slot1.setSize(sf::Vector2f(140.f, 260.f));
    slot1.setFillColor(sf::Color(255,132,39,255));
    slot1.setOrigin(slot1.getSize().x/2, slot1.getSize().y/2);
    slot1.setPosition(numberBG.getPosition().x-155, numberBG.getPosition().y);

    sf::RectangleShape slot2;
    slot2.setSize(sf::Vector2f(140.f, 260.f));
    slot2.setFillColor(sf::Color(255,132,39,255));
    slot2.setOrigin(slot2.getSize().x/2, slot2.getSize().y/2);
    slot2.setPosition(slot1.getPosition().x+150, slot1.getPosition().y);

    sf::RectangleShape slot3;
    slot3.setSize(sf::Vector2f(140.f, 260.f));
    slot3.setFillColor(sf::Color(255,132,39,255));
    slot3.setOrigin(slot3.getSize().x/2, slot3.getSize().y/2);
    slot3.setPosition(slot2.getPosition().x+150, slot2.getPosition().y);

    sf::RectangleShape button; // spin button
    button.setSize(sf::Vector2f(600, 100));
    button.setOrigin(button.getSize().x/2, button.getSize().y/2);
    button.setPosition(numberBG.getPosition().x, numberBG.getPosition().y+230);
    button.setFillColor(sf::Color(255,200,0,255));

    sf::CircleShape light1;
    light1.setRadius(50);
    light1.setFillColor(sf::Color(255,200,0));
    light1.setOrigin(50,50);
    light1.setPosition(window.getSize().x/2-450,window.getSize().y/2-75);
    sf::CircleShape light2;
    light2.setRadius(50);
    light2.setFillColor(sf::Color(255,200,0));
    light2.setOrigin(50,50);
    light2.setPosition(window.getSize().x/2-450,window.getSize().y/2+75);
    sf::CircleShape light3;
    light3.setRadius(50);
    light3.setFillColor(sf::Color(255,200,0));
    light3.setOrigin(50,50);
    light3.setPosition(window.getSize().x/2-450,window.getSize().y/2+225);

    sf::CircleShape light4;
    light4.setRadius(50);
    light4.setFillColor(sf::Color(255,200,0));
    light4.setOrigin(50,50);
    light4.setPosition(window.getSize().x/2+450,window.getSize().y/2-75);
    sf::CircleShape light5;
    light5.setRadius(50);
    light5.setFillColor(sf::Color(255,200,0));
    light5.setOrigin(50,50);
    light5.setPosition(window.getSize().x/2+450,window.getSize().y/2+75);
    sf::CircleShape light6;
    light6.setRadius(50);
    light6.setFillColor(sf::Color(255,200,0));
    light6.setOrigin(50,50);
    light6.setPosition(window.getSize().x/2+450,window.getSize().y/2+225);

    sf::Text spin; // defines the spin text variable
    spin.setFont(font);
    spin.setString("S P I N !");
    spin.setCharacterSize(100);
    spin.setFillColor(sf::Color(255,132,39,255));
    spin.setPosition(button.getPosition().x-175, button.getPosition().y-70);

    sf::Sprite number1;
    sf::Sprite number2;
    sf::Sprite number3;


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            };
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
            switch (event.type) {
                case sf::Event::MouseMoved: { // if the mouse is being moved
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                    if (button.getGlobalBounds().contains(mousePosF)) { // if the cursor is inside the box
                        button.setFillColor(sf::Color(255,235,0,255));
                    }
                    else {
                        button.setFillColor(sf::Color(255,200,0,255));

                    }
                }
                break;
                case sf::Event::MouseButtonPressed: { // if mouse button is pressed

                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                    if (button.getGlobalBounds().contains(mousePosF )) { // if the cursor is inside the box
                        button.setFillColor(sf::Color(77, 75, 71, 100));

                        std::vector<int> v = {0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9};
                        std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

                        std::shuffle(v.begin(), v.end(), rng);

                        int num1 = v[0];
                        std::cout << num1 << " ";
                        int num2 = v[1];
                        std::cout << num2 << " ";
                        int num3 = v[2];
                        std::cout << num3 << std::endl;

                        for (int i = 0; i < 50; ++i) {
                            window.clear(sf::Color(122, 231, 199, 255));
                            window.draw(canvas);
                            window.draw(numberBG);
                            window.draw(button);
                            window.draw(light1);
                            window.draw(light2);
                            window.draw(light3);
                            window.draw(light4);
                            window.draw(light5);
                            window.draw(light6);
                            window.draw(spin);
                            window.draw(slot1);
                            window.draw(slot2);
                            window.draw(slot3);
                            window.draw(dollarBG);
                            window.draw(dollarSpr);
                            window.draw(textBG);
                            window.draw(slotspinnerSpr);
                            window.draw(money);
                            std::vector<sf::Sprite> m = {zeroSpr,oneSpr,twoSpr,threeSpr,fourSpr,fiveSpr,sixSpr,sevenSpr,eightSpr,nineSpr};
                            std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
                            std::shuffle(m.begin(), m.end(), rng);
                            m[0].setPosition(slot1.getPosition().x, slot1.getPosition().y);
                            window.draw(m[0]);
                            m[1].setPosition(slot2.getPosition().x, slot2.getPosition().y);
                            window.draw(m[1]);
                            m[2].setPosition(slot3.getPosition().x, slot3.getPosition().y);
                            window.draw(m[2]);
                            window.display();



                        }

                        if (num1 == 0) {
                            zeroSpr.setPosition(slot1.getPosition().x, slot1.getPosition().y);
                            number1 = zeroSpr;
                        }
                        if (num1 == 1) {
                            oneSpr.setPosition(slot1.getPosition().x, slot1.getPosition().y);
                            number1 = oneSpr;
                        }
                        if (num1 == 2) {
                            twoSpr.setPosition(slot1.getPosition().x, slot1.getPosition().y);
                            number1 = twoSpr;
                        }
                        if (num1 == 3) {
                            threeSpr.setPosition(slot1.getPosition().x, slot1.getPosition().y);
                            number1 = threeSpr;
                        }
                        if (num1 == 4) {
                            fourSpr.setPosition(slot1.getPosition().x, slot1.getPosition().y);
                            number1 = fourSpr;
                        }
                        if (num1 == 5) {
                            fiveSpr.setPosition(slot1.getPosition().x, slot1.getPosition().y);
                            number1 = fiveSpr;
                        }
                        if (num1 == 6) {
                            sixSpr.setPosition(slot1.getPosition().x, slot1.getPosition().y);
                            number1 = sixSpr;
                        }
                        if (num1 == 7) {
                            sevenSpr.setPosition(slot1.getPosition().x, slot1.getPosition().y);
                            number1 = sevenSpr;
                        }
                        if (num1 == 8) {
                            eightSpr.setPosition(slot1.getPosition().x, slot1.getPosition().y);
                            number1 = eightSpr;
                        }
                        if (num1 == 9) {
                            nineSpr.setPosition(slot1.getPosition().x, slot1.getPosition().y);
                            number1 = nineSpr;
                        }

                        if (num2 == 0) {
                            zeroSpr.setPosition(slot2.getPosition().x, slot1.getPosition().y);
                            number2 = zeroSpr;
                        }
                        if (num2 == 1) {
                            oneSpr.setPosition(slot2.getPosition().x, slot1.getPosition().y);
                            number2 = oneSpr;
                        }
                        if (num2 == 2) {
                            twoSpr.setPosition(slot2.getPosition().x, slot1.getPosition().y);
                            number2 = twoSpr;
                        }
                        if (num2 == 3) {
                            threeSpr.setPosition(slot2.getPosition().x, slot1.getPosition().y);
                            number2 = threeSpr;
                        }
                        if (num2 == 4) {
                            fourSpr.setPosition(slot2.getPosition().x, slot1.getPosition().y);
                            number2 = fourSpr;
                        }
                        if (num2 == 5) {
                            fiveSpr.setPosition(slot2.getPosition().x, slot1.getPosition().y);
                            number2 = fiveSpr;
                        }
                        if (num2 == 6) {
                            sixSpr.setPosition(slot2.getPosition().x, slot1.getPosition().y);
                            number2 = sixSpr;
                        }
                        if (num2 == 7) {
                            sevenSpr.setPosition(slot2.getPosition().x, slot1.getPosition().y);
                            number2 = sevenSpr;
                        }
                        if (num2 == 8) {
                            eightSpr.setPosition(slot2.getPosition().x, slot1.getPosition().y);
                            number2 = eightSpr;
                        }
                        if (num2 == 9) {
                            nineSpr.setPosition(slot2.getPosition().x, slot1.getPosition().y);
                            number2 = nineSpr;
                        }

                        if (num3 == 0) {
                            zeroSpr.setPosition(slot3.getPosition().x, slot1.getPosition().y);
                            number3 = zeroSpr;
                        }
                        if (num3 == 1) {
                            oneSpr.setPosition(slot3.getPosition().x, slot1.getPosition().y);
                            number3 = oneSpr;
                        }
                        if (num3 == 2) {
                            twoSpr.setPosition(slot3.getPosition().x, slot1.getPosition().y);
                            number3 = twoSpr;
                        }
                        if (num3 == 3) {
                            threeSpr.setPosition(slot3.getPosition().x, slot1.getPosition().y);
                            number3 = threeSpr;
                        }
                        if (num3 == 4) {
                            fourSpr.setPosition(slot3.getPosition().x, slot1.getPosition().y);
                            number3 = fourSpr;
                        }
                        if (num3 == 5) {
                            fiveSpr.setPosition(slot3.getPosition().x, slot1.getPosition().y);
                            number3 = fiveSpr;
                        }
                        if (num3 == 6) {
                            sixSpr.setPosition(slot3.getPosition().x, slot1.getPosition().y);
                            number3 = sixSpr;
                        }
                        if (num3 == 7) {
                            sevenSpr.setPosition(slot3.getPosition().x, slot1.getPosition().y);
                            number3 = sevenSpr;
                        }
                        if (num3 == 8) {
                            eightSpr.setPosition(slot3.getPosition().x, slot1.getPosition().y);
                            number3 = eightSpr;
                        }
                        if (num3 == 9) {
                            nineSpr.setPosition(slot3.getPosition().x, slot1.getPosition().y);
                            number3 = nineSpr;
                        }
                        if (num1 == num2 or num1 == num3 or num2 == num3) {
                            credits += 100;

                        }
                        if (num1 == num2 and num2 == num3) {
                            credits += 2000;
                        }
                        money.setString(std::to_string(credits));
                        std::cout << credits << std::endl;


                    }
                    else {
                        spin.setFillColor(sf::Color(255,132,39,255));


                    }

                }



            }
        }

        window.clear(sf::Color(122, 231, 199, 255));
        window.draw(canvas);
        window.draw(numberBG);
        window.draw(button);
        window.draw(light1);
        window.draw(light2);
        window.draw(light3);
        window.draw(light4);
        window.draw(light5);
        window.draw(light6);
        window.draw(spin);
        window.draw(slot1);
        window.draw(slot2);
        window.draw(slot3);
        window.draw(number1);
        window.draw(number2);
        window.draw(number3);
        window.draw(dollarBG);
        window.draw(dollarSpr);
        window.draw(textBG);
        window.draw(slotspinnerSpr);
        window.draw(money);
        window.display();


    }


    return 0;
}


