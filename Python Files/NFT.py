import numpy as np
from PIL import Image

# Open Image
img = Image.open('NL.png')
array = np.array(img)

# Get image shape and number of rows/columns
numrows = len(array)    # 3 rows in your example
numcols = len(array[0]) # 2 columns in your example
print(array.shape)

# Get original sky & cloud colors
sky_color = np.copy(array[0,0])

cloud_color = np.copy(array[0,800])

## print(sky_color)
## print(sky_color2)
## print(cloud_color)

# New Sky Colors
sky_red_a = 3
sky_green_a = 169
sky_blue_a = 244
sky_alpha_a = 0.7*255

# New Cloud Colors
cloud_red_a = 183
cloud_green_a = 183
cloud_blue_a = 183
cloud_alpha_a = 1*255

# Array Copy
copy_array = np.copy(array)

for run_columns in range(numcols):
    for run_rows in range(numrows):
        # print(run_rows, run_columns) # Debug
        sky_color_comp = array[run_rows,run_columns,:] == sky_color[:]
        cloud_color_comp = array[run_rows,run_columns,:] == cloud_color[:]
        
        # Comparison
        if sky_color_comp.all():
            copy_array[run_rows, run_columns] = [sky_red_a, sky_green_a, sky_blue_a, sky_alpha_a]
        elif cloud_color_comp.all():
            copy_array[run_rows, run_columns] = [cloud_red_a, cloud_green_a, cloud_blue_a, cloud_alpha_a]   

# Save modified array as new image
new_array = Image.fromarray(copy_array)
new_array.save('NL_New.png')

old_img = Image.open('NL.png')
old_img.show()

new_img = Image.open('NL_New.png')
new_img.show()

print('END')
