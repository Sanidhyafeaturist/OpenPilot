/*M///////////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this license.
//  If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                           License Agreement
//                For Open Source Computer Vision Library
//
// Copyright (C) 2000-2008, Intel Corporation, all rights reserved.
// Copyright (C) 2009-2010, Willow Garage Inc., all rights reserved.
// Third party copyrights are property of their respective owners.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//   * Redistribution's of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistribution's in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//   * The name of the copyright holders may not be used to endorse or promote products
//     derived from this software without specific prior written permission.
//
// This software is provided by the copyright holders and contributors "as is" and
// any express or implied warranties, including, but not limited to, the implied
// warranties of merchantability and fitness for a particular purpose are disclaimed.
// In no event shall the Intel Corporation or contributors be liable for any direct,
// indirect, incidental, special, exemplary, or consequential damages
// (including, but not limited to, procurement of substitute goods or services;
// loss of use, data, or profits; or business interruption) however caused
// and on any theory of liability, whether in contract, strict liability,
// or tort (including negligence or otherwise) arising in any way out of
// the use of this software, even if advised of the possibility of such damage.
//
//M*/

#ifndef OPENCV_ALL_HPP
#define OPENCV_ALL_HPP

// File that defines what modules where included during the build of OpenCV
// These are purely the defines of the correct HAVE_OPENCV_modulename values


// Then the list of defines is checked to include the correct headers
// Core library is always included --> without no OpenCV functionality available
#include "modules/core/include/opencv2/core.hpp"

// Then the optional modules are checked
#ifdef HAVE_OPENCV_CALIB3D
#include "modules/calib3d.hpp"
#endif
#ifdef HAVE_OPENCV_FEATURES2D
#include "modules/features2d/include/opencv2/features2d.hpp"
#endif
#ifdef HAVE_OPENCV_DNN
#include "modules/dnn/include/opencv2/dnn.hpp"
#endif
#ifdef HAVE_OPENCV_FLANN
#include "modules/flann/include/opencv2/flann.hpp"
#endif
#ifdef HAVE_OPENCV_HIGHGUI
#include "modules/highgui/include/opencv2/highgui.hpp"
#endif
#ifdef HAVE_OPENCV_IMGCODECS
#include "modules/imgcodecs/include/opencv2/imgcodecs.hpp"
#endif
#ifdef HAVE_OPENCV_IMGPROC
#include "modules/imgproc/include/opencv2/imgproc.hpp"
#endif
#ifdef HAVE_OPENCV_ML
#include "modules/ml/include/opencv2/ml.hpp"
#endif
#ifdef HAVE_OPENCV_OBJDETECT
#include "modules/objdetect/opencv2/objdetect.hpp"
#endif
#ifdef HAVE_OPENCV_PHOTO
#include "modules/photo/include/opencv2/photo.hpp"
#endif
#ifdef HAVE_OPENCV_STITCHING
#include "modules/stitching/include/opencv2/stitching.hpp"
#endif
#ifdef HAVE_OPENCV_VIDEO
#include "modules/video/include/opencv2/video.hpp"
#endif
#ifdef HAVE_OPENCV_VIDEOIO
#include "modules/videoio/include/opencv2/videoio.hpp"
#endif

#endif
