#pragma once
#include "obstaculo.hpp"
#include "jogador.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Plataforma : public Obstaculo
        {
            private: 
                int tamanho;
            public:
                Plataforma();
                ~Plataforma();
                void executar();
                void obstacular(Entidades::Personagens::Jogador* p);
                void salvar();
                void setTamanho(int t);
        };
    }
}