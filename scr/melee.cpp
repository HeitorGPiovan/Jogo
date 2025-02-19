#include "melee.hpp"

Entidades::Personagens::Inimigos::Melee::Melee() : Inimigo(1)
{
    resistencia = (rand() % 3) + 1;
    tipo = 1;
    setVida(getVida() * resistencia);

    if (pGrafico)
    {
        pGrafico->definirTextura("Melee", sprite);
    }
    else
    {
        std::cout << "PONTEIRO NULO!";
    }
}

Entidades::Personagens::Inimigos::Melee::~Melee()
{
}

void Entidades::Personagens::Inimigos::Melee::movimentar()
{

    if (clock.getElapsedTime().asSeconds() >= 0.005)
    {
        if (getLoc())
        {
            mover();
        }

        clock.restart();
    }
}

void Entidades::Personagens::Inimigos::Melee::danificar(Jogador *p)
{
    static sf::Clock globalClock;
    static std::map<Jogador *, sf::Time> ultimoDano;

    if (p)
    {
        sf::Time agora = globalClock.getElapsedTime();
        sf::Time tempoUltimoDano = ultimoDano[p];
        sf::Time intervaloDano = sf::seconds(0.5);

        if (agora - tempoUltimoDano >= intervaloDano)
        {
            p->operator--();
            ultimoDano[p] = agora;
        }
    }
}

void Entidades::Personagens::Inimigos::Melee::executar()
{
    if (getVida() <= 0)
    {
        setVivo(false);
    }

    if (getVivo())
    {
        movimentar();
        atualizarGravidade();
        desenhar();
        sprite.setPosition(x, y);
    }
}

void Entidades::Personagens::Inimigos::Melee::salvar()
{
    nlohmann::json j;
    Inimigo::salvarDataBuffer(j);
    j["resistencia"] = resistencia;
    Entidade::exportarParaArquivo("salvamento.json", j);
}

void Entidades::Personagens::Inimigos::Melee::setResistencia(int r)
{
    resistencia = r;
}
