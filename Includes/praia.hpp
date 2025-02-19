#pragma once
#include "fase.hpp"
#include "aramefarpado.hpp"
#include "atirador.hpp"

namespace Fases
{

    class Praia : public Fase
    {
    private:
        int maxAtirador;
        int maxArame;

    public:
        Praia();
        ~Praia();
        void criarInimigos();
        void criarObstaculos();
        void criarJogadores();
    };

} 