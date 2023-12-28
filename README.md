Based on the project: [Magick++ API](https://imagemagick.org/script/magick++.php)

### How to compile:


```
c++ -std=c++17 `Magick++-config --cxxflags --cppflags` -O2 -o program_example  main_example.cpp src/ResizeImage++.cpp -Iinclude \
  `Magick++-config --ldflags --libs`
```
