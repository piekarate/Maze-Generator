#include "Application.h"


int main()
{
    srand(static_cast<unsigned>(time(NULL)));
    
    // Create the main window
    Application app;
    
    // Start the game loop
    while (app.isRunning())
    {
        app.update();

        app.render();
    }
}

