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

using mipt::fefm::Point, mipt::frtk::print;

int main()
{
    Point p = {20, 30};
    print(p);
}