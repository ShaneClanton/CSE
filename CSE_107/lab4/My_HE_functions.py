# MyHEFunctions.py

# Import numpy
import numpy as np

def compute_histogram( image_pixels ):
    #<your function header>
    # compute_histgram computing the normalized histogram.
    #
    # Syntax:
    #   compute_histogram( image_pixels )
    #
    # Input:
    #   image_pixels = the pixels of the input image.
    #
    # Output:
    #   hist = numpy array of length 256 representing the normalized histogram.
    #
    # History:
    #   S. Clanton     10/26/2022   created
    
     #<your implementation>
    hist = np.zeros(shape=(1, 256))
    
    for row in image_pixels:
        for pixel in row:
            hist[0][int(pixel)] += 1
    
    hist = hist[0] / (image_pixels.shape[0]*image_pixels.shape[1])
    
    return hist



def equalize( in_image_pixels ):
    #<your function header>
    # equalize equalizes the normalized histogram and uses it to return the equalized image
    #
    # Syntax:
    #   equalize( in_image_pixels )
    #
    # Input:
    #   in_image_pixels = equalized pixels of the input image
    #
    # Output:
    #   out_image_pixels = numpy array representing the equalized histogram
    #
    # History:
    #   S. Clanton     10/28/2022   created
    
    #<your implementation>
    hist = compute_histogram(in_image_pixels)
    eq_hist = np.zeros(shape=(1, 256))
    
    for i, entry in enumerate(hist):
        pixel_sum = 0
        for j in range(i):
            pixel_sum += hist[j]
        pixel_sum *= (256-1)
        eq_hist[0][i] = pixel_sum
    
    out_image_pixels = np.zeros(shape = in_image_pixels.shape)
    
    for i, row in enumerate(in_image_pixels):
        for j, pixel in enumerate(row):
            out_image_pixels[i][j] = eq_hist[0][int(pixel)]
    
    return out_image_pixels

def plot_histogram( hist ):
    # plot_histgram  Plots the length 256 numpy vector representing the normalized
    # histogram of a grayscale image.
    #
    # Syntax:
    #   plot_histogram( hist )
    #
    # Input:
    #   hist = The length 256 histogram vector..
    #
    # Output:
    #   none
    #
    # History:
    #   S. Newsam     10/23/2022   created

    # Import plotting functions from matplotlib.
    import matplotlib.pyplot as plt

    plt.bar( range(256), hist )

    plt.xlabel('intensity value');

    plt.ylabel('PMF'); 

    plt.show()
