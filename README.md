![GitHub](https://img.shields.io/github/license/Airthee/Facial-Recognition.svg?style=flat-square)
![Twitter Follow](https://img.shields.io/twitter/follow/Airthee.svg)

# Facial recognition

## Prerequisites

* cmake

## Create training data

Put your datas in src/training_data.

Structure should be :

```
  src/
    training_data/
      s1/
      s2/
      s3/
      ...
      data.csv
```

Create the csv file with :

``` bash
  cd src/training_data
  python createCSVFile.py . > data.csv
```

Resize all images in a repository (recursive) :

``` bash
for i in $(find -iregex '.+\(\.pgm\|jpe?g\|png\)'); do convert $i -resize 90x90! $i; done
```

## How to compile

Generate makefile : `cmake .`

Compile : `make`

## How to run

Run program 
``` bash
  cd bin
  ./main /usr/share/opencv/haarcascades/haarcascade_frontalface_alt2.xml ./training_data/data.csv 0
```
