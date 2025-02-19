#pragma once
#include <vector>
#include <string>
#include "ente.hpp"
#include "personagem.hpp"

namespace Gerenciadores{
    class Colisoes;
}

namespace Entidades
{
    namespace Personagens
    {
        class Jogador : public Personagem
        {
        private:
            int pontos;
            int pts1;
            int pts2;
            string nome;
            bool ehJog2;
            bool emSolo;
            static vector<Jogador*> pJogs;
            
        public:
            Jogador(const std::string& nome, int pontos);
            Jogador();
            ~Jogador();
            void executar();
            const int getPontos() const;
            void setPontos(const int p);
            void movimentar();
            void pular();
            const bool getEmSolo() const;
            void setEmSolo(const bool es);
            const bool getEhJog2() const;
            void setEhJog2(bool dois);
            static void addJog(Jogador* pj);
            void disparar();
            const string getNome() const;
            void setNome(string n);
            void salvar();
            void setPts1(int p1);
            const int getPts1() const;
            void setPts2(int p2);
            const int getPts2() const;
        };
        struct ComparadorJogador 
        {
            bool operator()(const Jogador* j1, const Jogador* j2) const 
            {
                if (j1->getPontos() == j2->getPontos()) {
                    return j1->getNome() < j2->getNome(); 
                }
                return j1->getPontos() > j2->getPontos();
            }
        };
    }
}

