#include "../Includes/trincheira.hpp"

Fases::Trincheira::Trincheira() : Fase(2),
                                  maxTanque(0),
                                  maxFosso(0)
{
    if (pGrafico)
    {
        pGrafico->definirTextura("Trincheira", sprite);
    }
    else
    {
        std::cout << "PONTEIRO NULO!";
    }

    LEs = new Listas::ListaEntidades();
}

Fases::Trincheira::~Trincheira()
{
}

void Fases::Trincheira::criarInimigos()
{
    int contTanque = 0;

    switch (quantPlats)
    {
    case 7:

        maxTanque = 1;
        break;

    case 8:

        maxTanque = 1;
        break;

    case 9:

        maxTanque = 1;
        break;

    case 10:

        maxTanque = 2;
        break;

    case 11:

        maxTanque = 3;
        break;

    default:
        maxTanque = 1;
        break;
    }

    int numTanque = 3 + (rand() % maxTanque);
    cout << "Tanques: " << numTanque << endl;

    for (int i = 0; i < numTanque; i++)
    {
        Entidades::Personagens::Inimigos::Tanque *pTanque = new Entidades::Personagens::Inimigos::Tanque();
        pColisoes->incluirInimigo(pTanque);

        if (LEs && pTanque)
        {
            LEs->incluir(pTanque);
        }

        contTanque++;

        switch (contTanque)
        {
        case 1:

            pTanque->setX(690);
            pTanque->setY(480);
            break;

        case 2:
            pTanque->setX(590);
            pTanque->setY(250);
            break;

        case 3:

            pTanque->setX(790);
            pTanque->setY(10);
            break;

        case 4:

            pTanque->setX(100);
            pTanque->setY(370);
            break;

        case 5:

            pTanque->setX(1100);
            pTanque->setY(50);
            break;

        default:
            break;
        }
    }
}

void Fases::Trincheira::criarObstaculos()
{
    if (quantPlats == 11)
    {
        maxFosso = 3;
    }
    else
    {
        maxFosso = 1;
    }
    int contFosso = 0;
    int numFossos = 3 + (rand() % maxFosso);
    cout << "Fossos: " << numFossos << endl;

    for (int i = 0; i < numFossos; i++)
    {
        Entidades::Obstaculos::Fosso *pFosso = new Entidades::Obstaculos::Fosso();

        pColisoes->incluirObstaculo(pFosso);

        if (LEs && pFosso)
        {
            LEs->incluir(pFosso);
        }

        contFosso++;

        switch (contFosso)
        {
        case 1:

            pFosso->setX(740);
            pFosso->setY(480);
            break;

        case 2:

            pFosso->setX(540);
            pFosso->setY(250);
            break;

        case 3:

            pFosso->setX(740);
            pFosso->setY(10);
            break;

        case 4:

            pFosso->setX(100);
            pFosso->setY(370);
            break;

        case 5:

            pFosso->setX(1100);
            pFosso->setY(50);
            break;

        default:
            break;
        }
    }
}

void Fases::Trincheira::criarJogadores()
{
    if (pJog1)
    {
        pColisoes->setJog1(pJog1);

        if (LEs)
        {
            LEs->incluir(pJog1);
        }
        if (!carregada)
        {
            pJog1->setX(120);
            pJog1->setY(580);
            pJog1->setVivo(true);
            pJog1->setVida(40);
            pJog1->setDir(2);
            pJog1->setDir(0);
        }
    }

    if (pJog2)
    {
        pColisoes->setJog2(pJog2);

        if (LEs)
        {
            LEs->incluir(pJog2);
        }
        if (!carregada)
        {
            pJog2->setX(240);
            pJog2->setY(580);
            pJog2->setVivo(true);
            pJog2->setVida(40);
            pJog2->setDir(2);
            pJog2->setDir(0);
        }
    }
}
