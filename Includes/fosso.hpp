#pragma once
#include "obstaculo.hpp"
#include "jogador.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Fosso : public Obstaculo
        {
            private:
                bool grande;
            public:
                Fosso();
                ~Fosso();
                void executar();
                void obstacular(Entidades::Personagens::Jogador* p);
                void salvar();
                void setGrande(bool g);
        };
    }
}