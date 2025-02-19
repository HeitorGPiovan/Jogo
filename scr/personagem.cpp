#include "../Includes/personagem.hpp"

Entidades::Personagens::Personagem::Personagem() : Entidade(),
                                                   num_vidas(5),
                                                   vivo(true),
                                                   tiro(NULL)
{
}

Entidades::Personagens::Personagem::~Personagem()
{
}


void Entidades::Personagens::Personagem::salvar()
{
}

// GESTÃO DE VIDA PARA JOGADORES E INIMIGOS

const bool Entidades::Personagens::Personagem::getVivo() const
{
    return vivo;
}

void Entidades::Personagens::Personagem::setVivo(const bool v)
{
    vivo = v;
}

void Entidades::Personagens::Personagem::operator--()
{
    if (getVivo())
    {
        num_vidas--;
        if (tipo == 0)
            cout << "Vida jogador: " << num_vidas << endl;
        /*
        switch (tipo)
        {
        case 0:
            cout << "Vida jogador: " << num_vidas << endl;
            break;
        case 1:
            cout << "Vida melee: " << num_vidas << endl;
            break;
        case 2:
            cout << "Vida atirador: " << num_vidas << endl;
            break;
        case 3:
            cout << "Vida tanque:" << num_vidas << endl;
            break;
        default:
            break;
        }
        */
    }
}

const int Entidades::Personagens::Personagem::getVida() const
{
    return num_vidas;
}

// MOVIMENTAÇÂO PADRÃO PARA JOGADORES E INIMIGOS

void Entidades::Personagens::Personagem::reverterMovimento()
{

    if (direcao == -1) // se estiver indo pra baixo
    {
        y--; // vai pra cima
    }

    if (direcao == 1) // se estiver indo pra cima
    {
        y++; // vai pra baixo
    }
    if (direcao == -2) // se estiver indo pra esquerda
    {
        x++; // vai pra direita
    }
    if (direcao == 2) // se estiver indo pra direita
    {
        x--; // vai pra esquerda
    }

    sprite.setPosition(x, y);
}

void Entidades::Personagens::Personagem::inverterDirecao()
{
    direcao = direcao * (-1);
}

void Entidades::Personagens::Personagem::mover()
{

    if (direcao == -1) // baixo
    {
        y++;
    }

    if (direcao == 1) // cima
    {
        y--;
    }

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
}

void Entidades::Personagens::Personagem::setVida(const int v)
{
    num_vidas = v;
}

void Entidades::Personagens::Personagem::disparar()
{
    if (tiro && tiro->getAtivo() == false)
    {
        if (clock.getElapsedTime().asSeconds() >= 1.0)
        {
            tiro->setY(getY());
            tiro->setDir(getDir());

            if (getDir() == 2)
            {
                tiro->setX(getX() + 55);
            }
            else if (getDir() == -2)
            {
                tiro->setX(getX() - 55);
            }

            tiro->setAtivo(true);
            tiro->setVel(0);
            clock.restart();
        }
    }
}

void Entidades::Personagens::Personagem::setTiro(Entidades::Projetil *t)
{
    tiro = t;
}

Entidades::Projetil *Entidades::Personagens::Personagem::getTiro() const
{
    return tiro;
}

void Entidades::Personagens::Personagem::salvarDataBuffer(nlohmann::json &j)
{
    Entidade::salvarDataBuffer(j);

    j["num_vidas"] = num_vidas;
    j["vivo"] = vivo;
}
