#pragma once
#include "grafico.hpp"
#include <iostream>
using namespace std;

class Ente
{
protected:
    static Gerenciadores::Grafico *pGrafico;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    int ID;
    static int contador;

public:
    Ente();
    virtual ~Ente();
    virtual void executar() = 0;
    void desenhar();
    const sf::Sprite getSprite() const;
    const sf::FloatRect getHitbox() const;
    sf::Clock getClock();
    void setID(int novoID);
    int getID();
};
