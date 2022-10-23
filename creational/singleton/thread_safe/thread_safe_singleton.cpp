#include <iostream>
#include <thread>
#include <mutex>

class Singleton
{
    public:
		~Singleton();
        static Singleton* getInstance();
        void setValue(int value)
		{ 
            mValue = value; 
        }
        int getValue()
		{
            return mValue;
        }

    private:
        int mValue;
        static Singleton *mInstance;
        static std::mutex mMutex;
        Singleton() : mValue(0) {}
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
};

std::mutex Singleton::mMutex;

Singleton *Singleton::mInstance = nullptr;

Singleton* Singleton::getInstance()
{
    std::lock_guard<std::mutex> lock(mMutex);
    if (mInstance == nullptr)
	{
        mInstance = new Singleton();
    }
	return mInstance;
}

void first()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton *p = Singleton::getInstance();
    p->setValue(13);
    std::cout << "Value = " << p->getValue() << std::endl;
}

void second()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton *p = Singleton::getInstance();
    p->setValue(69);
    std::cout << "Value = " << p->getValue() << std::endl;
}

int main()
{   
    std::cout <<"If there is the same value then singleton was reused\n" <<
                "If there are different values, then 2 singletons were created\n" <<
                "RESULTS:\n";   
    std::thread t1(first);
    std::thread t2(second);
    t1.join();
    t2.join();
    return 0;
}
