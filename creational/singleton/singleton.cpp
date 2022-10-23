#include <iostream>

class Singleton
{
    public:
        static Singleton*   getInstance();
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
        Singleton() : mValue(0) {}
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
};

Singleton* Singleton::mInstance = nullptr;

Singleton* Singleton::getInstance()
{
    if (mInstance == nullptr) 
	{
        mInstance = new Singleton();
    }
    return mInstance;
}

int main() {
    Singleton *p1 = Singleton::getInstance();
    p1->setValue(13);
    Singleton *p2 = Singleton::getInstance();
    std::cout << "Value = " << p2->getValue() << std::endl;
}
