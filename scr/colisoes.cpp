#include "../Includes/colisoes.hpp"
#define LARGURA 1280
#define ALTURA 720

Gerenciadores::Colisoes *Gerenciadores::Colisoes::pColisoes(NULL);

Gerenciadores::Colisoes::Colisoes() : pJog1(NULL),
                                      pJog2(NULL),
                                      LIs(),
                                      LOs(),
                                      LPs()

{
}

Gerenciadores::Colisoes::~Colisoes()
{
    if (pJog1 != NULL)
    {
        delete pJog1;
        pJog1 = NULL;
    }
    if (pJog2 != NULL)
    {
        delete pJog2;
        pJog2 = NULL;
    }

    for (auto inimigo : LIs)
    {
        delete inimigo;
    }
    LIs.clear();

    for (auto obstaculo : LOs)
    {
        delete obstaculo;
    }
    LOs.clear();

    for (auto projetil : LPs)
    {
        delete projetil;
    }
    LPs.clear();

    pColisoes = NULL;
}

Gerenciadores::Colisoes *Gerenciadores::Colisoes::getGerenciadorColisoes()
{
    if (pColisoes == NULL)
    {
        pColisoes = new Colisoes();
    }
    return pColisoes;
}

const bool Gerenciadores::Colisoes::verificarColisao(Entidades::Entidade *pe1, Entidades::Entidade *pe2) const
{
    if (pe1 && pe2)
    {
        sf::FloatRect hitbox1 = pe1->getHitbox();
        sf::FloatRect hitbox2 = pe2->getHitbox();

        if (hitbox1.intersects(hitbox2))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return NULL;
}

void Gerenciadores::Colisoes::tratarJogBorda()
{
    float larguraTela = LARGURA;
    float alturaTela = ALTURA;

    if (pJog1)
    {
        if (pJog1->getVivo())
        {
            sf::FloatRect hitbox = pJog1->getHitbox();

            float jog1Esquerda = hitbox.left;
            float jog1Direita = hitbox.left + hitbox.width;
            float jog1Topo = hitbox.top;
            float jog1Base = hitbox.top + hitbox.height;

            if (jog1Direita > larguraTela)
            {
                pJog1->setX(larguraTela - hitbox.width);
            }

            if (jog1Esquerda < 0)
            {
                pJog1->setX(0 + hitbox.width);
            }

            if (jog1Base > alturaTela)
            {
                pJog1->setY(alturaTela - hitbox.height);
                pJog1->setVel(0);
                pJog1->setVivo(false);
            }

            if (jog1Topo < 0)
            {
                pJog1->setY(0);
            }
        }
    }

    if (pJog2)
    {
        if (pJog2->getVivo())
        {
            sf::FloatRect hitbox = pJog2->getHitbox();

            float jog2Esquerda = hitbox.left;
            float jog2Direita = hitbox.left + hitbox.width;
            float jog2Topo = hitbox.top;
            float jog2Base = hitbox.top + hitbox.height;

            float larguraTela = LARGURA;
            float alturaTela = ALTURA;

            if (jog2Direita > larguraTela)
            {
                pJog2->setX(larguraTela - hitbox.width);
            }

            if (jog2Esquerda < 0)
            {
                pJog2->setX(0 + hitbox.width);
            }

            if (jog2Base > alturaTela)
            {
                pJog2->setY(alturaTela - hitbox.height);
                pJog2->setVel(0);
                pJog2->setVivo(false);
            }

            if (jog2Topo < 0)
            {
                pJog2->setY(0);
            }
        }
    }
}

void Gerenciadores::Colisoes::tratarIniBorda()
{
    std::vector<Entidades::Personagens::Inimigos::Inimigo *>::iterator it;

    for (it = LIs.begin(); it != LIs.end(); it++)
    {
        Entidades::Personagens::Inimigos::Inimigo *inimigo = *it;

        if (inimigo && inimigo->getVivo())
        {
            sf::FloatRect hitbox = inimigo->getHitbox();

            if (hitbox.left < 0)
            {
                inimigo->reverterMovimento();
                inimigo->inverterDirecao();
            }
            else if (hitbox.left + hitbox.width > LARGURA)
            {
                inimigo->reverterMovimento();
                inimigo->inverterDirecao();
            }
            else if (hitbox.top < 0)
            {
                inimigo->setY(0);
            }

            else if (hitbox.top + hitbox.height > ALTURA)
            {
                inimigo->setY(ALTURA - hitbox.height);
                inimigo->setVel(0);
                inimigo->setVivo(false);
            }
        }
    }
}

void Gerenciadores::Colisoes::tratarObsBorda()
{
    std::list<Entidades::Obstaculos::Obstaculo *>::iterator it;

    for (it = LOs.begin(); it != LOs.end(); it++)
    {
        Entidades::Obstaculos::Obstaculo *obstaculo = *it;

        if (obstaculo)
        {
            sf::FloatRect hitbox = obstaculo->getHitbox();

            if (hitbox.top + hitbox.height > ALTURA)
            {
                obstaculo->setY(ALTURA - hitbox.height);
                obstaculo->setVel(0);
            }
        }
    }
}

void Gerenciadores::Colisoes::tratarProBorda()
{
    std::set<Entidades::Projetil *>::iterator it;

    for (it = LPs.begin(); it != LPs.end(); it++)
    {
        Entidades::Projetil *projetil = *it;

        if (projetil && projetil->getAtivo())
        {
            sf::FloatRect hitbox = projetil->getHitbox();

            if (hitbox.left < 0 || hitbox.left + hitbox.width > LARGURA)
            {
                projetil->setAtivo(false);
            }
        }
    }
}

void Gerenciadores::Colisoes::tratarJogJog()
{

    if (pJog1 && pJog2)
    {
        if (pJog1->getVivo() && pJog2->getVivo())
        {
            if (verificarColisao(pJog1, pJog2))
            {
                pJog1->reverterMovimento();
                pJog2->reverterMovimento();
            }
        }
    }
    else
        std::cout << "PONTEIRO NULO!";
}

void Gerenciadores::Colisoes::tratarJogIni()
{
    sf::Clock clock;

    if (pJog1 || pJog2)
    {
        std::vector<Entidades::Personagens::Inimigos::Inimigo *>::iterator it;

        for (it = LIs.begin(); it != LIs.end(); it++)
        {
            Entidades::Personagens::Inimigos::Inimigo *inimigo = *it;

            if (inimigo && inimigo->getVivo())
            {
                if ((pJog1 && pJog1->getVivo()) || (pJog2 && pJog2->getVivo()))
                {
                    if (pJog1 && pJog2 && inimigo->getY() == pJog1->getY() && inimigo->getY() == pJog2->getY())
                    {
                        int distanciaJog1 = std::abs(inimigo->getX() - pJog1->getX());
                        int distanciaJog2 = std::abs(inimigo->getX() - pJog2->getX());

                        if (distanciaJog1 < distanciaJog2 && pJog1->getVivo())
                        {
                            inimigo->localizar(pJog1);
                        }
                        else if (pJog2->getVivo())
                        {
                            inimigo->localizar(pJog2);
                        }
                    }
                    else if (pJog1 && pJog1->getVivo() && inimigo->getY() == pJog1->getY())
                    {
                        inimigo->localizar(pJog1);
                    }
                    else if (pJog2 && pJog2->getVivo() && inimigo->getY() == pJog2->getY())
                    {
                        inimigo->localizar(pJog2);
                    }
                    else
                    {
                        inimigo->setLoc(false);
                    }
                }
                else
                {
                    inimigo->setLoc(false);
                }

                if (pJog1 && verificarColisao(pJog1, inimigo) && pJog1->getVivo())
                {
                    inimigo->danificar(pJog1);
                    if (pJog1->getDir() == 0)
                    {
                        inimigo->reverterMovimento();
                    }
                    else
                    {
                        inimigo->reverterMovimento();
                        pJog1->reverterMovimento();
                    }
                }

                if (pJog2 && verificarColisao(pJog2, inimigo) && pJog2->getVivo())
                {
                    inimigo->danificar(pJog2);
                    if (pJog2->getDir() == 0)
                    {
                        inimigo->reverterMovimento();
                    }
                    else
                    {
                        inimigo->reverterMovimento();
                        pJog2->reverterMovimento();
                    }
                }
            }
        }
    }
}

void Gerenciadores::Colisoes::tratarJogObs()
{
    if (pJog1)
    {
        if (pJog1->getVivo())
        {
            for (auto obstaculo : LOs)
            {
                if (verificarColisao(pJog1, obstaculo))
                { 
                    obstaculo->obstacular(pJog1);
                }
            }
        }
    }

    if (pJog2)
    {
        if (pJog2->getVivo())
        {
            for (auto obstaculo : LOs)
            {
                if (verificarColisao(pJog2, obstaculo))
                {
                    obstaculo->obstacular(pJog2);
                }
            }
        }
    }
}

void Gerenciadores::Colisoes::tratarObsIni()
{
    std::list<Entidades::Obstaculos::Obstaculo *>::iterator itO;
    std::vector<Entidades::Personagens::Inimigos::Inimigo *>::iterator itI;

    for (itO = LOs.begin(); itO != LOs.end(); itO++)
    {
        Entidades::Obstaculos::Obstaculo *obstaculo = *itO;
        sf::FloatRect hitboxObs = obstaculo->getHitbox();

        float obsEsquerda = hitboxObs.left;
        float obsDireita = hitboxObs.left + hitboxObs.width;
        float obsTopo = hitboxObs.top;
        float obsBase = hitboxObs.top + hitboxObs.height;

        for (itI = LIs.begin(); itI != LIs.end(); itI++)
        {
            Entidades::Personagens::Inimigos::Inimigo *inimigo = *itI;

            if (inimigo && inimigo->getVivo())
            {

                sf::FloatRect hitboxIni = inimigo->getHitbox();

                float iniEsquerda = hitboxIni.left;
                float iniDireita = hitboxIni.left + hitboxIni.width;
                float iniTopo = hitboxIni.top;
                float iniBase = hitboxIni.top + hitboxIni.height;

                if (hitboxIni.intersects(hitboxObs) && obstaculo->getTipo() != 6)
                {
                    if (iniBase > obsTopo && iniTopo < obsTopo && iniDireita > obsEsquerda && iniEsquerda < obsDireita)
                    {
                        inimigo->setY(obsTopo - hitboxIni.height);
                        inimigo->setVel(0);
                    }
                    if (obstaculo->getTipo() != 4)
                    {
                        if (iniDireita > obsEsquerda && iniEsquerda < obsEsquerda)
                        {
                            inimigo->reverterMovimento();
                        }
                        else if (iniEsquerda < obsDireita && iniDireita > obsDireita)
                        {
                            inimigo->reverterMovimento();
                        }

                        if (iniTopo < obsBase && iniBase > obsBase)
                        {
                            inimigo->setY(obsBase);
                            inimigo->setVel(0);
                        }
                    }
                }
            }
        }
    }
}

void Gerenciadores::Colisoes::tratarJogPro()
{
    if (pJog1)
    {
        std::set<Entidades::Projetil *>::iterator it;

        for (it = LPs.begin(); it != LPs.end(); it++)
        {
            Entidades::Projetil *projetil = *it;
            if (pJog1->getVivo() && projetil && projetil->getAtivo())
            {
                if (projetil->getDeInimigo())
                {
                    if (verificarColisao(pJog1, projetil))
                    {
                        projetil->acertar(pJog1);
                    }
                }
            }
        }
    }

    if (pJog2)
    {
        std::set<Entidades::Projetil *>::iterator it;

        for (it = LPs.begin(); it != LPs.end(); it++)
        {
            Entidades::Projetil *projetil = *it;

            if (pJog2->getVivo() && projetil && projetil->getAtivo())
            {
                if (projetil->getDeInimigo())
                {
                    if (verificarColisao(pJog2, projetil))
                    {
                        projetil->acertar(pJog2);
                    }
                }
            }
        }
    }
}

void Gerenciadores::Colisoes::tratarProIni()
{
    std::set<Entidades::Projetil *>::iterator itP;
    std::vector<Entidades::Personagens::Inimigos::Inimigo *>::iterator itI;

    for (itP = LPs.begin(); itP != LPs.end(); itP++)
    {
        Entidades::Projetil *projetil = *itP;

        for (itI = LIs.begin(); itI != LIs.end(); itI++)
        {
            Entidades::Personagens::Inimigos::Inimigo *inimigo = *itI;

            if (projetil->getDeInimigo() == false)
            {
                if (projetil->getAtivo() && inimigo->getVivo())
                {
                    if (verificarColisao(projetil, inimigo))
                    {
                        projetil->acertar(inimigo);
                    }
                }
            }
        }
    }
}

void Gerenciadores::Colisoes::tratarProObs()
{
    std::set<Entidades::Projetil *>::iterator itP;
    std::list<Entidades::Obstaculos::Obstaculo *>::iterator itO;

    for (itP = LPs.begin(); itP != LPs.end(); itP++)
    {
        Entidades::Projetil *projetil = *itP;
        if (projetil && projetil->getAtivo())
        {
            for (itO = LOs.begin(); itO != LOs.end(); itO++)
            {
                Entidades::Obstaculos::Obstaculo *obstaculo = *itO;

                if (verificarColisao(projetil, obstaculo))
                {
                    if (obstaculo->getTipo() == 4 && projetil->getY() < obstaculo->getY() + 80)
                    {
                        projetil->setAtivo(false);
                    }
                }
            }
        }
    }
}

void Gerenciadores::Colisoes::tratarObsObs()
{
    std::list<Entidades::Obstaculos::Obstaculo *>::iterator itO;
    std::list<Entidades::Obstaculos::Obstaculo *>::iterator itObs;

    for (itO = LOs.begin(); itO != LOs.end(); itO++)
    {
        Entidades::Obstaculos::Obstaculo *obstaculo1 = *itO;
        sf::FloatRect hitboxOb1 = obstaculo1->getHitbox();

        float obs1Topo = hitboxOb1.top;
        float obs1Base = hitboxOb1.top + hitboxOb1.height;

        for (itObs = LOs.begin(); itObs != LOs.end(); itObs++)
        {
            Entidades::Obstaculos::Obstaculo *obstaculo2 = *itObs;

            if (obstaculo1->getTipo() == 4)
            {
                sf::FloatRect hitboxOb2 = obstaculo2->getHitbox();

                float obs2Topo = hitboxOb2.top;
                float obs2Base = hitboxOb2.top + hitboxOb2.height;

                if (hitboxOb2.intersects(hitboxOb1))
                {
                    if (obs2Base > obs1Topo && obs2Topo < obs1Topo)
                    {
                        obstaculo2->setY(obs1Topo - hitboxOb2.height);
                        obstaculo2->setVel(0);
                    }

                    if (obs2Topo < obs1Base && obs2Base > obs1Base)
                    {
                        if (obstaculo2->getTipo() == 4)
                        {
                            obstaculo2->setY(obs1Base);
                            obstaculo2->setVel(0);
                        }
                    }
                }
            }
        }
    }
}

void Gerenciadores::Colisoes::setJog1(Entidades::Personagens::Jogador *pj1)
{
    if (pj1)
    {
        pJog1 = pj1;
    }
}

void Gerenciadores::Colisoes::setJog2(Entidades::Personagens::Jogador *pj2)
{
    if (pj2)
    {
        pJog2 = pj2;
    }
}

void Gerenciadores::Colisoes::incluirInimigo(Entidades::Personagens::Inimigos::Inimigo *pi)
{
    if (pi)
    {
        LIs.push_back(pi);
    }
    else
        std::cout << "PONTEIRO NULO!";
}

void Gerenciadores::Colisoes::incluirObstaculo(Entidades::Obstaculos::Obstaculo *po)
{
    if (po)
    {
        LOs.push_back(po);
    }
    else
        std::cout << "PONTEIRO NULO!";
}

void Gerenciadores::Colisoes::incluirProjetil(Entidades::Projetil *pp)
{
    LPs.insert(pp);
}

void Gerenciadores::Colisoes::executar()
{
    tratarJogBorda();
    tratarIniBorda();
    tratarProBorda();
    tratarJogIni();
    tratarJogObs();
    tratarObsIni();
    tratarJogPro();
    tratarProIni();
    tratarProObs();
    tratarObsObs();
    tratarObsBorda();
}

void Gerenciadores::Colisoes::limparListas()
{
    LIs.clear();
    LOs.clear();
    LPs.clear();
}