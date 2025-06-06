#pragma once
#include "IppImage.h"

void IppFilterMean(IppByteImage& imgSrc, IppByteImage& imgDst);
void IppFilterWeightedMean(IppByteImage& imgSrc, IppByteImage& imgDst);

void IppFilterMean2(IppByteImage& imgSrc, IppByteImage& imgDst);
void IppFilterWeightedMean2(IppByteImage& imgSrc, IppByteImage& imgDst);

void IppFilterLaplacian(IppByteImage& imgSrc, IppByteImage& imgDst);
void IppFilterUnsharpMask(IppByteImage& imgSrc, IppByteImage& imgDst);
void IppFilterHighboost(IppByteImage& imgSrc, IppByteImage& imgDst, float alpha);

void IppNoiseGaussian(IppByteImage& imgSrc, IppByteImage& imgDst, int amount);
void IppNoiseSalutNPepper(IppByteImage& imgSrc, IppByteImage& imgDst, int amount);
