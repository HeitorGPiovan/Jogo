#include "inimigo.hpp"

Entidades::Personagens::Inimigos::Inimigo::Inimigo(int dmg, bool loc) : Personagem(),
                                                              dano(dmg),
                                                              localizou(loc)
{
}

Entidades::Personagens::Inimigos::Inimigo::~Inimigo()
{
    dano = 0;
}

const int Entidades::Personagens::Inimigos::Inimigo::getDano() const
{
    return dano;
}

void Entidades::Personagens::Inimigos::Inimigo::localizar(Jogador *p)
{
    if (p)
    {
        setLoc(true);
        if (p->getX() >= getX())
        {
            setDir(2);
            sprite.setScale(1.f, 1.f);
        }
        else
        {
            setDir(-2);
            sprite.setScale(-1.f, 1.f);
        }
    }
}

void Entidades::Personagens::Inimigos::Inimigo::setLoc(const bool loc)
{
    localizou = loc;
}

const bool Entidades::Personagens::Inimigos::Inimigo::getLoc() const
{
    return localizou;
}

void Entidades::Personagens::Inimigos::Inimigo::salvarDataBuffer(nlohmann::json &j)
{
    Personagem::salvarDataBuffer(j);
    j["dano"] = dano;
    j["localizou"] = localizou;

}

void Entidades::Personagens::Inimigos::Inimigo::setDano(int dmg)
{
    dano = dmg;
}
