// STL
#include <memory>

// Local includes
#include "Application.h"


extern std::shared_ptr<Core::Application> Core::createApplication();

int main(int argc, char *argv[]) {
    auto app = Core::createApplication();
    app->run();
    return 0;
}