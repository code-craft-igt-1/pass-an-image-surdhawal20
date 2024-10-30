#ifndef BRIGHTENER_H
#define BRIGHTENER_H

#include <vector>
#include <memory>

class Image {
public:
    int rows;
    int columns;
    std::vector<int> pixels;

    Image(int r, int c, int initialBrightness = 0)
        : rows(r), columns(c), pixels(r* c, initialBrightness) {}

    int& pixel(int x, int y) {
        return pixels[x * columns + y];
    }
};

class ImageBrightener {
public:
    explicit ImageBrightener(std::unique_ptr<Image> inputImage);
    int BrightenWholeImage();
    const Image& GetImage() const;

private:
    std::unique_ptr<Image> m_inputImage;
    static const int BRIGHTNESS_INCREMENT = 25;
    static const int MAX_BRIGHTNESS = 255;
};

#endif
