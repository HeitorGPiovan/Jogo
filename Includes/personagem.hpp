#pragma once
#include "entidade.hpp"
#include "projetil.hpp"

namespace Entidades
{
    namespace Personagens
    {

        class Personagem : public Entidade
        {
        protected:
            int num_vidas;
            bool vivo;
            Projetil *tiro;

        public:
            Personagem();
            ~Personagem();
            void salvarDataBuffer(nlohmann::json &j);
            virtual void mover();
            virtual void reverterMovimento();
            virtual void inverterDirecao();
            virtual void salvar();
            virtual void executar() = 0;
            const bool getVivo() const;
            void setVivo(const bool v);
            void operator--();
            const int getVida() const;
            void setVida(const int v);
            virtual void disparar();
            void setTiro(Projetil *t);
            Projetil *getTiro() const;
        };
    }
} 
