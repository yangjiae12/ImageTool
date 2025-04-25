#pragma once
#include "IppImage.h"

void IppFilterMean(IppByteImage& imgSrc, IppByteImage& imgDst);
void IppFilterWeightedMean(IppByteImage& imgSrc, IppByteImage& imgDst);

void IppFilterMean2(IppByteImage& imgSrc, IppByteImage& imgDst);
void IppFilterWeightedMean2(IppByteImage& imgSrc, IppByteImage& imgDst);


