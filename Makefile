project: main.o time.o reg_win.o num_drill.o num_test.o speed_r.o speed_test.o practice.o practice_lessons.o score_chart.o box.o menu.o character_check.o data.o tree.o hand.o difficulty_level.o stack.o no_correction.o
	cc -o project main.o time.o reg_win.o num_drill.o num_test.o speed_r.o speed_test.o practice.o practice_lessons.o score_chart.o box.o menu.o character_check.o tree.o data.o hand.o difficulty_level.o stack.o no_correction.o -lncurses -lm
main.o: main.c dummy.h
	cc -c main.c -Wall
speed_r.o: speed_r.c
	cc -c speed_r.c -Wall
time.o: time.c
	cc -c time.c
reg_win.o: reg_win.c
	cc -c reg_win.c -Wall
num_drill.o: num_drill.c dummy.h
	cc -c num_drill.c -Wall
num_test.o: num_test.c dummy.h
	cc -c num_test.c -Wall     
speed_test.o: speed_test.c dummy.h
	cc -c speed_test.c -Wall
practice.o: practice.c dummy.h
	cc -c practice.c -Wall
practice_lessons.o: practice_lessons.c dummy.h
	cc -c practice_lessons.c -Wall
score_chart.o: score_chart.c
	cc -c score_chart.c -Wall
box.o: box.c
	cc -c box.c -Wall
menu.o: menu.c
	cc -c menu.c -Wall
character_check.o: character_check.c tree.h
	cc -c character_check.c -Wall
data.o: data.c tree.h dummy.h
	cc -c data.c -Wall
tree.o: tree.c tree.h dummy.h
	cc -c tree.c -Wall
hand.o: hand.c dummy.h
	cc -c hand.c -Wall
difficulty_level.o: difficulty_level.c dummy.h
	cc -c difficulty_level.c -Wall
stack.o: stack.c stack.h
	cc -c stack.c -Wall
no_correction.o: no_correction.c dummy.h
	cc -c no_correction.c
clean: 
	rm *.o
