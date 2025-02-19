#pragma once
#include "inimigo.hpp"
#include "jogador.hpp"

namespace Entidades
{
    namespace Personagens
    {
        namespace Inimigos
        {
            class Melee : public Inimigo
            {
            private:
                int resistencia;

            public:
                Melee();
                ~Melee();
                void movimentar();
                void danificar(Jogador *p);
                void executar();
                void salvar();
                void setResistencia(int r);
            };
        }
    }
}
