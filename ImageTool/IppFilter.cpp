#include "pch.h"
#include "IppFilter.h"

void IppFilterMean(IppByteImage& imgSrc, IppByteImage& imgDst)
{
	int w = imgSrc.GetWidth();
	int h = imgSrc.GetHeight();

	imgDst = imgSrc;

	BYTE** pSrc = imgSrc.GetPixels2D();
	BYTE** pDst = imgDst.GetPixels2D();

	int mask[3][3] = {
		{ 1, 1, 1 },
		{ 1, 1, 1 },
		{ 1, 1, 1 },
	};

	int i, j, m, n, sum;
	for (j = 1; j < h - 1; j++)
		for (i = 1; i < w - 1; i++)
		{
			sum = 0;
			for (m = 0; m < 3; m++)
				for (n = 0; n < 3; n++)
				{
					sum += (pSrc[j - 1 + m][i - 1 + n] * mask[m][n]);
				}

			pDst[j][i] = static_cast<BYTE>(limit(sum / 9. + 0.5));
		}

}

void IppFilterWeightedMean(IppByteImage& imgSrc, IppByteImage& imgDst)
{

	int w = imgSrc.GetWidth();
	int h = imgSrc.GetHeight();

	imgDst = imgSrc;

	BYTE** pSrc = imgSrc.GetPixels2D();
	BYTE** pDst = imgDst.GetPixels2D();

	int mask[3][3] = {
		{ 1, 2, 1 },
		{ 2, 4, 2 },
		{ 1, 2, 1 },
	};

	int i, j, m, n, sum;
	for (j = 1; j < h - 1; j++)
		for (i = 1; i < w - 1; i++)
		{
			sum = 0;
			for (m = 0; m < 3; m++)
				for (n = 0; n < 3; n++)
				{
					sum += (pSrc[j - 1 + m][i - 1 + n] * mask[m][n]);
				}

			pDst[j][i] = static_cast<BYTE>(limit(sum / 16. + 0.5));
		}

}

void IppFilterMean2(IppByteImage& imgSrc, IppByteImage& imgDst)
{
	int w = imgSrc.GetWidth();
	int h = imgSrc.GetHeight();

	imgDst = imgSrc;

	BYTE** pSrc = imgSrc.GetPixels2D();
	BYTE** pDst = imgDst.GetPixels2D();

	int mask[5][5] = {
		{1,1,1,1,1},
		{1,1,1,1,1},
		{1,1,1,1,1},
		{1,1,1,1,1},
		{1,1,1,1,1}
	};

	int i, j, m, n, sum;

	for (j = 2; j < h - 2; j++)
		for (i = 2; i < w - 2; i++) {
			sum = 0;
			for (m = 0; m < 5; m++)
				for (n = 0; n < 5; n++) {
					sum += (pSrc[j - 2 + m][i - 2 + n] * mask[m][n]);
				}

			pDst[j][i] = static_cast<BYTE>(limit(sum / 25. + 0.5));
		}

}

void IppFilterWeightedMean2(IppByteImage& imgSrc, IppByteImage& imgDst)
{
	int w = imgSrc.GetWidth();
	int h = imgSrc.GetHeight();

	imgDst = imgSrc;

	BYTE** pSrc = imgSrc.GetPixels2D();
	BYTE** pDst = imgDst.GetPixels2D();

	int mask[5][5] = {
		{1,4,6,4,1},
		{4,16,24,16,4},
		{6,24,36,24,6},
		{4,16,24,16,4},
		{1,4,6,4,1}
	};

	int i, j, m, n, sum;

	for (j = 2; j < h - 2; j++)
		for (i = 2; i < w - 2; i++) {
			sum = 0;
			for (m = 0; m < 5; m++)
				for (n = 0; n < 5; n++) {
					sum += (pSrc[j - 2 + m][i - 2 + n] * mask[m][n]);
				}

			pDst[j][i] = static_cast<BYTE>(limit(sum / 256. + 0.5));
		}

}
