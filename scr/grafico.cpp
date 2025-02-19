#include "../Includes/grafico.hpp"
#include "../Includes/ente.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

Gerenciadores::Grafico *Gerenciadores::Grafico::pGrafico(NULL);

Gerenciadores::Grafico::Grafico() : window(new sf::RenderWindow(sf::VideoMode(LARG, ALT), "Dia C"))
{
    if (window == NULL)
    {
        std::cout << "Nao foi possivel criar uma janela grafica" << std::endl;
        exit(1);
    }

    // https://www.seaart.ai/pt/explore/detail/clmp4894msbc739bu0r0
    carregarTextura("Melee", "Imagens/Melee.png"); // Créditos: Austin Kelly
    carregarTextura("Jog1", "Imagens/Verde.png");
    carregarTextura("Jog2", "Imagens/Azul.png");
    carregarTextura("Atirador", "Imagens/Atirador.png");
    carregarTextura("Tanque", "Imagens/Tanque.png");

    // https://lovepik.com/image-610487496/q-version-cartoon-horizontal-version-of-the-game-character-scene.html
    carregarTextura("PlataformaP", "Imagens/PlataformaP.png"); // Créditos: QianKuWang
    carregarTextura("PlataformaM", "Imagens/PlataformaM.png"); // Créditos: QianKuWang
    carregarTextura("PlataformaG", "Imagens/PlataformaG.png"); // Créditos: QianKuWang
    carregarTextura("PlataformaI", "Imagens/PlataformaI.png"); // Créditos: QianKuWang

    carregarTextura("Projetil", "Imagens/Projetil.png");

    //https://www.shutterstock.com/pt/image-vector/black-hole-pixel-art-flat-icon-2201194677
    carregarTextura("Fosso", "Imagens/Fosso.png");
    carregarTextura("Fosso Grande", "Imagens/Fosso Grande.png");

    carregarTextura("Arame", "Imagens/Arame.png");

    //FUNDO PRAIA
    //https://www.google.com/url?sa=i&url=https%3A%2F%2Fpt.vecteezy.com%2Farte-vetorial%2F37047308-pixel-mar-panorama-8-bits-sol-de-praia-com-aceno-nuvem-e-areia-jogos-verao-oceano-panorama-nublado-azul-ceu-com-horizonte-fundo-pixeis-ilha-cena-vetor-ilustracao&psig=AOvVaw0RIUXhaDqDug9PQ2vk_zmE&ust=1736623397731000&source=images&cd=vfe&opi=89978449&ved=0CBcQjhxqFwoTCPjkhLzw64oDFQAAAAAdAAAAABAE
    carregarTextura("Praia", "Imagens/Praia.jpg");

    //FUNDO TRINCHEIRA
    //yeschat.ai
    carregarTextura("Trincheira", "Imagens/Trincheira.jpg");

    //https://www.vectorstock.com/royalty-free-vector/pixelated-red-flag-vector-41549601
    carregarTextura("Fim","Imagens/Fim.png");
}

Gerenciadores::Grafico::~Grafico()
{
    if (window)
    {
        delete (window);
        window = NULL;
    }

    pGrafico = NULL;
}

Gerenciadores::Grafico *Gerenciadores::Grafico::getGerenciadorGrafico()
{
    if (pGrafico == NULL)
    {
        pGrafico = new Grafico();
    }
    return pGrafico;
}

sf::RenderWindow *Gerenciadores::Grafico::getWindow()
{
    if (window)
        return window;
    else
        return NULL;
}

void Gerenciadores::Grafico::fecharJanela()
{
    if (window)
        window->close();
    else
        std::cout << "PONTEIRO NULO!";
}

void Gerenciadores::Grafico::limparJanela()
{
    if (window)
        window->clear();
    else
        std::cout << "PONTEIRO NULO!";
}

void Gerenciadores::Grafico::mostrarElementos()
{
    if (window)
        window->display();
    else
        std::cout << "PONTEIRO NULO!";
}

const bool Gerenciadores::Grafico::verificaJanelaAberta()
{
    if (window)
        return window->isOpen();
    else
        return false;
}

void Gerenciadores::Grafico::desenharEnte(Ente *pE)
{
    if (pE && window)
    {
        window->draw(pE->getSprite());
    }
    else
        std::cout << "PONTEIRO NULO!";
}

void Gerenciadores::Grafico::desenharElemento(const sf::Drawable &elemento) // teste de hitbox
{
    if (window)
        window->draw(elemento);
    else
        std::cout << "PONTEIRO NULO!";
}

void Gerenciadores::Grafico::carregarTextura(const std::string &chave, const std::string &caminho)
{
    sf::Texture textura;
    if (!textura.loadFromFile(caminho))
    {
        std::cerr << "Erro ao carregar textura: " << caminho << std::endl;
    }
    else
    {
        texturas[chave] = textura;
    }
}

void Gerenciadores::Grafico::definirTextura(const std::string &chave, sf::Sprite &sprite)
{
    sf::Texture *textura = getTextura(chave);
    if (textura)
    {
        sprite.setTexture(*textura);
    }
}

sf::Texture* Gerenciadores::Grafico::getTextura(const std::string& chave)
{
    std::map<std::string, sf::Texture>::iterator it = texturas.find(chave);

    if (it != texturas.end())
    {
        return &(it->second);
    }
    else
    {
        std::cout << "Erro: Textura com chave '" << chave << "' não encontrada!" << std::endl;
        return NULL;
    }
}
