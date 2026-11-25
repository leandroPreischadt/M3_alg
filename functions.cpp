#include <iostream>
#include <fstream>
#include <random>
#include <sstream>
#include <cctype>

#define NUM_FILES 5

using namespace std;



void read_file(string movie_name)
{

    ifstream fil(movie_name);

    string buffer;

    int x = 0;
    
    char user_choice;

    while (getline(fil, buffer))
    {

        if (x == 6)
        {
            x = 0;

            string text;
            char correct;

            istringstream asw(buffer);

            asw >> text >> correct;

            if (user_choice == correct)
            {
                cout << "Você acertou!" << endl;

                //chamar função de user_score

            } else {
                cout << "Você errou!" << endl;
            }
            
            cout << endl;
        }

        cout << buffer << endl;
        x++;

        if (x == 5)
        {
            streampos pos = fil.tellg();

            fil.seekg(pos);

            
            do
            {
                cout << endl;
                cout << "Escolha a resposta entre as disponíveis: ";

                cin >> user_choice;
    
                if (!isalpha(user_choice))
                {
                    cout << endl;
                    cout << "A resposta deve ser uma letra" << endl;
                }

                
            } while (!isalpha(user_choice));
            
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

void index_films_organizer(int index_films[], int num_files) {
    
    for (int i = 0; i < num_files; i++)
    {
        index_films[i] = -1;
    }

}