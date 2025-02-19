#pragma once
#include "obstaculo.hpp"
#include "jogador.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Arame_Farpado : public Obstaculo
        {
        private:
            int perfuracao;
        public:
            Arame_Farpado();
            ~Arame_Farpado();
            void executar();
            void obstacular(Entidades::Personagens::Jogador* p);
            void salvar();
            void setPerfuracao(int p);
        }; 
    }
}
