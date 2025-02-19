#include "../Includes/entidade.hpp"


Entidades::Entidade::Entidade(int dir, int x, int y) : Ente(),
                                                       tipo(0),
                                                       x(x),
                                                       y(y),
                                                       direcao(dir),
                                                       velocidadeVertical(0),
                                                       gravidade(0.005f)

{
}

Entidades::Entidade::~Entidade()
{
}

void Entidades::Entidade::salvarDataBuffer(nlohmann::json &j)
{
    j["ID"] = ID;
    j["tipo"] = tipo;
    j["x"] = x;
    j["y"] = y;
    j["direcao"] = direcao;
    j["velocidadeVertical"] = velocidadeVertical;
}

void Entidades::Entidade::setY(const int PosY)
{
    y = PosY;
    sprite.setPosition(x, y);
}
void Entidades::Entidade::setX(const int PosX)
{
    x = PosX;
    sprite.setPosition(x, y);
}

const int Entidades::Entidade::getX() const
{
    return x;
}

const int Entidades::Entidade::getY() const
{
    return y;
}

void Entidades::Entidade::setDir(const int dir)
{
    direcao = dir;
}

const int Entidades::Entidade::getDir() const
{
    return direcao;
}

void Entidades::Entidade::atualizarGravidade()
{
    velocidadeVertical += gravidade;
    y += velocidadeVertical;
}

void Entidades::Entidade::setVel(const float vel)
{
    velocidadeVertical = vel;
}

void Entidades::Entidade::setTipo(const int NovoTipo)
{
    tipo = NovoTipo;
}

const float Entidades::Entidade::getVel() const
{
    return velocidadeVertical;
}

const int Entidades::Entidade::getTipo() const
{
    return tipo;
}

void Entidades::Entidade::exportarParaArquivo(const std::string &nomeArquivo, const nlohmann::json &dados_json)
{
    std::ifstream inputFile(nomeArquivo);
    nlohmann::json existingData;

    if (inputFile.is_open())
    {
        inputFile >> existingData;
        inputFile.close();
    }
    else
    {
        existingData = nlohmann::json::object(); 
    }

    if (dados_json.contains("ID"))
    {
        int id = dados_json["ID"];

        existingData[std::to_string(id)] = dados_json; 

        std::ofstream outputFile(nomeArquivo, std::ios::out);
        if (!outputFile.is_open())
        {
            std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << std::endl;
            return;
        }

        outputFile << existingData.dump(4) << std::endl;
        outputFile.close();
    }
    else
    {
        std::cerr << "A chave 'ID' não foi encontrada no JSON." << std::endl;
    }
}


