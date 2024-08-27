#include<iostream>
#include<string>
#include<vector>
#include"Movies.h"

using namespace std;
/*
class Movie {
    private:
        string name;
        string rating;
        int watched;
    public:
        void set_name(string name_val) { name = name_val; };
        string get_name() { return name; };

        void set_rating(string rating_val) { rating = rating_val; };
        string get_rating() { return rating; };

        void set_name(int watch_count) { watched = watch_count; };
        int get_watched() { return watched; };

        Movie(string name_val, string rating_val, int watch_count) 
            :name{name_val}, rating{rating_val}, watched{watch_count} {    
        }

        void increment_watched() { ++watched; }

};

class Movies {
    private:
        vector<Movie> movies_list {};
    public:
        //vector<Movie> movies_list {};
        //bool check_movie(string);
        bool add_movie(string name_val, string rating_val, int watched_val);
        bool increment_watched(string name);
        void display();

};

bool Movies::add_movie(string name_val, string rating_val, int watched_val) {
    for(auto check: movies_list) {
        if(check.get_name() == name_val) return 0;
    }

    Movie temp {name_val, rating_val, watched_val};
    movies_list.push_back(temp);
    return 1;
}

void Movies::display() {
    if(movies_list.size() == 0) cout << "Sorry, no movies to display" << endl;
    for(auto &disp: movies_list) {
        cout << disp.get_name() << ", " << disp.get_rating() << ", " << disp.get_watched() << endl;
    }
}

bool Movies::increment_watched(string name) {
    for(auto &disp: movies_list) {
        if(disp.get_name() == name) {
            disp.increment_watched();
            return 1;
        }
    }
    return 0;
}
*/

void increment_watched(Movies &movies, string name) {
    if(movies.increment_watched(name)) 
        cout << name << " watch incremented" << endl;
    else    
        cout << name << " not found" << endl;
}

void add_movie(Movies &movies, string name_val, string rating_val, int watched_val) {
    if(movies.add_movie(name_val, rating_val, watched_val)) {
        cout << name_val << " added" << endl;
    }
    else
        cout << name_val << " already exists" << endl;
}

int main() {
    Movies my_movies;

    my_movies.display();
    
    add_movie(my_movies, "Big", "PG-13",2);                 
    add_movie(my_movies,"Star Wars", "PG",5);             
    add_movie(my_movies,"Cinderella", "PG",7);           
     
    my_movies.display();  
    
    add_movie(my_movies,"Cinderella", "PG",7);            
    add_movie(my_movies,"Ice Age", "PG",12);              
 
    my_movies.display();    
    
    increment_watched(my_movies,"Big");                    
    increment_watched(my_movies,"Ice Age");              
    
    my_movies.display();   
    
    increment_watched(my_movies,"XXX");

    return 0;
}