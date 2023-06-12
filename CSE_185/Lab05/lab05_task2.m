clc;clear;close all;

img = im2double(imread("einstein1.jpg"));
img2 = im2double(imread("einstein2.jpg"));

template = im2double(imread("template.jpg"));

[output, matched] = template_matching_SSD(img, template);

imwrite(output ./ max(output(:)), 'einstein1_ssd_output.jpg');
imwrite(matched, 'einstein1_ssd_match.jpg');

[output, matched] = template_matching_SSD(img2, template);

imwrite(output ./ max(output(:)), 'einstein2_ssd_output.jpg');
imwrite(matched, 'einstein2_ssd_match.jpg');



[output1, matched1] = template_matching_normcorr(img, template);

imwrite(output1 ./ max(output1(:)), 'einstein1_normcorr_output.jpg');
imwrite(matched1, 'einstein1_normcorr_match.jpg');

[output1, matched1] = template_matching_normcorr(img2, template);

imwrite(output1 ./ max(output1(:)), 'einstein2_normcorr_output.jpg');
imwrite(matched1, 'einstein2_normcorr_match.jpg');

% 
% figure, imshow(output./max(output(:)));
% figure, imshow(matched);