function [output, matched] = template_matching_SSD(img, template)
        
        shift_u = floor(size(template, 1)/2);
        shift_v = floor(size(template, 2)/2);
        
        output = zeros(size(img));

        for u =  1 + shift_u : size(img, 2) - shift_u
            for v = 1 + shift_v : size(img, 1) - shift_v
                    
                    patch = img(v-shift_v:v+shift_v, u-shift_u:u+shift_u);
                    
                    % SSD
                    value = sum((template(:)-patch(:)).^2); 
                    output(v, u) = value;
            end 
        end
        
        matched = (output < 25);
end