#include <iostream>

struct Button
{
	virtual void paint() = 0;
};

struct GUIFactory 
{
	virtual Button *createButton(std::string) = 0;
};

struct PushButton : Button
{
	void paint()
	{
		std::cout << "Push button" << std::endl;
	}
};
 
struct PopButton : Button 
{
	void paint()
	{
		std::cout << "Pop button \n";
	}
};

struct Factory : GUIFactory
{
	Button *createButton(std::string type) 
	{
		if(type.compare("Pop") == 0)
		{
			return new PopButton;
		}
		else if(type.compare("Push") == 0)
		{
			return new PushButton;
		}
		return nullptr;
	}
};

int main()
{
	GUIFactory* guiFactory;
	Button *btn;

	guiFactory = new Factory;

	btn = guiFactory->createButton("Push");
	btn -> paint();
	btn = guiFactory->createButton("Pop");
	btn -> paint();

	return EXIT_SUCCESS;
}
