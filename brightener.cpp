#include "brightener.h"

ImageBrightener::ImageBrightener(std::unique_ptr<Image> inputImage)
    : m_inputImage(std::move(inputImage)) {}

int ImageBrightener::BrightenWholeImage() {
    int attenuatedPixelCount = 0;
    for (int x = 0; x < m_inputImage->rows; ++x) {
        for (int y = 0; y < m_inputImage->columns; ++y) {
            int& pixelValue = m_inputImage->pixel(x, y);
            if (pixelValue > (MAX_BRIGHTNESS - BRIGHTNESS_INCREMENT)) {
                pixelValue = MAX_BRIGHTNESS;
                ++attenuatedPixelCount;
            }
            else {
                pixelValue += BRIGHTNESS_INCREMENT;
            }
        }
    }
    return attenuatedPixelCount;
}

const Image& ImageBrightener::GetImage() const {
    return *m_inputImage;
}
