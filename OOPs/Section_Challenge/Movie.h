#ifndef _MOVIE_H_
#define _MOVIE_H_
#include<string>
#include<vector>

using namespace std;

class Movie {
    friend class Movies;
    private:
        std::string name;
        std::string rating;
        int watched;
    public:
        string get_name();
        string get_rating();
        int get_watched();

        Movie(string name_val, string rating_val, int watch_count);

        void increment_watched();
};

#endif
