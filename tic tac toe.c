#include <stdio.h>
#include <string.h>

char board[9] = {"-", "-", "-",
                 "-", "-", "-",
                 "-", "-", "-"};

void print_board() {
    printf("%c | %c | %c\n", board[0], board[1], board[2]);
    printf("%c | %c | %c\n", board[3], board[4], board[5]);
    printf("%c | %c | %c\n", board[6], board[7], board[8]);
}

void take_turn(char player) {
    printf("%c's turn.\n", player);
    int position;
    while (1) {
        printf("Choose a position from 1-9: ");
        scanf("%d", &position);
        if (position >= 1 && position <= 9) break;
        printf("Invalid input. Choose a position from 1-9: ");
    }
    position--;
    while (board[position]!= '-') {
        printf("Position already taken. Choose a different position: ");
        scanf("%d", &position);
        position--;
    }
    board[position] = player;
    print_board();
}

char check_game_over() {
    if ((board[0] == board[1] && board[1] == board[2] && board[0]!= '-') ||
        (board[3] == board[4] && board[4] == board[5] && board[3]!= '-') ||
        (board[6] == board[7] && board[7] == board[8] && board[6]!= '-') ||
        (board[0] == board[3] && board[3] == board[6] && board[0]!= '-') ||
        (board[1] == board[4] && board[4] == board[7] && board[1]!= '-') ||
        (board[2] == board[5] && board[5] == board[8] && board[2]!= '-') ||
        (board[0] == board[4] && board[4] == board[8] && board[0]!= '-') ||
        (board[2] == board[4] && board[4] == board[6] && board[2]!= '-')) {
        return 'w';
    } else if (strchr(board, '-') == NULL) {
        return 't';
    } else {
        return 'p';
    }
}

void play_game() {
    print_board();
    char current_player = 'X';
    char game_over = 'p';
    while (game_over == 'p') {
        take_turn(current_player);
        game_over = check_game_over();
        if (game_over == 'w') {
            printf("%c wins!\n", current_player);
        } else if (game_over == 't') {
            printf("It's a tie!\n");
        } else {
            current_player = (current_player == 'X')? 'O' : 'X';
        }
    }
}

int main() {
    play_game();
    return 0;
}