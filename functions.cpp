#include <iostream>
#include <fstream>
#include <random>
#include <sstream>
#include <cctype>

#define NUM_FILES 5

using namespace std;

bool check_answer(char answ);
void index_films_organizer(int index_films[], int num_files);
void read_file(string movie_name);
int score(char user_choice, char correct);
string pick_file(const vector<string> &films, int index_films[], int num_files);

void read_file(string movie_name)
{

    ifstream fil(movie_name);

    string buffer;

    int x = 0;

    char user_choice;
    bool checked_choice;
    int user_score;

    while (getline(fil, buffer))
    {

        if (x == 6)
        {
            x = 0;

            string text;
            char correct;

            istringstream resp(buffer);

            resp >> text >> correct;

            user_score = score(user_choice, correct);

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

                checked_choice = check_answer(user_choice);

                if (!isalpha(user_choice) || !checked_choice)
                {
                    cout << endl;
                    cout << "A resposta deve ser uma letra minúscula entre (a-d)" << endl;
                }

            } while (!isalpha(user_choice) || checked_choice == false);

            cout << endl;
        }
    }
}

int score(char user_choice, char correct)
{

    if (user_choice == correct)
    {
        cout << "Você acertou!" << endl;

        return 1;
    }

    cout << "Você errou!" << endl;
    return 0;
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

void index_films_organizer(int index_films[], int num_files)
{

    for (int i = 0; i < num_files; i++)
    {
        index_films[i] = -1;
    }
}

bool check_answer(char response)
{

    if (response == 'a' || response == 'b' || response == 'c' || response == 'd')
    {
        return true;
    }

    return false;
}

void score_file(string name_file) {

}