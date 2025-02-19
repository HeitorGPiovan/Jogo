#include "../Includes/fase.hpp"
#include <stdexcept>

Fases::Fase::Fase(int num) : pJog1(NULL),
                             pJog2(NULL),
                             pColisoes(Gerenciadores::Colisoes::getGerenciadorColisoes()),
                             criada(false),
                             numFase(num),
                             maxMelees(1),
                             carregada(false)
{
    if (pGrafico)
    {
        pGrafico->definirTextura("Fim", fim);
    }
}

Fases::Fase::Fase() : pJog1(NULL),
                      pJog2(NULL),
                      pColisoes(Gerenciadores::Colisoes::getGerenciadorColisoes()),
                      criada(false),
                      numFase(1),
                      maxMelees(1)
{
    if (pGrafico)
    {
        pGrafico->definirTextura("Fim", fim);
    }
}

Fases::Fase::~Fase()
{
    LEs->limpar();
    delete LEs;
    LEs = NULL;

    pJog1 = NULL;
    pJog2 = NULL;

    pColisoes = NULL;
}

void Fases::Fase::gerenciar_colisoes()
{
    pColisoes->executar();
}

void Fases::Fase::criarMelee()
{
    int contMelee = 0;

    int numMelees = 3 + (rand() % maxMelees);
    cout << "Melees: " << numMelees << endl;

    for (int i = 0; i < numMelees; i++)
    {
        Entidades::Personagens::Inimigos::Melee *pMelee = new Entidades::Personagens::Inimigos::Melee();
        pColisoes->incluirInimigo(pMelee);

        if (LEs && pMelee)
        {
            LEs->incluir(pMelee);
        }

        contMelee++;

        if (numFase == 1)
        {
            switch (contMelee)
            {
            case 1:

                pMelee->setX(500);
                pMelee->setY(460);
                break;

            case 2:

                pMelee->setX(500);
                pMelee->setY(250);
                break;

            case 3:

                pMelee->setX(800);
                pMelee->setY(180);
                break;

            case 4:

                pMelee->setX(1050);
                pMelee->setY(420);
                break;

            case 5:

                pMelee->setX(500);
                pMelee->setY(10);
                break;

            default:
                break;
            }
        }

        else if (numFase == 2)
        {
            switch (contMelee)
            {
            case 1:

                pMelee->setX(494);
                pMelee->setY(490);
                break;

            case 2:

                pMelee->setX(734);
                pMelee->setY(270);
                break;

            case 3:

                pMelee->setX(494);
                pMelee->setY(40);
                break;

            case 4:

                pMelee->setX(1034);
                pMelee->setY(380);
                break;

            case 5:

                pMelee->setX(200);
                pMelee->setY(100);
                break;

            default:
                break;
            }
        }
    }
}

void Fases::Fase::criarPlat()
{
    int contPlat = 0;
    int numPlataformas = 0;
    bool aleatorioBaixo = rand() % 2;
    maxMelees = 1;

    if (numFase == 1)
    {
        numPlataformas = 8 + (rand() % 4);
    }
    else if (numFase == 2)
    {
        numPlataformas = 9 + (rand() % 3);
    }

    quantPlats = numPlataformas;
    cout << "Plats: " << numPlataformas << endl;

    for (int i = 0; i < numPlataformas; i++)
    {
        Entidades::Obstaculos::Plataforma *pPlat = new Entidades::Obstaculos::Plataforma();
        pColisoes->incluirObstaculo(pPlat);

        if (LEs && pPlat)
        {
            LEs->incluir(pPlat);
        }

        contPlat++;

        if (numFase == 1)
        {
            switch (contPlat)
            {
            case 1:

                pPlat->setX(0);
                pPlat->setY(640);
                pPlat->setTamanho(1);
                break;

            case 2:

                pPlat->setX(350);
                pPlat->setY(560);
                pPlat->setTamanho(2);
                break;

            case 3:

                pPlat->setX(650);
                pPlat->setY(530);
                pPlat->setTamanho(2);
                break;

            case 4:

                pPlat->setX(350);
                pPlat->setY(350);
                pPlat->setTamanho(3);
                break;

            case 5:

                pPlat->setX(950);
                pPlat->setY(510);
                pPlat->setTamanho(2);
                maxMelees = 2;
                break;

            case 6:

                pPlat->setX(650);
                pPlat->setY(260);
                pPlat->setTamanho(3);
                break;

            case 7:

                pPlat->setX(985);
                pPlat->setY(340);
                pPlat->setTamanho(3);
                break;

            case 8:

                pPlat->setX(1020);
                pPlat->setY(100);
                pPlat->setTamanho(3);
                break;

            case 9:
                pPlat->setX(0);
                pPlat->setY(270);
                pPlat->setTamanho(4);

                maxMelees = 2;
                break;

            case 10:

                pPlat->setX(350);
                pPlat->setY(100);
                pPlat->setTamanho(3);
                maxMelees = 3;
                break;

            case 11:

                pPlat->setX(0);
                pPlat->setY(110);
                pPlat->setTamanho(3);
                maxMelees = 3;
                break;

            default:
                maxMelees = 1;
                break;
            }
        }
        else if (numFase == 2)
        {
            switch (contPlat)
            {
            case 1:

                pPlat->setX(100);
                pPlat->setY(650);
                pPlat->setTamanho(1);
                break;

            case 2:

                pPlat->setX(400);
                pPlat->setY(560);
                pPlat->setTamanho(2);

                break;

            case 3:

                pPlat->setX(640);
                pPlat->setY(560);
                pPlat->setTamanho(2);
                break;

            case 4:

                pPlat->setX(400);
                pPlat->setY(340);
                pPlat->setTamanho(3);
                break;

            case 5:

                pPlat->setX(640);
                pPlat->setY(340);
                pPlat->setTamanho(3);
                break;

            case 6:

                pPlat->setX(400);
                pPlat->setY(120);
                pPlat->setTamanho(3);
                break;

            case 7:

                pPlat->setX(640);
                pPlat->setY(120);
                pPlat->setTamanho(3);
                break;

            case 8:

                if (aleatorioBaixo)
                {
                    pPlat->setX(65); // esquerda
                    pPlat->setY(430);
                    pPlat->setTamanho(3);
                }
                else
                {
                    pPlat->setX(995); // direita
                    pPlat->setY(430);
                    pPlat->setTamanho(4);
                    maxMelees = 2;
                }

                break;

            case 9:

                if (aleatorioBaixo)
                {
                    pPlat->setX(30); // esquerda
                    pPlat->setY(110);
                    pPlat->setTamanho(3);

                    maxMelees = 2;
                }
                else
                {
                    pPlat->setX(1030); // direita
                    pPlat->setY(110);
                    pPlat->setTamanho(3);
                }
                break;

            case 10:

                if (aleatorioBaixo)
                {
                    pPlat->setX(995); // direita
                    pPlat->setY(430);
                    pPlat->setTamanho(4);
                }
                else
                {
                    pPlat->setX(65); // esquerda
                    pPlat->setY(430);
                    pPlat->setTamanho(3);
                }
                maxMelees = 2;
                break;

            case 11:

                if (aleatorioBaixo)
                {
                    pPlat->setX(1030); // direita
                    pPlat->setY(110);
                    pPlat->setTamanho(3);
                }
                else
                {
                    pPlat->setX(30); // esquerda
                    pPlat->setY(110);
                    pPlat->setTamanho(3);
                }

                maxMelees = 3;
                break;

            default:
                break;
            }
        }
    }
}

void Fases::Fase::executar()
{
    desenhar();
    pGrafico->desenharElemento(fim);
    checarFim();
    gerenciar_colisoes();
    LEs->percorrer();
}

void Fases::Fase::criarCenario()
{
    std::cout << "Criando cenario aleatorio" << std::endl;
    pColisoes->limparListas();
    LEs->limpar();

    if (numFase == 1)
    {
        fim.setPosition(1100, 70);
    }
    else if (numFase == 2)
    {
        fim.setPosition(615, 69); 
    }
    carregada = false;
    pGrafico->desenharElemento(fim);
    criarJogadores();
    criarPlat();
    criarMelee();
    criarObstaculos();
    criarInimigos();
    criarProjeteis();
    setCriada(true);
}

void Fases::Fase::criarProjeteis()
{
    if (LEs)
    {
        Listas::Iterador<Entidades::Entidade> *iterador = LEs->criarIterador();

        while (!iterador->fim())
        {
            Entidades::Entidade *entidade = iterador->obterProximo();

            if (entidade)
            {
                Entidades::Personagens::Personagem *personagem = dynamic_cast<Entidades::Personagens::Personagem *>(entidade);

                if (personagem)
                {
                    if (personagem->getTipo() == 0 || personagem->getTipo() == 2 || personagem->getTipo() == 3)
                    {
                        LEs->incluir(personagem->getTiro());
                        pColisoes->incluirProjetil(personagem->getTiro());
                    }
                }
            }
        }
        delete iterador;
    }
}

void Fases::Fase::setJog(Entidades::Personagens::Jogador *pj1)
{
    pJog1 = pj1;
    pJog2 = NULL;
}

void Fases::Fase::setJog(Entidades::Personagens::Jogador *pj1, Entidades::Personagens::Jogador *pj2)
{
    pJog1 = pj1;
    pJog2 = pj2;
}

const bool Fases::Fase::getCriada() const
{
    return criada;
}

void Fases::Fase::setCriada(const bool situacao)
{
    criada = situacao;
}

const int Fases::Fase::getNumFase() const
{
    return numFase;
}

void Fases::Fase::setNumFase(const int fase)
{
    numFase = fase;
}

const int Fases::Fase::getQuantPlats() const
{
    return quantPlats;
}

void Fases::Fase::checarFim()
{
    sf::FloatRect hitboxJog1 = pJog1->getHitbox();
    sf::FloatRect hitboxJog2 = (pJog2 ? pJog2->getHitbox() : sf::FloatRect());
    sf::FloatRect hitboxFim = fim.getGlobalBounds();

    if ((hitboxJog1.intersects(hitboxFim)) || (pJog2 && hitboxJog2.intersects(hitboxFim)))
    {
        Listas::Iterador<Entidades::Entidade> *iterador = LEs->criarIterador();

        if (getNumFase() == 1)
        {
            pJog1->setPontos(pJog1->getPontos() - pJog1->getPts1());
            pJog1->setPts1(0);
        }
        else if (getNumFase() == 2)
        {
            pJog1->setPontos(pJog1->getPontos() - pJog1->getPts2());
            pJog1->setPts2(0);
        }

        while (!iterador->fim())
        {
            Entidades::Entidade *entidadeAtual = iterador->obterAtual();
            Entidades::Personagens::Inimigos::Inimigo *inimigo = dynamic_cast<Entidades::Personagens::Inimigos::Inimigo *>(entidadeAtual);

            if (inimigo && !inimigo->getVivo())
            {
                if (getNumFase() == 1)
                {
                    if (inimigo->getTipo() == 1)
                    {
                        pJog1->setPts1(pJog1->getPts1() + 5);
                    }
                    else if (inimigo->getTipo() == 2)
                    {
                        pJog1->setPts1(pJog1->getPts1() + 10);
                    }
                }
                else if (getNumFase() == 2)
                {
                    if (inimigo->getTipo() == 1)
                    {
                        pJog1->setPts2(pJog1->getPts2() + 5);
                    }
                    else if (inimigo->getTipo() == 3)
                    {
                        pJog1->setPts2(pJog1->getPts2() + 20);
                    }
                }
            }

            iterador->proximo();
        }

        if (getNumFase() == 1)
        {
            pJog1->setPontos(pJog1->getPontos() + pJog1->getPts1());
        }
        else if (getNumFase() == 2)
        {
            pJog1->setPontos(pJog1->getPontos() + pJog1->getPts2());
        }

        delete iterador;

        setCriada(false);
        numFase++;

        LEs->limpar();
    }
    else if ((pJog1 && !pJog1->getVivo()) && (!pJog2 || !pJog2->getVivo()))
    {
        setCriada(false);
        setNumFase(3);
    }
}

void Fases::Fase::salvarEntidades()
{
    if (std::remove("salvamento.json") != 0)
    {
        std::cerr << "Erro ao excluir o arquivo de salvamento ou arquivo não existente." << std::endl;
    }

    if (LEs)
    {
        LEs->salvarEntidades();
    }
    else
    {
        std::cerr << "Lista de entidades não inicializada." << std::endl;
    }
}

void Fases::Fase::carregarCenario(const std::string &caminhoArquivo)
{
    try
    {
        std::ifstream arquivo(caminhoArquivo);
        if (!arquivo.is_open())
        {
            throw std::runtime_error("Não foi possível abrir o arquivo JSON.");
        }
        json dados;
        arquivo >> dados;

        for (const auto &entidade : dados)
        {
            int tipo = entidade["tipo"].get<int>();
            Entidades::Entidade *novaEntidade = nullptr;

            switch (tipo)
            {

            case 1: // Melee
            {
                auto *pMelee = new Entidades::Personagens::Inimigos::Melee();
                pMelee->setX(entidade["x"].get<float>());
                pMelee->setY((entidade["y"].get<float>()));
                pMelee->setTipo(tipo);
                pMelee->setDano(entidade["dano"].get<float>());
                pMelee->setDir(entidade["direcao"].get<int>());
                pMelee->setLoc(entidade["localizou"].get<bool>());
                pMelee->setVida(entidade["num_vidas"].get<int>());
                pMelee->setResistencia(entidade["resistencia"].get<float>());
                pMelee->setVel(entidade["velocidadeVertical"].get<float>());
                pMelee->setVivo(entidade["vivo"].get<bool>());

                pColisoes->incluirInimigo(pMelee);
                novaEntidade = pMelee;
                break;
            }
            case 2: // Atirador
            {
                auto *atirador = new Entidades::Personagens::Inimigos::Atirador();
                atirador->setID(entidade["ID"].get<int>());
                atirador->setCoice(entidade["coice"].get<int>());
                atirador->setTipo(tipo);
                atirador->setDano(entidade["dano"].get<int>());
                atirador->setDir(entidade["direcao"].get<int>());
                atirador->setLoc(entidade["localizou"].get<int>());
                atirador->setVida(entidade["num_vidas"].get<int>());
                atirador->setVel(entidade["velocidadeVertical"].get<float>());
                atirador->setVivo(entidade["vivo"].get<bool>());
                atirador->setX(entidade["x"].get<float>());
                atirador->setY((entidade["y"].get<float>()));

                pColisoes->incluirInimigo(atirador);
                novaEntidade = atirador;
                break;
            }
            case 3: // Tanque
            {
                auto *pTanque = new Entidades::Personagens::Inimigos::Tanque();
                pTanque->setID(entidade["ID"].get<int>());
                pTanque->setDano(entidade["dano"].get<int>());
                pTanque->setDir(entidade["direcao"].get<int>());
                pTanque->setLoc(entidade["localizou"].get<bool>());
                pTanque->setVida(entidade["num_vidas"].get<int>());
                pTanque->setPotencia(entidade["potencia"].get<int>());
                pTanque->setTipo(tipo);
                pTanque->setVel(entidade["velocidadeVertical"].get<float>());
                pTanque->setVivo(entidade["vivo"].get<bool>());
                pTanque->setX(entidade["x"].get<float>());
                pTanque->setY((entidade["y"].get<float>()));

                pColisoes->incluirInimigo(pTanque);
                novaEntidade = pTanque;
                break;
            }
            case 4: // Plataforma
            {
                auto *plataforma = new Entidades::Obstaculos::Plataforma();
                plataforma->setID(entidade["ID"].get<int>());
                plataforma->setDan(entidade["danoso"].get<bool>());
                plataforma->setTipo(tipo);
                plataforma->setDir(entidade["direcao"].get<int>());
                plataforma->setTamanho(entidade["tamanho"].get<int>());
                plataforma->setVel(entidade["velocidadeVertical"].get<float>());
                plataforma->setX(entidade["x"].get<float>());
                plataforma->setY((entidade["y"].get<float>()));

                pColisoes->incluirObstaculo(plataforma);
                novaEntidade = plataforma;
                break;
            }
            case 5: // Arame
            {
                auto *pArame = new Entidades::Obstaculos::Arame_Farpado();
                pArame->setID(entidade["ID"].get<int>());
                pArame->setDan(entidade["danoso"].get<bool>());
                pArame->setTipo(tipo);
                pArame->setDir(entidade["direcao"].get<int>());
                pArame->setPerfuracao(entidade["perfuracao"].get<int>());
                pArame->setVel(entidade["velocidadeVertical"].get<float>());
                pArame->setX(entidade["x"].get<float>());
                pArame->setY((entidade["y"].get<float>()));

                pColisoes->incluirObstaculo(pArame);
                novaEntidade = pArame;
                break;
            }
            case 6: // Fosso
            {
                auto *pFosso = new Entidades::Obstaculos::Fosso();
                pFosso->setID(entidade["ID"].get<int>());
                pFosso->setDan(entidade["danoso"].get<bool>());
                pFosso->setDir(entidade["direcao"].get<int>());
                pFosso->setGrande(entidade["grande"].get<bool>());
                pFosso->setTipo(tipo);
                pFosso->setVel(entidade["velocidadeVertical"].get<float>());
                pFosso->setX(entidade["x"].get<float>());
                pFosso->setY((entidade["y"].get<float>()));

                pColisoes->incluirObstaculo(pFosso);
                novaEntidade = pFosso;
                break;
            }
            case 7: // Projetil
            {
                auto *pProjetil = new Entidades::Projetil();
                pProjetil->setID(entidade["ID"].get<int>());
                pProjetil->setAtivo(entidade["ativo"].get<bool>());
                pProjetil->setDeInimigo(entidade["deInimigo"].get<bool>());
                pProjetil->setDano(entidade["dano"].get<int>());
                pProjetil->setDir(entidade["direcao"].get<int>());
                pProjetil->setTipo(tipo);
                pProjetil->setVel(entidade["velocidadeVertical"].get<float>());
                pProjetil->setX(entidade["x"].get<float>());
                pProjetil->setY(entidade["y"].get<float>());

                pColisoes->incluirProjetil(pProjetil);
                novaEntidade = pProjetil;
                break;
            }
            default:
                break;
            }

            if (novaEntidade && LEs)
            {
                LEs->incluir(novaEntidade);
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro ao carregar cenário: " << e.what() << std::endl;
    }
}

void Fases::Fase::criarCenarioCarregado()
{
    std::cout << "Criando cenario carregado" << std::endl;
    pColisoes->limparListas();
    LEs->limpar();
    std::string caminhoArquivo = "salvamento.json";
    carregarCenario(caminhoArquivo);

    if (numFase == 1)
    {
        fim.setPosition(1095, 69);
    }
    else if (numFase == 2)
    {
        fim.setPosition(615, 69);
    }
    carregada = true;
    pGrafico->desenharElemento(fim);
    setCriada(true);
    criarJogadores();
    criarProjeteis();
}