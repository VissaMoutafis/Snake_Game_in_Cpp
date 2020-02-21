#include "Graphics.h"
#include <chrono>
#include <thread>
///Utillities for the graphics
unsigned int sleepTime = 50000000;
static WINDOW *_box = NULL;

static void createBox(void){
    _box = newwin(LINES-2, COLS, 2, 0);
    box(_box, 0, 0);
    wrefresh(_box);
}
static void destroyBox(void){
    wborder(_box, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(_box);
    delwin(_box);
}
//Initialization function
void initializeGraphics(void){
    initscr(); //initialize curses
    cbreak(); //set line buffering to false
    noecho(); //set input echo to false
    keypad(stdscr, TRUE); //this step enables the use of arrow keys and other function keys
    nodelay(stdscr, true);
    //We must clear the screen from unecessary garbage
    clear();
    //Print the title
    mvprintw(0, (COLS/2) - 12, "~Snake Game by VissaM~");
    refresh();
    
    //create the game box
    createBox();
}

//Exit function
void endGraphics(void){
    destroyBox();
    endwin();
}

//Typical refresh function (ease the eye with a custom function instead of the actual one)
void refreshScreen(void){
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono;      // nanoseconds, system_clock, seconds
    sleep_for(nanoseconds(sleepTime));
    
    refresh(); // just use the curses version ;p
    wrefresh(_box);
}

void printChar(int y, int x, graphics_input img){
    mvwaddch(_box, y, x, img);
    refresh();
    wrefresh(_box);
}

void printMsg(int y, int x, char* str){
    mvwaddstr(_box, y, x, str);
    refresh();
    wrefresh(_box);
}

char readChar(int y, int x){
    mvwgetch(_box, y, x);
    refresh();
    wrefresh(_box);
}

int readInpt(){
    return getch();
}
