#include <fstream>

#include "Config.h"
#include "Option.h"
#include "OptionManager.h"

int main(int argc, char *argv[]) {
    auto config = Option<std::string>("-c","--config");

    auto optionManager = OptionManager();
    optionManager.add_option(config);

    optionManager.parse(argc, argv);

    if (config.has_value()) {
        std::fstream f(config.get_value());
        Config::fromJson(json::parse(f));
    }

    return 0;
}
