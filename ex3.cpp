#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
À partir de uma lista de nomes disponível em um arquivo TXT, transforma-los em nomes no formato agenda telefônica. Exemplo:

José Antonio Santos Silva
Silva, José Antonio Santos
*/

int main(int argc, char** argv) {
    ifstream arquivoEntrada("nomes.txt");
    if (!arquivoEntrada.is_open()) {
        cout << "Erro ao abrir o arquivo de entrada." << endl;
        return 1;
    }

    ofstream arquivoSaida("nomes_formatados.txt", ios::app);
    if (!arquivoSaida.is_open()) {
        cout << "Erro ao abrir ou criar o arquivo de saída." << endl;
        return 1;
    }

    // Ler os nomes do arquivo de entrada e transformá-los
    string nome;
    while (getline(arquivoEntrada, nome)) {
        // Encontra o último espaço para separar o último sobrenome
        size_t posUltimoEspaco = nome.find_last_of(' ');
        if (posUltimoEspaco == string::npos) {
            // Se não encontrar espaço, escreve o nome original no arquivo de saída
            arquivoSaida << nome << endl;
        } else {
            // Obtém o último sobrenome e o resto do nome
            string ultimoSobrenome = nome.substr(posUltimoEspaco + 1);
            string restoNome = nome.substr(0, posUltimoEspaco);

            // Formata o nome no formato "Último Sobrenome, Resto do nome"
            string nomeFormatado = ultimoSobrenome + ", " + restoNome;

            // Escreve o nome formatado no arquivo de saída
            arquivoSaida << nomeFormatado << endl;
        }
    }

    arquivoEntrada.close();
    arquivoSaida.close();

    cout << "Nomes formatados com sucesso!" << endl;

    return 0;
}
