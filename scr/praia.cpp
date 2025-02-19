#include "../Includes/praia.hpp"

Fases::Praia::Praia() : Fase(1),
                        maxAtirador(0),
                        maxArame(0)
{
    if (pGrafico)
    {
        pGrafico->definirTextura("Praia", sprite);
    }
    else
    {
        std::cout << "PONTEIRO NULO!";
    }

    LEs = new Listas::ListaEntidades();
}

Fases::Praia::~Praia()
{
}

void Fases::Praia::criarInimigos()
{
    int contAtirador = 0;

    switch (quantPlats)
    {
    case 7:

        maxAtirador = 1;
        break;

    case 8:

        maxAtirador = 2;
        break;

    case 9:

        maxAtirador = 3;
        break;

    case 10:

        maxAtirador = 3;
        break;

    case 11:

        maxAtirador = 4;
        break;

    default:
        maxAtirador = 1;
        break;
    }

    int numAtirador = 3 + (rand() % maxAtirador);
    cout << "Atiradores: " << numAtirador << endl;

    for (int i = 0; i < numAtirador; i++)
    {
        Entidades::Personagens::Inimigos::Atirador *pAtirador = new Entidades::Personagens::Inimigos::Atirador();
        pColisoes->incluirInimigo(pAtirador);

        if (LEs && pAtirador)
        {
            LEs->incluir(pAtirador);
        }

        contAtirador++;

        switch (contAtirador)
        {
        case 1:

            pAtirador->setX(800);
            pAtirador->setY(420);
            break;

        case 2:

            pAtirador->setX(1150);
            pAtirador->setY(260);
            break;

        case 3:

            pAtirador->setX(1150);
            pAtirador->setY(20);
            break;

        case 4:
            pAtirador->setX(1150);
            pAtirador->setY(410);
            break;

        case 5:

            pAtirador->setX(20);
            pAtirador->setY(180);
            break;

        case 6:
            pAtirador->setX(20);
            pAtirador->setY(10);
            break;

        default:
            break;
        }
    }
}

void Fases::Praia::criarObstaculos()
{
    if (quantPlats == 9 || quantPlats == 10)
    {
        maxArame = 2;
    }

    else if (quantPlats == 11)
    {
        maxArame = 3;
    }
    else
    {
        maxArame = 1;
    }

    int contArame = 0;
    int numArames = 3 + (rand() % maxArame);
    cout << "Arames: " << numArames << endl;

    for (int i = 0; i < numArames; i++)
    {
        Entidades::Obstaculos::Arame_Farpado *pArame = new Entidades::Obstaculos::Arame_Farpado();

        pColisoes->incluirObstaculo(pArame);

        if (LEs && pArame)
        {
            LEs->incluir(pArame);
        }

        contArame++;

        switch (contArame)
        {
        case 1:

            pArame->setX(1020);
            pArame->setY(100);
            break;

        case 2:

            pArame->setX(680);
            pArame->setY(400);
            break;

        case 3:

            pArame->setX(720);
            pArame->setY(180);
            break;

        case 4:

            pArame->setX(100);
            pArame->setY(180);
            break;

        case 5:

            pArame->setX(100);
            pArame->setY(20);
            break;

        default:
            break;
        }
    }
}

void Fases::Praia::criarJogadores()
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
            pJog1->setX(20);
            pJog1->setY(550);
            pJog1->setVivo(true);
            pJog1->setVida(40);
            pJog1->setDir(2);
            pJog1->mover();
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
            pJog2->setX(100);
            pJog2->setY(550);
            pJog2->setVivo(true);
            pJog2->setVida(40);
            pJog2->setDir(2);
            pJog2->mover();
            pJog2->setDir(0);
        }
    }
}