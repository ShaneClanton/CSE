# Import pillow
from PIL import Image, ImageOps

# Import numpy
import numpy as np
from numpy import asarray

# Read the image from file.
im = Image.open('Beginnings.jpg')

# Show the image.
im.show()

# Convert image to gray scale.
im_gray = ImageOps.grayscale(im)

# Show the grayscale image.
im_gray.show()

# Get access to the pixel values through the matrix im_gray_pixels.
im_gray_pixels = asarray(im_gray)

# Determine the dimensions of the image.
rows, cols = im_gray_pixels.shape
print("Image size is: ", rows, "rows x", cols, "columns")
# <THE REST OF CODE>

# Cast image into numpy array
im_gray = np.array(im_gray)

# Create empty variable
im_gray_ccw_pixel = 0

# Finds largest pixel values
for row in im_gray:
    for pixel in row:
        if im_gray_ccw_pixel < pixel:
            im_gray_ccw_pixel = pixel

# Prints pixel values
print(im_gray_ccw_pixel)

# Creates new numpy array
im_gray_ccw = np.full((533, 800), 0)

# Rotates the image 90 degrees counter clockwise
for i,row in enumerate(im_gray):
    for j,pixel in enumerate(row):
        im_gray_ccw[j,i] = pixel

# Cast numpy array to image
im_gray_ccw = Image.fromarray(np.uint8(im_gray_ccw))

# Show image
im_gray_ccw.show()

# Save image
im_gray_ccw.save("im_gray_ccw.jpg")

# Get access to the pixel values through the matrix im_gray_pixels.
im_gray_ccw_pixels = asarray(im_gray_ccw)

# Determine the dimensions of the image.
rows, cols = im_gray_ccw_pixels.shape
print("CCW image size is: ", rows, "rows x", cols, "columns")

# CLOCKWISE ROTATION

# Creates new numpy array
im_gray_cw = np.full((533, 800), 0)

# Rotates the image 90 degrees clockwise
for i,row in enumerate(im_gray):
    for j,pixel in enumerate(row):
        im_gray_cw[j,-i] = pixel

# Cast numpy array to image
im_gray_cw = Image.fromarray(np.uint8(im_gray_cw))

# Show image
im_gray_cw.show()

# Save image
im_gray_cw.save("im_gray_cw.jpg")

# Create empty variable
im_gray_cw_pixel = 0

# Finds largest pixel values
for row in np.array(im_gray_cw):
    for pixel in row:
        if im_gray_cw_pixel < pixel:
            im_gray_cw_pixel = pixel
            
# Prints pixel values
print(im_gray_cw_pixel)