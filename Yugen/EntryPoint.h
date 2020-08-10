// STL
#include <memory>

// Local includes
#include "Application.h"


extern std::shared_ptr<Yugen::Application> Yugen::createApplication();

int main(int argc, char *argv[]) {
    auto app = Yugen::createApplication();
    app->run();
    return 0;
}