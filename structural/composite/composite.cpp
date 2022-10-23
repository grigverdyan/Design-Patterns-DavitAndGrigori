#include <iostream>
#include <string>
#include <vector>

class Shape
{
	public:
    	virtual void draw() = 0;
};

class Circle : public Shape
{
	public:
    	void draw() 
		{ 
			std::cout << "Circle" << std::endl; 
		}
};

class Square : public Shape
{
	public:
		void draw()
		{
			std::cout << "Square" << std::endl;
		}
};

class Group : public Shape {
	public:
    	Group(const std::string& name) : _name{name} {}
    	void draw()
		{
			std::cout << "Group " << _name.c_str() << " contains:" << std::endl;
        	for (auto&& obj : _objects)
            	obj->draw();
		}
		void addShape(Shape* shape)
		{
			_objects.push_back(shape);
		}
	private:
		std::string              _name;
		std::vector<Shape*>      _objects;
};

int main()
{
    Group group("main");
    group.addShape(new Circle);
    Group subgroup("sub");
    subgroup.addShape(new Square);
    group.addShape(&subgroup);
    group.draw();

	return EXIT_SUCCESS;
}
