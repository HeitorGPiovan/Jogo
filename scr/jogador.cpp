#include "../Includes/jogador.hpp"
#include "../Includes/colisoes.hpp"

vector<Entidades::Personagens::Jogador *> Entidades::Personagens::Jogador::pJogs;

Entidades::Personagens::Jogador::Jogador(const std::string &nome, int pontos) : Personagem(),
                                                                                pontos(pontos),
                                                                                pts1(0),
                                                                                pts2(0),
                                                                                nome(nome)
{
    setVida(-1);
    setTiro(NULL);
    tipo = 0;
}

Entidades::Personagens::Jogador::Jogador() : Personagem(),
                                             pontos(0),
                                             nome("")

{
    tipo = 0;
    setVida(40);
    setTiro(new Projetil(getDir(), getX(), getY(), false, 1));

    if (pJogs.empty())
    {
        ehJog2 = false;
    }
    else
    {
        ehJog2 = true;
    }

    Entidades::Personagens::Jogador::addJog(this);

    if (ehJog2 == false)
    {

        if (pGrafico)
        {
            pGrafico->definirTextura("Jog1", sprite);
        }
        else
        {
            std::cout << "PONTEIRO NULO!";
        }
    }

    else
    {
        if (pGrafico)
        {
            pGrafico->definirTextura("Jog2", sprite);
        }
        else
        {
            std::cout << "PONTEIRO NULO!";
        }
    }
}

Entidades::Personagens::Jogador::~Jogador()
{
    delete tiro;
}

void Entidades::Personagens::Jogador::executar()
{
    if (num_vidas <= 0)
    {
        setVivo(false);
    }
    if (getVivo())
    {
        movimentar();
        atualizarGravidade();
        desenhar();
    }
}

void Entidades::Personagens::Jogador::movimentar()
{

    if (clock.getElapsedTime().asSeconds() >= 0.005)
    {
        mover();
        clock.restart();
    }
}

const int Entidades::Personagens::Jogador::getPontos() const
{
    return pontos;
}

void Entidades::Personagens::Jogador::setPontos(const int p)
{
    pontos = p;
}

const bool Entidades::Personagens::Jogador::getEhJog2() const
{
    return ehJog2;
}

void Entidades::Personagens::Jogador::addJog(Jogador *pj)
{
    if (pj)
    {
        pJogs.push_back(pj);
    }
}

void Entidades::Personagens::Jogador::pular()
{
    if (getEmSolo())
    {
        setVel(-0.95f);
        setEmSolo(false);
    }
}

const bool Entidades::Personagens::Jogador::getEmSolo() const
{
    return emSolo;
}

void Entidades::Personagens::Jogador::setEmSolo(const bool es)
{
    emSolo = es;
}

void Entidades::Personagens::Jogador::disparar()
{
    if (tiro && tiro->getAtivo() == false)
    {
        sf::Vector2f escala = sprite.getScale();

        tiro->setY(getY());

        if (escala.x > 0)
        {
            tiro->setDir(2);
            tiro->setX(getX() + 55);
        }
        else if (escala.x < 0)
        {
            tiro->setDir(-2);
            tiro->setX(getX() - 55);
        }

        tiro->setAtivo(true);
        tiro->setVel(0);
        clock.restart();
    }
}

void Entidades::Personagens::Jogador::salvar()
{
    nlohmann::json j;
    Personagem::salvarDataBuffer(j);
    j["pontos"] = pontos;
    j["nome"] = nome;
    j["ehJog2"] = ehJog2;
    j["emSolo"] = emSolo;
    Entidade::exportarParaArquivo("salvamento.json", j);
}

const string Entidades::Personagens::Jogador::getNome() const
{
    return nome;
}

void Entidades::Personagens::Jogador::setNome(string n)
{
    nome = n;
}

void Entidades::Personagens::Jogador::setEhJog2(bool dois)
{
    ehJog2 = dois;
}

void Entidades::Personagens::Jogador::setPts1(int p1)
{
    pts1 = p1;
}

const int Entidades::Personagens::Jogador::getPts1() const
{
    return pts1;
}

void Entidades::Personagens::Jogador::setPts2(int p2)
{
    pts2 = p2;
}

const int Entidades::Personagens::Jogador::getPts2() const
{
    return pts2;
}