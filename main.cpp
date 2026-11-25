#include <iostream>
#include "functions.cpp"
#include <vector>

using namespace std;

int main() {

    int num_files = 5;

    vector<string> films = {"marvel.txt", "theLordOfTheRings.txt", "theImitationGame.txt", "spiderMan.txt", "backToTheFuture.txt"};
    
    int index_films[films.size()];

    for (int i = 0; i < NUM_FILES; i++)
    {
        index_films[i] = -1;
    }

    int sup = 0;

    cout << "Bem vindo ao Quiz sobre filmes" << endl;
    cout << "Acerte as perguntas e acumule pontos" << endl;
    cout << "Boa sorte" << endl;

    while (sup < num_files)
    {
        cout << endl;
        string film_sorted = pick_file(films ,index_films, num_files);
        read_file(film_sorted);
        sup++;
    } 

    cout << "Acabou os filmes" << endl;

    return 0;
}