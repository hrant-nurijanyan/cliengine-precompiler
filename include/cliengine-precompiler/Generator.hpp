#ifndef BEBOP_CLIENGINE_PREPROCESSOR_GENERATOR_HPP
#define BEBOP_CLIENGINE_PREPROCESSOR_GENERATOR_HPP

#include <fstream>
#include <nlohmann/json.hpp>
#include <sstream>
#include <string>

namespace bebop::cliengine::preprocessor
{

/**
 * @brief Responsible for generating a precompiled C++ header from a JSON command schema.
 *
 * The Generator reads a JSON file that defines CLI commands and outputs a C++ header
 * containing a function that returns a populated command map.
 * This precompiled header can then be included and used by the CLI engine.
 */
struct Generator
{
    /**
     * @brief Generates a C++ header containing precompiled CLI command definitions.
     *
     * Parses a JSON file containing command definitions, their flags, and arguments,
     * and writes a corresponding `.hpp` file containing C++ code that builds a
     * `std::unordered_map<std::string, CommandDef>`.
     *
     * The generated function is wrapped in the namespace `bebop::cliengine::precompiled`
     * and can be used by defining `CLIENGINE_PRECOMPILED_HEADER_PATH` and including it.
     *
     * @param jsonPath Path to the input JSON file describing command definitions.
     * @param outputHeaderPath Path to the output `.hpp` file that will be generated.
     *
     * @throws std::runtime_error if either the input JSON file cannot be opened or
     *         the output header cannot be written.
     *
     * @see bebop::cliengine::CommandDef
     */
    static void generate(const std::string& jsonPath, const std::string& outputHeaderPath);

   private:
    /**
     * @brief Escapes a string to be safely embedded as a C++ string literal.
     *
     * Replaces characters like `"` and `\` with their escaped equivalents.
     *
     * @param s The input string.
     * @return A new string with necessary escape sequences inserted.
     */
    static std::string escape(const std::string& s);
};

}  // namespace bebop::cliengine::preprocessor

#endif  // BEBOP_CLIENGINE_PREPROCESSOR_GENERATOR_HPP
