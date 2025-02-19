#include "eventos.hpp"
#include "grafico.hpp"
#include "jogador.hpp"
#include "menu.hpp"

Gerenciadores::Grafico *Gerenciadores::Eventos::pGrafico = Gerenciadores::Grafico::getGerenciadorGrafico();
Gerenciadores::Eventos *Gerenciadores::Eventos::pEventos = NULL;

Gerenciadores::Eventos::Eventos()
    : W(false),
      Cima(false),
      pJog1(NULL),
      pJog2(NULL)
{
}

Gerenciadores::Eventos::~Eventos()
{
    pEventos = NULL;
    pJog1 = NULL;
    pJog2 = NULL;
}

void Gerenciadores::Eventos::lerJanela()
{
    if (event.type == sf::Event::Closed)
    {
        pGrafico->fecharJanela();
    }
}

void Gerenciadores::Eventos::executar()
{
    while (pGrafico->getWindow()->pollEvent(event))
    {
        lerJanela();
        lerTeclas();
        lerMenu();
        if(pMenu->getMenu() == 4)
        {
            lerNome();
        }
    }
}

void Gerenciadores::Eventos::lerTeclas()
{

    if (event.type == sf::Event::KeyPressed)
    {
        if (pJog1 && pJog1->getVivo())
        {
            // Jogador 1
            if (event.key.code == sf::Keyboard::F)
            {
                pJog1->disparar();
            }
            if (event.key.code == sf::Keyboard::W)
            {
                if (clock.getElapsedTime().asSeconds() >= 0.7)
                {
                    if (W == false)
                    {
                        pJog1->pular();
                        W = true;
                    }

                    clock.restart();
                }
            }
            if (event.key.code == sf::Keyboard::D)
                pJog1->setDir(2);

            if (event.key.code == sf::Keyboard::A)
                pJog1->setDir(-2);

            if (event.key.code == sf::Keyboard::S)
                pJog1->setDir(-1);
        }

        if (pJog2 && pJog2->getVivo())
        {
            // Jogador 2
            if (event.key.code == sf::Keyboard::M)
            {
                pJog2->disparar();
            }
            if (event.key.code == sf::Keyboard::Up)
            {
                if (clock.getElapsedTime().asSeconds() >= 0.7)
                {
                    if (Cima == false)
                    {
                        pJog2->pular();
                        Cima = true;
                    }

                    clock.restart();
                }
            }
            if (event.key.code == sf::Keyboard::Right)
                pJog2->setDir(2);

            if (event.key.code == sf::Keyboard::Left)
                pJog2->setDir(-2);

            if (event.key.code == sf::Keyboard::Down)
                pJog2->setDir(-1);
        }
    }

    else if (event.type == sf::Event::KeyReleased)
    {
        if (pJog1)
        {
            // Jogador 1

            if (event.key.code == sf::Keyboard::W)
                W = false;

            if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::S)
            {
                pJog1->setDir(0);
            }
        }

        if (pJog2)
        {
            // Jogador 2
            if (event.key.code == sf::Keyboard::Up)
                Cima = false;

            if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::Down)
            {
                pJog2->setDir(0);
            }
        }
    }
}

Gerenciadores::Eventos *Gerenciadores::Eventos::getGerenciadorEventos()
{
    if (pEventos == NULL)
    {
        pEventos = new Eventos();
    }
    return pEventos;
}

void Gerenciadores::Eventos::lerMenu()
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Num1)
        {
            pMenu->setBotao(1);
            pMenu->setConfirmado(true);
        }
        else if (event.key.code == sf::Keyboard::Num2)
        {
            pMenu->setBotao(2);
            pMenu->setConfirmado(true);
        }
        else if (event.key.code == sf::Keyboard::Num3)
        {
            pMenu->setBotao(3);
            pMenu->setConfirmado(true);
        }
        else if (event.key.code == sf::Keyboard::Num4)
        {
            pMenu->setBotao(4);
            pMenu->setConfirmado(true);
        }
        else if (event.key.code == sf::Keyboard::Num5)
        {
            pMenu->setBotao(5);
            pMenu->setConfirmado(true);
        }
        else if (event.key.code == sf::Keyboard::Num6)
        {
            pMenu->setBotao(6);
            pMenu->setConfirmado(true);
        }
        else if (event.key.code == sf::Keyboard::Up)
        {
            pMenu->ajustarBotao(-1);
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
            pMenu->ajustarBotao(1);
        }
        else if (event.key.code == sf::Keyboard::Enter)
        {
            pMenu->setConfirmado(true);
        }
        else if (event.key.code == sf::Keyboard::Escape)
        {
            pMenu->setPausado();
        }
    }
}

void Gerenciadores::Eventos::lerNome()
{
    if (event.type == sf::Event::TextEntered) 
    {
        if (event.text.unicode == '\b') 
        {
            std::string nomeAtual = pJog1->getNome();
            if (!nomeAtual.empty()) 
            {
                nomeAtual.pop_back();
                pJog1->setNome(nomeAtual);
            }
        } 
        else if (event.text.unicode == '\r') 
        { 
            std::cout << "Nome finalizado: " << pJog1->getNome() << std::endl;
        } 
        else if (event.text.unicode < 128) 
        { 
            std::string nomeAtual = pJog1->getNome();
            nomeAtual += static_cast<char>(event.text.unicode);
            pJog1->setNome(nomeAtual);
        }
    }
}

void Gerenciadores::Eventos::setMenu(Menu* pm)
{
    pMenu = pm;
}

void Gerenciadores::Eventos::setJog1(Entidades::Personagens::Jogador* pj1)
{
    pJog1 = pj1;
}


void Gerenciadores::Eventos::setJog2(Entidades::Personagens::Jogador* pj2)
{
    pJog2 = pj2;
}