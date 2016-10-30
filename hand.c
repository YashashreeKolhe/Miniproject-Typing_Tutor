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
#include"dummy.h"

void hand(WINDOW *subwin) {
	int i, j, k;
	start_color();
	init_pair(4, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_WHITE, COLOR_GREEN);
	
	WINDOW *new = newwin(10, 15, 21, 101);
	//wbkgd(new, COLOR_PAIR(5));
	for(j = 0; j<=2; j = j+2){
		for(i = 3; i<6; i++) {
			mvwprintw(new, i, j, "|");
		}
	}
	for(k = j-1; k<=(j+1); k+=2) {
		for(i = 2; i<6; i++) {
			mvwprintw(new, i, k, "|");
		}
	}
	for(j = k-1; j<=(k+1); j+=2) {
		for(i = 1; i<6; i++) {
			mvwprintw(new, i, j, "|");
		}
	}
	for(k = j-1; k<=(j+1); k+=2) {
		for(i = 2; i<6; i++) {
			mvwprintw(new, i, k, "|");
		}
	}
	for(j = k-1; j<=(k+1); j+=2) {
		for(i = 4; i<6; i++) {
			mvwprintw(new, i, j, "|");
		}
	}
	mvwprintw(new, 2, 1, "_");
	wattron(new, COLOR_PAIR(4) | A_BOLD);
	mvwprintw(new, 3, 1, "L");
	wattroff(new, COLOR_PAIR(4) | A_BOLD);
	mvwprintw(new, 1, 4, "_");
	wattron(new, COLOR_PAIR(4) |A_BOLD);
	mvwprintw(new, 2, 4, "R");
	wattroff(new, COLOR_PAIR(4) |A_BOLD);
	mvwprintw(new, 0, 7, "_");
	wattron(new, COLOR_PAIR(4) |A_BOLD);
	mvwprintw(new, 1, 7, "M");
	wattroff(new, COLOR_PAIR(4) |A_BOLD);
	mvwprintw(new, 1, 10, "_");
	wattron(new, COLOR_PAIR(4) |A_BOLD);
	mvwprintw(new, 2, 10, "F");
	wattroff(new, COLOR_PAIR(4) |A_BOLD);
	mvwprintw(new, 3, 13, "_");
	wattron(new, COLOR_PAIR(4) |A_BOLD);
	mvwprintw(new, 4, 13, "T");
	wattroff(new, COLOR_PAIR(4) |A_BOLD);
	mvwprintw(new, 6, 0, "|");
	mvwprintw(new, 7, 0, "|");
	mvwprintw(new, 6, 14, "|");
	mvwprintw(new, 7, 14, "|");
	mvwprintw(new, 8, 0, "\\");
	mvwprintw(new, 8, 14, "/");
	mvwprintw(new, 9, 1, "\\");
	mvwprintw(new, 9, 13, "/");
	for(i = 2; i<13; i++)
		mvwprintw(new, 9, i, "_");
	wattron(new, COLOR_PAIR(4) |A_BOLD);
	mvwprintw(new, 7, 5, "LEFT");
	wattroff(new, COLOR_PAIR(4) |A_BOLD);
	wrefresh(new);
	
	WINDOW *new2 = newwin(10, 15, 21, 116);
	//wbkgd(new, COLOR_PAIR(5));
	for(j = 0; j<=2; j+=2){
		for(i = 4; i<6; i++) {
			mvwprintw(new2, i, j, "|");
		}
	}
	for(k = j-1; k<=(j+1); k+=2) {
		for(i = 2; i<6; i++) {
			mvwprintw(new2, i, k, "|");
		}
	}
	for(j = k-1; j<=(k+1); j+=2) {
		for(i = 1; i<6; i++) {
			mvwprintw(new2, i, j, "|");
		}
	}
	for(k = j-1; k<=(j+1); k+=2) {
		for(i = 2; i<6; i++) {
			mvwprintw(new2, i, k, "|");
		}
	}
	for(j = k-1; j<=(k+1); j+=2) {
		for(i = 3; i<6; i++) {
			mvwprintw(new2, i, j, "|");
		}
	}
	mvwprintw(new2, 3, 1, "_");
	wattron(new2, COLOR_PAIR(2) |A_BOLD);
	mvwprintw(new2, 4, 1, "T");
	wattroff(new2, COLOR_PAIR(2) |A_BOLD);
	mvwprintw(new2, 1, 4, "_");
	wattron(new2, COLOR_PAIR(2) |A_BOLD);
	mvwprintw(new2, 2, 4, "F");
	wattroff(new2, COLOR_PAIR(2) |A_BOLD);
	mvwprintw(new2, 0, 7, "_");
	wattron(new2, COLOR_PAIR(2) |A_BOLD);
	mvwprintw(new2, 1, 7, "M");
	wattroff(new2, COLOR_PAIR(2) |A_BOLD);
	mvwprintw(new2, 1, 10, "_");
	wattron(new2, COLOR_PAIR(2) | A_BOLD);
	mvwprintw(new2, 2, 10, "R");
	wattroff(new2, COLOR_PAIR(2) | A_BOLD);
	mvwprintw(new2, 2, 13, "_");
	wattron(new2, COLOR_PAIR(2) | A_BOLD);
	mvwprintw(new2, 3, 13, "L");
	wattroff(new2, COLOR_PAIR(2) | A_BOLD);
	mvwprintw(new2, 6, 0, "|");
	mvwprintw(new2, 7, 0, "|");
	mvwprintw(new2, 6, 14, "|");
	mvwprintw(new2, 7, 14, "|");
	mvwprintw(new2, 8, 0, "\\");
	mvwprintw(new2, 8, 14, "/");
	mvwprintw(new2, 9, 1, "\\");
	mvwprintw(new2, 9, 13, "/");
	for(i = 2; i<13; i++)
		mvwprintw(new2, 9, i, "_");
	wattron(new2, COLOR_PAIR(2) |A_BOLD);
	mvwprintw(new2, 7, 5, "RIGHT");
	wattroff(new2, COLOR_PAIR(2) |A_BOLD);
	wrefresh(new2);
}
