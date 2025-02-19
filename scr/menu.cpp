#include "../Includes/menu.hpp"
#include "dia.hpp"
#define LARGURA 1280
#define ALTURA 720

Menu::Menu(Dia *pJogo) : pGrafico(Gerenciadores::Grafico::getGerenciadorGrafico()),
                         pEventos(Gerenciadores::Eventos::getGerenciadorEventos()),
                         pJogo(pJogo),
                         confirmado(false),
                         botao(0),
                         pausado(false),
                         numMenu(1),
                         maxBotao(6)
{
    pEventos->setMenu(this);

    if (!fonte.loadFromFile("C:/Type_Machine.ttf"))
    {
    }
    titulo.setFont(fonte);
    titulo.setCharacterSize(50);
    titulo.setFillColor(sf::Color::White);
}

Menu::~Menu()
{
}

void Menu::menuPrincipal()
{
    titulo.setFont(fonte);
    titulo.setString("MENU PRINCIPAL");
    titulo.setCharacterSize(40);
    titulo.setFillColor(sf::Color::White);
    sf::FloatRect tamanhoTitulo = titulo.getLocalBounds();
    titulo.setPosition((LARGURA - tamanhoTitulo.width) / 2, 100);

    for (int i = 0; i < 6; i++)
    {
        botoes[i].setFont(fonte);
        botoes[i].setCharacterSize(25);
        botoes[i].setFillColor(sf::Color::White);
        switch (i)
        {
        case 0:
            botoes[i].setString("Fase 1 - Singleplayer");
            break;
        case 1:
            botoes[i].setString("Fase 1 - Multiplayer");
            break;
        case 2:
            botoes[i].setString("Fase 2 - Singleplayer");
            break;
        case 3:
            botoes[i].setString("Fase 2 - Multiplayer");
            break;
        case 4:
            botoes[i].setString("Carregar");
            break;
        case 5:
            botoes[i].setString("Ranking");
            break;
        }

        sf::FloatRect tamanhoBotao = botoes[i].getLocalBounds();
        botoes[i].setPosition((LARGURA - tamanhoBotao.width) / 2, 200 + i * 30);
    }
}

void Menu::menuPausa()
{
    titulo.setFont(fonte);
    titulo.setString("PAUSADO");
    titulo.setCharacterSize(40);
    titulo.setFillColor(sf::Color::White);
    sf::FloatRect tamanhoTitulo = titulo.getLocalBounds();
    titulo.setPosition((LARGURA - tamanhoTitulo.width) / 2, 100);

    for (int i = 0; i < 4; i++)
    {
        botoes[i].setFont(fonte);
        botoes[i].setCharacterSize(25);
        botoes[i].setFillColor(sf::Color::White);
        switch (i)
        {
        case 0:
            botoes[i].setString("Continuar");
            break;
        case 1:
            botoes[i].setString("Salvar");
            break;
        case 2:
            botoes[i].setString("Cadastrar Nome");
            break;
        case 3:
            botoes[i].setString("Sair");
            break;
        }

        sf::FloatRect tamanhoBotao = botoes[i].getLocalBounds();
        botoes[i].setPosition((LARGURA - tamanhoBotao.width) / 2, 200 + i * 30);
    }
}

void Menu::menuRanking()
{
    titulo.setFont(fonte);
    titulo.setString("RANKING");
    titulo.setCharacterSize(40);
    titulo.setFillColor(sf::Color::White);
    sf::FloatRect tamanhoTitulo = titulo.getLocalBounds();
    titulo.setPosition((LARGURA - tamanhoTitulo.width) / 2, 100);

    for (int i = 0; i < 9; i++)
    {
        botoes[i].setFont(fonte);
        botoes[i].setCharacterSize(25);
        botoes[i].setFillColor(sf::Color::White);
        switch (i)
        {
        case 0:
            botoes[i].setString(pJogo->acessarRanking(0));
            break;
        case 1:
            botoes[i].setString(pJogo->acessarRanking(1));
            break;
        case 2:
            botoes[i].setString(pJogo->acessarRanking(2));
            break;
        case 3:
            botoes[i].setString(pJogo->acessarRanking(3));
            break;
        case 4:
            botoes[i].setString(pJogo->acessarRanking(4));
            break;
        case 5:
            botoes[i].setString(pJogo->acessarRanking(5));
            break;
        case 6:
            botoes[i].setString(pJogo->acessarRanking(6));
            break;  
        case 7:
            botoes[i].setString(pJogo->acessarRanking(7));
            break;            
        case 8:
            botoes[i].setString("Sair");
            break;
        }
        sf::FloatRect tamanhoBotao = botoes[i].getLocalBounds();
        botoes[i].setPosition((LARGURA - tamanhoBotao.width) / 2, 200 + i * 30);
    }
}

void Menu::menuNome()
{
    titulo.setFont(fonte);
    titulo.setString("CADASTRAR NOME");
    titulo.setCharacterSize(40);
    titulo.setFillColor(sf::Color::White);
    sf::FloatRect tamanhoTitulo = titulo.getLocalBounds();
    titulo.setPosition((LARGURA - tamanhoTitulo.width) / 2, 100);

    for (int i = 0; i < 2; i++)
    {
        botoes[i].setFont(fonte);
        botoes[i].setCharacterSize(25);
        botoes[i].setFillColor(sf::Color::White);
        switch (i)
        {
        case 0:
            botoes[i].setString(pJogo->acessarNome());     
            break;      
        case 1:
            botoes[i].setString("Sair");
            break;
        }
        sf::FloatRect tamanhoBotao = botoes[i].getLocalBounds();
        botoes[i].setPosition((LARGURA - tamanhoBotao.width) / 2, 200 + i * 30);
    }
}

void Menu::executar()
{
    if (numMenu == 1)
    {
        menuPrincipal();
        maxBotao = 6;
    }
    else if (numMenu == 2)
    {
        menuPausa();
        maxBotao = 4;
    }
    else if (numMenu == 3)
    {
        menuRanking();
        maxBotao = 9;
    }
    else if(numMenu == 4)
    {
        menuNome();
        maxBotao = 2;
    }

    pEventos->executar();

    pGrafico->limparJanela();
    pGrafico->desenharElemento(titulo);

    for (int i = 0; i < maxBotao; i++)
    {
        if (botao == i)
        {
            botoes[i].setFillColor(sf::Color::Green);
        }
        else
        {
            botoes[i].setFillColor(sf::Color::White);
        }

        pGrafico->desenharElemento(botoes[i]);
    }

    pGrafico->mostrarElementos();


    if (confirmado)
    {
        pJogo->setOpcao(botao + 1);
        confirmado = false;
    }
}

void Menu::setBotao(const int selecionado)
{
    botao = selecionado - 1;
}

const int Menu::getBotao() const
{
    return botao;
}

void Menu::setConfirmado(const bool enter)
{
    confirmado = enter;
}

const bool Menu::getConfirmado() const
{
    return confirmado;
}

void Menu::ajustarBotao(int deslocamento)
{
    if (clock.getElapsedTime().asSeconds() >= 0.2)
    {
        botao += deslocamento;
        clock.restart();
    }
    limitarBotao();
}

void Menu::limitarBotao()
{
    if (botao < 0)
        botao = maxBotao - 1;
    else if (botao > maxBotao - 1)
        botao = 0;
}

const bool Menu::getPausado() const
{
    return pausado;
}

void Menu::setPausado()
{
    setConfirmado(false);
    setMenu(2);
    pJogo->setOpcao(-1);
    botao = 0;
}

const int Menu::getMenu() const
{
    return numMenu;
}

void Menu::setMenu(int selecionado)
{
    numMenu = selecionado;
}

sf::Font Menu::getFonte()
{
    return fonte;
}