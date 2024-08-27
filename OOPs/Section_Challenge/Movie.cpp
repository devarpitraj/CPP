#include"Movie.h"
#include<string>

using namespace std;

Movie::Movie(string name_val, string rating_val, int watch_count)
    :name{name_val}, rating{rating_val}, watched{watch_count} {

    }

string Movie::get_name() { return name; }
string Movie::get_rating() { return rating; }
int Movie::get_watched() { return watched; }
void Movie::increment_watched() { ++watched; }