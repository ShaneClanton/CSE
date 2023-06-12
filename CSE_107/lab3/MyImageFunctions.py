# MyImageFunctions.py
# Import pillow
from re import X
from PIL import Image, ImageOps

# Import numpy
import numpy as np
from numpy import asarray

# For sqrt(), floor()
import math
from math import sqrt, floor, ceil

def myImageResize( original_im, N_Rows, N_Cols, interpolation_method):
    
    # Determine the dimenstions of the image.
    row, col = original_im.shape
    M = row/N_Rows
    N = col/N_Cols
    # Create a numpy matrix of this size.
    new_im = np.zeros(shape=(N_Rows, N_Cols))
    
    if interpolation_method == 'nearest':
        for i in range(N_Rows):
            x_points = (M * (i + 0.5) - 0.5)
            x_vals = round(x_points)
            for j in range(N_Cols):
                y_points = (N * (j + 0.5) - 0.5)
                y_vals = round(y_points)
                new_im[i,j] = original_im[x_vals,y_vals]
        return new_im  

    elif interpolation_method == 'bilinear':
        x_ceil , x_floor = 0, 0
        y_ceil , y_floor = 0, 0
        
        # Computes the average along the first dimension
        for i in range(N_Rows):
            x_points = (M * (i + 0.5) - 0.5)
            if (x_points <= 1):
                x_floor = 0
                x_ceil = 1
            elif (x_points > row  - 1):
                x_floor = row - 2
                x_ceil = row - 1
            else:
                x_floor = floor(x_points)
                x_ceil = ceil(x_points)
            # Computes the average along the second dimension
            for j in range(N_Cols):
                y_points = (N * (j + 0.5) - 0.5)
                if (y_points <= 1):
                    y_floor = 0
                    y_ceil = 1
                elif(y_points > col -1):
                    y_floor = col - 2
                    y_ceil = col - 1
                else:
                    y_floor = floor(y_points)
                    y_ceil = ceil(y_points)
                x_1, x_2, x_3, x_4 = x_floor, x_floor, x_ceil,x_ceil
                y_1, y_3, y_2, y_4 = y_floor, y_floor, y_ceil, y_ceil
                # Call mybilinear and assign it to p_5
                p_5 = mybilinear(x_1,y_1, original_im[x_1, y_1], x_2,y_2, original_im[x_2, y_2], x_3,y_3, original_im[x_3, y_3], x_4,y_4, original_im[x_4, y_4], x_points, y_points)
                new_im[i,j] = p_5
        return new_im
#< your implementation>

def myRMSE( first_im_pixels, second_im_pixels ):
    
    # Determine the dimenstions of the image.
    row, col = first_im_pixels.shape
    # Assign RMSE a integer value
    RMSE = 0
    
    # From here on it computes the Root Mean Squared Error
    for i in range(row):
        for j in range(row):
            RMSE = RMSE + (first_im_pixels[i][j] - second_im_pixels[i][j])**2
            
    RMSE = sqrt(RMSE/(row*col))
    
    return RMSE
#< your implementation>

def mybilinear(x1,y1,p1,x2,y2,p2,x3,y3,p3,x4,y4,p4,x5,y5):
    # Computes P5' as well as P5'' like how it was done in HW 1 question 4b
    p5p = (p3 - p1) * ((x5 - x1) / (x3 - x1)) + p1
    p5dp = (p4 - p2) * ((x5 - x2) / (x4 - x2)) + p2
    p5 = (p5dp - p5p) * ((y5 - y1) / (y2 - y1)) + p5p
    
    return p5
#< your implementation>