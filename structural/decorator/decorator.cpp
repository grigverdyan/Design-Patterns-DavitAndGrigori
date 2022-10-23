#include <iostream>
#include <string>
#include <sstream>

class Shape
{
	public:
		virtual operator std::string() = 0;
};

class Square : public Shape
{
	public:
		Square(double side = 0) : _side{side} {}
		operator std::string()
		{
			std::ostringstream ss;
			ss << "Square with side " << _side;
			return ss.str();
		}
	private:
		double _side;
};

class ColoredShape : public Shape
{
	public:
		ColoredShape(Shape& shape, std::string& color) 
			: _shape{shape}, _color{color} {}
		operator std::string()
		{
			std::ostringstream ss;
			ss << std::string(_shape) << " is " << _color;
			return ss.str();
		}
	private:
		Shape&		_shape;
		std::string	_color;

};

int main()
{
	Square square(13);
	std::string color = "blue";
	ColoredShape blueSquare(square, color);
	std::cout << std::string(square) << std::endl
			  << std::string(blueSquare) << std::endl;

	return EXIT_SUCCESS;
}
