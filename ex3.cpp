#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
� partir de uma lista de nomes dispon�vel em um arquivo TXT, transforma-los em nomes no formato agenda telef�nica. Exemplo:

Jos� Antonio Santos Silva
Silva, Jos� Antonio Santos
*/

int main(int argc, char** argv) {
    ifstream arquivoEntrada("nomes.txt");
    if (!arquivoEntrada.is_open()) {
        cout << "Erro ao abrir o arquivo de entrada." << endl;
        return 1;
    }

    ofstream arquivoSaida("nomes_formatados.txt", ios::app);
    if (!arquivoSaida.is_open()) {
        cout << "Erro ao abrir ou criar o arquivo de sa�da." << endl;
        return 1;
    }

    // Ler os nomes do arquivo de entrada e transform�-los
    string nome;
    while (getline(arquivoEntrada, nome)) {
        // Encontra o �ltimo espa�o para separar o �ltimo sobrenome
        size_t posUltimoEspaco = nome.find_last_of(' ');
        if (posUltimoEspaco == string::npos) {
            // Se n�o encontrar espa�o, escreve o nome original no arquivo de sa�da
            arquivoSaida << nome << endl;
        } else {
            // Obt�m o �ltimo sobrenome e o resto do nome
            string ultimoSobrenome = nome.substr(posUltimoEspaco + 1);
            string restoNome = nome.substr(0, posUltimoEspaco);

            // Formata o nome no formato "�ltimo Sobrenome, Resto do nome"
            string nomeFormatado = ultimoSobrenome + ", " + restoNome;

            // Escreve o nome formatado no arquivo de sa�da
            arquivoSaida << nomeFormatado << endl;
        }
    }

    arquivoEntrada.close();
    arquivoSaida.close();

    cout << "Nomes formatados com sucesso!" << endl;

    return 0;
}
