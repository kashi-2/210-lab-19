// COMSC-210 | Lab #19 | Akashdeep Singh
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

//named constants
const double MIN_RATING = 1.0;
const double MAX_RATING = 5.0;
const int REVIEWS_PER_MOVIE = 3;
const int NUM_MOVIES = 4;

//Review node
struct Node
{
    double rating;
    string comment;
    Node* next;
};

//Movie class 
class Movie
{
private:
    string title;
    Node* head;

    public:
        Movie();
        Movie(string);
        ~Movie();

        void setTitle(string);
        string getTitle();

        void addReview(double, string);
        void outputReviews();
        void deleteList();
};

//function prototypes
double generateRating();
vector<string> loadComments(string);

int main()
{
    srand(time(0));

    vector<Movie> movies;

    //loading comments from file
    vector<string> comments = loadComments("reviews.txt");

    //creating movie objects
    movies.push_back(Movie("The Last Horizon"));
    movies.push_back(Movie("Echoes of Tomorrow"));
    movies.push_back(Movie("Shadow Realm"));
    movies.push_back(Movie("City of Stars"));

    int commentIndex = 0;

    //add reviews to each movie 
    for (auto& movie : movies)
    {
        for (int i = 0; i < REVIEWS_PER_MOVIE; i++)
        {
            double rating = generateRating();
            string comment = comments[commentIndex % comments.size()];

            movie.addReview(rating, comment);

            commentIndex++;
        }
    }
    
    //Output movie reviews
    for (auto& movie: movies)
    {
        cout << "\nMovie: " << movie.getTitle() << endl;
        movie.outputReviews();
    }
    return 0;
}
//Function definations

//default constructor 
Movie::Movie()
{
    title = "Unknown";
    head = nullptr;
}

//parameter constructor
Movie::Movie(string t)
{
    title = t;
    head = nullptr;
}

//destructor
Movie::~Movie()
{
    deleteList();
}

//setTitle
void Movie::setTitle(string t)
{
    title = t;
}

//getTitle
string Movie::getTitle()
{
    return title;
}

//addReview() which will add node to head of the list
void Movie::addReview(double rating, string comment)
{
    Node* newNode = new Node;

    newNode->rating = rating;
    newNode->comment = comment;
    newNode->next = head;

    head = newNode;
}

//outputReviews()
void Movie::outputReviews()
{
    if (!head)
    {
        cout << "    No reviews\n";
        return;
    }

    Node* current = head;
    int count = 1;
    double total = 0;

    while (current)
    {
        cout << "    Review #" << count << ": " << current->rating << " : " << current->comment << endl;

        total += current->rating;
        current = current->next;
        count++;
    }

    cout << "    Average Rating: " << total / (count - 1) << endl;
}
//deleteList()
void Movie::deleteList()
{
    Node* current
}