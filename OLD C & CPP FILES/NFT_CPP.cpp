#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

extern "C" {
	#define STB_IMAGE_IMPLEMENTATION
	#include "stb-master/stb_image.h"

    #define STBI_MSC_SECURE_CRT
	#define STB_IMAGE_WRITE_IMPLEMENTATION
	#include "stb-master/stb_image_write.h"
}

// Loads as RGBA... even if file is only RGB
// Feel free to adjust this if you so please, by changing the 4 to a 0.
bool load_image(std::vector<unsigned char>& image, const std::string& filename, int& x, int& y, int& z)
{
    unsigned char* data = stbi_load(filename.c_str(), &x, &y, &z, 4);
    if (data != nullptr)
    {
        image = std::vector<unsigned char>(data, data + x * y * 4);
    }
    stbi_image_free(data);
    return (data != nullptr);
}

int main()
{
    std::string filename = "NL.png";
    std::string filename2 = "NL_CPP.png";
    
    int width, height, comp;
    std::vector<unsigned char> image;
    std::vector<unsigned char> image2;
    bool success = load_image(image, filename, width, height, comp);
    if (!success)
    {
        std::cout << "Error loading image\n";
        return 1;
    }
    
    std::cout << "Image width = " << width << '\n';
    std::cout << "Image height = " << height << '\n';
    
    const size_t RGBA = 4;

    int x = 3;
    int y = 4;
    size_t index = RGBA * (y * width + x);

    image2 = image;
    image2[index + 0] = 69;
    
    std::cout << "RGBA pixel @ (x=3, y=4): " 
              << static_cast<int>(image2[index + 0]) << " "
              << static_cast<int>(image2[index + 1]) << " "
              << static_cast<int>(image2[index + 2]) << " "
              << static_cast<int>(image2[index + 3]) << '\n';

    stbi_write_png("NL_CPP.png", width, height, comp, image2, 100);

    return 0;
}
