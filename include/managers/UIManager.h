#ifndef UIMANAGER_H
#define UIMANAGER_H
#include "../core/ui.h"
#include <memory>
#include <vector>

class UIManager {
    public:
    UIManager();
    ~UIManager();
    bool Init(SDL_Window* window, SDL_GLContext glContext);
    void render();
    void addUI(std::shared_ptr<UI> element);
    void removeElement(std::shared_ptr<UI> element);
    void shutdown();
    
    
    private:
    std::vector<std::shared_ptr<UI>> elements;
};

#endif