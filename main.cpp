#include<iostream>
#include "piece.h"
#include "square.h"
#include "checkerBoard.h"
#include "gui.h"
#include <ncurses.h>

using namespace std;

int main(){
  
  //GUI
  initscr(); //makes screen
  raw(); //disables line buffer, AKA you don't have to press enter for getch and wgetch
  noecho(); //disables input displaying on screen
  start_color(); //enables colors
  
  //COLOR PAIRS
  //White square
  init_pair(1, COLOR_WHITE, COLOR_WHITE);
  //Black square/piece
  init_pair(2, COLOR_BLACK, COLOR_BLACK);
  //Red piece
  init_pair(3, COLOR_RED, COLOR_RED);
  //Screen border
  init_color(COLOR_MAGENTA, 500, 500, 500);
  init_pair(4, COLOR_MAGENTA, COLOR_MAGENTA);
  //King Piece
  init_color(COLOR_YELLOW, 1000, 800, 100);
  init_pair(5, COLOR_YELLOW, COLOR_YELLOW); 
  
  //TITLE BOX
  int title_h, title_w, title_y, title_x;

  title_h = 3;
  title_w = 10;
  title_y = 3;
  title_x = (COLS - title_w) / 2;

  WINDOW *title = newwin(title_h, title_w, title_y, title_x);
  box(title, 0, 0);
  mvwprintw(title, 1, 1, "CHECKERS");
  wrefresh(title); 
  
  //BOARD EDGE
  int edge_h, edge_w, edge_y, edge_x;

  edge_h = 26;
  edge_w = 50;
  edge_y = (LINES/6) - 1;
  edge_x = (COLS/2) - 25;

  WINDOW *edge = newwin(edge_h, edge_w, edge_y, edge_x);
  wattron(edge, COLOR_PAIR(4));
  box(edge, 0, 0);
  wattroff(edge, COLOR_PAIR(4));
  wrefresh(edge);
  
  //BOARD INITIALIZATION
  CheckerBoard board;
  board.initBoard();

  
  board.refreshBoard();
  wgetch(title);

  //Start square
  WINDOW* sqStart = board.getSqWin(33);
  wprintw(sqStart, "test");
  wrefresh(sqStart);
  wgetch(sqStart);
/*
  //TURNS
  int count = 0;
  int current_row = 0;
  int current_col = 0;
  int proposed_row = 0;
  int proposed_col = 0;
  int selected=0;
  
  while( count < 5 ) {
    int ch = wgetch(title);
    switch(ch) {
      case KEY_UP:
	      //move up
        if(selected==0){
          if(current_row==7)
            current_row=0;
          else
            ++current_row;
        }
        else{
          if(proposed_row==7)
            proposed_row=0;
          else
            ++proposed_row;
        }
	      break;
      case KEY_LEFT:
	      // move left
        if(selected==0){
          if(current_col==0)
            current_col=7;
          else
            --current_col;
        }
        else{
          if(proposed_col==0)
            proposed_col=7;
          else
            --proposed_col;
        }
	      break;
      case KEY_DOWN:
	      //move down
        if(selected==0){
          if(current_row==0)
            current_row=7;
          else
            --current_row;
        }
        else{
          if(proposed_col==0)
            proposed_row=7;
          else
            --proposed_row;
        }
	      break;
      case KEY_RIGHT:
	      if(selected==0){
          if(current_col==0)
            current_col=7;
          else
            --current_col;
        }
        else{
          if(proposed_col==7)
            proposed_col=0;
          else
            ++proposed_col;
        }
	      break;
      case 10: // ENTER
	      //select piece
        if(board.isCurrentEmpty(current_row,current_col)==0){
          if(selected==0){
            selected=1;
            board.getLegalMoves(current_row,current_col);
          }
          else{
            
          }
        }
        else{
          if(board.isCurrentEmpty(current_row,current_col)==0){

          }
          else
            printw("Empty square");
        }

        selected=0;
	      break;
      default:
	      printw("Please enter a valid input");
	      break;
    }
  
    board.refreshBoard();
  }

  */

  // TURNS
  /*
  Move ** legalmoves = new Move *[100];
  while(count < 10){
    cout << "Current row: " << endl;
    cin >> current_row;
    cout << "Current col: " << endl;
    cin >> current_col;
    if (board.isCurrentEmpty(current_row, current_col)) {
	cout << "Please choose a square that contains a checker piece." << "\n" << "\n";
	continue;
    }
    legalmoves = board.getLegalMoves(current_row, current_col);
    cout << "\n";
    cout << "Proposed row: " << endl;
    cin >> proposed_row;
    cout << "Proposed col: " << endl;
    cin >> proposed_col;
    board.move(current_row, current_col, legalmoves[proposed_row]);
    board.printBoard();
    count++;
  }
  
  */
  //GUI
  getch(); //REFRESHES PARENT SCREEN OVER CHILDREN
  endwin(); //ends ncurses mode
}
