#include <iostream>
#include "functions.cpp"

using namespace std;

int main() {

    string file_name = "quiz.txt";
    int index_films[NUM_FILES];
    int num_films = 0;

    cout << "Bem vindo ao Quiz sobre filmes" << endl;
    cout << "Acerte as perguntas e acumule pontos" << endl;
    cout << "Boa sorte" << endl;
    cout << endl;

    while (num_films < NUM_FILES)
    {
        string film_sorted = pick_file(index_films);
        read_file(film_sorted);
        num_films++;
    } 

    cout << "Acabou os filmes" << endl;

    return 0;
}