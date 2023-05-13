#include "game_of_life.h"

game_of_life::game_of_life()
{
    srand(time(nullptr));
    for (int i = 0; i < REDAKA; i++)
    {
        for (int j = 0; j < STUPACA; j++)
        {
            int rnd = slucajna_vrijednost();
            if (rnd == 1)
            {
                _generacija[i][j] = true;
            }
            else
            {
                _generacija[i][j] = false;
            }

            _sljedeca_generacija[i][j] = false;
        }
    }

}

void game_of_life::sljedeca_generacija()
{
    for (int i = 0; i < REDAKA; i++)
    {
        for (int j = 0; j < STUPACA; j++)
        {
            int broj_susjeda = 0;
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    if (di == 0 && dj == 0)
                    {
                        continue;
                    }
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni < 0)
                    {
                        ni = REDAKA - 1;
                    }
                    if (ni >= REDAKA)
                    {
                        ni = 0;
                    }
                    if (nj < 0)
                    {
                        nj = STUPACA - 1;
                    }
                    if (nj >= STUPACA)
                    {
                        nj = 0;
                    }
                    if (_generacija[ni][nj])
                    {
                        broj_susjeda++;
                    }
                }
            }
            if (_generacija[i][j])
            {
                if (broj_susjeda < 2 || broj_susjeda > 3)
                {
                    _sljedeca_generacija[i][j] = false;
                }
                else
                {
                    _generacija[i][j] = true;
                }
            }
            else if (broj_susjeda == 3)
            {
                _sljedeca_generacija[i][j] = true;
            }
            else
            {
                _sljedeca_generacija[i][j] = false;
            }

        }
    }
    for (int i = 0; i < REDAKA; i++)
    {
        for (int j = 0; j < STUPACA; j++)
        {
            _generacija[i][j] = _sljedeca_generacija[i][j];
        }
    }
}


int game_of_life::slucajna_vrijednost()
{
    return rand() % 4 + 1;
}

string game_of_life::iscrtaj() {
    stringstream ss;
    ss << "|";
    for (int i = 0; i < REDAKA; i++)
    {
        for (int j = 0; j < STUPACA; j++)
        {
            if (_generacija[i][j])
            {
                ss << "+";
            }
            else
            {
                ss << "-";
            }
        }
    }
    ss << "|" << endl;
    return ss.str();
}