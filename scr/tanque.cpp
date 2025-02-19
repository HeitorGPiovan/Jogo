#include "../Includes/tanque.hpp"

Entidades::Personagens::Inimigos::Tanque::Tanque() : Inimigo()
{
    setVida(15);
    tipo = 3;
    potencia = (rand() % 11) + 5;

    setTiro(new Projetil(getDir(), getX(), getY(), true, (potencia/2)));

    if (pGrafico)
    {
        pGrafico->definirTextura("Tanque", sprite);
    }
    else
    {
        std::cout << "PONTEIRO NULO!";
    }
}

Entidades::Personagens::Inimigos::Tanque::~Tanque()
{
    delete tiro;
}

void Entidades::Personagens::Inimigos::Tanque::danificar(Jogador *p)
{
    if (p)
    {
        p->setVivo(false);
    }
}

void Entidades::Personagens::Inimigos::Tanque::executar()
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

void Entidades::Personagens::Inimigos::Tanque::disparar()
{
    if (tiro && tiro->getAtivo() == false)
    {
        if (clock.getElapsedTime().asSeconds() >= 1.0)
        {
            tiro->setY(getY());
            tiro->setDir(getDir());

            if (getDir() == 2)
            {
                tiro->setX(getX() + 100);
            }
            else if (getDir() == -2)
            {
                tiro->setX(getX() - 100);
            }

            tiro->setAtivo(true);
            tiro->setVel(0);
            for (int i = 0; i < potencia; i++)
            {
                mover();
            }
            clock.restart();
        }
    }
}

void Entidades::Personagens::Inimigos::Tanque::salvar()
{
    nlohmann::json j;
    Inimigo::salvarDataBuffer(j);
    j["potencia"] = potencia;
    Entidade::exportarParaArquivo("salvamento.json", j);
}

void Entidades::Personagens::Inimigos::Tanque::setPotencia(int pot)
{
    potencia = pot;
}