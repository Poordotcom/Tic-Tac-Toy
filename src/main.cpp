#include <iostream>
using namespace std;

// Define ANSI Escape Codes for colors
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define CYAN_TEXT "\033[36m"

// Function To Draw The  X & O GameBoard
void drawBoard(char gameBord[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "       |     ";
            if (gameBord[i][j] == 'X')
                cout << RED << gameBord[i][j] << RESET; // Red for player 1
            else if (gameBord[i][j] == 'O')
                cout << GREEN << gameBord[i][j] << RESET; // Green for player 2
            else
                cout << gameBord[i][j];
            cout << "       |    ";
        }
        cout << "\n       ----------------------------------------------------------------\n";
    }
}

// End Of The Drawing Function

// The Fuction That Gets User input  And Checks If It's Valid Then Place it To The Board
int set_value(char op, char gameBord[3][3], char playerSigne, int flag)
{
    switch (op)
    {
    case '1':
        if (gameBord[0][0] == '1')
        {
            gameBord[0][0] = playerSigne;
            return ++flag;
        }
        else
        {
            cout << "Is Already Used\n";
            return flag;
        };
        break;

    case '2':
        if (gameBord[0][1] == '2')
        {
            gameBord[0][1] = playerSigne;
            return ++flag;
        }
        else
        {
            cout << "Is Already Used\n";
            return flag;
        };
        break;
    case '3':
        if (gameBord[0][2] == '3')
        {
            gameBord[0][2] = playerSigne;
            return ++flag;
        }
        else
        {
            cout << "Is Already Used\n";
            return flag;
        };
        break;

    case '4':
        if (gameBord[1][0] == '4')
        {
            gameBord[1][0] = playerSigne;
            return ++flag;
        }
        else
        {
            cout << "Is Already Used\n";
            return flag;
        };
        break;
    case '5':
        if (gameBord[1][1] == '5')
        {
            gameBord[1][1] = playerSigne;
            return ++flag;
        }
        else
        {
            cout << "Is Already Used\n";
            return flag;
        };
        break;

    case '6':
        if (gameBord[1][2] == '6')
        {
            gameBord[1][2] = playerSigne;
            return ++flag;
        }
        else
        {
            cout << "Is Already Used\n";
            return flag;
        };
        break;

    case '7':
        if (gameBord[2][0] == '7')
        {
            gameBord[2][0] = playerSigne;
            return ++flag;
        }
        else
        {
            cout << "Is Already Used\n";
            return flag;
        };
        break;

    case '8':
        if (gameBord[2][1] == '8')
        {
            gameBord[2][1] = playerSigne;
            return ++flag;
        }
        else
        {
            cout << "Is Already Used\n";
            return flag;
        };
        break;
    case '9':
        if (gameBord[2][2] == '9')
        {
            gameBord[2][2] = playerSigne;
            return ++flag;
        }
        else
        {
            cout << "Is Already Used\n";
            return flag;
        };
        break;
    default:
        cout << "You Entered Wrong Value Please Try Again" << endl;
        return flag;
        break;
    };
}

// Function To Check The Rounds For Winner Or Draw
bool isWinner(char gameBord[3][3], char &winner)
{
    // Check rows and columns for a win
    for (int i = 0; i < 3; i++)
    {
        if (gameBord[i][0] == gameBord[i][1] && gameBord[i][1] == gameBord[i][2])
        {
            winner = gameBord[i][0];
            return true; // Row win
        }
        if (gameBord[0][i] == gameBord[1][i] && gameBord[1][i] == gameBord[2][i])
        {
            winner = gameBord[0][i];
            return true; // Column win
        }
    }

    // Check diagonals for a win
    if ((gameBord[0][0] == gameBord[1][1] && gameBord[1][1] == gameBord[2][2]) ||
        (gameBord[0][2] == gameBord[1][1] && gameBord[1][1] == gameBord[2][0]))
    {
        winner = gameBord[1][1];
        return true; // Diagonal win
    }

    // Check for a draw
    bool draw = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (gameBord[i][j] != 'X' && gameBord[i][j] != 'O')
            {
                draw = false; // If any cell is not filled by X or O, it's not a draw
                break;
            }
        }
    }
    if (draw)
    {
        winner = '-';
        return true; // Draw
    }

    return false; // No winner yet
}

int main()
{
    int choice;
    int x, y, i = 2;
    char player1 = 'O', player2 = 'X', op, winner;
    char gameBord[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    // إضافة ASCII Art كعنوان رئيسي للعبة

    // [ Main Menue For The Game ]

    cout << YELLOW_TEXT << R"(
  ___  _  _  __  ____  __    ____  ____  ____  __  __  ____  ____  ____ 
 / __)( \/ )(  )(  _ \(  )  (  _ \( ___)(_  _)(  \/  )( ___)(_  _)( ___)
( (__  )  /  )(  ) _ < )(__  ) _ < )__)   )(   )    (  )__)   )(   )__) 
 \___)(_/\_)(__)(____/(____)(____/(____) (__) (_/\/\_)(____) (__) (____)
)" << RESET
         << endl;
    cout << CYAN_TEXT << "Welcome to Tic Tac Toy!" << RESET << endl;
    cout << GREEN << "1. Start Game" << RESET << endl;
    cout << RED << "2. Exit" << RESET << endl;
    cout << YELLOW_TEXT << "Enter your choice: ";
    cin >> choice;

    // handling The user Choice
    switch (choice)
    {
    case 1:
        cout << GREEN << "********* Tic Tac Toy For Hevery Body Chose Number To Put Your X OR Y **********\n\n"
             << RESET;
        drawBoard(gameBord);

        while (!(isWinner(gameBord, winner)))
        {

            // Player 1 Turns
            if (i % 2 == 0)
            {
                cout << "\n ***** Player 1 ****** : \n";
                cout << "\nEnter The Number You Whant : \n";
                cin >> op;
                i = set_value(op, gameBord, player1, i);
                drawBoard(gameBord);
            }

            // Player 2 Turns
            else if (i % 2 == 1)
            {
                cout << "\n ***** Player 2 ****** : \n";
                cout << "\nEnter The Number You Whant : \n";
                cin >> op;
                i = set_value(op, gameBord, player2, i);
                drawBoard(gameBord);
            }
        };

        if (isWinner(gameBord, winner))
        {
            if (winner == '-')
                cout << "It's a draw!\n";
            else
                cout << GREEN << "Player " << RED << winner << GREEN << " wins!\n"
                     << RESET;
        }
        else
        {
            cout << "No winner yet.\n";
        }
        break;
    case 2:
        cout << GREEN << "Goodbye! Exiting the game." << RESET << endl;
        break;
    default:
        cout << YELLOW_TEXT << "Invalid choice. Please select again." << RESET << endl;
        break;
    }

    return 0;
}