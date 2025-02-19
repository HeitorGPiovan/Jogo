#include "atirador.hpp"
#include <stdlib.h>
#include <time.h>

Entidades::Personagens::Inimigos::Atirador::Atirador() : Inimigo()
{
    tipo = 2;
    setTiro(new Projetil(getDir(), getX(), getY(), true, 1));

    coice = (rand() % 81) + 50;

    if (pGrafico)
    {
        pGrafico->definirTextura("Atirador", sprite);
    }
    else
    {
        std::cout << "PONTEIRO NULO!";
    }
}

Entidades::Personagens::Inimigos::Atirador::~Atirador()
{
    delete tiro;
}

void Entidades::Personagens::Inimigos::Atirador::danificar(Jogador *p)
{
    if (p)
    {
        p->operator--();

        // EMPURRA
        if (getDir() > 0)
        {
            p->setX(p->getX() + coice);
        }
        else
        {
            p->setX(p->getX() - coice);
        }
    }
}

void Entidades::Personagens::Inimigos::Atirador::executar()
{
    if (getVida() <= 0)
    {
        setVivo(false);
    }
    if (getVivo())
    {
        atualizarGravidade();
        desenhar();
        if (localizou)
        {
            disparar();
        }
        sprite.setPosition(x, y);
    }
}

void Entidades::Personagens::Inimigos::Atirador::salvar()
{
    nlohmann::json j;
    Inimigo::salvarDataBuffer(j);
    j["coice"] = coice;
    Entidade::exportarParaArquivo("salvamento.json", j);
}

void Entidades::Personagens::Inimigos::Atirador::setCoice(int c)
{
    coice = c;
}
