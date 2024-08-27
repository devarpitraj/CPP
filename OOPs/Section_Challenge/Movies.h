#ifndef _MOVIES_H_
#define _MOVIES_H_
#include<string>
#include<vector>
#include"Movie.h"

using namespace std;

class Movies {
    private:
        vector<Movie> movies_list;
    public:
        bool add_movie(std::string, string rating, int watched);
        bool increment_watched(std::string);
        void display();
};

#endif