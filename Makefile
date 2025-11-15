# Compiler and flags
CXX = g++
CXXFLAGS = -I"C:/Users/NITRO/Documents/SFML Download/SFML-3.0.2-windows-gcc-14.2.0-mingw-64-bit/SFML-3.0.2/include" -L"C:/Users/NITRO/Documents/SFML Download/SFML-3.0.2-windows-gcc-14.2.0-mingw-64-bit/SFML-3.0.2/lib"
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Targets
all: app cube

app:
	$(CXX) $(filter-out cmain.cpp, $(wildcard *.cpp)) -o app.exe $(CXXFLAGS) $(LIBS)

cube:
	$(CXX) cmain.cpp -o cube.exe $(CXXFLAGS) $(LIBS)

clean:
	del *.exe

.PHONY: all app cube clean