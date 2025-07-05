#include <cliengine-precompiler/Generator.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: cliengine-precompiler <input.json> <output.hpp>\n";
        return 1;
    }

    try
    {
        bebop::cliengine::preprocessor::Generator::generate(argv[1], argv[2]);
        std::cout << "Header generated at " << argv[2] << "\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}