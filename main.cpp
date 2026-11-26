#include <iostream>
#include "functions.cpp"
#include <vector>

using namespace std;

int main() {

    int num_files = 5;
    string score_file = "score.txt";
    string user_name;
    int user_score = 0;

    vector<string> films = {"marvel.txt", "theLordOfTheRings.txt", "theImitationGame.txt", "spiderMan.txt", "backToTheFuture.txt"};

    
    int index_films[films.size()];

    index_films_organizer(index_films, num_files);
    
    int sup = 0;

    cout << "Bem vindo ao Quiz sobre filmes" << endl;
    cout << "Acerte as perguntas e acumule pontos" << endl;

    cout << "Escreva seu nome: ";
    cin >> user_name;

    cout << "Boa sorte" << endl;

    while (sup < num_files)
    {
        cout << endl;
        string film_sorted = pick_file(films ,index_films, num_files);
        read_file(film_sorted, score_file, user_name, user_score);
        sup++;
    } 

    cout << endl;
    cout << "Acabou as perguntas" << endl;
    cout << "Jogador: "<< user_name << endl;
    cout << "pontuação: " << user_score <<"/" << num_files << endl;

    score_marker(score_file, user_score, user_name);

    return 0;
}