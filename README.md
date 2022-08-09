
# Image Segmentation

In [digital image processing](https://www.wikiwand.com/en/Digital_image_processing) and [computer vision](https://www.wikiwand.com/en/Computer_vision), image segmentation is the process of partitioning a digital image into multiple image segments, also known as image regions or image objects (sets of pixels). The goal of segmentation is to simplify and/or change the representation of an image into something that is more meaningful and easier to analyze.

Image segmentation is typically used to locate objects and boundaries (lines, curves, etc.) in images. More precisely, image segmentation is the process of assigning a label to every pixel in an image such that pixels with the same label share certain characteristics.

The result of image segmentation is a set of segments that collectively cover the entire image, or a set of contours extracted from the image. Each of the pixels in a region are similar with respect to some characteristic or computed property, such as color, intensity, or texture. Adjacent regions are significantly different color respect to the same characteristic(s).

In this document, we are trying to implement Image segmentation from scratch(without using any user defined library) in C++. ***With as minimal performance as possible.***
