#include <iostream>
#include "core/Header.h"
#include "tools/stats.h"
int main()
{
	Rendering::Log::Init();
	
	INFO("HI");
	return 0;
}

// TODO LIST
/*
Camera 
BxDf
BeckmannDistribution -> sample_wh
BSDF -> sample_f pdf
Material::Bump
BSSRDF sub class

implementation : imagetexture

http://bgrawi.com/Fourier-Visualizations/ fourier
 Monte carlo https://zhuanlan.zhihu.com/p/61611088
*/