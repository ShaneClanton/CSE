clc;clear;close all;
%%
% 1. Rotate 01.jpg by 45 degrees using forward warping, and save as rotate_0.jpg

% Read the original image
im = imread('01.jpg');

% Get the size of the image
[rows, columns, channels] = size(im);

% Compute the center of the image
center = [rows / 2, columns / 2];

% Create the rotation matrix
theta = 45;
rotation_matrix = [cosd(theta), -sind(theta); sind(theta), cosd(theta)];

% Initialize the rotated image
rotated_im = uint8(zeros(rows, columns, channels));

% Forward warp the image
for i = 1:rows
    for j = 1:columns
        coord = rotation_matrix * ([i, j] - center)' + center';
        disp(coord)
        row = round(coord(1));
        col = round(coord(2));
        if row >= 1 && row <= rows && col >= 1 && col <= columns
            rotated_im(row, col, :) = im(i, j, :);
        end
    end
end

% Save the rotated image
imwrite(rotated_im, 'rotate_0.jpg');
%figure, imshow(rotated_im);
%%
% 2. Rotate 01.jpg by 45 degrees using backward warping, and save as rotate_1.jpg

% Read the original image
im = imread('01.jpg');

% Get the size of the image
[rows, columns, channels] = size(im);

% Compute the center of the image
center = [rows / 2, columns / 2];

% Create the rotation matrix
theta = 45;
rotation_matrix = [cosd(theta), sind(theta); -sind(theta), cosd(theta)];

% Initialize the rotated image
rotated_im = uint8(zeros(rows, columns, channels));

% Backward warp the image
for i = 1:rows
    for j = 1:columns
        coord = rotation_matrix * ([i, j] - center)' + center';
        row = round(coord(1));
        col = round(coord(2));
        if row >= 1 && row <= rows && col >= 1 && col <= columns
            rotated_im(i, j, :) = im(row, col, :);
        end
    end
end

% Save the rotated image
imwrite(rotated_im, 'rotate_1.jpg');
%%
% 3. Implement median_filter.m for lena_noisy.jpg, use patch size = 3 and save the image as median_0.jpg

% Load the image
img = imread('lena_noisy.jpg');

% Define the patch size
patch_size = 3;

result_img = median_filter(img, patch_size);
% Save the result image
imwrite(result_img, 'median_0.jpg');
%%
% 4. Use patch size = 5, and save the image as median_1.jpg

% Load the image
img = imread('lena_noisy.jpg');

% Define the patch size
patch_size = 5;

result_img = median_filter(img, patch_size);
% Save the result image
imwrite(result_img, 'median_1.jpg');