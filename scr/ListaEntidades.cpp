#include "../Includes/ListaEntidades.hpp"
Listas::ListaEntidades::ListaEntidades() : pGrafico(Gerenciadores::Grafico::getGerenciadorGrafico())
{
}

Listas::ListaEntidades::~ListaEntidades()
{
}

void Listas::ListaEntidades::incluir(Entidades::Entidade *entidade)
{
    LEs.incluir(entidade);
}

void Listas::ListaEntidades::percorrer()
{
    Iterador<Entidades::Entidade> *iterador = LEs.criarIterador();

    while (!iterador->fim())
    {
        Entidades::Entidade *entidade = iterador->obterAtual();

        if (entidade)
        {
            Entidades::Personagens::Personagem *personagem = dynamic_cast<Entidades::Personagens::Personagem *>(entidade);
            if (personagem)
            {
                if (personagem->getVivo())
                {
                    entidade->executar();
                }
            }
            else
            {
                Entidades::Projetil *projetil = dynamic_cast<Entidades::Projetil *>(entidade);
                if (projetil)
                {
                    if (projetil->getAtivo())
                    {
                        entidade->executar();
                    }
                }
                else
                {
                    entidade->executar();
                }
            }
        }

        iterador->proximo();
    }

    delete iterador;
}

Listas::Iterador<Entidades::Entidade> *Listas::ListaEntidades::criarIterador()
{
    return LEs.criarIterador();
}

void Listas::ListaEntidades::limpar()
{
    LEs.limpar();
}

void Listas::ListaEntidades::salvarEntidades()
{
    Iterador<Entidades::Entidade> *iterador = LEs.criarIterador();

    while (!iterador->fim())
    {
        Entidades::Entidade *entidade = iterador->obterAtual();

        if (entidade)
        {
            entidade->salvar();

            iterador->proximo();
        } 
    }
    delete iterador;
}
