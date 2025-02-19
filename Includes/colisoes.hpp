#pragma once
#include "entidade.hpp"
#include "jogador.hpp"
#include "inimigo.hpp"
#include "obstaculo.hpp"
#include "projetil.hpp"
#include <vector>
#include <list>
#include <set>

namespace Gerenciadores
{

    class Colisoes
    {
    private:
        Entidades::Personagens::Jogador *pJog1;
        Entidades::Personagens::Jogador *pJog2;
        vector<Entidades::Personagens::Inimigos::Inimigo*> LIs;
        list<Entidades::Obstaculos::Obstaculo*> LOs;
        set<Entidades::Projetil*> LPs;

        static Colisoes *pColisoes;

    protected:
        Colisoes();

    public:
        ~Colisoes();
       
        const bool verificarColisao(Entidades::Entidade* pe1, Entidades::Entidade* pe2) const;
        void tratarJogBorda();
        void tratarIniBorda();
        void tratarObsBorda();
        void tratarProBorda();
        void tratarJogJog();
        void tratarJogObs();
        void tratarJogIni();
        void tratarJogPro();
        void tratarObsIni();
        void tratarProIni();
        void tratarProObs();
        void tratarObsObs();
        void incluirInimigo(Entidades::Personagens::Inimigos::Inimigo *pi);
        void incluirObstaculo(Entidades::Obstaculos::Obstaculo *po);
        void incluirProjetil(Entidades::Projetil* pp);
        void setJog1(Entidades::Personagens::Jogador* pj1);
        void setJog2(Entidades::Personagens::Jogador* pj2);
        static Colisoes *getGerenciadorColisoes();
        void executar();
        void limparListas();
    };

}