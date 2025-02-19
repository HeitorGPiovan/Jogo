#include "obstaculo.hpp"

Entidades::Obstaculos::Obstaculo::Obstaculo(bool d): Entidade(),
                                                     danoso(d)
{

}

Entidades::Obstaculos::Obstaculo::Obstaculo() : Entidade(),
                                                danoso(false)
{
}

Entidades::Obstaculos::Obstaculo::~Obstaculo()
{
}

void Entidades::Obstaculos::Obstaculo::salvarDataBuffer(nlohmann::json &j)
{
    Entidade::salvarDataBuffer(j);
    j["danoso"] = danoso;
}


const bool Entidades::Obstaculos::Obstaculo::getDan() const
{
    return danoso;
}

void Entidades::Obstaculos::Obstaculo::setDan(const bool d)
{
    danoso = d;
}