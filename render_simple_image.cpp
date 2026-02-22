#include <iostream>

/* PPM file (Portable Pixmap Format) - a simple, uncompressed raster image file format widely used for basic image manipulation
 */

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
        std::clog << "\rScan lines remaining: " << (height - 1) << ' ' << std::flush;
        for (int j = 0; j < width; j++)
        {
            // auto keyword is a type specifier that directs the compiler to automatically deduce the data type of a variable
            // from its initializer expression at compile time
            auto r = double(i) / (width - 1);
            auto g = double(j) / (height - 1);
            auto b = 0.0;

            // We use 255.999 avoids rounding error (make sure the value rounds up to 255 for the max input)
            int ir = int(255 * r);
            int ig = int(255 * g);
            int ib = int(255 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    std::clog << "\rDone.           " << '\n';
}