#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

// Function declarations
void block_display(char *arr);
int human_player(char *arr);
int computer_player(char *arr);
int dual_player(char *arr);
int check_winner(char *arr, char symbol);
int check_draw(char *arr);

// Function definitions
void block_display(char *arr)
{
    system("cls");
    cout << "       |" << "       |" << "       " << endl;
    cout << "   " << arr[0] << "   |" << "   " << arr[1] << "   |" << "   " << arr[2] << "   " << endl;
    cout << "_______|" << "_______|" << "_______" << endl;
    cout << "       |" << "       |" << "       " << endl;
    cout << "   " << arr[3] << "   |" << "   " << arr[4] << "   |" << "   " << arr[5] << "   " << endl;
    cout << "_______|" << "_______|" << "_______" << endl;
    cout << "       |" << "       |" << "       " << endl;
    cout << "   " << arr[6] << "   |" << "   " << arr[7] << "   |" << "   " << arr[8] << "   " << endl;
    cout << "       |" << "       |" << "       " << endl;
}

int check_winner(char *arr, char symbol)
{
    int winPatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    for (int i = 0; i < 8; ++i)
        if (arr[winPatterns[i][0]] == symbol &&
            arr[winPatterns[i][1]] == symbol &&
            arr[winPatterns[i][2]] == symbol)
            return 1;

    return 0;
}

int check_draw(char *arr)
{
    for (int i = 0; i < 9; i++)
        if (arr[i] == ' ')
            return 0;

    if (check_winner(arr, 'X') == 0 && check_winner(arr, 'O') == 0)
        return 1;

    return 0;
}

int human_player(char *arr)
{
    int n;
    while (true) {
        block_display(arr);
        cout << "Enter a position (1-9): ";
        cin >> n;
        if (n >= 1 && n <= 9 && arr[n - 1] == ' ') {
            arr[n - 1] = 'X';
            break;
        } else {
            cout << "Invalid move. Try again." << endl;
            system("pause");
        }
    }

    block_display(arr);
    if (check_winner(arr, 'X')) {
        cout << "You won!!" << endl;
        return 1;
    }
    if (check_draw(arr)) {
        cout << "The game is draw!!" << endl;
        return 1;
    }

    return 0;
}

int computer_player(char *arr)
{
    int n;
    while (true) {
        n = rand() % 9;
        if (arr[n] == ' ') {
            arr[n] = 'O';
            break;
        }
    }

    block_display(arr);
    if (check_winner(arr, 'O')) {
        cout << "You lose!!" << endl;
        return 1;
    }
    if (check_draw(arr)) {
        cout << "The game is draw!!" << endl;
        return 1;
    }

    return 0;
}

int dual_player(char *arr)
{
    char symbol='X';
    int n;
    while(true){
    while (true) {
        block_display(arr);
        cout<<"Player "<<symbol <<" moves.\n";
        cout << "Enter a position (1-9): ";
        cin >> n;
        if (n >= 1 && n <= 9 && arr[n - 1] == ' ') {
            arr[n - 1] = symbol;
            break;
        } else {
            cout << "Invalid move. Try again." << endl;
            system("pause");
        }
    }

    block_display(arr);
    if (check_winner(arr, symbol)) {
        cout << "Player "<<symbol<<" wins." << endl;
        return 1;
    }
    if (check_draw(arr)) {
        cout << "The game is draw!!" << endl;
        return 1;
    }
    symbol=(symbol=='X')?'O':'X';
    }
    return 1;
}

int main()
{
    srand(time(0));  // Seed the RNG

    char choice;
    do {
        char place[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
        int starter;
        bool play = false;

        do {
            system("cls");
            cout << "Welcome to TIC-TAC-TOE GAME!!" << endl;
            cout << "Please Enter your choice:\n";
            cout << "1. Player begins first.\n";
            cout << "2. Computer begins first.\n";
            cout << "3. Two players game.\n";
            cout << "4. Exit <--\n";
            cin >> starter;
            if(starter==4)
                goto out;
            if (starter == 1 || starter == 2|| starter ==3)
                break;

            cout << "Invalid choice. Try again.\n";
            system("pause");

        } while (true);

        // Start the game
        while (true) {
            if (starter == 1) {
                play = human_player(place);
                if (play) break;
                play = computer_player(place);
                if (play) break;
            } else if(starter == 2){
                play = computer_player(place);
                if (play) break;
                play = human_player(place);
                if (play) break;
            }
            else{
                play=dual_player(place);
                if(play) break;
            }
        }

        cout << "\nPlay another game? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');
    out:
    cout << "Thanks for playing!" << endl;
    system("pause");
    return 0;
}
