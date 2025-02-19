#pragma once
#include "Lista.hpp"
#include "entidade.hpp"
#include "personagem.hpp"
#include "projetil.hpp"
#include "jogador.hpp"
#include "melee.hpp"
#include "atirador.hpp"
#include "tanque.hpp"
#include "plataforma.hpp"
#include "aramefarpado.hpp"
#include "fosso.hpp"

namespace Listas
{

    class ListaEntidades
    {

    private:
        Lista<Entidades::Entidade> LEs;
        Gerenciadores::Grafico *pGrafico;

    public:
        ListaEntidades();
        ~ListaEntidades();
        void limpar();
        void incluir(Entidades::Entidade *Entidade);
        void percorrer();
        void salvarEntidades();
        Iterador<Entidades::Entidade> *criarIterador();
    };
}