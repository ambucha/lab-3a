// COMSC-210 | Lab 3A | Andrei Buchatskiy
// IDE used : Visual Studio Code

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Create the struct 'Restaurant' with the five following variables:
 name
 founding year
 food safety grade
 rating 
 vegetarian or not
*/

struct Restaurant{
    string name;
    int year;
    char grade;
    double rating;
    bool veggie;
};

// restaurant_input() collects user data to create the structs
// arguments: loop number
// returns: restaurant data
Restaurant restaurant_input(int);

// restaurant_display() displays the collected restaurant data to the user
// arguments: restaurants data, num of restaurants
// returns: nothing
void restaurant_display(const vector<Restaurant>&, int);

int main() {
    // Create an int to collect number of restaurants user wants to collect data for
    int n;

    // Collect number of restaurants
    cout << "Enter number of restaurants (min 4): ";
    cin >> n;

    // Create a vector of the number of restaurants
    vector<Restaurant> restaurants(n);

    // Create a loop to fill the vector of restaurants with user inputed data
    for(int i = 0; i < n; i++){
        restaurants.at(i) = restaurant_input(i);
    }

    // Display the data
    restaurant_display(restaurants, n);
    return 0;
}

Restaurant restaurant_input(int i){
    // Create a temp Restaurant struct
    Restaurant temp;

    // Collect the data
    cout << "Enter Restaurant " << i + 1 << "'s name: ";
    getline(cin >> ws, temp.name);
    cout << "Enter year founded: ";
    cin >> temp.year;
    cout << "Enter food safety grade: ";
    char g;
    cin >> g;
    temp.grade = toupper(g);
    cout << "Enter rating (out of five): ";
    cin >> temp.rating;
    cout << "Is the restaurant vegetarian? (Y/N)";
    char y_n;
    cin >> y_n;
    y_n = toupper(y_n);
    // Check if it was a valid entry
    while(y_n != 'Y' && y_n != 'N') {
        cout << "\tERROR: Y/N only: ";
        cin >> y_n;
        y_n = toupper(y_n);
    }
    temp.veggie = y_n == 'Y' ? true: false;
    return temp;
}

void restaurant_display(const vector<Restaurant>& x, int num){
    // Create loop to display the data
    for(int i = 0; i < num; i++){
        cout << "Restaurant #" << i + 1 << ": " << x.at(i).name << endl;
        cout << "\tYear Founded: " << x.at(i).year << endl;
        cout << "\tFood Safety Grade: " << x.at(i).grade << endl;
        cout << "\tRating: " << x.at(i).rating << endl;
        cout << "\tVegetarian: ";
        x.at(i).veggie ? cout << "Yes" : cout << "No";
        cout << endl; 
    }
}
