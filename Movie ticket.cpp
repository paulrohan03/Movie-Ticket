#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int MAX_ROWS = 5;
const int MAX_COLS = 10;

void showMovieList();
void displaySeatingChart(const vector<vector<char> > &seatingChart);
bool isSeatAvailable(const vector<vector<char> > &seatingChart, int row, int col);
void reserveSeat(vector<vector<char> > &seatingChart, int row, int col, int &totalReservedSeats);

int main() {
    vector<vector<char> > seatingChart(MAX_ROWS, vector<char>(MAX_COLS, 'O')); 
    int totalReservedSeats = 0;

    while (true) {
        cout << "Welcome to the Movie Ticket Reservation System" << endl;
        cout << "1. Show Movie Listings" << endl;
        cout << "2. Display Seating Chart" << endl;
        cout << "3. Reserve Tickets" << endl;
        cout << "4. Exit" << endl;

        int userChoice;
        cout << "Enter your choice: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                showMovieList();
                break;
            case 2:
                displaySeatingChart(seatingChart);
                break;
            case 3:
                {
                    int selectedRow, selectedCol;
                    cout << "Enter row and column for the seat (1-" << MAX_ROWS << ", 1-" << MAX_COLS << "): ";
                    cin >> selectedRow >> selectedCol;

                    if (selectedRow >= 1 && selectedRow <= MAX_ROWS && selectedCol >= 1 && selectedCol <= MAX_COLS) {
                        if (isSeatAvailable(seatingChart, selectedRow - 1, selectedCol - 1)) {
                            reserveSeat(seatingChart, selectedRow - 1, selectedCol - 1, totalReservedSeats);
                        } else {
                            cout << "Sorry, the seat is already reserved. Please choose another seat." << endl;
                        }
                    } else {
                        cout << "Invalid row or column. Please enter a valid seat." << endl;
                    }
                }
                break;
            case 4:
                cout << "Thank you for using the Movie Ticket Reservation System. Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}

void showMovieList() {
    cout << "Available Movies:" << endl;
    cout << "1. Animal" << endl;
    cout << "2. Avatar" << endl;
    cout << "3. Jawan" << endl;
}

void displaySeatingChart(const vector<vector<char> > &seatingChart) {
    cout << "Seating Chart:" << endl;
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            cout << seatingChart[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSeatAvailable(const vector<vector<char> > &seatingChart, int row, int col) {
    return seatingChart[row][col] == 'O';
}

void reserveSeat(vector<vector<char> > &seatingChart, int row, int col, int &totalReservedSeats) {
    seatingChart[row][col] = 'X'; 
    totalReservedSeats++;
    cout << "Seat reserved successfully! Total seats reserved: " << totalReservedSeats << endl;
}

