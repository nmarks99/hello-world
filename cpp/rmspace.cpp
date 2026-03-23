#include <filesystem>
#include <iostream>
#include <format>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {

    bool quiet = false;

    if (argc > 1) {
        if (std::string(argv[1]) == "-q") {
            quiet = true;
        }
    }

    int count = 0;
    for (auto file_entry : fs::directory_iterator(fs::path("."))) {
        if (file_entry.is_regular_file()) {

            auto before = file_entry.path().filename().string();

            // skip hidden files
            if (before[0] == '.') {
                continue;
            }

            auto after = before;

            // if no spaces in filename, skip
            size_t i = after.find(" ");
            if (i == std::string::npos) {
                continue;
            }

            // get file name with spaces replaced with underscores
            while (i != std::string::npos) {
                after.replace(i, 1, "_");
                i = after.find(" ");
            }

            if (fs::exists(after)) {
                std::cout << std::format("Skipping '{}' to prevent overwrite\n", before);
            } else {
                if (!quiet) {
                    std::cout << std::format("Renaming '{}' to '{}'\n", before, after);
                }
                fs::rename(file_entry.path(), fs::path(after));
                count += 1;
            }
        }
    }
    if (!quiet) {
        std::cout << "Renamed " << count << " files" << std::endl;
    }
}
