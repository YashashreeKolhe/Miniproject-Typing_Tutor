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

void reg_window(WINDOW *subwin, int boolean){
	int i = 0, j;
	int ch, x, y;
	char arr[16];
	FILE *fp;
	fp = fopen("score_record.txt", "a+");
	box(subwin, 0, 0);
	wattron(subwin, A_STANDOUT);
	mvwprintw(subwin,2, 3, "Enter Your Username:");
	wattroff(subwin, A_STANDOUT);
	wrefresh(subwin);
	keypad(subwin, TRUE);
	while(i<16){
		ch = wgetch(subwin);
		if(ch == KEY_BACKSPACE){
			getyx(subwin, y, x);
			wmove(subwin, y,x-1);
			wdelch(subwin);
			cbreak();
			wrefresh(subwin);
			i--;
			continue;	
		}
		if(ch == 27){
			wclear(subwin);
			wrefresh(subwin);
			speed(subwin);
		}
		if(ch == 10)
			break;
		wprintw(subwin,"%c", ch);
		arr[i] = ch;
		i++;
	}	
	for(j = 0; j<i;j++)
		fprintf(fp, "%c", arr[j]);
	fclose(fp);
}

