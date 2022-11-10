﻿#include <iostream>
#include <time.h>
#include <string>
#include <stdio.h>
#include <locale.h>
#include <ctime>
using namespace std;

char** make_field(int height, int width, int bombs){
    char** field = new char* [height];
    for (int i = 0; i < height; i++)
        field[i] = new char[width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++) {
            field[i][j] = ' ';
        }
    }
    int k = bombs;
    while (k > 0)
    {
        int x = rand() % width;
        int y = rand() % height;
        if (field[y][x] != '*')
        {
            field[y][x] = '*';
            k--;
        }
    }
    if (field[0][0] != '*')
    {
        int kb = 0;
        if (field[1][0] == '*')
            kb++;
        if (field[0][1] == '*')
            kb++;
        if (field[1][1] == '*')
            kb++;
        if (kb > 0)
            field[0][0] = (char)(((int)'0') + kb);
    }
    if (field[0][width-1] != '*')
    {
        int kb = 0;
        if (field[1][width-1] == '*')
            kb++;
        if (field[0][width-2] == '*')
            kb++;
        if (field[1][width-2] == '*')
            kb++;
        if (kb > 0)
            field[0][width] = (char)(((int)'0') + kb);
    }
    if (field[height-1][width-1] != '*')
    {
        int kb = 0;
        if (field[height - 2][width - 1] == '*')
            kb++;
        if (field[height - 1][width - 2] == '*')
            kb++;
        if (field[height - 2][width - 2] == '*')
            kb++;
        if (kb > 0)
            field[height-1][width-1] = (char)(((int)'0') + kb);
    }
    if (field[height-1][0] != '*')
    {
        int kb = 0;
        if (field[height - 2][0] == '*')
            kb++;
        if (field[height-1][1] == '*')
            kb++;
        if (field[height - 2][1] == '*')
            kb++;
        if (kb > 0)
            field[height-1][width-1] = (char)(((int)'0') + kb);
    }
    for (int i = 1; i < width - 1; i++) {
        int kb = 0;
        if (field[0][i] != '*')
        {
            
            if (field[0][i - 1] == '*')
                kb++;
            if (field[1][i - 1] == '*')
                kb++;
            if (field[1][i] == '*')
                kb++;
            if (field[1][i + 1] == '*')
                kb++;
            if (field[0][i + 1] == '*')
                kb++;
            if (kb > 0)
                field[0][i] = (char)(((int)'0') + kb);
        }
        
    }
    for (int i = 1; i < height - 1; i++) {
        int kb = 0;
        if (field[i][0] != '*')
        {

            if (field[i - 1][0] == '*')
                kb++;
            if (field[i - 1][1] == '*')
                kb++;
            if (field[i][1] == '*')
                kb++;
            if (field[i+1][1] == '*')
                kb++;
            if (field[i+1][0] == '*')
                kb++;
            if (kb > 0)
                field[i][0] = (char)(((int)'0') + kb);
        }
    }
    for (int i = 1; i < height - 1; i++) {
        int kb = 0;
        if (field[i][width-1] != '*')
        {

            if (field[i - 1][width - 1] == '*')
                kb++;
            if (field[i - 1][width - 2] == '*')
                kb++;
            if (field[i][width - 2] == '*')
                kb++;
            if (field[i + 1][width - 2] == '*')
                kb++;
            if (field[i + 1][width - 1] == '*')
                kb++;
            if (kb > 0)
                field[i][width - 1] = (char)(((int)'0') + kb);
        }
    }
    for (int i = 1; i < width - 1; i++) {
        int kb = 0;
        if (field[height-1][i] != '*')
        {

            if (field[height-1][i - 1] == '*')
                kb++;
            if (field[height-2][i - 1] == '*')
                kb++;
            if (field[height-2][i] == '*')
                kb++;
            if (field[height-2][i + 1] == '*')
                kb++;
            if (field[height-1][i + 1] == '*')
                kb++;
            if (kb > 0)
                field[height-1][i] = (char)(((int)'0') + kb);
        }
    }
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            int kb = 0;
            if (field[i][j] != '*'){
                if (field[i - 1][j - 1] == '*')
                    kb++;
                if (field[i - 1][j] == '*')
                    kb++;
                if (field[i - 1][j + 1] == '*')
                    kb++;
                if (field[i][j + 1] == '*')
                    kb++;
                if (field[i + 1][j + 1] == '*')
                    kb++;
                if (field[i + 1][j] == '*')
                    kb++;
                if (field[i + 1][j - 1] == '*')
                    kb++;
                if (field[i][j - 1] == '*')
                    kb++;
                if (kb > 0)
                    field[i][j] = (char)(((int)'0') + kb);
            }
        }
    }
    return field;
}

void open_empty_cell(char** view_field, char** field, int x, int y, int height, int width) {
    if (x >= 0 && y >= 0 && x < width && y < height) {
        view_field[y][x] = field[y][x];
        if (field[y][x] == ' ')
        {
            if (x!=0&&y!=0&&view_field[y-1][x-1]=='#')
            open_empty_cell(view_field, field, x - 1, y - 1, height, width);
            if (y != 0 && view_field[y - 1][x] == '#')
            open_empty_cell(view_field, field, x, y - 1, height, width);
            if ((x != width - 1) && y != 0 && view_field[y - 1][x + 1] == '#')
            open_empty_cell(view_field, field, x + 1, y - 1, height, width);
            if ((x != width - 1) && view_field[y][x + 1] == '#')
            open_empty_cell(view_field, field, x + 1, y, height, width);
            if ((y != height - 1) && (x != width - 1) && view_field[y + 1][x + 1] == '#')
            open_empty_cell(view_field, field, x + 1, y + 1, height, width);
            if ((y != height - 1) &&view_field[y + 1][x] == '#')
            open_empty_cell(view_field, field, x, y + 1, height, width);
            if (x != 0 && (y != height - 1) && view_field[y + 1][x - 1] == '#')
            open_empty_cell(view_field, field, x - 1, y + 1, height, width);
            if (x != 0 && view_field[y][x - 1] == '#')
            open_empty_cell(view_field, field, x - 1, y, height, width);
        }
    }
}
char** make_view_field(int height, int width, int bombs) {
    char** view_field = new char* [height];
    for (int i = 0; i < height; i++)
        view_field[i] = new char[width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++) {
            view_field[i][j] = '#';
        }
    }
    return view_field;
}
void output_field(char** field, int height, int width)
{
    printf("   |");
    for (int i = 0; i < width; i++) {
        printf("%3d", i);
        cout << "|";
    }
    cout << endl;
    for (int i = 0; i < height; i++)
    {
        for (int i = 0; i <= width; i++) {
            cout << "____";
        }
        cout << endl;
        printf("%3d", i);
        for (int j = 0; j < width; j++) {
            cout << "|";
            printf("%3c", field[i][j]);
        }
        cout << "|";
        cout << endl;
    }
    for (int i = 0; i <= width; i++) {
        cout << "____";
    }
    cout << endl;
}
int menu() {
    
    cout << "1-Start Game" << endl;
    cout << "2-Instructions" << endl;
    cout << "3-Exit" << endl;
    //cout << rand() % 2<<endl;
    int m;
    char c;
    if (scanf_s(" %d%c", &m, &c) && c == '\n') {
        system("cls");
        switch (m) {
        case 1:
        {
            return 1;
        }
        case 2: {
            return 2;
        }
        case 3: {
            return 3;
        }
        default:
            system("cls");
        }
    }
    else {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("cls");
        menu();
    }
}
int enter_level() {
    int n;
    char c;
    cout << "Enter a level of game(1-easy, 2-medium, 3-hard) or 0 to exit in main menu" << endl;
    if (scanf_s("%d%c", &n, &c) && c=='\n') {
        system("cls");
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        else if (n == 3)
            return 3;
        else if (n == 0)
            return 0;
        else
            enter_level();
    }
    else {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("cls");
        enter_level();
    }
   
}
int instruction() {
    int n;
    char c;
    cout << "Instructions:" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "|You should enter a coordinates like 'x y'                                     |" << endl;
    cout << "|Next write action                                                             |" << endl;
    cout << "|If you want to open a cell, write o(o-open)                                   |" << endl;
    cout << "|Else write f(f-flag) to put a flag                                            |" << endl;
    cout << "|You will win, if in all bombs stay a flag and count of flags == count of bombs|" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "Write 0 to exit in main menu" << endl;
    if (scanf_s("%d%c", &n, &c) && c == '\n')
        if (n == 0) {
            return 0;
        }
        else {
            system("cls");
            instruction();
        }
    else
    {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("cls");
        instruction();
    }
}
bool check_win(char** view_field, char** field, int height, int width, int bombs) {
    int flags=0, flag_in_bomb = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++) {
            if (view_field[i][j] == '!') {
                flags++;
                if (field[i][j] == '*')
                    flag_in_bomb++;
            }
        }
    }
    return flags == flag_in_bomb && flags == bombs;
}
bool check_around(char** view_field, char** field, int x, int y, int height, int width) {
    int flags = 0, flag_in_bomb = 0, bombs=0;
    if (x != 0 && y != 0 && field[y - 1][x - 1] == '*')
    {
        bombs++;
        if (view_field[y - 1][x - 1] == '!')
            flag_in_bomb++;
                
    }
    if (y != 0 && field[y - 1][x] == '*') {
        bombs++;
        if (view_field[y - 1][x] == '!')
            flag_in_bomb++;
    }
    if ((x != width - 1) && y != 0 && field[y - 1][x + 1] == '*') {
        bombs++;
        if (view_field[y - 1][x + 1] == '!')
            flag_in_bomb++;
    }
    if ((x != width - 1) && field[y][x + 1] == '*') {
        bombs++;
        if (view_field[y][x + 1] == '!')
            flag_in_bomb++;
    }
    if ((y != height - 1) && (x != width - 1) && field[y + 1][x + 1] == '*') {
        bombs++;
        if (view_field[y + 1][x + 1] == '!')
            flag_in_bomb++;
    }
    if ((y != height - 1) && field[y + 1][x] == '*') {
        bombs++;
        if (view_field[y + 1][x] == '!')
            flag_in_bomb++;
    }
    if (x != 0 && (y != height - 1) && field[y + 1][x - 1] == '*') {
        bombs++;
        if (view_field[y + 1][x - 1] == '!')
            flag_in_bomb++;
    }
    if (x != 0 && field[y][x - 1] == '*') {
        bombs++;
        if (view_field[y][x - 1] == '!')
            flag_in_bomb++;
    }

    if (x != 0 && y != 0 && view_field[y - 1][x - 1] == '!')
        flags++;
    if (y != 0 && view_field[y - 1][x] == '!') 
        flags++;
    if ((x != width - 1) && y != 0 && view_field[y - 1][x + 1] == '!') 
        flags++;
    if ((x != width - 1) && view_field[y][x + 1] == '!') 
        flags++;
    if ((y != height - 1) && (x != width - 1) && view_field[y + 1][x + 1] == '!') 
        flags++;
    if ((y != height - 1) && view_field[y + 1][x] == '!') 
        flags++;
    if (x != 0 && (y != height - 1) && view_field[y + 1][x - 1] == '!') 
        flags++;
    if (x != 0 && view_field[y][x - 1] == '!') 
        flags++;
    return flags == flag_in_bomb&&bombs==flag_in_bomb;
}

void open_around(char** view_field, char** field, int x, int y, int height, int width) {
    if (x != 0 && y != 0 && view_field[y - 1][x - 1] != '!') {
        view_field[y - 1][x - 1] = field[y - 1][x - 1];
        open_empty_cell(view_field, field, x-1, y-1, height, width);
    }
    if (y != 0 && view_field[y - 1][x] != '!') {
        view_field[y - 1][x] = field[y - 1][x];
        open_empty_cell(view_field, field, x, y-1, height, width);
    }
    if ((x != width - 1) && y != 0 && view_field[y - 1][x + 1] != '!') {
        view_field[y - 1][x + 1] = field[y - 1][x + 1];
        open_empty_cell(view_field, field, x+1, y-1, height, width);
    }
    if ((x != width - 1) && view_field[y][x + 1] != '!') {
        view_field[y][x + 1] = field[y][x + 1];
        open_empty_cell(view_field, field, x+1, y, height, width);
    }
    if ((y != height - 1) && (x != width - 1) && view_field[y + 1][x + 1] != '!') {
        view_field[y + 1][x + 1] = field[y + 1][x + 1];
        open_empty_cell(view_field, field, x+1, y+1, height, width);
    }
    if ((y != height - 1) && view_field[y + 1][x] != '!') {
        view_field[y + 1][x] = field[y + 1][x];
        open_empty_cell(view_field, field, x, y+1, height, width);
    }
    if (x != 0 && (y != height - 1) && view_field[y + 1][x - 1] != '!') {
        view_field[y + 1][x - 1] = field[y + 1][x - 1];
        open_empty_cell(view_field, field, x-1, y+1, height, width);
    }
    if (x != 0 && view_field[y][x - 1] != '!') {
        view_field[y][x - 1] = field[y][x - 1];
        open_empty_cell(view_field, field, x-1, y, height, width);
    }
}
int main()
{
    
    setlocale(LC_ALL, "");
    srand(time(NULL));
    int height, width, bombs;
    bool f = true;
    while (f) {
        switch (menu()){
        case 1:
            switch (enter_level()) {
            case 0:
            {
                system("cls");
                break;
            }
            case 1:
            {
                height = 9;
                width = 9;
                bombs = 10;
                f = false;
                break;
            }
            case 2: {
                height = 16;
                width = 16;
                bombs = 40;
                f = false;
                break; }
            case 3: {
                height = 16;
                width = 30;
                bombs = 99;
                f = false;
                break; }
            }
            break;
        case 2:
            instruction();
            break;
        case 3:
            return 0;
        default:
            break;
        }
        system("cls");
        
    }
    char** field = make_field(height, width, bombs); 
    char** view_field = make_view_field(height, width, bombs);
    int x, y;
    char d, c;
    f = true;
    unsigned int start_time = clock();
    while (f) {
        output_field(view_field, height, width);
        cout << "Enter a x coord and a y coord with 'space', 'enter' and (f/o) "<<endl;
        if (scanf_s("%d%c", &x, &c) && c == ' ' && x >= 0 && x < width && scanf_s("%d%c", &y, &c) && c == '\n' && y >= 0 && y < height && scanf_s("%c%c", &d, &c) && c == '\n' && (d == 'o' || d == 'f'))
        {
            if (d == 'o') {
                if (field[y][x] == '*')
                {
                    system("cls");
                    output_field(field, height, width);
                    cout << "You lose!!!" << endl;
                    unsigned int end_time = clock();
                    unsigned int search_time = end_time - start_time;
                    cout << "Your time is "<< search_time / 1000.0;
                    return 0;
                }
                else if (field[y][x] == ' ') {
                    open_empty_cell(view_field, field, x, y, height, width);
                }
                else if (view_field[y][x] >= '1' && view_field[y][x] <= '8')
                {
                    if (check_around(view_field, field, x, y, height, width)) {
                        open_around(view_field, field, x, y, height, width);
                    }

                }
                else
                    view_field[y][x] = field[y][x];
            }
            else if (d == 'f')
                if (view_field[y][x] == '#')
                    view_field[y][x] = '!';
                else if (view_field[y][x] == '!')
                    view_field[y][x] = '#';
        }
        else
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("cls");
        if (check_win(view_field, field, height, width, bombs))
        {
            system("cls");
            output_field(field, height, width);
            cout << "You win!!!"<<endl;
            unsigned int end_time = clock();
            unsigned int search_time = end_time - start_time;
            cout << "Your time is " << search_time / 1000.0;
            return 0;
        }
    }
    
}
