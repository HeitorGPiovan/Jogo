#pragma once

namespace Listas
{
    template <typename TL>
    class Lista;


    template <typename T>
    class Iterador
    {
    public:
        Iterador() {}
        virtual ~Iterador() {}

        virtual bool fim() const = 0;
        virtual T *obterAtual() const = 0;
        virtual void proximo() = 0;
        virtual T *obterProximo() = 0;

        // Classe aninhada IteradorLista
        template <typename TL>
        class IteradorLista : public Iterador<TL>
        {
        private:
            typename Listas::Lista<TL>::template Elemento<TL> *atual;

        public:
            IteradorLista(typename Listas::Lista<TL>::template Elemento<TL> *inicio) : atual(inicio) {}

            ~IteradorLista() {}

            bool fim() const override
            {
                return (atual == nullptr);
            }

            TL *obterAtual() const override
            {
                if (atual)
                {
                    return atual->getInfo();
                }
                return nullptr;
            }

            void proximo() override
            {
                if (atual)
                {
                    atual = atual->getProx();
                }
            }

            TL *obterProximo() override
            {
                if (atual)
                {
                    TL *info = atual->getInfo();
                    atual = atual->getProx();
                    return info;
                }
                return nullptr;
            }
        };
    };

}

