#include <iostream>
#include "functions.cpp"

using namespace std;

int main() {

    string file_name = "quiz.txt";
    

    int num_films = 0;

    cout << "Bem vindo ao Quiz sobre filmes" << endl;
    cout << "Acerte as perguntas e acumule pontos" << endl;
    cout << "Boa sorte" << endl;

    while (num_films < NUM_FILES)
    {
        cout << endl;
        string film_sorted = pick_file();
        read_file(film_sorted);
        num_films++;
    } 

    cout << "Acabou os filmes" << endl;

    return 0;
}