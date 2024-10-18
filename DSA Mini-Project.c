#include <stdio.h>
#include <string.h>

#define MAX_TRAINS 10
#define MAX_BOOKINGS 50

// Train structure
struct Train {
    int train_no;
    char name[50];
    char source[50];
    char destination[50];
    int seats;
};

// Booking structure
struct Booking {
    char user_name[50];
    int train_no;
    int num_seats;
};

// Arrays to hold trains and bookings
struct Train trains[MAX_TRAINS];
struct Booking bookings[MAX_BOOKINGS];

// Counters for trains and bookings
int train_count = 0;
int booking_count = 0;

// Function to add a train
void add_train(int train_no, char name[], char source[], char destination[], int seats) {
    struct Train t;
    t.train_no = train_no;
    strcpy(t.name, name);
    strcpy(t.source, source);
    strcpy(t.destination, destination);
    t.seats = seats;
    trains[train_count++] = t;
}

// Function to view available trains
void view_trains() {
    printf("Available Trains:\n");
    for (int i = 0; i < train_count; i++) {
        printf("%d: %s - %s to %s (%d seats available)\n", trains[i].train_no, trains[i].name, trains[i].source, trains[i].destination, trains[i].seats);
    }
}

// Function to book tickets
void book_ticket(char user_name[], int train_no, int num_seats) {
    for (int i = 0; i < train_count; i++) {
        if (trains[i].train_no == train_no && trains[i].seats >= num_seats) {
            trains[i].seats -= num_seats;

            struct Booking b;
            strcpy(b.user_name, user_name);
            b.train_no = train_no;
            b.num_seats = num_seats;
            bookings[booking_count++] = b;

            printf("Booking successful for %s! %d seats booked on %s.\n", user_name, num_seats, trains[i].name);
            return;
        }
    }
    printf("Booking failed. Either the train number is incorrect or there are not enough seats.\n");
}

// Function to view all bookings
void view_bookings() {
    printf("All Bookings:\n");
    for (int i = 0; i < booking_count; i++) {
        printf("%s booked %d seats on Train No %d\n", bookings[i].user_name, bookings[i].num_seats, bookings[i].train_no);
    }
}

// Main function to simulate the railway system
int main() {
    // Adding some sample trains
    add_train(101, "Express Train", "CityA", "CityB", 100);
    add_train(102, "Fast Train", "CityC", "CityD", 50);

    // Displaying available trains
    view_trains();

    // Booking tickets
    book_ticket("Alice", 101, 2);
    book_ticket("Bob", 102, 3);

    // Displaying all bookings
    view_bookings();

    return 0;
}
