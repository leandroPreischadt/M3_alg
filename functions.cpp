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
        cout << buffer << endl;
        x++;

        if (x == 6)
        {
            streampos pos = fil.tellg();

            x = 0;

            char choice;
            fil.seekg(pos);

            cout << "Escolha a resposta entre as disponíveis: ";

            cin >> choice;
            cout << endl;
        }
    }

    if (x == 5)
    {
        x = 0;
    }
}

void user_score(string score_file)
{
}

string pick_file(int index_films[NUM_FILES])
{

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, NUM_FILES - 1);

    string films[NUM_FILES] = {"marvel.txt", "theLordOfTheRings.txt", "theImitationGame.txt", "spiderMan.txt", "backToTheFuture.txt"};

    while (true)
    {
        int sorted = dist(gen);

        for (int i = 0; i < NUM_FILES - 1; i++)
        {

            if (sorted == index_films[i])
            {
                continue;
            }

            index_films[sorted] = sorted;

            return films[sorted];
        }
    }
}
// Perguntar se pode usar vector