#include "File.h"

File::File() {

}

File::~File() {

}

void File::bestScores() {
    
    std::vector<int> v;
    for (int i = 0; i < vec.size(); i++)
    {
       int x;
        x = stoi(vec[i]);
        v.push_back(x);
    }
    vec.clear();

    std::ranges::sort(v);
    std::ranges::reverse(v);
    
    const auto rd = std::ranges::unique(v);

    for (int i = 0; i < v.size(); i++)
    {
        std::string s;
        s = std::to_string(v[i]);
        vec.push_back(s);
    }


    v.clear();
}

void File::fileIn() {

    std::ifstream plik(path);

    if (plik)
    {
        while (getline(plik, data))
        {
            vec.push_back(data);
        }
    }    
    else
    {
        std::cout << "Blad pliku wejsciowego. " << std::endl;
    }
    plik.close();

}

void File::addScore(int score) {

    std::string s = std::to_string(score);
    vec.push_back(s);
}


void File::fileOut() {

    File::bestScores();

    std::ofstream plik(path);

    if (plik)
    {
        plik.clear();

        for (int i = 0; i < vec.size(); ++i)
        {
            plik << vec[i] << std::endl;
        }
    }
    std::cout << "Dane zaaktualizowane ";
}

