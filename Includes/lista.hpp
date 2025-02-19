#pragma once
#include <iostream>
#include <iterator.hpp>
namespace Listas
{
    template <typename TL>

    class Lista
    {
    public:
        template <typename TE>

        class Elemento
        {

        private:
            Elemento<TE> *pProx;
            TE *pInfo;

        public:
            Elemento(TE *info = NULL) : pProx(NULL),
                                        pInfo(info)
            {
            }

            ~Elemento() {}

            void setProx(Elemento<TE> *pE)
            {
                pProx = pE;
            }

            Elemento<TE> *getProx() const
            {
                return pProx;
            }

            void incluir(TE *p)
            {
                Elemento<TE> *novo = new Elemento<TE>(p);
                novo->pProx = this->pProx;
                this->pProx = novo;
            }
            TE *getInfo() const
            {
                return pInfo;
            }
        };

    private:
        Elemento<TL> *pPrimeiro;
        Elemento<TL> *pUltimo;

    public:
        Lista() : pPrimeiro(NULL),
                  pUltimo(NULL)
        {
        }
        ~Lista()
        {
            limpar();
        }

        void incluir(TL *info)
        {
            Elemento<TL> *novo = new Elemento<TL>(info);

            if (pUltimo)
            {
                pUltimo->setProx(novo);
            }
            else
            {
                pPrimeiro = novo;
            }

            pUltimo = novo;
        }

        void limpar()
        {
            Elemento<TL> *atual = pPrimeiro;
            while (atual)
            {
                Elemento<TL> *prox = atual->getProx();
                if (atual->getInfo() && atual->getInfo()->getTipo() != 0)
                {
                    delete atual;
                }
                atual = prox;
            }
            pPrimeiro = NULL;
            pUltimo = NULL;
        }

        typename Iterador<TL>::IteradorLista<TL> *criarIterador()
        {
            return new typename Iterador<TL>::IteradorLista<TL>(pPrimeiro);
        }
    };
}