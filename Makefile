compile: src/*.c
	gcc src/*.c -lpng -o bin/project

test_blinker: bin/project
	./bin/project data/data_file_blinker data/cords_test_blinker

clean:
	rm -r bin/*.png

test_octagon: bin/project
	./bin/project data/data_file_blinker data/cords_octagon

test_gun: bin/project
	./bin/project data/data_file_gun data/cords_big_gun

test_bad_data: bin/project
	./bin/project data/data_bad_data

test_no_data: bin/project
	./bin/project