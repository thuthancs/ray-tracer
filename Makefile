CXX = g++
TARGET = main_program

$(TARGET): main.cpp
	$(CXX) main.cpp -o $(TARGET)

.PHONY: run clean
run: $(TARGET)
	./$(TARGET) > image.ppm

clean:
	rm -f $(TARGET)
