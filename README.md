W repozytorium znajduje się Makefile, zakłada on strukturę

./ bin src data Makefile 

aby działał poprawnie.

Polecamy skorzystanie z Makefile w kolejności :
make compile 
make test_no_data
make test_bad_data
make test_gun

make clear
make test_blinker

make clear 
make test_octagon

make clear
make test_von_Neumann

make clear
make test_Moore_random

make clear
make test_another_gun

make clear
make test_puffer


W razie chęci przetestowania programu ze swoimi pakietami danych koordynaty w pliku podajemy w kolejności szerokość, wysokość, plik zawierający dane najważniejsze powinien być w konwencji:

500 500 (rozmiar tablicy)  1500 (ilość organizmów w istotna w przypadku generacji losowej)  1000 (iteracja na której program ma kończyć pracę) 1 (co ile iteracji chcemy generować png) 0 (0 jeśli zasady sąsiedztwa Moore'a, 1 von Neumanna)

Następny plik zawierający koordynaty oraz następnie plik zawierający stopklatki oczekiwane (oba pliki opcjonalne)

