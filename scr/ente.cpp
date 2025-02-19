#include "ente.hpp"

Gerenciadores::Grafico *Ente::pGrafico = NULL;
int Ente::contador = 0;

Ente::Ente() : clock(),
               ID(contador)
{
    if (pGrafico == NULL)
    {
        pGrafico = Gerenciadores::Grafico::getGerenciadorGrafico();
    }
    contador++;
}

Ente::~Ente()
{
}

void Ente::desenhar()
{
    if (pGrafico)
        pGrafico->desenharEnte(this);
    else
        std::cout << "PONTEIRO NULO!";
}

const sf::Sprite Ente::getSprite() const
{
    return sprite;
}

const sf::FloatRect Ente::getHitbox() const
{
    return sprite.getGlobalBounds();
}


sf::Clock Ente::getClock()
{
    return clock;
}

void Ente::setID(int novoID)
{
    ID = novoID;
}

int Ente::getID()
{
    return ID;
}