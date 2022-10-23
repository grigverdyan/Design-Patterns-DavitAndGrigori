#include <iostream>

class ApplicationImplementer
{
	public:
		virtual void forMobile() = 0;
		virtual void forDesktop() = 0;
		virtual ~ApplicationImplementer() {};
};

class Application
{
	public:
		Application(ApplicationImplementer* app)
			: imp{app} {}
		virtual ~Application() {}
		virtual void design() = 0;
	protected:
		ApplicationImplementer* imp;
};

class MobileApplication : public Application
{
	public:
		MobileApplication(ApplicationImplementer* app)
			: Application{app}
		{
			std::cout << "Application will be on Mobile" << std::endl;
		}
		void design()
		{
			imp->forMobile();
		}
};

class DesktopApplication : public Application
{
	public:
	DesktopApplication(ApplicationImplementer* app)
		: Application{app}
	{
		std::cout << "Application will be on Desktop" << std::endl;
	}
	void design()
	{ 
		imp->forMobile();
	}
};

class LinuxImplementer : public ApplicationImplementer
{
	public:
		LinuxImplementer()
		{
			std::cout << "Linux has been selected for the Application" << std::endl;
		}
		void forDesktop()
		{
			std::cout << "Linux has been selected for Mobile" << std::endl;
		}
		void forMobile()
		{
			std::cout << "Linux has been selected for Desktop" << std::endl;
		}
};

class WindowsImplementer : public ApplicationImplementer
{
	public:
		WindowsImplementer()
		{
			std::cout << "Windows has been selected for the Application" << std::endl;
		}
		void forDesktop()
		{
			std::cout << "Windows has been selected for Mobile" << std::endl;
		}
		void forMobile()
		{
			std::cout << "Windows has been selected for Desktop" << std::endl;
		}
};

int main()
{
	ApplicationImplementer* app = new WindowsImplementer;
	DesktopApplication desktop(app);
	desktop.design();
	delete app;

	return EXIT_SUCCESS;
}
