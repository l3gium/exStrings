#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

/*
Receber através de digitação uma mensagem.

Apresentar esta mensagem, centralizada, na linha 5 da tela.

À partir daí, cada letra desta mensagem deverá "cair", da linha 5 até a linha 20, simulando uma "cascata". Ao final, a mensagem deverá estar toda apresentada na linha 20.
*/

void gotoxy(short x, short y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(int argc, char** argv) {
    string msg;
    cout << "Digite uma palavra para ser exibida no centro da tela: ";
    getline(cin, msg);

    
    int centraliza = (80 - msg.length()) / 2; 

    
    gotoxy(centraliza, 5);
    cout << msg;

    
    for (int i = 0; i < msg.length(); i++) {
        for (int j = 5; j <= 20; j++) {
            
            gotoxy(centraliza + i, j);
            cout << " ";

            
            if (j >= 5 + i) {
                gotoxy(centraliza + i, j);
                cout << msg[i];
            }
        }
    }

    return 0;
}
