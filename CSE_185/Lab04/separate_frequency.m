function [low_pass_img, high_pass_img] = separate_frequency(img, ratio)
    % 1: fft
    frequency_map = fft2(img);
    %figure, imshow(log(abs(frequency_map) + 1), []);
    %2: rearrange the frequency map
    frequency_map_shifted = fftshift(frequency_map);
    %figure, imshow(log(abs(frequency_map_shifted) + 1), []);
    %3: compute the low-frequency mask
    mask = zeros(size(img));
    [h,w, ~] = size(img);
    y1 = round(h/2)-round(ratio*h/2);
    y2 = round(h/2)+round(ratio*h/2)+1;
    x1 = round(w/2)-round(ratio*w/2);
    x2 = round(w/2)+round(ratio*w/2)+1;
    mask(y1 : y2, x1 : x2, :) = 1;

    %figure, imshow(mask);
    %4:
    low_shifted = frequency_map_shifted .* mask;
    high_shifted = frequency_map_shifted .* (1-mask);
    %figure, imshow(log(abs(low_shifted) + 1), []);
    %figure, imshow(log(abs(high_shifted) + 1), []);
    %5:
    low_map = ifftshift(low_shifted);
    high_map = ifftshift(high_shifted);
    %figure, imshow(log(abs(low_map) + 1), []);
    %figure, imshow(log(abs(high_map) + 1), []);
    %6:
    low_pass_img = real(ifft2(low_map));
    high_pass_img = real(ifft2(high_map));

    %figure,imshow(low_img);
    %figure, imshow(high_img+0.5);

  





end