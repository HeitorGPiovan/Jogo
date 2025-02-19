#pragma once
#include <string>
#include "jogador.hpp"
#include "grafico.hpp"
#include "eventos.hpp"
#include "colisoes.hpp"
#include "melee.hpp"
#include "plataforma.hpp"
#include "fosso.hpp"
#include "aramefarpado.hpp"
#include "praia.hpp"
#include "trincheira.hpp"
#include "tanque.hpp"
#include "menu.hpp"

class Dia
{
private:
    Gerenciadores::Grafico *pGrafico;
    Gerenciadores::Eventos *pEventos;
    Gerenciadores::Colisoes *pColisoes;
    Entidades::Personagens::Jogador Jog1;
    Entidades::Personagens::Jogador Jog2;
    Fases::Praia praia;
    Fases::Trincheira trincheira;
    Menu* pMenu;
    int opcao;
    int ultimaOpcao;
    multiset<Entidades::Personagens::Jogador*, Entidades::Personagens::ComparadorJogador> ranking;

public:
    Dia();
    ~Dia();
    void executar();
    void setOpcao(const int selecionado);
    const int getOpcao() const;
    void setUltOpcao(const int selecionado);
    const int getUltOpcao() const;
    const bool jogoEmExecucao() const;
    void execucaoPrincipal();
    void execucaoPausa();
    void execucaoRanking();
    void execucaoNome();
    int verificarCenario();
    void incluirRanking(Entidades::Personagens::Jogador* pj1);
    void salvarRanking();
    void recuperarRanking();
    string acessarRanking(long long unsigned int posicao);
    string acessarNome();
};