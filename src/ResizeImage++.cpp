#include <string>
#include <Magick++.h>
#include "ResizeImage++.h"

using namespace std;
using namespace Magick;


  ResizePhoto::ResizePhoto(char **argv)
  {
    Magick::InitializeMagick(*argv);
  }

  Image ResizePhoto::resize(string *size, string *filePath, string *filePathOut)
  {
    Image actualImage;
    actualImage.read(*filePath);
    actualImage.scale(*size);
    return actualImage;
  }

  Geometry ResizePhoto::calculateGeometry(int *wc, int *hc, double *wp, double *hp)
  {
    double px = (*wc - *wp) / 2;
    double py = (*hc - *hp) / 2;

    Geometry geometry = to_string(*wp) + "x" + to_string(*hp) + "+" + to_string(px) + "+" + to_string(py);
    return geometry;
  }

  Image ResizePhoto::copyAndCenter(int *width, int *height, string *filePath)
  {
    string size = to_string(*width) + "x" + to_string(*height);
    Image container = Magick::Image(size, ColorRGB(255, 255, 255, 0));
    Image target = resize(&size, filePath, filePath);
    target.quality(100);
    double w = target.size().width();
    double h = target.size().height();
    Geometry geometry = calculateGeometry(width, height, &w, &h);

    container.composite(target, geometry, Magick::CopyCompositeOp);
    container.quality(100);
    return container;
  }

  void ResizePhoto::save(string path, string filename, string *outPathDir, int *w, int *h)
  {
    string filePathOut = *outPathDir;
    filePathOut.append("/").append(filename);
    Image image = copyAndCenter(w, h, &path);
    image.write(filePathOut);
  }