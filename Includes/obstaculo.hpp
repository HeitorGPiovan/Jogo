#pragma once
#include "entidade.hpp"
#include "jogador.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Obstaculo : public Entidade
        {
        protected:
            bool danoso;

        public:
            Obstaculo(bool d);
            Obstaculo();
            ~Obstaculo();

            virtual void executar() = 0;
            virtual void obstacular(Entidades::Personagens::Jogador *p) = 0;
            virtual void salvar() = 0;
            void salvarDataBuffer(nlohmann::json &j);
            const bool getDan() const;
            void setDan(const bool d);
        };
    }
}