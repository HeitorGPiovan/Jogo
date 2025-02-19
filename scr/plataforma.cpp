#include "plataforma.hpp"

Entidades::Obstaculos::Plataforma::Plataforma() : Obstaculo(),
                                                  tamanho(3)
{
    tipo = 4;
}

Entidades::Obstaculos::Plataforma::~Plataforma()
{
}

void Entidades::Obstaculos::Plataforma::executar()
{
    sprite.setPosition(x, y);
    atualizarGravidade();
    desenhar();
}

void Entidades::Obstaculos::Plataforma::obstacular(Entidades::Personagens::Jogador *p)
{
    if (p)
    {
        if (p->getVivo())
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
            float obsBase = hitboxObs.top + 80;

            if (jog1Base > obsTopo && jog1Topo < obsTopo && jog1Direita > obsEsquerda && jog1Esquerda < obsDireita)
            {
                p->setY(obsTopo - hitboxJog1.height);
                p->setVel(0);
                p->setEmSolo(true);
            }
            else if (jog1Topo < obsBase && jog1Base > obsBase)
            {
                p->setY(obsBase);
                p->setVel(0);
            }
            else if (p->getY() >= obsTopo && p->getY() <= obsTopo + 80)
            {
                if (jog1Base > obsTopo && jog1Topo < obsTopo + 80)
                {
                    if (jog1Direita > obsEsquerda && jog1Esquerda < obsEsquerda)
                    {
                        p->reverterMovimento();
                    }
                    else if (jog1Esquerda < obsDireita && jog1Direita > obsDireita)
                    {
                        p->reverterMovimento();
                    }
                }
            }
        }
    }
}

void Entidades::Obstaculos::Plataforma::salvar()
{
    nlohmann::json j;
    Obstaculo::salvarDataBuffer(j);
    j["tamanho"] = tamanho;
    Entidade::exportarParaArquivo("salvamento.json", j);
}

void Entidades::Obstaculos::Plataforma::setTamanho(int t)
{
    tamanho = t;

    if (pGrafico)
    {

        switch (tamanho)
        {
        case 1:
            pGrafico->definirTextura("PlataformaI", sprite);
            break;

        case 2:
            pGrafico->definirTextura("PlataformaP", sprite);
            break;

        case 3:
            pGrafico->definirTextura("PlataformaM", sprite);
            break;

        case 4:
            pGrafico->definirTextura("PlataformaG", sprite);
            // cout << "Alterando textura para tamanho " << tamanho << std::endl;

            break;

        default:
            break;
        }
    }
}