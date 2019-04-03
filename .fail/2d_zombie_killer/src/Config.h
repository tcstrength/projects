#ifndef CONFIG_H
#define CONFIG_H

struct Config
{
    const char* title = "Zombie Killer";
    int width = 1280;
    int height = 720;
    int frameRate = 120;
    bool isFullscreen = false;
    bool vsyncEnabled = true;
    bool showFPS = true;

    ///////////////////////////////////////////
    /// \brief load Load config from config.txt
    ///////////////////////////////////////////
    void load()
    {

    }
};

#endif // CONFIG_H
