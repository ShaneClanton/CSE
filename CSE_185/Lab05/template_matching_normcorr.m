function [output, matched] = template_matching_normcorr(img, template)
        
        shift_u = floor(size(template, 1)/2);
        shift_v = floor(size(template, 2)/2);
        
        output = zeros(size(img));
        template = template(:) - mean(template(:));
        template = template/ norm(template);

        for u =  1 + shift_u : size(img, 2) - shift_u
            for v = 1 + shift_v : size(img, 1) - shift_v
                    
                    patch = img(v-shift_v:v+shift_v, u-shift_u:u+shift_u);

                    %normalize corss correlation
                    p_ = patch(:)-mean(patch(:));
                    p_ = p_ / norm(p_);
                    value = dot(template, p_);
                    output(v, u) = value;
            end 
        end

        matched = (output > 0.5);


end