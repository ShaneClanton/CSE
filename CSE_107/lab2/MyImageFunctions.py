# MyImageFunctions.py
# Import pillow

from PIL import Image, ImageOps

# Import numpy
import numpy as np
from numpy import asarray
def myImageInverse( inImage_pixels ):
    
# This function takes as input a numpy matrix representing a grayscale image and
# outputs another numpy matrix which is the image inverse of the input.
# That is, for each pixel, output_value = 255 - input_value
#
# Syntax:
#   out_numpy_matrix = myImageInverse( in_numpy_matrix )
#
# Input:
#   in_numpy_matrix = the grayscale values of the input image
#
# Output:
#   out_numpy_matrix = the grayscale of the inverse image
    
    # Creating new numpy matrix
    outImage_pixels = np.full(inImage_pixels.shape, 0)
    
    # Inverting the pixel values
    for i,row in enumerate(inImage_pixels):
        for j,pixel in enumerate(row):
            outImage_pixels[i,j] = 255 - pixel
    return outImage_pixels