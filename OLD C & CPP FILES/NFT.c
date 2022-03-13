#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb-master/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb-master/stb_image_write.h"

int main(void) {

	int w, h, c;
	unsigned char *img = stbi_load("NL.png", &w, &h, &c, 0);

 	if(!img) {
		printf("Error in loading the image\n");
		exit(0);
	}

	printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", w, h, c);

	printf("%s\n", img);

	free(img);

	return 0;
}