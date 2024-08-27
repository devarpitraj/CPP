#include<iostream>
#include<iomanip>
#include<string>
#include<list>
#include<limits>

class Song {
    friend std::ostream& operator<<(std::ostream &os, const Song &obj);
    std::string name;
    std::string artist;
    int rating;
    public:
        Song() = default;
        Song(std::string name, std::string artist, int rating)
            :name{name}, artist{artist}, rating{rating} {}

        bool operator<(const Song &rhs) {
            return name < rhs.name;
        }

        bool operator==(const Song &rhs) {
            return name == rhs.name;
        }
};

std::ostream& operator<<(std::ostream &os, const Song &obj) {
    os << std::setw(30) << std::left << obj.name
        << std::setw(30) << std::left <<  obj.artist
        << std::setw(5) << std::right << obj.rating << std::endl;
}

void display_menu() {
    std::cout << "F - Play first song \n"
                << "N - Play next song \n"
                << "P - Play previous song \n"
                << "A - Add and play a new song \n"
                << "L - List the playlist";
    std::cout << "\n=========================" << std::endl;
    std::cout << "Enter selection (Q to Quit): ";
}

void play_current_song(const Song &song) {
    std::cout << "Playing: ";
    std::cout << song << std::endl;
}

int main() {
    std::list<Song> playlist {
        {"God's Plan",        "Drake",                     5},
        {"Never Be The Same", "Camila Cabello",            5},
        {"Pray For Me",       "The Weekend and K. Lamar",  4},
        {"The Middle",        "Zedd, Maren Morris & Grey", 5},
        {"Wait",              "Maroone 5",                 4},
        {"Whatever It Takes", "Imagine Dragons",           3}
    };

    auto current_song = playlist.begin();

    char selection{};
    do {
        display_menu();
        std::cin >> selection;
        selection = std::toupper(selection);

        if(selection == 'F') {
            std::cout << "Playing first song: " << std::endl;
            current_song = playlist.begin();
            play_current_song(*current_song);
        }

        else if(selection == 'N') {
            std::cout << "Playing Next song: " << std::endl;
            current_song++;
            play_current_song(*current_song);
        }

        else if(selection == 'P') {
            std::cout << "Playinf previous song: " << std::endl;
            current_song--;
            play_current_song(*current_song);
        }

        else if(selection == 'L') {
            std::cout << "Displaying Playlist: " << std::endl;
            current_song = playlist.begin();
            while(current_song != playlist.end()) {
                std::cout << *current_song ;
                current_song++;
            }
            std::cout << "\n========================" << std::endl;
        }

        else if(selection == 'A') {
            std::string name{};
            std::string artist{};
            int rating{};

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter name of song: ";
            std::getline(std::cin, name);
            std::cout << "Enter name of artist: ";
            std::getline(std::cin, artist);
            std::cout << "Enter rating (1-5): ";
            std::cin >> rating;

            playlist.insert(current_song, Song{name, artist, rating});
            current_song--;
            play_current_song(*current_song);
        }

        else if(selection == 'Q')
            std::cout << "Quitting" << std::endl;
        
        else    
            std::cout << "Illegal choice - make choice again" << std::endl;

    }while(selection != 'Q');

    return 0;
}