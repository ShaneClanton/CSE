clc;clear;close all;
%% Task 1: Split Frequency
img = im2double(imread('lena.jpg')); 
ratio = 0.2;

[low_pass_img, high_pass_img] = separate_frequency(img, ratio);


imwrite(low_pass_img, 'lena_low_0.2.jpg'); 
imwrite(high_pass_img + 0.5, 'lena_high_0.2.jpg');



%% Task 2: Hybrid Image
name1 = 'marilyn.jpg';
name2 = 'einstein.jpg';
img1 = im2double(imread(name1)); 
img2 = im2double(imread(name2));
ratio = 0.2;
[hybrid_2, hybrid_1] = hybrid_image(img1, img2, ratio);

imwrite(hybrid_1, 'hybrid_2.jpg'); 
imwrite(hybrid_2, 'hybrid_1.jpg'); 

