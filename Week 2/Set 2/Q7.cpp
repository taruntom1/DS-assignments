#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Movie {
private:
    string title;
    string studio;
    string rating;

public:
    // Constructor that takes title, studio, and rating
    Movie(string t, string s, string r) : title(t), studio(s), rating(r) {}

    // Constructor that takes title and studio, sets rating to "PG"
    Movie(string t, string s) : title(t), studio(s), rating("PG") {}

    // Method to filter movies with "PG" rating
    static vector<Movie> getPG(const vector<Movie>& movies) {
        vector<Movie> pgMovies;
        for (const Movie& movie : movies) {
            if (movie.rating == "PG") {
                pgMovies.push_back(movie);
            }
        }
        return pgMovies;
    }

    // Method to display movie details (for testing purposes)
    void display() const {
        cout << "Title: " << title << ", Studio: " << studio << ", Rating: " << rating << endl;
    }
};

int main() {
    // Creating an instance of the class Movie
    Movie casinoRoyale("Casino Royale", "Eon Productions", "PG13");

    // Creating additional movie instances for demonstration
    Movie movie1("Movie A", "Studio A", "PG");
    Movie movie2("Movie B", "Studio B", "R");
    Movie movie3("Movie C", "Studio C", "PG");

    // Vector of movies
    vector<Movie> movies = { casinoRoyale, movie1, movie2, movie3 };

    // Filtering movies with "PG" rating
    vector<Movie> pgMovies = Movie::getPG(movies);

    // Displaying the PG-rated movies
    cout << "PG-rated movies:" << endl;
    for (const Movie& movie : pgMovies) {
        movie.display();
    }

    return 0;
}