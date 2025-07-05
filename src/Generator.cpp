#include <cliengine-precompiler/Generator.hpp>
#include <fstream>
#include <sstream>
#include <stdexcept>

using json = nlohmann::json;

#include <cliengine-precompiler/Generator.hpp>

using json = nlohmann::json;

void bebop::cliengine::preprocessor::Generator::generate(const std::string& jsonPath, const std::string& outputHeaderPath)
{
    std::ifstream in(jsonPath);
    if (!in.is_open())
        throw std::runtime_error("Failed to open input JSON");

    json j;
    in >> j;

    std::ofstream out(outputHeaderPath);
    if (!out.is_open())
        throw std::runtime_error("Failed to write to output header");

    out << "#ifndef CLIENGINE_PRECOMPILED_COMMANDS_HPP\n";
    out << "#define CLIENGINE_PRECOMPILED_COMMANDS_HPP\n\n";
    out << "#include <cliengine/Defines.hpp>\n\n";
    out << "namespace bebop::cliengine::precompiled {\n\n";
    out << "inline std::unordered_map<std::string, bebop::cliengine::CommandDef> loadPrecompiledCommands() {\n";
    out << "    using namespace bebop::cliengine;\n";
    out << "    std::unordered_map<std::string, CommandDef> map;\n\n";

    for (const auto& cmd : j["commands"])
    {
        out << "    map[\"" << escape(cmd["name"]) << "\"] = CommandDef{\n";
        out << "        \"" << escape(cmd["name"]) << "\",\n";
        out << "        \"" << escape(cmd["description"]) << "\",\n";

        // Positional args
        out << "        {\n";
        for (const auto& arg : cmd["args"])
        {
            out << "            { \"" << escape(arg["name"]) << "\", ArgumentType::" << arg["type"].get<std::string>() << ", "
                << (arg["required"].get<bool>() ? "true" : "false") << " },\n";
        }
        out << "        },\n";

        // Flags
        out << "        {\n";
        for (const auto& flag : cmd["flags"])
        {
            out << "            { \"" << escape(flag["name"]) << "\", ArgumentType::" << flag["type"].get<std::string>() << ", "
                << (flag["required"].get<bool>() ? "true" : "false") << " },\n";
        }
        out << "        }\n";
        out << "    };\n\n";
    }

    out << "    return map;\n";
    out << "}\n\n";  // close function
    out << "} // namespace bebop::cliengine::precompiled\n\n";
    out << "#endif  // CLIENGINE_PRECOMPILED_COMMANDS_HPP\n";
}

std::string bebop::cliengine::preprocessor::Generator::escape(const std::string& s)
{
    std::ostringstream oss;
    for (char c : s)
    {
        if (c == '"')
            oss << "\\\"";
        else if (c == '\\')
            oss << "\\\\";
        else
            oss << c;
    }
    return oss.str();
}
