#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h>
#include <mmsystem.h>


//-lwinmm

void checkMenu();
void inMenu();
void about();
void gameRule();
void Inbanco(char banco[13][13]);
void Nhap(char banco[13][13], char player);
int KiemTraNhapHopLe(char banco[13][13], int nhap);
int checkWinner(char banco[13][13], char player);
void playGame();

// ham in menu
void inMenu(){
    PlaySound(TEXT("Sounds\\game_play"), NULL, SND_ASYNC | SND_LOOP); // Phát âm thanh nền

    printf("=====##==MENU==##=====\n\n");
    printf("1. About us\n2. Game rule\n3. Play game\n4. Quit\n\n");
    printf("======================\n");
    printf("Please enter: ");
    checkMenu();

}

// ham kiem tra menu
void checkMenu() {

    int nhapm;
    // kiem tra lua chon cua user
    scanf("%d", &nhapm);
    switch (nhapm) {
        case 1:
            about();
            break;
        case 2:
            gameRule();
            break;
        case 3:
            playGame();
            break;
        case 4:
            exit(0);
        default:
            getchar();
            printf("Your choice is invalid. Please choose again!\n");
            checkMenu();
            break;

    }
}

// ham thong tin nhom
void about() {
    system("cls");
    printf("===ABOUT US===\n\n");
    printf("Group 2:  \n\n");
    printf("Members:\n\n");
    printf("1. NamDVCE190076\t\tDong Viet Nam\n");
    printf("2. HieuQTCE191357\t\tQuach Trong Hieu\n");
    printf("3. KietTTCE190871\t\tTran Tuan Kiet\n");
    printf("4. KhangNDCE192012\t\tNguyen Duy Khang\n");
    printf("5. VinhNHTCE190384\t\tNguyen Hoang Thai Vinh\n");
    printf("\nPlease enter to return Menu ");
    getchar();
    getchar();
    system("cls");
    inMenu();
}

// ham luat choi
void gameRule() {
    system("cls");
    printf("===GAME RULE===\n");

    // Thể lệ trò chơi
    printf(" To play:\n");
    printf("1. Choose a position on the grid by entering its coordinates when prompted.\n");
    printf("2. Player 1 uses the symbol 'X', and Player 2 uses the symbol 'O'.\n");
    printf("3. Players will input the desired number of rows and columns.\n");
    printf("4. The game announces the winner or declares a draw at the end.\n");
    printf("5. A symbol cannot be placed on a square that already contains another symbol.\n\n");
    printf("Enjoy playing Tic Tac Toe!\n");

    printf("\nPlease enter to return Menu ");
    getchar();
    getchar();
    system("cls");
    inMenu();
}

// ham in ra ban co
void Inbanco(char banco[13][13]) {
    //lam sach man hinh sau moi lan in ban co
    system("cls");
    // dat bien dem stt cot trai
    int l = 0;
    // canh le cho dong dau
    printf("    ");
    //in stt cho dong dau
    for (int i = 0; i < 13; i++) {
        if (i == 2) {
            printf("1");
        } else if (i == 6) {
            printf("    2");
        } else if (i == 10) {
            printf("    3");
        } else {
            printf(" ");
        }
    }

    // canh le tren cot dau
    printf("\n");

    // in stt cho cot
    for (int i = 0; i < 13; i++) {


        // in ra stt cho cot
        if (l == 2) {
            printf("1 ");
        } else if (l == 6) {
            printf("2 ");
        } else if (l == 10) {
            printf("3 ");
        } else {
            printf("  ");
        }
        l++; // tang bien dem stt cot sau moi lan lap

        for (int j = 0; j < 13; j++) {
            printf("%c ", banco[i][j]);
        }
        printf("\n");
    }
}

// tao ham cho phep nhap X va Y
void Nhap(char banco[13][13], char player) {
    // tạo biến nhap và kiểm tra vị trí nhập trên bàn cờ và in ra X/O trên bàn cờ

    int nhap;
    while (1) {
        if (player == 'X') {
            printf("\nLuot nhap cua Player_1: ");
        } else {
            printf("\nLuot nhap cua Player_2: ");
        }

        scanf("%d", &nhap);
        getchar();
        if (KiemTraNhapHopLe(banco, nhap)) {
            break; // nếu nhập hợp lệ thì thoát vòng lặp
        }else if(isdigit(nhap)){
            printf("Your choose. Please enter again!");
        }
        else {
            printf("The position you entered has been filled in. Please enter again!");
        }
    }
    printf("\n");

    // Cập nhật bàn cờ dựa trên vị trí nhập
    switch (nhap) {
        case 11:
            banco[2][2] = player;
            break;
        case 12:
            banco[2][6] = player;
            break;
        case 13:
            banco[2][10] = player;
            break;
        case 21:
            banco[6][2] = player;
            break;
        case 22:
            banco[6][6] = player;
            break;
        case 23:
            banco[6][10] = player;
            break;
        case 31:
            banco[10][2] = player;
            break;
        case 32:
            banco[10][6] = player;
            break;
        case 33:
            banco[10][10] = player;
            break;
    }
}

// ham kiem tra vi tri da duoc danh dau hay chua

int KiemTraNhapHopLe(char banco[13][13], int nhap) {
    switch (nhap) {
        case 11:
            if (banco[2][2] == ' ') {
                return 1;
            } else {
                return 0;
            }

        case 12:
            if (banco[2][6] == ' ') {
                return 1;
            } else {
                return 0;
            }
        case 13:
            if (banco[2][10] == ' ') {
                return 1;
            } else {
                return 0;
            }
        case 21:
            if (banco[6][2] == ' ') {
                return 1;
            } else {
                return 0;
            }
        case 22:
            if (banco[6][6] == ' ') {
                return 1;
            } else {
                return 0;
            }
        case 23:
            if (banco[6][10] == ' ') {
                return 1;
            } else {
                return 0;
            }
        case 31:
            if (banco[10][2] == ' ') {
                return 1;
            } else {
                return 0;
            }
        case 32:
            if (banco[10][6] == ' ') {
                return 1;
            } else {
                return 0;
            }
        case 33:
            if (banco[10][10] == ' ') {
                return 1;
            } else {
                return 0;
            }
        default:
            return 0;
    }
}

// ham kiem tra nguoi thang cuoc

int checkWinner(char banco[13][13], char player) {
    // Check các hàng và cột
    for (int i = 0; i < 3; i++) {
        // Kiểm tra hàng i
        if (banco[i * 4 + 2][2] == player && banco[i * 4 + 2][6] == player && banco[i * 4 + 2][10] == player) {
            return 1; // Trả về 1 nếu có người chiến thắng
        }
        // Kiểm tra cột i
        if (banco[2][i * 4 + 2] == player && banco[6][i * 4 + 2] == player && banco[10][i * 4 + 2] == player) {
            return 1; // Trả về 1 nếu có người chiến thắng
        }
    }

    // Check đường chéo chính
    if (banco[2][2] == player && banco[6][6] == player && banco[10][10] == player) {
        return 1; // Trả về 1 nếu có người chiến thắng
    }

    // Check đường chéo phụ
    if (banco[2][10] == player && banco[6][6] == player && banco[10][2] == player) {
        return 1; // Trả về 1 nếu có người chiến thắng
    }

    // Nếu không có ai thắng
    return 0; // Trả về 0 nếu không có người chiến thắng
}

int checkDraw(char banco[13][13]) {
    for (int i = 2; i <= 10; i += 4) {
        for (int j = 2; j <= 10; j += 4) {
            if (banco[i][j] == ' ') {
                return 0; // neu van con o trong thi tra ve 0
            }
        }
    }
    return 1; // neu tat ca cac o deu ko co khoang trong thi tra ve 1
}

// ham hien thi thong bao sau khi ket thuc game
void Notification(){
    PlaySound(NULL, 0, 0); // Dừng phát âm thanh nền
    system("cls");
    printf("\n=====##==Notification==##=====\n\n");
    printf("1. Back to Menu\n2. Quit\n3. Play again\n\n");
    printf("======================\n");
    printf("Please enter: ");

    int nhapN;
    scanf("%d", &nhapN);

    switch (nhapN) {
        case 1:
            getchar();
            system("cls");
            inMenu();
            break;
        case 2:
            exit(0);
        case 3:
            getchar();
            system("cls");
            playGame();
            break;
        default:
            getchar();
            Notification();
            printf("Your choice is invalid. Please choose again!\n");

    }
}


// ham thuc hien tro choi
void playGame() {
//    Play
    PlaySound(TEXT("Sounds\\intro_game"), NULL, SND_ASYNC | SND_LOOP); // Phát âm thanh nền
    // khai bao ban co
    char banco[13][13] = {

        '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
        '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*',
        '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*',
        '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*',
        '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
        '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*',
        '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*',
        '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*',
        '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
        '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*',
        '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*',
        '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*',
        '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'

    };
    // in ra ban co
    Inbanco(banco);

    // ham thay phien nhap X/Y cua 2 player
    while (1) {
        Nhap(banco, 'X');
        Inbanco(banco);
        // Kiểm tra chiến thắng sau mỗi lượt đi của người chơi X
        if (checkWinner(banco, 'X')) {
            PlaySound(TEXT("Sounds\\win_game"), NULL, SND_ASYNC); // Phát âm thanh nền

            printf("Player X wins!\n");
            printf("\nPress Enter to continue...");
            getchar();  // doi nhan enter
            Notification();
            break;

        }
        if (checkDraw(banco)) {
            PlaySound(TEXT("Sounds\\game_hoa"), NULL, SND_ASYNC); // Phát âm thanh nền

            printf("The game is a draw!\n");
            printf("\nPress Enter to continue...");
            getchar();
            Notification();
            break;
        }
        Nhap(banco, 'O');
        Inbanco(banco);
        // Kiểm tra chiến thắng sau mỗi lượt đi của người chơi O
        if (checkWinner(banco, 'O')) {
            PlaySound(TEXT("Sounds\\win_game"), NULL, SND_ASYNC); // Phát âm thanh nền

            printf("Player O wins!\n");
            printf("\nPress Enter to continue...");
            getchar();
            Notification();
            break;
        }

        // kiem tra hoa

        if (checkDraw(banco)) {
            PlaySound(TEXT("Sounds\\game_hoa"), NULL, SND_ASYNC);

            printf("The game is a draw!\n");
            printf("\nPress Enter to continue...");
            getchar();
            Notification();
            break;
        }
    }
}

int main() {
    inMenu();
    return 0;
}

