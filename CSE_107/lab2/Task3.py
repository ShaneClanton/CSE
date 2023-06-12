# Import pillow
from PIL import Image, ImageOps

# Import numpy
import numpy as np
from numpy import asarray

# The size of the gradient image.
rows = 100
cols = 256

# Create a numpy matrix of this size.
im_pixels = np.zeros(shape=(rows, cols))

# Creates greyscale
for i in range(cols):
    for j in range(rows):
        im_pixels[j,i] = i

# Create image from im_pixels
im_pixels =  Image.fromarray(np.uint8(im_pixels))

# Show image pixels
im_pixels.show()

# Save the inverse image to a file.
im_pixels.save("Gradient.tif")

# Create empty variables
pixel_sum = 0
num_pixels = 0

# Computes averate pixel value of gradient image
for row in np.array(im_pixels):
    for pixel in row:
        pixel_sum += pixel
        num_pixels += 1

# Print gradient value
print(pixel_sum/num_pixels)