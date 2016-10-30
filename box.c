/*****************************************************************************
 * Copyright (C) Yashashree V.K. yashashreekolhe@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
#include<ncurses.h>

int box1(WINDOW *subwin) {
	initscr();
	noecho();
	crmode();
	start_color();
	int height = 4, width = 7;
 	char *arr[61] = {"~", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "_", "+", "Bkspc", "Tab", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "{", "}", "|", "Cpslk", "A", "S", "D", "F", "G", "H", "J", "K", "L", ":", "\"", "Enter", "Shift", "Z", "X", "C", "V", "B", "N", "M", "<", ">", "?", "Shift", "Cntrl", "Fn", "Win", "Alt", "Space", "Alt", "Ctrl"};
	char *arr2[61] = {"`", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "[", "]", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", ";", "'", " ", " ", " ", " ", " ", " ", " ", " ", " ", ",", ".", "/", " ", " ", " ", " ", " ", " ", " ", " "};
 	int i = 0, j = 0, k = 14, m = 0, z = 0, g = 0;
 	WINDOW *win;	
 	subwin = newwin(22, 100, 21, 0);
	box(subwin, 0, 0);
	wrefresh(subwin);
	for(i = 0; i<5;i++){
    		for(j = 0; j<k;j++) {
    			if(m == 2){
	    			k = 13;
	    			width = 7;
	    		}
	    		else if(m == 3){
	    			k = 12;
	    			width = 8;
	    		}
	    		else if(m == 4){
	    			k = 7;
	    			width = 12;
	    		}
	    		else
	  			width = 7;
	   		
	    		if(i == 0 && j == 0)
	    			win = newwin(height, width, 22, 1);
	    		else if(i == 0)
	    			win = newwin(height, width, 22, (j*width)+1);
	    		else if(j == 0)
	    			win = newwin(height, width, (i*height)+22, 1);
	    		else
    				win = newwin(height, width, (i*height)+22, (j*width)+1);
    			mvwprintw(win, 1, 1, "%s", arr[z++]);
    			mvwprintw(win, 2, 1, "%s", arr2[g++]);
    			box(win, 0, 0);
    			wrefresh(win);
    			wrefresh(subwin);
    		}	
    		m++;
   	}
   	printf("\n");
   	return 0;
}

void practice_box(WINDOW *subwin){
	initscr();
	noecho();
   	crmode();
   	start_color();
   	init_pair(1, COLOR_WHITE, COLOR_CYAN);
   	init_pair(4, COLOR_WHITE, COLOR_GREEN);
   	init_pair(2, COLOR_WHITE, COLOR_BLUE);
   	WINDOW *wwin;
   	wwin = newwin(8, 25, 21, 111);
   	box(wwin, 0, 0);
   	wbkgd(wwin, COLOR_PAIR(1));
	wrefresh(wwin);
	wattron(wwin, COLOR_PAIR(2));
	mvwprintw(wwin, 1, 1, "Blue-Left Hand");
	wattroff(wwin, COLOR_PAIR(2));
	wattron(wwin, COLOR_PAIR(4));
	mvwprintw(wwin, 2, 1, "Green-Right Hand");
	wattroff(wwin, COLOR_PAIR(4));
	mvwprintw(wwin, 3, 1, "F-Fore Finger");
	mvwprintw(wwin, 4, 1, "T-Thumb");
	mvwprintw(wwin, 5, 1, "M-Middle Finger");
	mvwprintw(wwin, 6, 1, "R-Ring Finger");
	mvwprintw(wwin, 6, 1, "L-Little Finger");
	wrefresh(wwin);
}
	
