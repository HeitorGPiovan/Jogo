#include "projetil.hpp"
#include "personagem.hpp"

Entidades::Projetil::Projetil(int dir, int x, int y, bool di, int dmg) : Entidade(dir, x, y),
                                                                         ativo(false),
                                                                         dano(dmg),
                                                                         deInimigo(di)
{
    if (pGrafico)
    {
        pGrafico->definirTextura("Projetil", sprite);
    }
    else
    {
        std::cout << "PONTEIRO NULO!";
    }

    tipo = 7;
}

Entidades::Projetil::Projetil() : ativo(false)
{
    if (pGrafico)
    {
        pGrafico->definirTextura("Projetil", sprite);
    }
    else
    {
        std::cout << "PONTEIRO NULO!";
    }

    setDeInimigo(false);
    setDir(2);
    setX(0);
    setY(0);
    dano = 1;
    tipo = 7;
}

Entidades::Projetil::~Projetil()
{
    ativo = false;
}

void Entidades::Projetil::executar()
{
    if (getAtivo())
    {
        transitar();
        desenhar();
        atualizarGravidade();
    }
}

void Entidades::Projetil::transitar()
{
    if (clock.getElapsedTime().asSeconds() >= 0.0005)
    {

        if (direcao == 2) // direita
        {
            x++;
            sprite.setScale(1.f, 1.f);
        }
        if (direcao == -2) // esquerda
        {
            x--;
            sprite.setScale(-1.f, 1.f);
        }

        sprite.setPosition(x, y);
        clock.restart();
    }
}

void Entidades::Projetil::acertar(Entidades::Personagens::Personagem *p)
{
    if (dano == 1)
    {
        p->operator--();
    }
    else
    {
        p->setVida(p->getVida() - dano);
    }

    setAtivo(false);
}

const bool Entidades::Projetil::getAtivo() const
{
    return ativo;
}

void Entidades::Projetil::setAtivo(const bool atv)
{
    ativo = atv;
}

void Entidades::Projetil::salvar()
{
    nlohmann::json j;
    Entidade::salvarDataBuffer(j);
    j["ativo"] = ativo;
    j["dano"] = dano;
    j["deInimigo"] = deInimigo;
    Entidade::exportarParaArquivo("salvamento.json", j);
}

void Entidades::Projetil::setDano(int dmg)
{
    dano = dmg;
}

void Entidades::Projetil::setDeInimigo(bool di)
{
    deInimigo = di;
}

const bool Entidades::Projetil::getDeInimigo() const
{
    return deInimigo;
}

void Entidades::Projetil::atualizarGravidade()
{
    velocidadeVertical += gravidade;
    y += (velocidadeVertical/1.3);
}
