#include <apue.h>
#include <sys/epoll.h>
#include "../Utility/GGSingleton.h"

class GGEpollSession
{
    public:
         GGEpollSession();
         ~GGEpollSession();

    

    protected:

        int Create();
        

    private:

       int epoll_fd;

};

