function output = sobel_filter(img, kernel)
    % YOUR CODE HERE
    [H, W] = size(img);
    %
    shift_u = floor(size(kernel, 2)/2);
    shift_v = floor(size(kernel, 1)/2);
    %
    output = zeros(H, W);

    for u = 1 + shift_u : W - shift_u
        for v = 1 + shift_v : H - shift_v
            y1 = v - shift_v;
            y2 = v + shift_v;
            x1 = u - shift_u;
            x2 = u + shift_u;
            patch = img(y1:y2, x1:x2);
            value = patch .* kernel;
            value = sum(value(:));
            output(v,u) = value;
        end
    end

end