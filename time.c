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

void time_taken(WINDOW *subwin,int snt, int cnt, int cnt2,int boolean, int no_backsp, int no_wrong){		
	double gross_wpm;
	double net_wpm;
	float accuracy;
	FILE *fp;

	gross_wpm = (((double)cnt/5.0)/(double)snt)*60;
	net_wpm = ((((double)cnt/5.0) - ((double)cnt2))/snt)*60;
	accuracy = (((double)(cnt - (no_backsp + no_wrong)))/(double)cnt)*100;
	if(boolean == 1){
		fp = fopen("score_record.txt", "a+");
		fprintf(fp, " %lf ", gross_wpm);
		fprintf(fp, "%lf ", net_wpm);
		fprintf(fp, "%.2lf ", accuracy);
		time_t mytime;
		mytime = time(NULL);
		fprintf(fp, ctime(&mytime));
		fclose(fp);
		boolean = 0;
	}
	wattron(subwin, A_STANDOUT);
	mvwprintw(subwin, height-6, width-28,               "Gross speed: %.2lf wpm     ", gross_wpm);
	mvwprintw(subwin, height-5, width-28,               "Net speed: %.2lf wpm       ", net_wpm);
	if(accuracy == 100.00)
		mvwprintw(subwin, height-4, width-28,       "Accuracy: %.2lf%%          ", accuracy);
	else
		mvwprintw(subwin, height-4, width-28,       "Accuracy: %.2lf%%           ", accuracy);
	mvwprintw(subwin, height-3, width-28,               "Corrected Entries: %d       ", no_backsp);
	mvwprintw(subwin, height-2, width-28,               "Incorrect Entries: %d      ", no_wrong);
	mvwprintw(subwin, height-1, width-28,                 "Total characters typed: %d", cnt) ;
	wrefresh(subwin);
}
