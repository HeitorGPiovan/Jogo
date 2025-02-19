#pragma once
#include <time.h>
#include <set>
#include "ente.hpp"
#include "jogador.hpp"
#include "grafico.hpp"
#include "eventos.hpp"
#include "colisoes.hpp"
#include "melee.hpp"
#include "plataforma.hpp"
#include "fosso.hpp"
#include "aramefarpado.hpp"
#include "ListaEntidades.hpp"
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

namespace Fases
{

    class Fase : public Ente
    {
    protected:
        Entidades::Personagens::Jogador *pJog1;
        Entidades::Personagens::Jogador *pJog2;
        Listas::ListaEntidades *LEs;
        Gerenciadores::Colisoes *pColisoes;
        bool criada;
        int quantPlats;
        sf::Sprite fim;
        int numFase;
        int maxMelees;
        bool carregada;
        

    public:
        Fase(int num = 0);
        Fase();
        ~Fase();
        virtual void executar();
        void gerenciar_colisoes();
        void criarMelee();
        void criarPlat();
        void criarProjeteis();
        virtual void criarInimigos() = 0;
        virtual void criarObstaculos() = 0;
        virtual void criarJogadores() = 0;
        void setJog(Entidades::Personagens::Jogador *pj1);
        void setJog(Entidades::Personagens::Jogador *pj1, Entidades::Personagens::Jogador *pj2);
        void criarCenario();
        const bool getCriada() const;
        void setCriada(const bool situacao);
        const int getQuantPlats() const;
        void checarFim();
        const int getNumFase() const;
        void setNumFase(const int fase);
        void salvarEntidades();
        void carregarCenario(const std::string &caminhoArquivo);
        void criarCenarioCarregado();
    };
} 