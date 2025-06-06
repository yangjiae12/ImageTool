#include "pch.h"
#include "IppFilter.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <random>
#include <algorithm>


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

void IppFilterLaplacian(IppByteImage& imgSrc, IppByteImage& imgDst)
{
	int w = imgSrc.GetWidth();
	int h = imgSrc.GetHeight();

	imgDst = imgSrc; 

	BYTE** pSrc = imgSrc.GetPixels2D();
	BYTE** pDst = imgDst.GetPixels2D();

	int mask[3][3] = {
		{ 0, 1, 0 },
		{ 1, -4, 1 },
		{ 0, 1, 0 },
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

			pDst[j][i] = static_cast<BYTE>(limit(sum + 128));
		}



}

void IppFilterUnsharpMask(IppByteImage& imgSrc, IppByteImage& imgDst)
{
	int w = imgSrc.GetWidth();
	int h = imgSrc.GetHeight();

	imgDst = imgSrc;

	BYTE** pSrc = imgSrc.GetPixels2D();
	BYTE** pDst = imgDst.GetPixels2D();

	int mask[3][3] = {
		{ 0, -1, 0 },
		{ -1, 5, -1 },
		{ 0, -1, 0 },
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

			pDst[j][i] = static_cast<BYTE>(limit(sum));
		}
}

void IppFilterHighboost(IppByteImage& imgSrc, IppByteImage& imgDst, float alpha)
{
	int w = imgSrc.GetWidth();
	int h = imgSrc.GetHeight();

	imgDst = imgSrc;

	BYTE** pSrc = imgSrc.GetPixels2D();
	BYTE** pDst = imgDst.GetPixels2D();

	int mask[3][3] = {
		{ 0, -1, 0 },
		{ -1, 6, -1 },
		{ 0, -1, 0 },
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

			pDst[j][i] = static_cast<BYTE>(limit(sum + 0.5));
		}
}

void IppNoiseGaussian(IppByteImage& imgSrc, IppByteImage& imgDst, int amount)
{
	int size = imgSrc.GetSize();

	imgDst = imgSrc;
	BYTE* pDst = imgDst.GetPixels();

	unsigned int seed = static_cast<unsigned int>(time(NULL));
	std::default_random_engine generator(seed);
	std::normal_distribution<double> distribution(0.0, 1.0);

	double rn;
	for (int i = 0; i < size; i++) {
		rn = distribution(generator) * 255 * amount / 100;
		pDst[i] = static_cast<BYTE>(limit(pDst[i] + rn));
	}

}

void IppNoiseSalutNPepper(IppByteImage& imgSrc, IppByteImage& imgDst, int amount)
{
	int size = imgSrc.GetSize();

	imgDst = imgSrc;
	BYTE* pDst = imgDst.GetPixels();

	unsigned int seed = static_cast<unsigned int>(time(NULL));
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(0, size - 1);

	int num = size * amount / 100;
	for (int i = 0; i < num; i++) {
		pDst[distribution(generator)] = (i & 0x01) * 255;
	}
}
