function[magnitude, orientation] = sobel_feature(img)
    Hy = [1, 2, 1; 0, 0, 0; -1, -2, -1];
    Hx = [1, 0, -1; 2, 0, -2; 1, 0, -1];
    x = imfilter(img, Hx);
    y = imfilter(img, Hy);
    magnitude = sqrt(y.^2 + x.^2);
    orientation = atan2(y,x);
end