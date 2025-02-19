#pragma once
#include "ente.hpp"
#include "json.hpp"
#include <fstream>
#include <iostream>
using namespace std;

namespace Entidades
{
    class Entidade : public Ente
    {

    protected:
        int tipo;
        int x;
        int y;
        int direcao;
        float velocidadeVertical;
        const float gravidade;

    public:
        Entidade(int dir = 0, int x = 0, int y = 0);
        virtual ~Entidade();
        virtual void executar() = 0;
        void setY(const int PosY);
        void setX(const int PosX);
        void setDir(const int dir);
        const int getDir() const;
        const int getX() const;
        const int getY() const;
        virtual void atualizarGravidade();
        const float getVel() const;
        const int getTipo() const;
        void setVel(const float vel);
        void setTipo(const int NovoTipo);
        virtual void salvar() = 0;
        void salvarDataBuffer(nlohmann::json &j);
        void exportarParaArquivo(const std::string &nomeArquivo, const nlohmann::json &dados_json);
    };

} 
