#include <iostream>

int main()
{
    // Define the image size in 2D
    int width = 256;
    int height = 256;

    // Render the image on screen
    std::cout << "P3\n"
              << width << ' ' << height << "\n255\n";

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // auto keyword is a type specifier that directs the compiler to automatically deduce the data type of a variable
            // from its initializer expression at compile time
            auto r = double(i) / (width - 1);
            auto g = double(j) / (height - 1);
            auto b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}