function Matrix = LoadBinaryPNG(filepath)
    RGB_Image = imread(filepath);
    GRAY_Image = rgb2gray(RGB_Image);
    Matrix = GRAY_Image < 0.5;
end

