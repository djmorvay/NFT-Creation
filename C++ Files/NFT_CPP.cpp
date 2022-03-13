/* COLOR TRACKER
 
 # Sky Colors
    - Row 1: NL sky
    - Row 2: Blue sky
 
 # Cloud Colors
    - Row 1: NL clouds
    - Row 2: Grey clouds
 
 # Shirt Colors
    - Row 1: NL shirt
    - Row 2: Green shirt
 
 # Helmet Colors
    - Row 1, Array 1: NL Main helmet color
    - Row 2, Array 1: NL Outline helmet color #1
    - Row 3, Array 1: NL Outline helmet color #2
    - Row 4, Array 1: NL Outline helmet color #3
    - Row 5, Array 1: NL Cross on helmet
    - Row 6, Array 1: NL Bottom of helmet
    - Row 7, Array 1: NL Helmet tab
 
    - Row 1, Array 2: Lime Main helmet color
    - Row 2, Array 2: Lime Outline helmet color #1
    - Row 3, Array 2: Lime Outline helmet color #2
    - Row 4, Array 2: Lime Outline helmet color #3
    - Row 5, Array 2: Lime Cross on helmet
    - Row 6, Array 2: Lime Bottom of helmet
    - Row 7, Array 2: Lime Helmet tab
 
    - Row 1, Array 3: Blue Main helmet color
    - Row 2, Array 3: Blue Outline helmet color #1
    - Row 3, Array 3: Blue Outline helmet color #2
    - Row 4, Array 3: Blue Outline helmet color #3
    - Row 5, Array 3: Blue Cross on helmet
    - Row 6, Array 3: Blue Bottom of helmet
    - Row 7, Array 3: Blue Helmet tab
 
    - Row 1, Array 4: Black Main helmet color
    - Row 2, Array 4: Black Outline helmet color #1
    - Row 3, Array 4: Black Outline helmet color #2
    - Row 4, Array 4: Black Outline helmet color #3
    - Row 5, Array 4: Black Cross on helmet
    - Row 6, Array 4: Black Bottom of helmet
    - Row 7, Array 4: Black Helmet tab
 
 # Skin Colors
    - Row 1, Array 1: African American Main
    - Row 2, Array 1: African American Secondary
    
    - Row 1, Array 2: White American Main
    - Row 2, Array 2: White American Secondary
 
 */

// -------------------------------- //

/* Image Assignment
 
 1 = Sky
 2 = Clouds
 3 = Shirt
 4 = Main helmet color
 5 = Outline helmet color #1
 6 = Outline helmet color #2
 7 = Outline helmet color #3
 8 = Cross on helmet (Could be the same as #6)
 9 = Bottom of helmet
 10 = Helmet tab
 11 = Skin color primary
 12 = Skin color secondary

 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>

#define STB_IMAGE_IMPLEMENTATION
#include "stb-master/stb_image.h"

#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb-master/stb_image_write.h"

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
    // Program Timer Start
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    
    // --------------------- Initialize Variables --------------------- //
    
    // 2-D Sky and Cloud Arrays
    // New row indicates next sky or cloud color
    unsigned char sky_colors[2][4];
    unsigned char cloud_colors[2][4];
    
    // Blue sky, grey clouds
    sky_colors[1][0] = 3; sky_colors[1][1] = 169; sky_colors[1][2] = 244; sky_colors[1][3] = 179;
    cloud_colors[1][0] = 183; cloud_colors[1][1] = 183; cloud_colors[1][2] = 183; cloud_colors[1][3] = 255;
    
    // 2-D Shirt Color Array
    unsigned char shirt_colors[2][4];
    
    // Green shirt
    shirt_colors[1][0] = 4; shirt_colors[1][1] = 178; shirt_colors[1][2] = 48; shirt_colors[1][3] = 204;
    
    /* 3-D Helmet Color Array
        # Row 1 - Main helmet color
        # Row 2 - Outline helmet color #1
        # Row 3 - Outline helmet color #2
        # Row 4 - Outline helmet color #3
        # Row 5 - Cross on helmet (Could be the same as Row 2)
        # Row 6 - Bottom of helmet
        # Row 7 - Helmet tab
    */
    unsigned char helmet_colors[7][4][4];
    
    /* 3-D Skin Color Array
        # Row 1 - Main Skin Tone
        # Row 2 - Secondary Skin Tone
    */
    unsigned char skin_colors[2][4][2];
    
    // -------------------------- Load Images -------------------------- //
    
    // Load No Logo Image
    const char* OG_file_name = "NL.png";
    int width, height, channels;
    
    unsigned char *image = stbi_load(OG_file_name, &width, &height, &channels, 4);
        if(image == NULL) {
            printf("Error in loading the image\n");
            exit(1);
        }
    
    // Load Logo Image
    const char* Logo_1 = "Smile.png";
    int width_logo, height_logo, channels_logo;
    
    unsigned char *logo_im_1 = stbi_load(Logo_1, &width_logo, &height_logo, &channels_logo, 4);
        if(logo_im_1 == NULL) {
            printf("Error in loading the image\n");
            exit(1);
        }
    
    // Load Lime Helmet
    const char* lime_helmet = "lime_helmet.png";
    int width_lime_helmet, height_lime_helmet, channels_lime_helmet;
    
    unsigned char *lime_helmet_im = stbi_load(lime_helmet, &width_lime_helmet, &height_lime_helmet, &channels_lime_helmet, 4);
        if(lime_helmet_im == NULL) {
            printf("Error in loading the image\n");
            exit(1);
        }
    
    // Load Blue Helmet
    const char* blue_helmet = "blue_helmet.png";
    int width_blue_helmet, height_blue_helmet, channels_blue_helmet;
    
    unsigned char *blue_helmet_im = stbi_load(blue_helmet, &width_blue_helmet, &height_blue_helmet, &channels_blue_helmet, 4);
        if(blue_helmet_im == NULL) {
            printf("Error in loading the image\n");
            exit(1);
        }
    
    // Load Black Helmet
    const char* black_helmet = "black_helmet.png";
    int width_black_helmet, height_black_helmet, channels_black_helmet;
    
    unsigned char *black_helmet_im = stbi_load(black_helmet, &width_black_helmet, &height_black_helmet, &channels_black_helmet, 4);
        if(black_helmet_im == NULL) {
            printf("Error in loading the image\n");
            exit(1);
        }
    
    // Load Grey Shirt
    const char* grey_shirt = "grey_shirt.png";
    int width_grey_shirt, height_grey_shirt, channels_grey_shirt;
    
    unsigned char *grey_shirt_im = stbi_load(grey_shirt, &width_grey_shirt, &height_grey_shirt, &channels_grey_shirt, 4);
        if(grey_shirt_im == NULL) {
            printf("Error in loading the image\n");
            exit(1);
        }
    
    // Load Supreme Logo
    const char* supreme = "supreme.png";
    int width_supreme, height_supreme, channels_supreme;
    
    unsigned char *supreme_im = stbi_load(supreme, &width_supreme, &height_supreme, &channels_supreme, 4);
        if(supreme_im == NULL) {
            printf("Error in loading the image\n");
            exit(1);
        }
    
    const char* New_file_name = "New_NL.png";
    
    // Debug
    // printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);
    std::cout << "Image width = " << width << '\n';
    std::cout << "Image height = " << height << '\n';
    
    // -------------------------- Color Assignment -------------------------- //
    
    const size_t RGBA = 4;

    // Create array for new image
    unsigned char* image2;
    image2 = image;
    // image2[index_debug + 0] = cloud_red_a;
    
    // Get OG Sky and Cloud Colors
    size_t cloud_finder = RGBA * (0 * width + 800);
    // Assign NL sky color
    sky_colors[0][0] = image[0]; sky_colors[0][1] = image[1]; sky_colors[0][2] = image[2]; sky_colors[0][3] = image[3];
    // Assign NL cloud color
    cloud_colors[0][0] = image[cloud_finder + 0]; cloud_colors[0][1] = image[cloud_finder + 1];
    cloud_colors[0][2] = image[cloud_finder + 2]; cloud_colors[0][3] = image[cloud_finder + 3];
    
    // Get OG Shirt Color
    size_t shirt_finder = RGBA * (2400 * width + 1000);
    shirt_colors[0][0] = image[shirt_finder + 0]; shirt_colors[0][1] = image[shirt_finder + 1];
    shirt_colors[0][2] = image[shirt_finder + 2]; shirt_colors[0][3] = image[shirt_finder + 3];
    
    // Helmet color finder
    size_t helmet_finder[7];
    helmet_finder[0] = RGBA * (900 * width + 1000);
    helmet_finder[1] = RGBA * (850 * width + 730);
    helmet_finder[2] = RGBA * (650 * width + 1000);
    helmet_finder[3] = RGBA * (1800 * width + 1900);
    helmet_finder[4] = RGBA * (850 * width + 1500);
    helmet_finder[5] = RGBA * (1950 * width + 800);
    helmet_finder[6] = RGBA * (1100 * width + 900);
    
    // Get OG helmet color
    for (int loop1_a = 0; loop1_a < 7; loop1_a++) {
        for (int loop1_b = 0; loop1_b < 4; loop1_b++) {
            helmet_colors[loop1_a][loop1_b][0] = image[helmet_finder[loop1_a] + loop1_b];
            helmet_colors[loop1_a][loop1_b][1] = lime_helmet_im[helmet_finder[loop1_a] + loop1_b];
            helmet_colors[loop1_a][loop1_b][2] = blue_helmet_im[helmet_finder[loop1_a] + loop1_b];
            helmet_colors[loop1_a][loop1_b][3] = black_helmet_im[helmet_finder[loop1_a] + loop1_b];
        }
    }
    
    // Skin color finder
    size_t skin_finder[2];
    skin_finder[0] = RGBA * (2200 * width + 1300);
    skin_finder[1] = RGBA * (2100 * width + 1600);
    
    // Get Skin Colors
    for (int loop2_a = 0; loop2_a < 2; loop2_a++) {
        for (int loop2_b = 0; loop2_b < 4; loop2_b++) {
            skin_colors[loop2_a][loop2_b][0] = image[skin_finder[loop2_a] + loop2_b];
            skin_colors[loop2_a][loop2_b][1] = black_helmet_im[skin_finder[loop2_a] + loop2_b];
        }
    }
    
    /* DEBUG
    int x_debug = 3;
    int y_debug = 4;
    size_t index_debug = RGBA * (y_debug * width + x_debug);
     
    std::cout << "RGBA pixel @ (x=3, y=4): "
              << static_cast<int>(image2[index_debug + 0]) << " "
              << static_cast<int>(image2[index_debug + 1]) << " "
              << static_cast<int>(image2[index_debug + 2]) << " "
              << static_cast<int>(image2[index_debug + 3]) << '\n';
     */
    
    unsigned char pixel_loop[4] = {image[0], image[0], image[0], image[0]};
    size_t index;
    std::vector<std::vector<int> > image_map(height, std::vector<int> (width, 0));
    
    for (int a = 0; a < width; a++) {
        for (int b = 0; b < height; b++) {
            index = RGBA * (b * width + a);
            pixel_loop[0] = image[index + 0];
            pixel_loop[1] = image[index + 1];
            pixel_loop[2] = image[index + 2];
            pixel_loop[3] = image[index + 3];
            
            if ((pixel_loop[0] == sky_colors[0][0]) && (pixel_loop[1] == sky_colors[0][1]) &&
                (pixel_loop[2] == sky_colors[0][2]) && (pixel_loop[3] == sky_colors[0][3])) {
                image_map[b][a] = 1;
            }
            else if ((pixel_loop[0] == cloud_colors[0][0]) && (pixel_loop[1] == cloud_colors[0][1]) &&
                     (pixel_loop[2] == cloud_colors[0][2]) && (pixel_loop[3] == cloud_colors[0][3])) {
                image_map[b][a] = 2;
            }
            else if ((pixel_loop[0] == shirt_colors[0][0]) && (pixel_loop[1] == shirt_colors[0][1]) &&
                     (pixel_loop[2] == shirt_colors[0][2]) && (pixel_loop[3] == shirt_colors[0][3])) {
                image_map[b][a] = 3;
            }
            else if ((pixel_loop[0] == helmet_colors[0][0][0]) && (pixel_loop[1] == helmet_colors[0][1][0]) &&
                     (pixel_loop[2] == helmet_colors[0][2][0]) && (pixel_loop[3] == helmet_colors[0][3][0])) {
                image_map[b][a] = 4;
            }
            else if ((pixel_loop[0] == helmet_colors[1][0][0]) && (pixel_loop[1] == helmet_colors[1][1][0]) &&
                     (pixel_loop[2] == helmet_colors[1][2][0]) && (pixel_loop[3] == helmet_colors[1][3][0])) {
                image_map[b][a] = 5;
            }
            else if ((pixel_loop[0] == helmet_colors[2][0][0]) && (pixel_loop[1] == helmet_colors[2][1][0]) &&
                     (pixel_loop[2] == helmet_colors[2][2][0]) && (pixel_loop[3] == helmet_colors[2][3][0])) {
                image_map[b][a] = 6;
            }
            else if ((pixel_loop[0] == helmet_colors[3][0][0]) && (pixel_loop[1] == helmet_colors[3][1][0]) &&
                     (pixel_loop[2] == helmet_colors[3][2][0]) && (pixel_loop[3] == helmet_colors[3][3][0])) {
                image_map[b][a] = 7;
            }
            else if ((pixel_loop[0] == helmet_colors[4][0][0]) && (pixel_loop[1] == helmet_colors[4][1][0]) &&
                     (pixel_loop[2] == helmet_colors[4][2][0]) && (pixel_loop[3] == helmet_colors[4][3][0])) {
                image_map[b][a] = 8;
            }
            else if ((pixel_loop[0] == helmet_colors[5][0][0]) && (pixel_loop[1] == helmet_colors[5][1][0]) &&
                     (pixel_loop[2] == helmet_colors[5][2][0]) && (pixel_loop[3] == helmet_colors[5][3][0])) {
                image_map[b][a] = 9;
            }
            else if ((pixel_loop[0] == helmet_colors[6][0][0]) && (pixel_loop[1] == helmet_colors[6][1][0]) &&
                     (pixel_loop[2] == helmet_colors[6][2][0]) && (pixel_loop[3] == helmet_colors[6][3][0])) {
                image_map[b][a] = 10;
            }
            else if ((pixel_loop[0] == skin_colors[0][0][0]) && (pixel_loop[1] == skin_colors[0][1][0]) &&
                     (pixel_loop[2] == skin_colors[0][2][0]) && (pixel_loop[3] == skin_colors[0][3][0])) {
                image_map[b][a] = 11;
            }
            else if ((pixel_loop[0] == skin_colors[1][0][0]) && (pixel_loop[1] == skin_colors[1][1][0]) &&
                     (pixel_loop[2] == skin_colors[1][2][0]) && (pixel_loop[3] == skin_colors[1][3][0])) {
                image_map[b][a] = 12;
            }
        }
    }
    
    printf("Changing Background Color...\n");
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            index = RGBA * (j * width + i);
            pixel_loop[0] = image[index + 0];
            pixel_loop[1] = image[index + 1];
            pixel_loop[2] = image[index + 2];
            pixel_loop[3] = image[index + 3];
            
            /* if (image_map[j][i] == 1) {
                image2[index + 0] = sky_colors[1][0];
                image2[index + 1] = sky_colors[1][1];
                image2[index + 2] = sky_colors[1][2];
                image2[index + 3] = sky_colors[1][3];
            }
             */
            if (image_map[j][i] == 2) {
                image2[index + 0] = helmet_colors[6][0][3];
                image2[index + 1] = helmet_colors[6][1][3];
                image2[index + 2] = helmet_colors[6][2][3];
                image2[index + 3] = helmet_colors[6][3][3];
            }
            else if (image_map[j][i] == 3) {
                // Swap shirt
                image2[index + 0] = helmet_colors[0][0][3];
                image2[index + 1] = helmet_colors[0][1][3];
                image2[index + 2] = helmet_colors[0][2][3];
                image2[index + 3] = helmet_colors[0][3][3];
                
                /*
                image2[index + 0] = logo_im_1[index + 0];
                image2[index + 1] = logo_im_1[index + 1];
                image2[index + 2] = logo_im_1[index + 2];
                image2[index + 3] = logo_im_1[index + 3];
                
                if ((logo_im_1[index + 0] == shirt_colors[0][0]) && (logo_im_1[index + 1] == shirt_colors[0][1]) &&
                    (logo_im_1[index + 2] == shirt_colors[0][2]) && (logo_im_1[index + 3] == shirt_colors[0][3])) {
                        // Change shirt color
                        image2[index + 0] = shirt_colors[1][0];
                        image2[index + 1] = shirt_colors[1][1];
                        image2[index + 2] = shirt_colors[1][2];
                        image2[index + 3] = shirt_colors[1][3];
                }
                */
            }
            else if (image_map[j][i] == 4) {
                // Swap main helmet color
                image2[index + 0] = helmet_colors[0][0][3];
                image2[index + 1] = helmet_colors[0][1][3];
                image2[index + 2] = helmet_colors[0][2][3];
                image2[index + 3] = helmet_colors[0][3][3];
            }
            else if (image_map[j][i] == 5) {
                // Swap helmet outline color #1
                image2[index + 0] = helmet_colors[1][0][3];
                image2[index + 1] = helmet_colors[1][1][3];
                image2[index + 2] = helmet_colors[1][2][3];
                image2[index + 3] = helmet_colors[1][3][3];
            }
            else if (image_map[j][i] == 6) {
                // Swap helmet outline color #2
                image2[index + 0] = helmet_colors[2][0][3];
                image2[index + 1] = helmet_colors[2][1][3];
                image2[index + 2] = helmet_colors[2][2][3];
                image2[index + 3] = helmet_colors[2][3][3];
            }
            else if (image_map[j][i] == 7) {
                // Swap helmet outline color #3
                image2[index + 0] = helmet_colors[3][0][3];
                image2[index + 1] = helmet_colors[3][1][3];
                image2[index + 2] = helmet_colors[3][2][3];
                image2[index + 3] = helmet_colors[3][3][3];
            }
            else if (image_map[j][i] == 8) {
                // Swap cross on helmet
                image2[index + 0] = helmet_colors[4][0][3];
                image2[index + 1] = helmet_colors[4][1][3];
                image2[index + 2] = helmet_colors[4][2][3];
                image2[index + 3] = helmet_colors[4][3][3];
            }
            else if (image_map[j][i] == 9) {
                // Swap bottom of helmet
                image2[index + 0] = helmet_colors[5][0][3];
                image2[index + 1] = helmet_colors[5][1][3];
                image2[index + 2] = helmet_colors[5][2][3];
                image2[index + 3] = helmet_colors[5][3][3];
            }
            else if (image_map[j][i] == 10) {
                // Swap helmet tab
                image2[index + 0] = helmet_colors[6][0][3];
                image2[index + 1] = helmet_colors[6][1][3];
                image2[index + 2] = helmet_colors[6][2][3];
                image2[index + 3] = helmet_colors[6][3][3];
            }
            else if (image_map[j][i] == 11) {
                // Swap helmet tab
                image2[index + 0] = skin_colors[0][0][1];
                image2[index + 1] = skin_colors[0][1][1];
                image2[index + 2] = skin_colors[0][2][1];
                image2[index + 3] = skin_colors[0][3][1];
            }
            else if (image_map[j][i] == 12) {
                // Swap helmet tab
                image2[index + 0] = skin_colors[1][0][1];
                image2[index + 1] = skin_colors[1][1][1];
                image2[index + 2] = skin_colors[1][2][1];
                image2[index + 3] = skin_colors[1][3][1];
            }
        }
    }
    
    /* int a_sup = 0, b_sup =0, index_sup = 0;
    
    for (int j_sup = 0; j_sup < width; j_sup++) {
        for (int i_sup = 0; i_sup < height; i_sup++) {
            index = RGBA * (j_sup * width + i_sup);
            pixel_loop[0] = image[index + 0];
            pixel_loop[1] = image[index + 1];
            pixel_loop[2] = image[index + 2];
            pixel_loop[3] = image[index + 3];
            
            if (((i_sup >= 1170) && (i_sup < 1470)) && ((j_sup >= 2445) && (j_sup < 2549))) {
                index_sup = RGBA * (a_sup * width_supreme + b_sup);
                image2[index + 0] = supreme_im[index_sup + 0];
                image2[index + 1] = supreme_im[index_sup + 1];
                image2[index + 2] = supreme_im[index_sup + 2];
                image2[index + 3] = supreme_im[index_sup + 3];
                
                // Debug
                // std::cout << b_sup << " " << a_sup << " " << i_sup << " " << j_sup << "\n";
                
                b_sup++;
            }
            
            if (b_sup >= 300)
            {
                a_sup++;
                b_sup = 0;
            }
        }
    }
    
     */
    // Output new image
    stbi_write_png(New_file_name, width, height, channels, image2, 0);
    std::cout << "Image created.\n";
    
    stbi_image_free(image);
    stbi_image_free(logo_im_1);
    stbi_image_free(blue_helmet_im);
    stbi_image_free(lime_helmet_im);
    stbi_image_free(grey_shirt_im);
    stbi_image_free(black_helmet_im);
    stbi_image_free(supreme_im);

    // Program Timer End
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
    
    return 0;
}

