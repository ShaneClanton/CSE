function feature = multiscale_sobel_feature(img, scale)
    feature = [];

    for i = 1:scale
        [mag, or]  = sobel_feature(img);
        feature = cat(1, feature, or(:));
        feature = imresize(feature, 1/i);
    end
end