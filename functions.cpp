#include <iostream>
#include <fstream>
#include <random>
#include <sstream>
#include <cctype>

#define NUM_FILES 5

using namespace std;

bool check_answer(char answ);
void index_films_organizer(int index_films[], int num_files);
void read_file(string movie_name, string score_file, string user_name);
int score(char user_choice, char correct);
string pick_file(const vector<string> &films, int index_films[], int num_files);
void score_marker(string score_file, int user_score, string user_name);

void read_file(string movie_name, string score_file, string user_name, int &user_score)
{

    ifstream file(movie_name);

    string buffer;

    int x = 0;

    char user_choice;
    bool checked_choice;
    
    while (getline(file, buffer))
    {

        if (x == 6)
        {
            x = 0;

            string text;
            char correct;

            istringstream resp(buffer);

            resp >> text >> correct;

            user_score += score(user_choice, correct);

            cout << endl;
        }

        cout << buffer << endl;
        x++;

        if (x == 5)
        {
            streampos pos = file.tellg();

            file.seekg(pos);

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

void score_marker(string score_file, int user_score, string user_name)
{

    fstream file(score_file, std::ios::in | std::ios::out);

    int score = 0;
    string user;
    string buffer;

    int low_score = 5;

    if (!file.is_open())
    {
        cout << "Não foi possível abrir o arquivo!" << endl;
    }

    if (!getline(file, buffer))
    {
        file.clear();

        file << user_name << ": " << user_score;

        file.close();
    }

    while (getline(file, buffer))
    {
        istringstream consult(buffer);

        consult >> user >> score;

        if (score < low_score)
        {
            low_score = score;
        }
        
        if (score < user_score)
        {
            streampos pos = file.tellg();
            file.seekp(pos);

            file << user_name << ": " << user_score;
            file.close();
            break;
        }
        
    }
    if (user_score <= low_score)
    {
        file.clear();
        
        file.seekp(0, std::ios::end);
        file << "\n";
        file << user_name << ": " << user_score;
        file.close();
    }
}