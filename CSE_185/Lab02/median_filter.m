function result_img = median_filter(img, patch_size)
    % Get the size of the image
    [m, n] = size(img);
    
    % Create a padding of zeros around the image
    padded_img = padarray(img, [(patch_size-1)/2, (patch_size-1)/2]);
    
    % Initialize the result image
    result_img = zeros(m, n);
    
    % Loop through each pixel in the image
    for i = 1:m
        for j = 1:n
            % Get the current patch
            patch = padded_img(i:i+patch_size-1, j:j+patch_size-1);
            
            % Find the median value in the patch
            median_value = median(patch(:));
            
            % Assign the median value to the result image
            result_img(i, j) = median_value;
        end
    end
    
    % Convert the result image to uint8
    result_img = uint8(result_img);
end
