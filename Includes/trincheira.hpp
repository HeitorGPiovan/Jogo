#pragma once
#include "fase.hpp"
#include "fosso.hpp"
#include "tanque.hpp"

namespace Fases
{

    class Trincheira : public Fase
    {
    private:
        int maxTanque;
        int maxFosso;
    public:
        Trincheira();
        ~Trincheira();
        void criarInimigos();
        void criarObstaculos();
        void criarJogadores();
    };

} 