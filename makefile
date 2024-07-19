all: clean compile link run

compile:
	g++ -c main.cpp game.cpp sky.cpp ground.cpp pipe.cpp pipe_manager.cpp start_screen.cpp bird.cpp button.cpp score.cpp screen_text.cpp local_storage.cpp -I"C:\SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit\SFML-2.5.1\include" -I"C:\SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit\SFML-2.5.1\bin" -I"C:\GAME PROJECTS\Flappy-Bird\images" -I"C:\GAME PROJECTS\Flappy-Bird\fonts" -I"C:\GAME PROJECTS\Flappy-Bird\storage" -DSFML_STATIC

link:
	g++ main.o game.o sky.o ground.o pipe.o pipe_manager.o start_screen.o bird.o button.o score.o screen_text.o local_storage.o -o main -L"C:\SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit\SFML-2.5.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main -Wl,-Bstatic -lsfml-graphics -lsfml-window -lsfml-system -Wl,-Bdynamic

run:
	.\main

clean:
	rm -f main *.o
