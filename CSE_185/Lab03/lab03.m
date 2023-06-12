% 1. Implement sobel_filter.m, use horizontal filter and save
% the image as sobel_h.jpg
% 2. Use vertical filter and save the image as sobel_v.jpg
% 3. Implement gaussian_filter.m, use hsize = 5, sigma = 2, and save the image as gaussian_5.jpg
% 4. Use hsize = 9, sigma = 4, and save the image as
% gaussian_9.jpg
% 5. Upload your output images and lab03.m, sobel_filter.m,
% and gaussian_filter.m

img = im2double(imread('lena.jpg'));
%% Sobel filter
%img = im2double(imread('lena.jpg'));
%H = [1, 2, 1; 0, 0, 0; -1, -2, -1]; % horizontal edge 
H = [1, 0, -1; 2, 0, -2; 1, 0, -1]; % vertical edge

img_sobel = sobel_filter(img, H); 

figure, imshow(img_sobel); 

imwrite(img_sobel, 'sobel_V.jpg');


%% Gaussian filter
%img = im2double(imread('lena.jpg'));
%hsize = 5; sigma = 2;
 hsize = 9; sigma = 4;
img_gaussian = gaussian_filter(img, hsize, sigma); 

figure, imshow(img_gaussian); 

imwrite(img_gaussian, 'gaussian_9.jpg');