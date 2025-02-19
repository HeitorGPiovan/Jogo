#pragma once
#include "inimigo.hpp"
#include "projetil.hpp"
#include "jogador.hpp"

namespace Entidades
{
    namespace Personagens
    {
        namespace Inimigos
        {
            class Atirador : public Inimigo
            {
            private: 
                int coice;
            public:
                Atirador();
                ~Atirador();
                void salvar();
                void executar();
                void danificar(Jogador* p); 
                void setCoice(int c);
            };
        }
    }
}