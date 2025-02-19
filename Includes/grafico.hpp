#pragma once
#include <SFML/Graphics.hpp>
#include <map>

#define LARG 1280
#define ALT 720

class Ente;

namespace Gerenciadores
{

    class Grafico
    {
    private:
        sf::RenderWindow *window;
        static Grafico *pGrafico;
        std::map<std::string, sf::Texture> texturas;

    
    protected:
        Grafico();

    public:
        ~Grafico();

        const bool verificaJanelaAberta();
        sf::RenderWindow *getWindow();
        static Grafico *getGerenciadorGrafico();
        void desenharEnte(Ente *pE);
        void limparJanela();
        void fecharJanela();
        void mostrarElementos();      
        void definirTextura(const std::string& chave, sf::Sprite& sprite);
        void carregarTextura(const std::string& chave, const std::string& caminho);
        sf::Texture* getTextura(const std::string& chave);
        void desenharElemento(const sf::Drawable& elemento); 

    };

} 