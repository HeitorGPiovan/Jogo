#include "aramefarpado.hpp"

using namespace Entidades::Obstaculos;

Arame_Farpado::Arame_Farpado() : Obstaculo(rand() % 2)
{
    tipo = 5;
    perfuracao = (rand() % 3) + 1;

    if (getDan() == true)
    {
        perfuracao = (rand() % 4) + 2;
    }
    else
    {
        perfuracao = (rand() % 3) + 1;
    }

    if (pGrafico)
    {
        pGrafico->definirTextura("Arame", sprite);
    }
    else
    {
        std::cout << "PONTEIRO NULO!";
    }
}

Arame_Farpado::~Arame_Farpado()
{
}

void Arame_Farpado::obstacular(Entidades::Personagens::Jogador *p)
{
    if (p)
    {
        sf::FloatRect hitboxJog1 = p->getHitbox();
        sf::FloatRect hitboxObs = getHitbox();
        float jog1Esquerda = hitboxJog1.left;
        float jog1Direita = hitboxJog1.left + hitboxJog1.width;
        float jog1Topo = hitboxJog1.top;
        float jog1Base = hitboxJog1.top + hitboxJog1.height;
        float obsEsquerda = hitboxObs.left;
        float obsDireita = hitboxObs.left + hitboxObs.width;
        float obsTopo = hitboxObs.top;
        float obsBase = hitboxObs.top + hitboxObs.height;

        if (jog1Base > obsTopo && jog1Topo < obsTopo && jog1Direita > obsEsquerda && jog1Esquerda < obsDireita)
        {
            p->setY(obsTopo - hitboxJog1.height);
            p->setVel(0);
            p->setEmSolo(true);
        }
        else if (jog1Direita > obsEsquerda && jog1Esquerda < obsEsquerda)
        {
            p->reverterMovimento();
        }
        else if (jog1Esquerda < obsDireita && jog1Direita > obsDireita)
        {
            p->reverterMovimento();
        }
        else if (jog1Topo < obsBase && jog1Base > obsBase)
        {
            p->setY(obsBase);
            p->setVel(0);
        }

        if (clock.getElapsedTime().asSeconds() >= 0.5)
        {
            if (getDan())
            {
                for (int i = 0; i < perfuracao; i++)
                {
                    p->operator--();
                }
            }
            clock.restart();
        }
    }
}

void Arame_Farpado::salvar()
{
    nlohmann::json j;
    Obstaculo::salvarDataBuffer(j);
    j["perfuracao"] = perfuracao;
    Entidade::exportarParaArquivo("salvamento.json", j);
}

void Arame_Farpado::executar()
{
    atualizarGravidade();
    sprite.setPosition(x, y);
    desenhar();
}

void Entidades::Obstaculos::Arame_Farpado::setPerfuracao(int p)
{
    perfuracao = p;
}
