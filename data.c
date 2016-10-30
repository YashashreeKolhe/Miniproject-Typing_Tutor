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
# define LEFT 1
#define RIGHT 2
void datat(tree *st){
    	int i;
    	char ch;
    	init(st);
    	datas t;
    	ch = 'a';
    	for(i = 0; i<36; i++) {
    		t.str = ch;
    		if(ch == 'a' || ch == 'q' || ch == 'z') {
    			t.hand = 'l';
    			t.finger = 'l';
    			t.loc_x = 4+7;
    			if(ch == 'q')
    				t.loc_y = 28;
    			else if(ch == 'a')
    				t.loc_y = 32;
    			else{
    				t.loc_y = 36;
    				t.loc_x = 4+8;
    			}			
    		}
    		else if(ch == 'w' || ch == 's' || ch == 'x') {
    			t.hand = 'l';
    			t.finger = 'r';
    			t.loc_x = 4+7*2;
    			if(ch == 'w')
    				t.loc_y = 28;
    			else if(ch == 's')
    				t.loc_y = 32;
    			else{
    				t.loc_y = 36;
    				t.loc_x = 4+8*2;
    			}	
    		}
    		else if(ch == 'e' || ch == 'd' || ch == 'c') {
    			t.hand = 'l';
    			t.finger = 'm';
    			t.loc_x = 4+7*3;
    			if(ch == 'e')
    				t.loc_y = 28;
    			else if(ch == 'd')
    				t.loc_y = 32;
    			else{
    				t.loc_y = 36;
    				t.loc_x = 4+3*8;
    			}	
    		}
    		else if(ch == 'r' || ch == 'f' || ch == 't' || ch == 'v' || ch == 'g') {
    			t.hand = 'l';
    			t.finger = 'f';
    			t.loc_x = 4+7*4;
    			if(ch == 'r')
    				t.loc_y = 28;
    			else if(ch == 'f')
    				t.loc_y = 32;
    			else if(ch == 'v'){
    				t.loc_y = 36;
    				t.loc_x = 4+4*8;
    			}
    			else if(ch == 't'){
    				t.loc_x = 4+7*5;
    				t.loc_y = 28;
    			}
    			else if(ch == 'g') {
    				t.loc_x = 4+7*5;
    				t.loc_y = 32;
    			}	
    		}
    		else if(ch == 'y' || ch == 'u' || ch == 'h' || ch == 'j' || ch == 'b') {
    			t.hand = 'r';
    			t.finger = 'f';
    			t.loc_x = 4+7*6;
    			if(ch == 'y')
    				t.loc_y = 28;
    			else if(ch == 'h')
    				t.loc_y = 32;
    			else if(ch == 'b'){
    				t.loc_y = 36;
    				t.loc_x = 4+5*8;
    			}
    			else if(ch == 'u'){
    				t.loc_x = 4+7*7;
    				t.loc_y = 28;
    			}
    			else if(ch == 'j') {
    				t.loc_x = 4+7*7;
    				t.loc_y = 32;
    			}	
    		}
    		else if(ch == 'i' || ch == 'k' || ch == 'n') {
    			t.hand = 'r';
    			t.finger = 'm';
    			t.loc_x = 4+7*8;
    			if(ch == 'i'){
    				t.loc_y = 28;
    			}
    			else if(ch == 'k')
    				t.loc_y = 32;
    			else{
    				t.loc_y = 36;
    				t.loc_x = 4+6*8;
    			}	
    		}
    		else if(ch == 'o' || ch == 'l' || ch == 'm') {
    			t.hand = 'r';
    			t.finger = 'r';
    			t.loc_x = 4+7*9;
    			if(ch == 'o') {
    				t.loc_x = 4+7*9;
    				t.loc_y = 28;
    			}
    			else if(ch == 'l')
    				t.loc_y = 32;
    			else{
    				t.loc_y = 36;
    				t.loc_x = 4+7*8;
    			}	
    		}
    		else if(ch == 'p') {
    			t.hand = 'r';
    			t.finger = 'l';
    			t.loc_x = 4+7*10;
    			t.loc_y = 28;
    		}
    		insert(st, t);
    		ch++;
    	}
}
  
datas *traverse(tree st, char ch) {
	tree p;
	datas *m;
	m = (datas *)malloc(sizeof(datas));
	p = st;
	while(p) {
		if(ch == p->d.str)
			break;
		else if(ch > p->d.str)
			p = p->right;
		else
		 	p = p->left;
	}
	m->str = ch;
	m->finger = p->d.finger;
	m->hand = p->d.hand;
	m->loc_x = p->d.loc_x;
	m->loc_y = p->d.loc_y;
	return m;
}		   
