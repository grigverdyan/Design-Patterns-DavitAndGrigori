#include <iostream>

class SocketAbstract
{
    public:
        SocketAbstract() {}
        ~SocketAbstract() {}
        virtual void americanSocket() = 0;
};

class Socket : public SocketAbstract
{
    public:
        Socket() {}
        ~Socket() {}
        void americanSocket()
        {
            std::cout << "This is a socket of american type\n";
        }
};

class AdapterAbstract
{
    public:
        AdapterAbstract() {}
        ~AdapterAbstract() {}
        virtual void europeanSocket() = 0;
};

class Adapter : public AdapterAbstract
{
    public:
        Adapter(SocketAbstract* obj)
        {
            mSocketPointer = obj;
        }
        ~Adapter() {}
        void europeanSocket()
        {
            mSocketPointer->americanSocket();
        }
    private:
        SocketAbstract* mSocketPointer;
};

int main()
{
    Socket* socketPtr = new Socket();
    AdapterAbstract* adapter = new Adapter(socketPtr);
    adapter->europeanSocket();

    return 0;
}
