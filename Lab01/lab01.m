clc;clear;close all;
%%
% Objective 1

I = imread("01.jpg");
figure, imshow(I);
imwrite(I, "01.jpg");

R = I( :, :, 1);
G = I( :, :, 2);
B = I( :, :, 3);

G(:,:) = 0;

I_green = cat(3, R, G, B);

figure, imshow(I_green);
imwrite(I_green, "green.jpg")
%%
%Objective 2

I = imread("01.jpg");

R = I( :, :, 1);
G = I( :, :, 2);
B = I( :, :, 3);
Y = 0.299 * R + 0.587 * G + 0.114 * B;

imwrite(Y, '01_gray.jpg');
Y = imread('01_gray.jpg');
figure, imshow(Y);

I_gray = imread('01_gray.jpg');
size(I_gray)
%%
%Objective 3

I = imread("01.jpg");

I(1,1)
I = im2double(I);
I(1,1)

I_cw = imrotate(I, 90);

figure, imshow(I_cw);
imwrite(I_cw,"rotate.jpg")
%%
%Objective 4

I = imread("01.jpg");

I_crop = I(30:270, 100:300,:);
figure, imshow(I_crop);
imwrite(I_crop,"crop.jpg")
%%
%Objective 5

I = imread("01.jpg");

I_flip = flip(I,2);

figure, imshow(I_flip);
imwrite(I_flip,"flip.jpg")
%%
%Objective 6 

I1= imread("01.jpg");

canvas = zeros(300 * 2 + 10, 400 * 2 + 10, 3, 'uint8');
canvas(1:300, 1:400, :) = I1;

I2 = imread("02.jpg");
canvas(1:300, 411:810,:) = I2;

I3 = imread("03.jpg");
canvas(311:610, 1:400,:) = I3;

I4 = imread("04.jpg");
canvas(311:610, 411:810,:) = I4;

figure, imshow(canvas);
imwrite(canvas, "combine.jpg")
%%
%Objective 7

I5 = imread("05.jpg");
vec5 = I5(:);
I6 = imread("06.jpg");
vec6 = I6(:);
avg = (vec5 + vec6) /2.;
avg = reshape(avg, 375, 1242, 3);

figure, imshow(avg);
imwrite(avg, "average.jpg")

% figure, imshow(I_combo);
% imwrite(I_combo,"combine.jpg")
