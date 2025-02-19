#pragma once
#include <SFML/Graphics.hpp>
#include "../Includes/grafico.hpp"
#include "personagem.hpp"
#include "jogador.hpp"


class Menu;

namespace Gerenciadores
{
    class Eventos
    {
    private:
        sf::Event event;
        static Grafico *pGrafico;
        static Eventos *pEventos;
        bool W;
        bool Cima;
        sf::Clock clock;
        Menu *pMenu;
        Entidades::Personagens::Jogador* pJog1;
        Entidades::Personagens::Jogador* pJog2;

        
    protected:
        Eventos();

    public:
        ~Eventos();
        void lerTeclas();
        void lerJanela();
        void lerMenu();
        void lerNome();
        void executar();
        static Eventos *getGerenciadorEventos();
        void setMenu(Menu* pm);
        void setJog1(Entidades::Personagens::Jogador* pj1);
        void setJog2(Entidades::Personagens::Jogador* pj2);
    };
}
