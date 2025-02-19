#include "dia.hpp"
#include <filesystem>

Dia::Dia() : pGrafico(Gerenciadores::Grafico::getGerenciadorGrafico()),
             pEventos(Gerenciadores::Eventos::getGerenciadorEventos()),
             pColisoes(Gerenciadores::Colisoes::getGerenciadorColisoes()),
             opcao(-1),
             ultimaOpcao(-1)
{
    if (std::filesystem::exists("ranking.txt"))
    {
        recuperarRanking();
    }

    pColisoes->setJog1(&Jog1);
    pColisoes->setJog2(&Jog2);
    pEventos->setJog1(&Jog1);
    pEventos->setJog2(&Jog2);
    pMenu = new Menu(this);
    executar();
}

Dia::~Dia()
{
    salvarRanking();

    for (auto jogador : ranking)
    {
        delete jogador;
    }
    ranking.clear();

    delete pMenu;
}

void Dia::executar()
{
    if (pGrafico && pEventos && pColisoes)
    {
        while (pGrafico->verificaJanelaAberta())
        {
            if (pMenu->getMenu() == 1)
            {
                pGrafico->limparJanela();
                execucaoPrincipal();
            }
            else if (pMenu->getMenu() == 2)
            {
                pGrafico->limparJanela();
                execucaoPausa();
            }
            else if (pMenu->getMenu() == 3)
            {
                pGrafico->limparJanela();
                execucaoRanking();
            }
            else if (pMenu->getMenu() == 4)
            {
                Jog1.setPontos(0);
                Jog1.setPts1(0);
                Jog1.setPts2(0);
                pGrafico->limparJanela();
                execucaoNome();
            }

            pEventos->executar();
        }
    }
}

void Dia::setOpcao(int selecionado)
{
    opcao = selecionado;
}

const int Dia::getOpcao() const
{
    return opcao;
}

void Dia::setUltOpcao(int selecionado)
{
    ultimaOpcao = selecionado;
}

const int Dia::getUltOpcao() const
{
    return ultimaOpcao;
}

const bool Dia::jogoEmExecucao() const
{
    if (opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Dia::execucaoPrincipal()
{
    switch (getOpcao())
    {
    case (1):
        pGrafico->limparJanela();
        if (!praia.getCriada())
        {
            praia.setNumFase(1);
            praia.setJog(&Jog1);
            praia.criarCenario();
        }

        praia.executar();

        if (praia.getNumFase() == 2)
        {
            incluirRanking(&Jog1);
            praia.setCriada(false);
            setOpcao(3);
        }
        else if (praia.getNumFase() == 3)
        {
            praia.setCriada(false);
            setOpcao(-1);
        }

        pGrafico->mostrarElementos();
        setUltOpcao(1);
        break;

    case (2):
        pGrafico->limparJanela();
        if (!praia.getCriada())
        {
            praia.setNumFase(1);
            praia.setJog(&Jog1, &Jog2);
            praia.criarCenario();
        }

        praia.executar();

        if (praia.getNumFase() == 2)
        {
            incluirRanking(&Jog1);
            praia.setCriada(false);
            setOpcao(4);
        }
        else if (praia.getNumFase() == 3)
        {
            praia.setCriada(false);
            setOpcao(-1);
        }

        pGrafico->mostrarElementos();
        setUltOpcao(2);
        break;

    case (3):
        pGrafico->limparJanela();
        if (!trincheira.getCriada())
        {
            trincheira.setNumFase(2);
            trincheira.setJog(&Jog1);
            trincheira.criarCenario();
        }

        trincheira.executar();

        if (trincheira.getNumFase() > 2)
        {
            if (Jog1.getVivo())
                incluirRanking(&Jog1);

            trincheira.setCriada(false);
            setOpcao(-1);
        }

        pGrafico->mostrarElementos();
        setUltOpcao(3);
        break;

    case (4):
        pGrafico->limparJanela();
        if (!trincheira.getCriada())
        {
            trincheira.setNumFase(2);
            trincheira.setJog(&Jog1, &Jog2);
            trincheira.criarCenario();
        }

        trincheira.executar();

        if (trincheira.getNumFase() > 2)
        {
            if (Jog1.getVivo() || Jog2.getVivo())
                incluirRanking(&Jog1);

            trincheira.setCriada(false);
            setOpcao(-1);
        }

        pGrafico->mostrarElementos();
        setUltOpcao(4);
        break;

    case (5): // Carregar
    {
        int fase = verificarCenario();
        praia.setNumFase(1);
        trincheira.setNumFase(2);

        if (fase == 1)
        {
            praia.setJog(&Jog1);
            praia.criarCenarioCarregado();
            praia.setNumFase(1);
            opcao = 1;
        }
        else if (fase == 2)
        {
            praia.setJog(&Jog1, &Jog2);
            praia.criarCenarioCarregado();
            praia.setNumFase(1);
            opcao = 2;
        }
        else if (fase == 3)
        {
            trincheira.setJog(&Jog1);
            trincheira.criarCenarioCarregado();
            trincheira.setNumFase(2);
            opcao = 3;
        }
        else if (fase == 4)
        {
            trincheira.setJog(&Jog1, &Jog2);
            trincheira.criarCenarioCarregado();
            trincheira.setNumFase(2);
            opcao = 4;
        }
        break;
    }

    case (6): // Ranking
        pMenu->setMenu(3);
        setOpcao(-1);
        break;

    default:
        pMenu->executar();
        break;
    }
}

void Dia::execucaoPausa()
{
    switch (getOpcao())
    {
    case (1):
        // Continuar
        setOpcao(ultimaOpcao);
        pMenu->setMenu(1);
        //cout << "Selecionado continuar" << endl;
        break;

    case (2):
        // Salvar
        if (praia.getCriada())
        {
            praia.salvarEntidades();
            incluirRanking(&Jog1);
            cout << "Todas as entidades foram salvas" << endl;
        }
        else if (trincheira.getCriada())
        {
            trincheira.salvarEntidades();
            incluirRanking(&Jog1);
            cout << "Todas as entidades foram salvas" << endl;
        }

        salvarRanking();

        setOpcao(-1);
        break;

    case (3):
        // Cadastrar Nome
        if (pMenu->getMenu() != 4)
        {
            pMenu->setMenu(4);
            setOpcao(-1);
            pMenu->setBotao(1);
        }
        break;

    case (4):
        // Sair
        if (pMenu->getMenu() != 1)
        {
            pMenu->setMenu(1);
            setOpcao(-1);
            praia.setCriada(false);
            trincheira.setCriada(false);
            pMenu->setBotao(1);
        }
        break;

    default:
        pMenu->executar();
        break;
    }
}

void Dia::execucaoRanking()
{
    switch (getOpcao())
    {
    case (1):
        setOpcao(-1);
        break;
    case (2):
        setOpcao(-1);
        break;
    case (3):
        setOpcao(-1);
        break;
    case (4):
        setOpcao(-1);
        break;
    case (5):
        setOpcao(-1);
        break;
    case (6):
        break;
    case (7):
        setOpcao(-1);
        break;
    case (8):
        setOpcao(-1);
        break;
    case (9):
        if (pMenu->getMenu() != 1)
        {
            pMenu->setMenu(1);
            setOpcao(-1);
            pMenu->setBotao(1);
        }
        break;

    default:
        pMenu->executar();
        break;
    }
}

void Dia::execucaoNome()
{
    switch (getOpcao())
    {

    case (1):
        setOpcao(-1);
        break;

    case (2):
        if (pMenu->getMenu() != 2)
        {
            pMenu->setMenu(2);
            setOpcao(-1);
            pMenu->setBotao(1);
        }
        break;

    default:
        pMenu->executar();
        break;
    }
}

int Dia::verificarCenario()
{
    std::ifstream arquivo("salvamento.json");
    int fase = 0;
    int numJogadores = 0;
    bool encontrouTipo2ou5 = false;
    bool encontrouTipo3ou6 = false;

    if (arquivo.is_open())
    {
        nlohmann::json dados;
        arquivo >> dados;

        for (const auto &entidade : dados)
        {
            try
            {
                int tipo = entidade["tipo"].get<int>();

                if (tipo == 0) // Jogador
                {
                    bool ehJog2 = entidade["ehJog2"].get<bool>();

                    if (!ehJog2)
                    {
                        Jog1.setID(entidade["ID"].get<int>());
                        Jog1.setDir(entidade["direcao"].get<int>());
                        Jog1.setEhJog2(entidade["ehJog2"].get<bool>());
                        Jog1.setEmSolo(entidade["emSolo"].get<bool>());
                        Jog1.setNome(entidade["nome"].get<std::string>());
                        Jog1.setVida(entidade["num_vidas"].get<int>());
                        Jog1.setPontos(entidade["pontos"].get<int>());
                        Jog1.setTipo(tipo);
                        Jog1.setVel(entidade["velocidadeVertical"].get<float>());
                        Jog1.setVivo(entidade["vivo"].get<bool>());
                        Jog1.setX(entidade["x"].get<float>());
                        Jog1.setY(entidade["y"].get<float>());
                    }
                    else
                    {
                        Jog2.setID(entidade["ID"].get<int>());
                        Jog2.setDir(entidade["direcao"].get<int>());
                        Jog2.setEhJog2(entidade["ehJog2"].get<bool>());
                        Jog2.setEmSolo(entidade["emSolo"].get<bool>());
                        Jog2.setNome(entidade["nome"].get<std::string>());
                        Jog2.setVida(entidade["num_vidas"].get<int>());
                        Jog2.setPontos(entidade["pontos"].get<int>());
                        Jog2.setTipo(tipo);
                        Jog2.setVel(entidade["velocidadeVertical"].get<float>());
                        Jog2.setVivo(entidade["vivo"].get<bool>());
                        Jog2.setX(entidade["x"].get<float>());
                        Jog2.setY(entidade["y"].get<float>());
                    }

                    numJogadores++;
                }
                else if (tipo == 2 || tipo == 5) // Entidades relacionadas à praia
                {
                    encontrouTipo2ou5 = true;
                }
                else if (tipo == 3 || tipo == 6) // Entidades relacionadas à trincheira
                {
                    encontrouTipo3ou6 = true;
                }
            }
            catch (nlohmann::json::type_error &e)
            {
                std::cerr << "Erro ao ler tipo da entidade: " << e.what() << std::endl;
                continue;
            }
            catch (nlohmann::json::out_of_range &e)
            {
                std::cerr << "Erro ao acessar atributo de jogador: " << e.what() << std::endl;
                continue;
            }
        }

        arquivo.close();

        if (encontrouTipo2ou5 && numJogadores == 1)
        {
            fase = 1;
        }
        else if (encontrouTipo2ou5 && numJogadores == 2)
        {
            fase = 2;
        }
        else if (encontrouTipo3ou6 && numJogadores == 1)
        {
            fase = 3;
        }
        else if (encontrouTipo3ou6 && numJogadores == 2)
        {
            fase = 4;
        }
    }

    return fase;
}

void Dia::incluirRanking(Entidades::Personagens::Jogador *jogador)
{
    auto it = ranking.begin();

    while (it != ranking.end())
    {
        if ((*it)->getNome() == jogador->getNome())
        {
            (*it)->setPontos(jogador->getPontos());
            return;
        }

        it++;
    }
    
    Entidades::Personagens::Jogador* jog = new Entidades::Personagens::Jogador;

    jog->setNome(jogador->getNome());
    jog->setPontos(jogador->getPontos());

    ranking.insert(jog);

    //jogador->setPontos(0);
}

void Dia::salvarRanking()
{
    FILE *arq;
    try
    {
        arq = fopen("ranking.txt", "w");

        if (arq == nullptr)
        {
            throw std::ios_base::failure("Não foi possível abrir o arquivo para escrita.");
        }

        for (const auto &jogador : ranking)
        {
            if (jogador)
            {
                fprintf(arq, "%s,%d\n", jogador->getNome().c_str(), jogador->getPontos());
            }
        }

        fclose(arq);
    }
    catch (const std::ios_base::failure &e)
    {
        std::cerr << "Erro ao manipular arquivo: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro inesperado ao salvar ranking: " << e.what() << std::endl;
    }
}

void Dia::recuperarRanking()
{
    FILE *arq;
    try
    {
        arq = fopen("ranking.txt", "r");

        if (arq == nullptr)
        {
            throw std::ios_base::failure("Não foi possível abrir o arquivo para leitura.");
        }

        char linha[256];
        while (fgets(linha, sizeof(linha), arq))
        {
            try
            {
                char nome[100];
                int pontos;

                if (sscanf(linha, "%99[^,],%d", nome, &pontos) == 2)
                {
                    auto novoJogador = new Entidades::Personagens::Jogador();
                    novoJogador->setNome(std::string(nome));
                    novoJogador->setPontos(pontos);
                    ranking.insert(novoJogador);
                }
                else
                {
                    throw std::runtime_error("Formato inválido na linha do arquivo: " + std::string(linha));
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << "Erro ao processar linha do arquivo: " << e.what() << std::endl;
                continue;
            }
        }

        fclose(arq);
    }
    catch (const std::ios_base::failure &e)
    {
        std::cerr << "Erro ao manipular arquivo: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro inesperado ao recuperar ranking: " << e.what() << std::endl;
    }
}

string Dia::acessarRanking(long long unsigned int posicao)
{
    if (posicao < ranking.size())
    {
        auto it = ranking.begin();
        if (*it)
        {
            std::advance(it, posicao);
            string colocado = (*it)->getNome() + " - " + to_string((*it)->getPontos());
            return colocado;
        }
        else
        {
            cout << "PONTEIRO NULO";
        }
    }
    return " - ";
}

string Dia::acessarNome()
{
    return Jog1.getNome();
}