#include <iostream>
#include <fstream>
#include <random>
#define NUM_FILES 5

using namespace std;



void read_file(string movie_name)
{

    ifstream fil(movie_name);

    string buffer;

    int x = 0;

    while (getline(fil, buffer))
    {
        char choice;

        if (x == 7)
        {
            // if choice == resposta -> ganhar pontos
            cout << choice << endl;
            cout << endl;
        }

        cout << buffer << endl;
        x++;

        if (x == 5)
        {
            streampos pos = fil.tellg();

            fil.seekg(pos);

            cout << "Escolha a resposta entre as disponíveis: ";

            cin >> choice;
            cout << endl;
        }
    }
}

void user_score(string score_file)
{
}

string pick_file(const vector<string> &films, int index_films[], int num_files)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, num_files - 1);

    int sorted;
    

    

    while (true)
    {
        sorted = dist(gen);

        if (sorted == index_films[sorted])
        {
            continue;
        }

        index_films[sorted] = sorted;

        return films[sorted];
    }
}

void index_films_organizer(int index_films[]) {

}