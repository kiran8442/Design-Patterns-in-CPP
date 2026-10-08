#include <iostream>
#include <vector>

using namespace std;

class Subscriber
{
    public: 
    virtual ~Subscriber() = default;
    virtual void notify() = 0;
};
class User: public Subscriber
{
    string name;
    public:
    User(string name):name(name)
    {

    }
    void notify() override
    {
        cout<< name << "\nnotified that Youtube channel is upload the photo\n";
    }
};
class YouTubeChannel
{
    vector<Subscriber*> vec;

    public:
    void AddUser(Subscriber* u)
    {
        vec.push_back(u);
    }
    void uploadVideo()
    {
        NotifyAll();
    }
    private:
    void NotifyAll()
    {
        for(Subscriber* i:vec)
            i->notify();
    }
};
int main()
{
    YouTubeChannel channel;// = new YouTubeChannel();
    User u1("Kiran");
    User u2("Aakash");
    channel.AddUser(&u1);
    channel.AddUser(&u2);
    channel.uploadVideo();

    return 0;
}
