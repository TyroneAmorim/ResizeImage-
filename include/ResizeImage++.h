#include <string>
#include <Magick++.h>

#ifndef RESIZEPHOTO_H
#define RESIZEPHOTO_H

class ResizePhoto
{
public:
    ResizePhoto(char **argv);

    Magick::Image resize(std::string *size, std::string *filePath, std::string *filePathOut);

    Magick::Geometry calculateGeometry(int *wc, int *hc, double *wp, double *hp);

    Magick::Image copyAndCenter(int *width, int *height, std::string *filePath);

    void save(std::string path, std::string filename, std::string *outPathDir, int *w, int *h);
};

#endif