#include "Movies.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

void Movies::display() {
    if(movies_list.size() == 0) 
        cout << "Sorry, no movies to display" << endl;
    else {
        for(auto &disp: movies_list) {
            cout << disp.get_name() << disp.get_rating() << disp.get_watched() << endl;
        }
    }
}

bool Movies::add_movie(string name, string rating, int watched) {
    for(auto &check: movies_list) {
        if(check.get_name() == name) return 0;
    }
    Movie temp{name, rating, watched};
    movies_list.push_back(temp);
    return 1;
}

bool Movies::increment_watched(string name) {
    for(auto &check: movies_list) {
        if(check.get_name() == name) {
            check.increment_watched();
            return 1;
        }
    }
    return 0;
}