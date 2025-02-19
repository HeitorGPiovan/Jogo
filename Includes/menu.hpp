#pragma once
#include "ente.hpp"
#include "grafico.hpp"
#include "eventos.hpp"

class Dia;

class Menu : public Ente
{
private:
    Gerenciadores::Grafico *pGrafico;
    Gerenciadores::Eventos *pEventos;
    Dia *pJogo;
    bool confirmado;
    int botao;
    bool pausado;
    sf::Font fonte;
    sf::Text titulo;
    sf::Text botoes[9];
    int numMenu;
    int maxBotao;

public:
    Menu(Dia *pJogo = NULL);
    ~Menu();
    void executar();
    void menuPrincipal();
    void menuPausa();
    void menuRanking();
    void menuNome();
    void setBotao(const int selecionado);
    const int getBotao() const;
    void setConfirmado(const bool enter);
    const bool getConfirmado() const;
    void ajustarBotao(int deslocamento);
    void limitarBotao();
    void setPausado();
    const bool getPausado() const;
    const int getMenu() const;  
    void setMenu(int selecionado);
    sf::Font getFonte();
};