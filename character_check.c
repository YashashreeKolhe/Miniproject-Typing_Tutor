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

void character_check(WINDOW *subwin, char *str, int boolean, int function) {	
	struct timeval t1, t2;
	struct timeval s1, s2;
	FILE *fp;
	tree st;
	datas *l;
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_CYAN);
	init_pair(2, COLOR_BLACK, COLOR_BLUE);
	init_pair(4, COLOR_BLACK, COLOR_GREEN);
	char **a = (char **)malloc(sizeof(char *));
	*a = (char *)malloc(sizeof(char)*10);
	strcpy(*a, "./project");
	char arr[1024], ch2, temp;
	int ch1, snt, counter = 0, counter2 = 0;
	int j = 0, x, y, z = 0, f = 0, m = 0, n = 0, q = 0;
	int localx, localy;
	int startx = 0;
	int starty = 0;
	stack s;
	sinit(&s);
	subwin = newwin(40, 138, starty, startx);
	wresize(subwin, height, width);
	wattron(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
	mvwprintw(subwin, 0, 0, "Press 'ESC' to quit the race and press 'UP ARROW KEY' to restart the race..                            ");
	wattroff(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
	keypad(subwin, TRUE);
	raw();
	noecho();
	cbreak();
	start_color();
	wrefresh(subwin);
	fp = fopen(str, "r");
	wmove(subwin, 4, 0);
	while(!feof(fp)){
		fscanf(fp, "%c", &ch2);
		wprintw(subwin,"%c", ch2);
		arr[j++] = ch2;
	}
	arr[j] = '\0';
	wrefresh(subwin);
	fclose(fp);
	if(function == 1) {
		if(width >= 130) {
			box1(subwin);
			//practice_box(subwin);
			hand(subwin);
		}
	}
	wattron(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);
	mvwprintw(subwin, 10, 0, "Enter your text here:");
	wattroff(subwin, COLOR_PAIR(1) | A_BOLD | A_ITALIC);                                                                               
	wrefresh(subwin);
	j = 0;
	startx = 0;
	starty = 11;
	gettimeofday(&t1, NULL);
	if(function == 1) {
		datat(&st);
		if(arr[0] == 33 || arr[0] == 44 || arr[0] == 46 || arr[0] == 58 || arr[0] == 59 || arr[0] == 45 || arr[0] == 63){
					wattroff(subwin, A_STANDOUT);
					wmove(subwin,starty, startx++);
					wrefresh(subwin);
		}
		else {
			if(arr[0] == 34) {
					wattron(subwin, COLOR_PAIR(2));
					mvwprintw(subwin, 20, 40, "Press \" with Littlefinger of  Right hand");
					mvwprintw(subwin, 32, 4 + 7*11, "L");
					wattroff(subwin, COLOR_PAIR(2));
					localx = 4+7*11;
					localy = 32;
					if(startx == (width-1)) {
						startx = 0;
						starty++;
					}
					wattroff(subwin, A_STANDOUT);
					wmove(subwin,starty, startx++);
					wrefresh(subwin);
			}
			else if(arr[0]<=90 && arr[0]>=65){
			 	temp = arr[0];
			 	temp = temp + 32;
			}
			else
				temp = arr[0];
			l = traverse(st, temp);
			if(l->hand == 'r') {
				wattron(subwin, COLOR_PAIR(2));
				if(l->finger == 'f') {
					mvwprintw(subwin, 20, 40, "Press %c with Forefinger   of Right hand", l->str);
					mvwprintw(subwin, l->loc_y, l->loc_x, " F ");
					localx = l->loc_x;
					localy = l->loc_y;
				}
				else if(l->finger == 'l') {
					mvwprintw(subwin, l->loc_y, l->loc_x, " L ");
					mvwprintw(subwin, 20, 40, "Press %c with Littlefinger of Right hand", l->str);
					localx = l->loc_x;
					localy = l->loc_y;
				}
				else if(l->finger == 'm') {
					mvwprintw(subwin, 20, 40, "Press %c with Middlefinger of Right hand", l->str);
					mvwprintw(subwin, l->loc_y, l->loc_x, " M ");
					localx = l->loc_x;
					localy = l->loc_y;
				}
				else if(l->finger == 'r') {
					mvwprintw(subwin, 20, 40, "Press %c with Ringfinger   of Right hand", l->str);
					mvwprintw(subwin, l->loc_y, l->loc_x, " R ");
					localx = l->loc_x;
					localy = l->loc_y;
				}
				wattroff(subwin, COLOR_PAIR(2)); 
			}    
			else if(l->hand == 'l') {
				wattron(subwin, COLOR_PAIR(4));
				if(l->finger == 'f') {
					mvwprintw(subwin, 20, 40, "Press %c with Forefinger    of Left hand", l->str);
					mvwprintw(subwin, l->loc_y, l->loc_x, " F ");
					localx = l->loc_x;
					localy = l->loc_y;
				}
				else if(l->finger == 'l') {
					mvwprintw(subwin, 20, 40, "Press %c with Littlefinger  of Left hand", l->str);
					mvwprintw(subwin, l->loc_y, l->loc_x, " L ");
					localx = l->loc_x;
					localy = l->loc_y;
				}
				else if(l->finger == 'm') {
					mvwprintw(subwin, 20, 40, "Press %c with Middlefinger  of Left hand", l->str);
					mvwprintw(subwin, l->loc_y, l->loc_x, " M ");
					localx = l->loc_x;
					localy = l->loc_y;	
				}
				else if(l->finger == 'r') {
					mvwprintw(subwin, 20, 40, "Press %c with  Ringfinger   of Left hand", l->str);
					mvwprintw(subwin, l->loc_y, l->loc_x, " R ");
					localx = l->loc_x;
					localy = l->loc_y;
				}      
			}	
			wattroff(subwin, COLOR_PAIR(4));
		}
	}
	wrefresh(subwin);
	wmove(subwin, 11, 0);
	startx = 1;
	starty = 11;
	while(1){
		if(arr[j+2] == '\0') {
			wmove(subwin, localy, localx);
			wattroff(subwin, A_STANDOUT);
			wprintw(subwin, " ");
			wrefresh(subwin);
			break;
		}
		getyx(subwin, y, x);
		ch1 = wgetch(subwin);
		wattroff(subwin, A_STANDOUT);
		counter++;
		gettimeofday(&s1,NULL);
		if(ch1 == 27){
			wclear(subwin);
			if(function == 2)
				speed(subwin);	
			else if(function == 3)
				num_drill(subwin);
			else if(function == 1)
				practice(subwin);			
		}
		if(ch1 == KEY_UP){
			wclear(subwin);
			wrefresh(subwin);
			if(function == 2)
				speed_test(subwin, str, boolean);
			else if(function == 3)
				num_test(subwin, str, boolean);
			else if(function == 1)
				prac_lesson(subwin, str, 2);
		}
		if(arr[j] == ch1){
			push(&s, ch1);
			wprintw(subwin,"%c", ch1);
			wrefresh(subwin);
			if(function == 1) {
				wmove(subwin, localy, localx);
				wattroff(subwin, A_STANDOUT);
				wprintw(subwin, "   ");
				wrefresh(subwin);
				if(arr[j+1] == 32) {   
					wattron(subwin, COLOR_PAIR(2));
					mvwprintw(subwin, 20, 40, "Press ' ' with Thumb      of Right hand");
					mvwprintw(subwin, 40, 4 + 12*4, " T ");
					wattroff(subwin, COLOR_PAIR(2));
					localx = 4+12*4;
					localy = 40;
					if(startx == (width-1)) {
						startx = 0;
						starty++;
					}
					wattroff(subwin, A_STANDOUT);
					wmove(subwin,starty, startx++);
					wrefresh(subwin);
				}
				else if(arr[j+1] == 33) {
					wattron(subwin, COLOR_PAIR(4));
					mvwprintw(subwin, 20, 40, "Press ! with Littlefinger  of Left hand");
					mvwprintw(subwin, 24, 4 + 7, " L ");
					wattroff(subwin, COLOR_PAIR(4));
					localx = 4+7;
					localy = 24;
					if(startx == (width-1)) {
						startx = 0;
						starty++;
					}
					wattroff(subwin, A_STANDOUT);
					wmove(subwin,starty, startx++);
					wrefresh(subwin);
				}
				else if(arr[j+1] == 34) {
					wattron(subwin, COLOR_PAIR(2));
					mvwprintw(subwin, 20, 40, "Press \" with Littlefinger of  Right hand");
					mvwprintw(subwin, 32, 4 + 7*11, " L ");
					wattroff(subwin, COLOR_PAIR(2));
					localx = 4+7*11;
					localy = 32;
					if(startx == (width-1)) {
						startx = 0;
						starty++;
					}
					wattroff(subwin, A_STANDOUT);
					wmove(subwin,starty, startx++);
					wrefresh(subwin);
				}
				else if(arr[j+1] == 36) {//$
					wattron(subwin, COLOR_PAIR(4));
					mvwprintw(subwin, 20, 40, "Press $ with Forefinger  of   Left hand");
					mvwprintw(subwin, 24, 4 + 7*4, " F ");
					wattroff(subwin, COLOR_PAIR(4));
					localx = 4+7*4;
					localy = 24;
					if(startx == (width-1)) {
						startx = 0;
						starty++;
					}
					wattroff(subwin, A_STANDOUT);
					wmove(subwin,starty, startx++);
					wrefresh(subwin);
				}
				else if(arr[j+1] == 37) {//%
					wattron(subwin, COLOR_PAIR(4));
					mvwprintw(subwin, 20, 40, "Press %% with Forefinger  of   Left hand");
					mvwprintw(subwin, 24, 4 + 7*5, " F ");
					wattroff(subwin, COLOR_PAIR(4));
					localx = 4+7*5;
					localy = 24;
					if(startx == (width-1)) {
						startx = 0;
						starty++;
					}
					wattroff(subwin, A_STANDOUT);
					wmove(subwin,starty, startx++);
					wrefresh(subwin);
				}
				else if(arr[j+1] == 45) {//-
					wattron(subwin, COLOR_PAIR(2));
					mvwprintw(subwin, 20, 40, "Press - with Littlefinger of Right hand");
					mvwprintw(subwin, 24, 4 + 7*11, " L ");
					wattroff(subwin, COLOR_PAIR(2));
					localx = 4+7*11;
					localy = 24;
					if(startx == (width-1)) {
						startx = 0;
						starty++;
					}
					wattroff(subwin, A_STANDOUT);
					wmove(subwin,starty, startx++);
					wrefresh(subwin);
				}
				else if(arr[j+1] == 46) {//.
					wattron(subwin, COLOR_PAIR(2));
					mvwprintw(subwin, 20, 40, "Press . with Ringfinger   of Right hand");
					mvwprintw(subwin, 36, 5 + 7*10, " R ");
					wattroff(subwin, COLOR_PAIR(2));
					localx = 5+7*10;
					localy = 36;
					if(startx == (width-1)) {
						startx = 0;
						starty++;
					}
					wattroff(subwin, A_STANDOUT);
					wmove(subwin,starty, startx++);
					wrefresh(subwin);
				}
				else if(arr[j+1] == 58) {//:
					wattron(subwin, COLOR_PAIR(2));
					mvwprintw(subwin, 20, 40, "Press : with Littlefinger of Right hand");
					mvwprintw(subwin, 32, 4 + 7*10, " L ");
					wattroff(subwin, COLOR_PAIR(2));
					localx = 4+7*10;
					localy = 32;
					if(startx == (width-1)) {
						startx = 0;
						starty++;
					}
					wattroff(subwin, A_STANDOUT);
					wmove(subwin,starty, startx++);
					wrefresh(subwin);
				}
				else if(arr[j+1] == 63) {//?
					wattron(subwin, COLOR_PAIR(2));
					mvwprintw(subwin, 20, 40, "Press ? with Littlefinger of Right hand");
					mvwprintw(subwin, 36, 5 + 7*11, " L ");
					wattroff(subwin, COLOR_PAIR(2));
					localx = 5+7*11;
					localy = 36;
					if(startx == (width-1)) {
						startx = 0;
						starty++;
					}
					wattroff(subwin, A_STANDOUT);
					wmove(subwin,starty, startx++);
					wrefresh(subwin);
				}	
				else if(arr[j+1] == 44) {//,
					wattron(subwin, COLOR_PAIR(2));
					mvwprintw(subwin, 20, 40, "Press , with Middlefinger of Right hand");
					mvwprintw(subwin, 36, 5 + 7*9, " M ");
					wattroff(subwin, COLOR_PAIR(2));
					localx = 5 + 7*9;
					localy = 36;
					if(startx == (width-1)) {
						startx = 0;
						starty++;
					}
					wattroff(subwin, A_STANDOUT);
					wmove(subwin,starty, startx++);
					wrefresh(subwin);
				}
				else if(arr[j+1] == 39) {//'
					wattron(subwin, COLOR_PAIR(2));
					mvwprintw(subwin, 20, 40, "Press ' with Littlefinger of Right hand");
					mvwprintw(subwin, 32, 4 + 7*11, " L ");
					wattroff(subwin, COLOR_PAIR(2));
					localx = 4+7*11;
					localy = 32;
					if(startx == (width-1)) {
						startx = 0;
						starty++;
					}
					wattroff(subwin, A_STANDOUT);
					wmove(subwin,starty, startx++);
					wrefresh(subwin);
				}							
				else if((arr[j+1]>=97 && arr[j+1]<=123) || (arr[j+1]>=65 && arr[j+1]<=90)){
					if(arr[j+1]>=65 && arr[j+1]<=90) {
						temp = arr[j+1];
						temp = temp +32;
					}
					else
						temp = arr[j+1];
					l = traverse(st, temp);
					if(l->hand == 'r') {
						wattron(subwin, COLOR_PAIR(2));
						if(l->finger == 'f') {
							mvwprintw(subwin, 20, 40, "Press %c with Forefinger   of Right hand", l->str);
							mvwprintw(subwin, l->loc_y, l->loc_x, " F ");
							localx = l->loc_x;
							localy = l->loc_y;
						}
						else if(l->finger == 'l') {
							mvwprintw(subwin, l->loc_y, l->loc_x, " L ");
							mvwprintw(subwin, 20, 40, "Press %c with Littlefinger of Right hand", l->str);
							localx = l->loc_x;
							localy = l->loc_y;
						}
						else if(l->finger == 'm') {
							mvwprintw(subwin, 20, 40, "Press %c with Middlefinger of Right hand", l->str);
							mvwprintw(subwin, l->loc_y, l->loc_x, " M ");
							localx = l->loc_x;
							localy = l->loc_y;
						}
						else if(l->finger == 'r') {
							mvwprintw(subwin, 20, 40, "Press %c with Ringfinger   of Right hand", l->str);
							mvwprintw(subwin, l->loc_y, l->loc_x, " R ");
							localx = l->loc_x;
							localy = l->loc_y;
						} 
						wattroff(subwin, COLOR_PAIR(2));
					}    
					else if(l->hand == 'l') {
						wattron(subwin, COLOR_PAIR(4));
						if(l->finger == 'f') {
							mvwprintw(subwin, 20, 40, "Press %c with Forefinger    of Left hand", l->str);
							mvwprintw(subwin, l->loc_y, l->loc_x, " F ");
							localx = l->loc_x;
							localy = l->loc_y;
						}
						else if(l->finger == 'l') {
							mvwprintw(subwin, 20, 40, "Press %c with Littlefinger  of Left hand", l->str);
							mvwprintw(subwin, l->loc_y, l->loc_x, " L ");
							localx = l->loc_x;
							localy = l->loc_y;
						}
						else if(l->finger == 'm') {
							mvwprintw(subwin, 20, 40, "Press %c with Middlefinger  of Left hand", l->str);
							mvwprintw(subwin, l->loc_y, l->loc_x, " M ");
							localx = l->loc_x;
							localy = l->loc_y;	
						}
						else if(l->finger == 'r') {
							mvwprintw(subwin, 20, 40, "Press %c with  Ringfinger   of Left hand", l->str);
							mvwprintw(subwin, l->loc_y, l->loc_x, " R ");
							localx = l->loc_x;
							localy = l->loc_y;
						} 
						wattroff(subwin, COLOR_PAIR(4));     
					}	
					if(startx == (width-1)) {
						startx = 0;
						starty++;
					}
					wattroff(subwin, A_STANDOUT);
					wmove(subwin,starty, startx++);
					wrefresh(subwin);
				}
				else if(arr[j+1] == 34 || arr[j+1] == 33 || arr[j+1] == 44 || arr[j+1] == 46 || arr[j+1] == 58 || arr[j+1] == 59 || arr[j+1] == 45 || arr[j+1] == 63 || (arr[j+1]>=65  && arr[j+1]<=90)){
					wattroff(subwin, A_STANDOUT);
					wmove(subwin,starty, startx++);
					wrefresh(subwin);
				 }
				 else{
				 	wmove(subwin,starty, startx++);
					wrefresh(subwin);
				 }
			}
			j++;
		}
		else {
			if(arr[j] != ch1 && ch1 != KEY_BACKSPACE) {
				push(&s, '*');
				z++;
				n++;
				counter2++;
				if(beeps == 0)
					beep();
				wattron(subwin, A_STANDOUT);
				wprintw(subwin, "^");
				wattroff(subwin, A_STANDOUT);
				if(function == 1)
					startx++;
			}
			else if(ch1 == KEY_BACKSPACE) {
				f = pop(&s);
				if(f == '*'){
					counter2--;
					z--;
				}
				else if(f == arr[j-1]){
					j--;
					q++;
				}
				if(function == 1)
					startx--;
				m++;
				getyx(subwin, y, x);
				wmove(subwin, y, x-1);
				wdelch(subwin);
				wrefresh(subwin);
			}
		}
		gettimeofday(&s2, NULL);
	}
	wrefresh(subwin);
	gettimeofday(&t2, NULL);
	snt = (t2.tv_sec - t1.tv_sec) - (counter*(s2.tv_sec - s1.tv_sec));
	if(timer != 1)
		time_taken(subwin, snt, counter,counter2,boolean, m-q, n);
	wrefresh(subwin);
}
