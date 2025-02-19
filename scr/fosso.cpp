#include "fosso.hpp"

Entidades::Obstaculos::Fosso::Fosso() : Obstaculo(rand() % 2)
{
    grande = rand() % 2;
    tipo = 6;
    if (pGrafico)
    {
        if (grande)
        {
            pGrafico->definirTextura("Fosso Grande", sprite);
        }
        else
        {
            pGrafico->definirTextura("Fosso", sprite);
        }
    }
    else
    {
        std::cout << "PONTEIRO NULO!";
    }
}

Entidades::Obstaculos::Fosso::~Fosso()
{
}

void Entidades::Obstaculos::Fosso::obstacular(Entidades::Personagens::Jogador *p)
{
    if (p)
    {
        if (p->getEhJog2() == false)
        {
            p->setX(120);
            p->setY(580);
        }
        else
        {
            p->setX(240);
            p->setY(580);
        }

        if(getDan())
        {
            p->operator--();
        }
    }
}

void Entidades::Obstaculos::Fosso::executar()
{
    atualizarGravidade();
    desenhar();
    sprite.setPosition(x, y);
}

void Entidades::Obstaculos::Fosso::salvar()
{
    nlohmann::json j;
    Obstaculo::salvarDataBuffer(j);
    j["grande"] = grande;
    Entidade::exportarParaArquivo("salvamento.json", j);
}

void Entidades::Obstaculos::Fosso::setGrande(bool g)
{
    grande = g;
}
