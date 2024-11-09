#include <cstdio>
#include <iostream>
#include <ostream>

namespace mipt
{
	namespace fefm
	{
		struct Point
		{
			int x, y;
		};
	}
	
	namespace frtk
	{
		void print(fefm::Point p)
		{
			std::cout << p.x << " " << p.y << std::endl;
		}
	}

}

using namespace mipt;

int main()
{
    fefm::Point p = {20, 30};
    frtk::print(p);
}