#include <iostream>
#include <string>
#include <locale.h>
using namespace std;

/*
Receber através de digitação uma mensagem. 

Informar se esta mensagem é ou não um dado palíndromo (no caso de haver espaços no texto, desconsiderá-los para a verificação). Exemplos:

OVO
ARARA
SOCORRAM ME SUBI NO ONIBUS EM MARROCOS
*/

int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "");
	
    string mensagem;
    cout << "Digite uma mensagem para verificar se é um palindromo: ";
    getline(cin, mensagem);

    
    string textoSemEspacos;
    for (char c : mensagem) {
        if (!is
		space(c)) {
            textoSemEspacos += c;
        }
    }

    
    bool palindromo = true;
    int tam = textoSemEspacos.length();
    for (int i = 0; i < tam / 2; i++) {
        if (tolower(textoSemEspacos[i]) != tolower(textoSemEspacos[tam - i - 1])) {
            palindromo = false;
            break;
        }
    }

    
    if (palindromo) {
        cout << "A mensagem \"" << mensagem << "\" é um palindromo." << endl;
    } else {
        cout << "A mensagem \"" << mensagem << "\" nao é um palindromo." << endl;
    }

    return 0;
}
