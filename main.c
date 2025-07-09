#include<stdio.h>
#include<stdlib>
#include<stdbool.h>
#include<ncurses.h>

#define user "pmdev"
#define DeviceName "pmdev"
#define INPUT_BUFFER 1024
#define ctrl(x) ((x) & 0x1f)


int main(int argc,char **argv){
    initscr();
    raw();
    noecho();
    
    bool QUIT = false;
    int ch;

    char command[INPUT_BUFFER] = {0};
    size_t command_s = 0;
    size_t line = 0;
    
    while(!QUIT){
        mvprintw(line,0,"%s@%s$",DeviceName,user);
        printw(command);
        ch = getch();
        switch(ch){
            case ctrl(q):
                QUIT = true;
                break;
            case 10:
                line++;
                memset(command,0,sizeof(char)*command_s);
                command_s=0;
                break;
            default:
                command[command_s++] = ch;
                break;
        }
        erase();
    }
    refresh();
    endwin();
    return 0;
}
