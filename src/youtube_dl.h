struct av_url 
{
            char video[1024];
            char audio[1024];
};

struct av_url *get_url(char url[]);
