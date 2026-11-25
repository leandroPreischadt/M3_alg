#include <iostream>
#include "functions.cpp"

using namespace std;

int main() {

    string file_name = "quiz.txt";
    int index_films[NUM_FILES];

    cout << "Bem vindo ao Quiz sobre filmes" << endl;
    cout << "Acerte as perguntas e acumule pontos" << endl;
    cout << "Boa sorte" << endl;
    cout << endl;


    string sorted_film = pick_file(index_films);

    cout << sorted_film << endl;

    return 0;
}