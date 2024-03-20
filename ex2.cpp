#include <iostream>
#include <string>
#include <locale.h>
using namespace std;

/*
Receber atrav�s de digita��o uma mensagem. 

Informar se esta mensagem � ou n�o um dado pal�ndromo (no caso de haver espa�os no texto, desconsider�-los para a verifica��o). Exemplos:

OVO
ARARA
SOCORRAM ME SUBI NO ONIBUS EM MARROCOS
*/

int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "");
	
    string mensagem;
    cout << "Digite uma mensagem para verificar se � um palindromo: ";
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
        cout << "A mensagem \"" << mensagem << "\" � um palindromo." << endl;
    } else {
        cout << "A mensagem \"" << mensagem << "\" nao � um palindromo." << endl;
    }

    return 0;
}
