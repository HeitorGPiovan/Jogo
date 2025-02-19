#pragma once
#include "inimigo.hpp"
#include "jogador.hpp"
#include "projetil.hpp"

namespace Entidades
{

    namespace Personagens
    {

        namespace Inimigos
        {
            class Tanque : public Inimigo
            {
            private:
                int potencia;

            public:
                Tanque();
                ~Tanque();
                void danificar(Jogador *p);
                void executar();
                void disparar();
                void salvar();
                void setPotencia(int pot);
            };
        }

    }

}