#pragma once
#include "entidade.hpp"

namespace Entidades 
{
    namespace Personagens 
    {
        class Personagem;
    }
}

namespace Entidades
{
    class Projetil : public Entidade
    {
    private:
        bool ativo;
        int dano;
        bool deInimigo;

    public:
        Projetil(int dir, int x, int y, bool di, int dmg=1);
        Projetil();
        ~Projetil();

        void executar();
        void transitar();
        void acertar(Entidades::Personagens::Personagem* p);
        const bool getAtivo() const;
        void setAtivo(const bool atv);
        void salvar();
        void setDano(int dmg);
        void setDeInimigo(bool di);
        const bool getDeInimigo() const;
        void atualizarGravidade();
    };
}