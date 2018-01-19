#include"map.h"
#include<windows.h>

void Map::PrintInitmap()
{
	for (auto& point : initmap)
	{
		point.Print();
		Sleep(10);
	}
}