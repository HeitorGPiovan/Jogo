#pragma once
#include "personagem.hpp"
#include "jogador.hpp"

namespace Entidades
{
    namespace Personagens
    {
        namespace Inimigos
        {
            class Inimigo : public Personagem
            {
            protected:
                int dano;
                bool localizou;

            public:
                Inimigo(int dmg = 0, bool loc = false);
                ~Inimigo();
                virtual void salvar() = 0;
                const int getDano() const;
                virtual void executar() = 0;
                virtual void danificar(Jogador *p) = 0;
                void localizar(Jogador *p);
                void setLoc(const bool loc);
                const bool getLoc() const;
                void salvarDataBuffer(nlohmann::json &j);
                void setDano(int dmg);
            };
        }
    }
}
