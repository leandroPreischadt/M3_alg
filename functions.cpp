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

string pick_file()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, NUM_FILES - 1);

    int index_films[NUM_FILES];

    for (int i = 0; i < NUM_FILES; i++)
    {
        index_films[i] = -1;
    }
    

    string films[NUM_FILES] = {"marvel.txt", "theLordOfTheRings.txt", "theImitationGame.txt", "spiderMan.txt", "backToTheFuture.txt"};

    while (true)
    {
        int sorted = dist(gen);

        if (sorted == index_films[sorted])
        {
            continue;
        }

        index_films[sorted] = sorted;

        return films[sorted];
    }
}
