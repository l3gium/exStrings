#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/*
À partir de uma lista de nomes disponível em um arquivo TXT, transforma-los em nomes no formato citação bibliográfica. Exemplo:

José Antonio Santos Silva
SILVA, José A. S.
*/

int main() {
    // Função para transformar um nome no formato de citação bibliográfica
    auto transformarNome = [](const string& nome) -> string {
        string nomeFormatado;
        istringstream ss(nome);
        string parte;
        vector<string> partes;

        // Divide o nome em partes separadas por espaços
        while (ss >> parte) {
            partes.push_back(parte);
        }

        // Adiciona o último sobrenome em maiúsculas seguido por vírgula
        string ultimoSobrenome = partes.back();
        for (char& c : ultimoSobrenome) {
            c = toupper(c);
        }
        nomeFormatado += ultimoSobrenome + ", ";

        // Adiciona o primeiro nome sem abreviação
        nomeFormatado += partes.front();
        nomeFormatado[0] = toupper(nomeFormatado[0]); // Primeira letra do primeiro nome em maiúscula
        nomeFormatado += " ";

        // Adiciona as iniciais abreviadas dos sobrenomes do meio
        for (size_t i = 1; i < partes.size() - 1; ++i) {
            nomeFormatado += toupper(partes[i][0]);
            nomeFormatado += ". ";
        }

        return nomeFormatado;
        };

    ifstream arquivoEntrada("nomes.txt");
    if (!arquivoEntrada.is_open()) {
        cout << "Erro ao abrir o arquivo de entrada." << endl;
        return 1;
    }

    ofstream arquivoSaida("nomes_formatados.txt");
    if (!arquivoSaida.is_open()) {
        cout << "Erro ao criar o arquivo de saída." << endl;
        return 1;
    }

    // Ler os nomes do arquivo de entrada e transformá-los
    string nome;
    while (getline(arquivoEntrada, nome)) {
        // Transforma o nome no formato de citação bibliográfica
        string nomeFormatado = transformarNome(nome);
        // Escreve o nome formatado no arquivo de saída
        arquivoSaida << nomeFormatado << endl;
    }

    arquivoEntrada.close();
    arquivoSaida.close();

    cout << "Nomes formatados com sucesso!" << endl;

    return 0;
}
