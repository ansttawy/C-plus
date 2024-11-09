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

int main()
{
    mipt::fefm::Point p = {20, 30};
    mipt::frtk::print(p);
}